#!/usr/bin/env python3
"""
fsrv_client.py — klient do serwera plikow FSRV.COM (Bosman-8 CP/M)

Protokol:
  GET  'G' + nazwa\0       -> 'K' + rlo + rhi + dane + crc8  |  'E'
  PUT  'P' + nazwa\0 + rlo + rhi + dane + crc8  ->  'K'  |  'E'
  DIR  'D'                 -> [11 bajtow]... + 0x00
  QUIT 'Q'                 -> 'K'

Uzycie:
  python3 fsrv_client.py [opcje] get  NAZWA_NA_CPM  [plik_lokalny]
  python3 fsrv_client.py [opcje] put  plik_lokalny  NAZWA_NA_CPM
  python3 fsrv_client.py [opcje] dir
  python3 fsrv_client.py [opcje] quit

Opcje:
  -p, --port    PORT      port szeregowy  (domyslnie /dev/ttyS0)
  -b, --baud    BAUD      predkosc        (domyslnie 9600)
  -t, --timeout SEKUNDY  timeout na odpowiedz (domyslnie 10)
"""

from __future__ import annotations

import argparse
import math
import sys
from pathlib import Path

try:
    import serial
except ImportError:
    sys.exit("Brak biblioteki pyserial.  Zainstaluj:  pip install pyserial")

RECORD = 128   # rozmiar rekordu CP/M w bajtach


# ---------------------------------------------------------------------------
# Warstwa transportowa
# ---------------------------------------------------------------------------

def recv_byte(port: serial.Serial) -> int:
    b = port.read(1)
    if not b:
        raise TimeoutError("Timeout — brak odpowiedzi serwera")
    return b[0]


def send_byte(port: serial.Serial, value: int) -> None:
    port.write(bytes([value]))


def send_bytes(port: serial.Serial, data: bytes) -> None:
    port.write(data)


def recv_exact(port: serial.Serial, n: int) -> bytes:
    buf = b""
    while len(buf) < n:
        chunk = port.read(n - len(buf))
        if not chunk:
            raise TimeoutError(f"Timeout — oczekiwano {n} B, odebrano {len(buf)} B")
        buf += chunk
    return buf


def send_name(port: serial.Serial, name: str) -> None:
    """Wyslij nazwe pliku CP/M: max 12 znakow, null-terminated, wielkie litery."""
    name = name.upper().strip()
    if len(name) > 12:
        raise ValueError(f"Nazwa za dluga (max 12 zn): {name!r}")
    send_bytes(port, name.encode("ascii") + b"\x00")


def expect_ok(port: serial.Serial) -> None:
    resp = recv_byte(port)
    if resp == ord("E"):
        raise RuntimeError("Serwer zwrocil blad (E)")
    if resp != ord("K"):
        raise RuntimeError(f"Nieoczekiwana odpowiedz serwera: 0x{resp:02X}")


# ---------------------------------------------------------------------------
# Komendy
# ---------------------------------------------------------------------------

def cmd_get(port: serial.Serial, cpm_name: str, local_path: Path) -> None:
    """Pobierz plik z serwera CP/M."""
    send_byte(port, ord("G"))
    send_name(port, cpm_name)

    resp = recv_byte(port)
    if resp == ord("E"):
        raise RuntimeError("Serwer zwrocil blad — plik nie istnieje lub blad odczytu")
    if resp != ord("K"):
        raise RuntimeError(f"Nieoczekiwana odpowiedz: 0x{resp:02X}")

    rlo = recv_byte(port)
    rhi = recv_byte(port)
    records = rhi * 256 + rlo
    total_bytes = records * RECORD

    print(f"  Pobieranie: {cpm_name}  ({records} rekordow, {total_bytes} B)")

    data = recv_exact(port, total_bytes)

    server_crc = recv_byte(port)
    local_crc = _crc8(data)
    if server_crc != local_crc:
        raise RuntimeError(
            f"Blad CRC: serwer={server_crc:02X}, obliczony={local_crc:02X}"
        )

    # Przytnij ewentualne bajty wypelnienia (CP/M ostatni rekord moze miec ^Z)
    data = _strip_cpm_eof(data)

    local_path.write_bytes(data)
    print(f"  Zapisano: {local_path}  ({len(data)} B po przycieciu)")


