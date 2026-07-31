#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
convert-polish-chars.py — Konwersja niestandardowego kodowania polskich znaków
z systemu CP/M BOSMAN-8 do UTF-8.

Komputer BOSMAN-8 (polski mikrokomputer z procesorem Z80, CP/M 2.2) używał
7-bitowego kodowania ASCII dla polskich znaków diakrytycznych. Znaki polskie
były zastępowane znakami interpunkcyjnymi ASCII według poniższej tabeli:

  @ (0x40) → ę    [ (0x5B) → ź    \ (0x5C) → Ł
  ] (0x5D) → ń    ^ (0x5E) → ś    ` (0x60) → ą
  { (0x7B) → ó    | (0x7C) → ł    } (0x7D) → ż
  ~ (0x7E) → ć

Dodatkowo niektóre pliki mają uszkodzony 8. bit (przypadkowo ustawiony),
co powoduje zamianę zwykłych znaków ASCII na znaki z zakresu 0x80-0xFF.
Skrypt domyślnie czyści te uszkodzenia przez `bajt & 0x7F`.

Użycie:
  python3 convert-polish-chars.py [OPCJE] PLIK [PLIK...]

Przykłady:
  # Konwersja pojedynczego pliku na stdout
  python3 convert-polish-chars.py -p dokument.txt

  # Konwersja do pliku .md obok oryginału
  python3 convert-polish-chars.py -p -s .md dokument.txt

  # Konwersja całego katalogu
  python3 convert-polish-chars.py -p -o output_dir/ *.txt

  # Modyfikacja plików w miejscu
  python3 convert-polish-chars.py -p -i dokument.txt

  # Tylko czyszczenie bitu 8, bez konwersji polskich znaków
  python3 convert-polish-chars.py -c plik.txt

  # Konwersja wszystkich wystąpień (bez heurystyki kontekstu)
  python3 convert-polish-chars.py -p --all plik.txt
"""

import argparse
import os
import sys
from pathlib import Path

# Mapowanie 7-bitowych znaków ASCII na polskie znaki UTF-8
# Używane w systemie BOSMAN-8 do reprezentacji polskich liter
POLISH_CHAR_MAP = {
    0x40: 'ę',  # @ → ę (eogonek)
    0x5B: 'ź',  # [ → ź (zacute)
    0x5C: 'Ł',  # \ → Ł (Lstrok - wielka litera)
    0x5D: 'ń',  # ] → ń (nacute)
    0x5E: 'ś',  # ^ → ś (sacute)
    0x60: 'ą',  # ` → ą (aogonek)
    0x7B: 'ó',  # { → ó (oacute)
    0x7C: 'ł',  # | → ł (lstrok - mała litera)
    0x7D: 'ż',  # } → ż (zdot)
    0x7E: 'ć',  # ~ → ć (cacute)
}

# Zbiór bajtów które mogą być polskimi znakami w kodowaniu BOSMAN-8
POLISH_BYTES = set(POLISH_CHAR_MAP.keys())

# Rozszerzenia plików binarnych CP/M - nie powinny być konwertowane
BINARY_EXTENSIONS = {
    '.COM', '.REL', '.OVR', '.OVL', '.OV1', '.OV2', '.CMD',
    '.HEX', '.BIN', '.CHN', '.CHR', '.OBR', '.KN', '.TAB',
    '.DAT', '.TBL', '.DIR', '.SYS', '.LIB', '.MSG', '.NUM',
    '.NDX', '.DBF', '.FIL', '.FIZ', '.HLP', '.MSK', '.PRN',
    '.OY1', '.BAK', '.TWN', '.TXN', '.EDT', '.YOM',
}


def is_binary_extension(filepath: str) -> bool:
    """Sprawdza, czy plik ma rozszerzenie wskazujące na format binarny."""
    ext = Path(filepath).suffix.upper()
    return ext in BINARY_EXTENSIONS


def is_binary_content(data: bytes, threshold: float = 0.3) -> bool:
    """
    Sprawdza, czy zawartość wygląda na binarną na podstawie proporcji
    bajtów niebędących tekstem.
    """
    if len(data) == 0:
        return False
    # Sprawdź pierwsze 8KB pliku
    sample = data[:8192]
    # Bajty tekstowe: drukowalne ASCII + tab, CR, LF + polskie znaki BOSMAN-8
    text_bytes = set(range(0x20, 0x7F)) | {0x09, 0x0A, 0x0D} | POLISH_BYTES
    non_text = sum(1 for b in sample if b not in text_bytes)
    # Jeśli >30% bajtów nie-tekstowych, uznajemy za binarny
    # PLiki CP/M często mają znaki sterujące jako wypełniacze, więc próg 30%
    return non_text / len(sample) > threshold


