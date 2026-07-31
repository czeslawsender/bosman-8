# FSRV - serwer plikow CP/M dla Bosman-8

https://forum.vcfed.org/index.php?threads/cp-m-emulator-for-linux.79281/

Serwer plikow dzialajacy na Bosmanie-8 pod CP/M 2.2 oraz klient PC w Pythonie.
Komunikacja jest binarna po RS-232 przez **SIO-B** (porty 0x81/0x83 — kanal
V.24/RS-232), domyslnie 9600 8N2.

## Pliki

| Plik | Opis |
|------|------|
| `fsrv.c` | Nowy serwer CP/M w C dla z88dk |
| `Makefile` | Budowanie `FSRV.COM` przez `zcc` |
| `FSRV.COM` | Plik wykonywalny CP/M 2.2 |
| `fsrv` | Klient PC (Python 3 + pyserial) |
| `fsrv.asm` | Starsza implementacja serwera w Z80 asm, zachowana jako referencja |
| `fsrv_client.py` | Starszy klient PC, zachowany jako referencja |

## Budowanie

```bash
cd tools/fsrv
make
```

Makefile uzywa `zcc +cpm -subtype=default -create-app`. Jezeli Twoja wersja z88dk
udostepnia subtype `generic`, mozna go wlaczyc tak:

```bash
make ZCC_SUBTYPE=generic
```

Instalacja z88dk zalezy od systemu. Na Debianie/Ubuntu uzyj pakietu `z88dk`, a
gdy pakiet jest zbyt stary, zbuduj aktualne z88dk z repozytorium projektu.

```bash
make clean
```

## Uruchamianie

### Na Bosmanie-8 (CP/M)

Wgraj `FSRV.COM` na dysk A lub B, nastepnie:

```
A> FSRV
```

Serwer wypisuje komunikat i czeka na polaczenie przez SIO-B. Aby zakonczyc
lokalnie, nacisnij `Q` miedzy komendami. Zdalnie mozna wyslac komende `quit`.

Uwaga: FSRV uzywa SIO-B, tego samego portu co protokol P2P dyskow D/E/F. Nie
uruchamiaj serwera, gdy Bosman jest w trybie mikrosystem.

### Na PC

Wymagane: Python 3 i `pyserial`.

```bash
# lista plikow na biezacym dysku CP/M
./fsrv -p /dev/ttyUSB0 dir

# lista plikow z maska i prefiksem dysku
./fsrv -p /dev/ttyUSB0 dir b:*.com

# pobierz plik z Bosmana
./fsrv -p /dev/ttyUSB0 get a:pip.com

# pobierz plik i zapisz lokalnie pod inna nazwa
./fsrv -p /dev/ttyUSB0 get dane.txt dane_backup.txt

# wyslij plik na Bosmana
./fsrv -p /dev/ttyUSB0 put ./test.com a:test.com

# zatrzymaj serwer zdalnie
./fsrv -p /dev/ttyUSB0 quit

# zmien predkosc serwera: 1=9600, 2=19200, 3=38400, 4=57600, 5=115200
./fsrv -p /dev/ttyUSB0 speed 5
```

Domyslny port to `$FSRV_PORT`, a gdy zmienna nie jest ustawiona: `/dev/ttyS0`.
Domyslne parametry lacza: `9600 8N2`; baud mozna tez ustawic przez `$FSRV_BAUD`.
Krotsze presety: `-1`..`-5` ustawiają odpowiednio `9600`..`115200`.
PySerial nie ma autodetekcji baudrate, wiec `speed` trzeba wyslac z aktualnie
dzialajaca predkoscia, a kolejne komendy uruchamiac z `-b` albo `$FSRV_BAUD`.

```bash
./fsrv --help
./fsrv -b 19200 --stopbits 1 -t 5 dir
```

### Zimny start bez FSRV.COM na CP/M

Gdy na CP/M nie ma jeszcze serwera, klient moze wyslac aktualny `FSRV.COM` przez
standardowe urzadzenie `RDR:` i CP/M `PIP`. Transfer jest tekstowy: klient
zamienia lokalny `FSRV.COM` na Intel HEX, wysyla go przez serial i konczy
znakiem `Ctrl-Z`. Po stronie CP/M nalezy potem uruchomic `LOAD`, zeby utworzyc
plik `.COM`.

```bash
./fsrv --cold -p /dev/ttyS0
```

Program wypisze instrukcje. Domyslnie poprosi, aby na CP/M wpisac:

```text
PIP A:FSRV.HEX=RDR:
```

Kiedy `PIP` czeka na dane z czytnika, wroc do PC i nacisnij Enter. Po transferze
na CP/M wpisz:

```text
LOAD FSRV
FSRV
```

Opcje przydatne przy wolniejszym lub bardziej wrazliwym laczu:

```bash
./fsrv --cold --cold-dest b:fsrv --cold-line-delay 0.05 -p /dev/ttyUSB0
```

