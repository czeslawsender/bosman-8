from __future__ import annotations

import importlib.util
import unittest
from importlib.machinery import SourceFileLoader
from pathlib import Path

MODULE_PATH = Path(__file__).with_name("fsrv")
SPEC = importlib.util.spec_from_loader("fsrv_client", SourceFileLoader("fsrv_client", str(MODULE_PATH)))
fsrv = importlib.util.module_from_spec(SPEC)
assert SPEC.loader is not None
SPEC.loader.exec_module(fsrv)


class FakeSerial:
    def __init__(self, incoming: bytes = b"") -> None:
        self.incoming = bytearray(incoming)
        self.outgoing = bytearray()
        self.baudrate = 9600

    def read(self, size: int = 1) -> bytes:
        if not self.incoming:
            return b""
        chunk = self.incoming[:size]
        del self.incoming[:size]
        return bytes(chunk)

    def write(self, data: bytes) -> int:
        self.outgoing.extend(data)
        return len(data)

    def close(self) -> None:
        pass

    def flush(self) -> None:
        pass


def entry(name: str, ext: str) -> bytes:
    return name.encode("ascii").ljust(8) + ext.encode("ascii").ljust(3)


class FsrvClientTests(unittest.TestCase):
    def test_normalize_cpm_names(self) -> None:
        self.assertEqual(fsrv.normalize_cpm_name("a:pip.com"), "A:PIP.COM")
        self.assertEqual(fsrv.normalize_cpm_name("*.com", allow_wildcards=True), "*.COM")
        self.assertEqual(fsrv.normalize_cpm_name("b:*.com", allow_wildcards=True), "B:*.COM")

    def test_crc_padding_and_eof_strip(self) -> None:
        self.assertEqual(fsrv.crc_xor(bytes([1, 2, 3])), 0)
        records, padded = fsrv.pad_cpm_records(b"abc")
        self.assertEqual(records, 1)
        self.assertEqual(padded, b"abc" + (b"\x1A" * 125))
        self.assertEqual(fsrv.strip_cpm_eof(b"abc\x1A\x1A"), b"abc")

    def test_dir_sends_mask_and_reads_11_byte_terminator(self) -> None:
        fake = FakeSerial(entry("ZED", "COM") + entry("AAA", "TXT") + (b"\x00" * 11))
        self.assertEqual(fsrv.dir_files(fake, "b:*.com"), ["AAA.TXT", "ZED.COM"])
        self.assertEqual(bytes(fake.outgoing), b"DB:*.COM\x00")

    def test_get_reads_payload_and_strips_padding(self) -> None:
        payload = b"HELLO" + (b"\x1A" * 123)
        rec_crc = fsrv.crc_xor(payload)
        # K + rlo/hi + record(128B) + per-rec CRC + final K
        fake = FakeSerial(b"K" + bytes([1, 0]) + payload + bytes([rec_crc]) + b"K")
        self.assertEqual(fsrv.get_file(fake, "a:test.com"), b"HELLO")
        self.assertEqual(bytes(fake.outgoing), b"GA:TEST.COM\x00" + b"K")

    def test_put_sends_padded_records_and_crc(self) -> None:
        expected_payload = b"abc" + (b"\x1A" * 125)
        rec_crc = fsrv.crc_xor(expected_payload)
        # 3 Ks: initial ACK + per-record ACK + final ACK
        fake = FakeSerial(b"K" * 3)
        records = fsrv.put_file(fake, b"abc", "a:test.com")
        self.assertEqual(records, 1)
        self.assertEqual(
            bytes(fake.outgoing),
            b"PA:TEST.COM\x00"
            + bytes([1, 0])
            + expected_payload
            + bytes([rec_crc]),
        )

    def test_error_and_timeout_paths(self) -> None:
        with self.assertRaises(RuntimeError):
            fsrv.get_file(FakeSerial(b"E"), "A:NOPE.COM")
        with self.assertRaises(TimeoutError):
            fsrv.dir_files(FakeSerial(b""), "*.*")

    def test_intel_hex_generation_for_com_origin(self) -> None:
        self.assertEqual(fsrv.intel_hex_record(0x0100, bytes([1, 2, 3])), ":03010000010203F6")
        hex_text = fsrv.com_to_intel_hex(bytes(range(20)), chunk_size=16)
        self.assertIn(":10010000000102030405060708090A0B0C0D0E0F77", hex_text)
        self.assertTrue(hex_text.endswith(":00000001FF\r\n"))

    def test_cold_boot_sends_hex_and_ctrl_z(self) -> None:
        fake = FakeSerial()
        sent = fsrv.send_cold_boot(fake, b"abc", line_delay=0, char_delay=0)
        payload = bytes(fake.outgoing)
        self.assertEqual(sent, len(payload))
        self.assertIn(b":03010000616263D6\r\n", payload)
        self.assertTrue(payload.endswith(b":00000001FF\r\n\x1A"))

    def test_parse_cold_destination(self) -> None:
        self.assertEqual(fsrv.parse_cold_destination("b:fsrv"), ("B", "FSRV"))
        self.assertEqual(fsrv.parse_cold_destination("loader.hex"), ("A", "LOADER"))

    def test_speed_command_sends_level_and_switches_local_baud(self) -> None:
        fake = FakeSerial(b"K")
        self.assertEqual(fsrv.set_speed(fake, 5), 115200)
        self.assertEqual(bytes(fake.outgoing), b"S\x05")
        self.assertEqual(fake.baudrate, 115200)

    def test_baud_shortcuts_map_to_expected_rates(self) -> None:
        parser = fsrv.build_parser()
        self.assertEqual(parser.parse_args(["-1", "dir"]).baud, 9600)
        self.assertEqual(parser.parse_args(["-5", "quit"]).baud, 115200)


if __name__ == "__main__":
    unittest.main()