def clean_high_bit(data: bytes) -> bytes:
    """
    Czyści uszkodzony 8. bit we wszystkich bajtach.
    W systemie BOSMAN-8 niektóre pliki mają przypadkowo ustawiony
    najwyższy bit, np. 0x8D zamiast 0x0D (CR), 0x8A zamiast 0x0A (LF),
    0xA0 zamiast 0x20 (spacja), 0xE1 zamiast 0x61 ('a'), itp.
    """
    return bytes(b & 0x7F for b in data)


def is_polish_context(data: bytes, pos: int) -> bool:
    """
    Heurystyka sprawdzająca, czy znak na pozycji `pos` jest użyty
    w kontekście polskiego tekstu (w środku lub na końcu słowa),
    czy jako znak interpunkcyjny (np. nawiasy klamrowe w kodzie).

    Zwraca True, jeśli znak jest prawdopodobnie polskim znakiem.
    """
    b = data[pos]

    # Sprawdź, czy otoczony jest literami (a-z, A-Z) lub spółgłoskami
    # To wskazuje na użycie wewnątrz słowa, np. "program{w" → "programów"
    prev_is_letter = False
    next_is_letter = False

    if pos > 0:
        prev_byte = data[pos - 1]
        prev_is_letter = (
            (0x41 <= prev_byte <= 0x5A) or  # A-Z
            (0x61 <= prev_byte <= 0x7A) or  # a-z
            prev_byte in POLISH_BYTES
        )

    if pos < len(data) - 1:
        next_byte = data[pos + 1]
        next_is_letter = (
            (0x41 <= next_byte <= 0x5A) or  # A-Z
            (0x61 <= next_byte <= 0x7A) or  # a-z
            next_byte in POLISH_BYTES
        )

    # Znak wewnątrz słowa (poprzedzony i zakończony literą)
    # lub na końcu słowa (poprzedzony literą, po nim spacja/koniec)
    if prev_is_letter:
        return True

    # Znak na początku słowa (przed nim spacja, po nim litera)
    # np. "|adny" → "ładny" - ale tylko dla małych liter
    # \ (backslash → Ł) może być na początku słowa
    if next_is_letter and b in {0x5C, 0x7C}:  # \ → Ł, | → ł
        return True

    return False


def convert_polish_chars(data: bytes, strict: bool = True) -> bytes:
    """
    Konwertuje polskie znaki z kodowania BOSMAN-8 na UTF-8.

    Args:
        data: Dane wejściowe (już po czyszczeniu bitu 8)
        strict: Jeśli True, używa heurystyki kontekstu do wykrywania
                polskich znaków. Jeśli False, konwertuje wszystkie
                wystąpienia znaków specjalnych.

    Returns:
        Dane tekstowe z przekonwertowanymi polskimi znakami (UTF-8)
    """
    result = bytearray()

    # Najpierw zbierzmy pozycje do konwersji
    i = 0
    while i < len(data):
        b = data[i]
        if b in POLISH_BYTES:
            should_convert = True
            if strict:
                should_convert = is_polish_context(data, i)

            if should_convert:
                result.extend(POLISH_CHAR_MAP[b].encode('utf-8'))
            else:
                result.append(b)
        else:
            result.append(b)
        i += 1

    return bytes(result)


def process_file(
    filepath: str,
    clean_high: bool = True,
    convert_polish: bool = False,
    strict: bool = True,
    force: bool = False,
    verbose: bool = False,
) -> bytes:
    """
    Przetwarza pojedynczy plik: czyta, konwertuje, zwraca wynik.

    Args:
        filepath: Ścieżka do pliku
        clean_high: Czy czyścić bit 8
        convert_polish: Czy konwertować polskie znaki
        strict: Tryb ścisły konwersji (heurystyka kontekstu)
        force: Wymuś przetwarzanie nawet dla plików binarnych
        verbose: Wypisuj informacje o postępie

    Returns:
        Przekonwertowana zawartość pliku

    Raises:
        ValueError: Jeśli plik jest binarny i force=False
    """
    with open(filepath, 'rb') as f:
        data = f.read()

    if not data:
        return data

    # Sprawdź, czy plik nie jest binarny
    if not force and (is_binary_extension(filepath) or is_binary_content(data)):
        raise ValueError(
            f"Plik '{filepath}' wygląda na binarny. "
            f"Użyj --force, aby wymusić konwersję."
        )

    result = data

    if clean_high:
        cleaned = clean_high_bit(result)
        if verbose and cleaned != result:
            changed = sum(1 for a, b in zip(result, cleaned) if a != b)
            print(f"  [clean-high-bit] {filepath}: naprawiono {changed} bajtów",
                  file=sys.stderr)
        result = cleaned

    if convert_polish:
        converted = convert_polish_chars(result, strict=strict)
        if verbose and converted != result:
            changed = sum(1 for a, b in zip(result, converted) if a != b)
            print(f"  [convert-polish] {filepath}: zamieniono {changed} znaków",
                  file=sys.stderr)
        result = converted

    return result