## Protokół FSRV

Binarny, inicjowany przez klienta (PC). Serwer nasłuchuje w pętli na SIO-B
(porty 0x81/0x83). Każda ramka protokołu to:

```
PC → Bosman:  bajt komendy + payload
Bosman → PC:  bajt statusu + payload + " OK\r\n"  (sukces)
              bajt statusu + " ERR\r\n"           (błąd)
```

Gdzie bajt statusu to `K` (0x4B = OK) lub `E` (0x45 = Error). Część `" OK\r\n"`
lub `" ERR\r\n"` jest wysyłana przez BDOS fn 9 (C_WRITSTR, `$`-terminated).

### Komendy

```
GET   PC: 'G' + nazwa\0
      SRV: 'K' + rlo + rhi + dane[(rhi*256+rlo)*128B] + crc8 + " OK\r\n"
      SRV: 'E' + " ERR\r\n"   (plik nie istnieje / błąd odczytu)

PUT   PC: 'P' + nazwa\0 + rlo + rhi + dane[rekordy*128B] + crc8
      SRV: 'K' + " OK\r\n"
      SRV: 'E' + " ERR\r\n"   (błąd zapisu / CRC mismatch / pełny dysk)

DIR   PC: 'D' + maska\0
      SRV: [11B: nazwa(8) + ext(3)]... + 11× 0x00 + " OK\r\n"
      Koniec listy sygnalizowany 11 bajtami zerowymi.

SPEED PC: 'S' + poziom
      poziom: 1=9600, 2=19200, 3=38400, 4=57600, 5=115200
      SRV: 'K' + " OK\r\n"   (po ok. 10ms zwłoki serwer zmienia baud)
      SRV: 'E' + " ERR\r\n"   (poziom spoza zakresu 1-5)
      Uwaga: po 'K' serwer odczekuje ~10ms i przełącza prędkość SIO-A.
      Klient musi również zmienić baudrate po swojej stronie.

QUIT  PC: 'Q'
      SRV: 'K' + " OK\r\n"   (serwer wychodzi z pętli i kończy pracę)
      SRV: 'E' + " ERR\r\n"   (nieprawidłowa komenda)
```

### Zakończenie serwera lokalnie

Klawiatura Bosmana jest podłączona przez SIO-A (terminal, porty 0x80/0x82).
Serwer nasłuchuje jednocześnie na SIO-B (protokół FSRV, porty 0x81/0x83)
i SIO-A (lokalna konsola). Aby zakończyć lokalnie, wpisz `Q` na klawiaturze.
Zdalne zakończenie: wyślij `Q` przez SIO-B (komenda `quit`).

### Szczegóły

- Rozmiar pliku w rekordach CP/M (1 rekord = 128 B), little-endian (rlo, rhi).
- CRC to XOR wszystkich bajtów danych (bez nagłówków).
- Przy `put` klient dopełnia ostatni rekord `0x1A`; przy `get` obcina końcowe `0x1A`.
- Nazwy CP/M: format 8.3, ASCII uppercase, zakończone `\0`.
- Prefiks dysku `A:`..`P:` mapowany na bajt 1..16 w FCB.
- Przy `DIR`: wildcard `*` z klienta interpretowany jako `?` w FCB serwera.
- FSRV używa SIO-B (porty 0x81/0x83) do protokołu. SIO-A (0x80/0x82) to konsola.

## Tryb send (transfer bez FSRV)

Komenda `send` wysyła plik przez serial bez protokołu FSRV — serwer nie jest
potrzebny. Przydatne do wgrywania plików na Bosmana przez `PIP RDR:`.

```bash
# Intel HEX (bezpieczny dla PIP):
./fsrv send --hex comset/COMSET.COM
# Na Bosmanie: PIP A:COMSET.HEX=RDR:   potem: LOAD COMSET

# Surowy binarnie z EOF:
./fsrv send --eot plik.bin

# Z nadpisaniem prędkości:
./fsrv send --hex --baud 19200 plik.com
```

W trybie `--hex` plik jest kodowany do Intel HEX (rekordy po 16 B, org 0x0100),
po danych wysyłany jest `^Z` (0x1A) jako znacznik EOF dla `PIP RDR:`.
W trybie surowym `^Z` jest dodawane tylko z flagą `--eot`.

## Tryb --cold (zimny start FSRV)

Gdy na Bosmanie nie ma jeszcze `FSRV.COM`, klient może go wysłać jako Intel HEX
przez `RDR:`:

```bash
./fsrv --cold -p /dev/ttyS0
```

Program wypisze instrukcje, zaczeka na Enter, po czym wyśle `FSRV.COM` jako
Intel HEX + `^Z`. Po stronie CP/M:

```
PIP A:FSRV.HEX=RDR:
LOAD FSRV
FSRV
```

## Testy

```bash
python3 -m unittest tools.fsrv.test_fsrv_client
make -C tools/fsrv
```