def cmd_put(port: serial.Serial, local_path: Path, cpm_name: str) -> None:
    """Wyslij plik do serwera CP/M."""
    raw = local_path.read_bytes()

    # Dopelnij do pelnych rekordow (jak CP/M)
    records = math.ceil(len(raw) / RECORD) if raw else 0
    padded = raw.ljust(records * RECORD, b"\x1A")  # wypelnienie ^Z

    rlo = records & 0xFF
    rhi = (records >> 8) & 0xFF
    crc = _crc8(padded)

    print(f"  Wysylanie: {local_path}  ({records} rekordow, {len(padded)} B)")

    send_byte(port, ord("P"))
    send_name(port, cpm_name)
    send_byte(port, rlo)
    send_byte(port, rhi)
    send_bytes(port, padded)
    send_byte(port, crc)

    expect_ok(port)
    print(f"  OK — zapisano na CP/M jako {cpm_name.upper()}")


def cmd_dir(port: serial.Serial) -> None:
    """Wyswietl liste plikow z serwera CP/M."""
    send_byte(port, ord("D"))

    entries: list[str] = []
    while True:
        raw = recv_exact(port, 11)
        if raw == b"\x00" * 11:
            break
        name = raw[:8].decode("ascii", errors="replace").rstrip()
        ext  = raw[8:11].decode("ascii", errors="replace").rstrip()
        if ext:
            entries.append(f"{name}.{ext}")
        else:
            entries.append(name)

    if not entries:
        print("  (brak plikow)")
    else:
        col = 5
        for i, e in enumerate(sorted(entries)):
            end = "\n" if (i + 1) % col == 0 else "  "
            print(f"  {e:<14}", end=end)
        if len(entries) % col:
            print()
    print(f"\n  {len(entries)} plikow")


def cmd_quit(port: serial.Serial) -> None:
    """Zakoncz prace serwera."""
    send_byte(port, ord("Q"))
    expect_ok(port)
    print("  Serwer zakonczyl prace.")


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def _crc8(data: bytes) -> int:
    crc = 0
    for b in data:
        crc ^= b
    return crc & 0xFF


def _strip_cpm_eof(data: bytes) -> bytes:
    """Usun bajty ^Z (0x1A) z konca pliku (CP/M EOF marker)."""
    return data.rstrip(b"\x1A")


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def build_parser() -> argparse.ArgumentParser:
    p = argparse.ArgumentParser(
        description="Klient serwera plikow FSRV.COM dla Bosman-8 CP/M 2.2",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=__doc__,
    )
    p.add_argument("-p", "--port",    default="/dev/ttyS0", help="Port szeregowy")
    p.add_argument("-b", "--baud",    default=9600, type=int, help="Predkosc (baud)")
    p.add_argument("-s", "--stopbits", default=2,   type=int, choices=[1, 2], help="Stop bity (domyslnie 2)")
    p.add_argument("-t", "--timeout", default=10,   type=float, help="Timeout [s]")

    sub = p.add_subparsers(dest="cmd", required=True)

    g = sub.add_parser("get", help="Pobierz plik z CP/M")
    g.add_argument("cpm_name",  help="Nazwa pliku na CP/M (np. DANE.TXT)")
    g.add_argument("local",     nargs="?", help="Sciezka lokalna (domyslnie: cpm_name)")

    pu = sub.add_parser("put", help="Wyslij plik do CP/M")
    pu.add_argument("local",    help="Lokalny plik zrodlowy")
    pu.add_argument("cpm_name", help="Nazwa pliku na CP/M")

    sub.add_parser("dir",  help="Lista plikow na CP/M")
    sub.add_parser("quit", help="Zatrzymaj serwer FSRV")

    return p


def main() -> None:
    args = build_parser().parse_args()

    stopbits = serial.STOPBITS_TWO if args.stopbits == 2 else serial.STOPBITS_ONE
    print(f"Lacze: {args.port}  {args.baud} baud  8N{args.stopbits}")
    try:
        port = serial.Serial(
            args.port,
            baudrate=args.baud,
            bytesize=serial.EIGHTBITS,
            parity=serial.PARITY_NONE,
            stopbits=stopbits,
            timeout=args.timeout,
        )
    except serial.SerialException as e:
        sys.exit(f"Blad otwarcia portu: {e}")

    try:
        if args.cmd == "get":
            local = Path(args.local) if args.local else Path(args.cpm_name)
            cmd_get(port, args.cpm_name, local)

        elif args.cmd == "put":
            local = Path(args.local)
            if not local.exists():
                sys.exit(f"Plik nie istnieje: {local}")
            cmd_put(port, local, args.cpm_name)

        elif args.cmd == "dir":
            cmd_dir(port)

        elif args.cmd == "quit":
            cmd_quit(port)

    except (RuntimeError, TimeoutError) as e:
        sys.exit(f"Blad: {e}")
    except KeyboardInterrupt:
        sys.exit("\nPrzerwano.")
    finally:
        port.close()


if __name__ == "__main__":
    main()