def main():
    parser = argparse.ArgumentParser(
        description='Konwersja polskich znaków z kodowania BOSMAN-8 (CP/M) do UTF-8',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Przykłady:
  %(prog)s -p dokument.txt              # Konwersja na stdout
  %(prog)s -p -s .md dokument.txt       # Zapis do dokument.txt.md
  %(prog)s -p -o wyniki/ *.txt          # Wsadowa konwersja do katalogu
  %(prog)s -p -i dokument.txt           # Modyfikacja w miejscu
  %(prog)s -c plik.txt                  # Tylko czyszczenie bitu 8

Mapowanie znaków BOSMAN-8 → UTF-8:
  @ → ę   [ → ź   \\ → Ł   ] → ń   ^ → ś
  ` → ą   { → ó   |  → ł   } → ż   ~ → ć
        """,
    )
    parser.add_argument(
        'files', nargs='+', help='Pliki do przetworzenia'
    )
    parser.add_argument(
        '-c', '--clean-high-bit', action='store_true', default=True,
        help='Czyść uszkodzony 8. bit we wszystkich bajtach (domyślnie włączone)'
    )
    parser.add_argument(
        '--no-clean-high-bit', action='store_true',
        help='Wyłącz czyszczenie bitu 8'
    )
    parser.add_argument(
        '-p', '--convert-polish', action='store_true',
        help='Konwertuj polskie znaki z kodowania BOSMAN-8 na UTF-8'
    )
    parser.add_argument(
        '--strict', action='store_true', default=True,
        help='Używaj heurystyki kontekstu przy konwersji (domyślnie)'
    )
    parser.add_argument(
        '--all', action='store_true',
        help='Konwertuj wszystkie wystąpienia znaków (bez heurystyki)'
    )
    parser.add_argument(
        '-f', '--force', action='store_true',
        help='Wymuś przetwarzanie nawet dla plików binarnych'
    )
    parser.add_argument(
        '-i', '--in-place', action='store_true',
        help='Modyfikuj pliki w miejscu (uważaj!)'
    )
    parser.add_argument(
        '-o', '--output', type=str, metavar='DIR',
        help='Katalog docelowy dla przekonwertowanych plików'
    )
    parser.add_argument(
        '-s', '--suffix', type=str, default='', metavar='SUFFIX',
        help='Dodaj sufiks do nazwy pliku wyjściowego (np. .md)'
    )
    parser.add_argument(
        '--keep-crlf', action='store_true',
        help='Zachowaj oryginalne zakończenia linii (CRLF)'
    )
    parser.add_argument(
        '-v', '--verbose', action='store_true',
        help='Wypisuj szczegółowe informacje o konwersji'
    )

    args = parser.parse_args()

    # Ustal tryb
    clean_high = not args.no_clean_high_bit
    strict = not args.all

    # Walidacja
    if not clean_high and not args.convert_polish:
        parser.error(
            'Nie wybrano żadnej operacji. '
            'Użyj -p do konwersji polskich znaków '
            'lub nie wyłączaj -c (czyszczenie bitu 8 jest domyślne).'
        )

    if args.in_place and (args.output or args.suffix):
        parser.error(
            '--in-place nie może być używane z --output ani --suffix'
        )

    errors = 0

    for filepath in args.files:
        try:
            if args.verbose:
                print(f'Przetwarzanie: {filepath}', file=sys.stderr)

            result = process_file(
                filepath,
                clean_high=clean_high,
                convert_polish=args.convert_polish,
                strict=strict,
                force=args.force,
                verbose=args.verbose,
            )

            # Ustal ścieżkę wyjściową
            if args.in_place:
                outpath = filepath
            elif args.output:
                fname = Path(filepath).name
                outpath = os.path.join(args.output, fname + args.suffix)
                os.makedirs(args.output, exist_ok=True)
            elif args.suffix:
                outpath = filepath + args.suffix
            else:
                # Domyślnie: stdout
                # Konwertuj CRLF → LF chyba że --keep-crlf
                text = result.decode('utf-8', errors='replace')
                if not args.keep_crlf:
                    text = text.replace('\r\n', '\n').replace('\r', '\n')
                sys.stdout.write(text)
                continue

            # Zapis do pliku
            with open(outpath, 'wb') as f:
                f.write(result)

            if args.verbose:
                print(f'  Zapisano: {outpath}', file=sys.stderr)

        except ValueError as e:
            print(f'Błąd: {e}', file=sys.stderr)
            errors += 1
        except OSError as e:
            print(f'Błąd I/O: {e}', file=sys.stderr)
            errors += 1

    if errors:
        sys.exit(1)


if __name__ == '__main__':
    main()