# Oprogramowanie komputera BOSMAN-8

## Wstęp

To repozytorium zawiera oprogramowanie dla **polskiego mikrokomputera BOSMAN-8**
(procesor Z80, system operacyjny CP/M 2.2), odzyskane z oryginalnych dyskietek
użytkownika z Gdyni.

**Łącznie: 878 plików, ~14 MB danych, 64 dyskietki (strony a i b).**

## Komputer BOSMAN-8

BOSMAN-8 był polskim mikrokomputerem z procesorem Z80, produkowanym w latach
80. XX wieku. Działał pod kontrolą systemu operacyjnego CP/M 2.2 — standardowego
systemu dla mikrokomputerów 8-bitowych tamtej ery.

## Kodowanie polskich znaków

System BOSMAN-8 używał **niestandardowego 7-bitowego kodowania** polskich znaków
diakrytycznych (NIE jest to standardowe Mazovia ani CP-852). Polskie litery były
zastępowane znakami interpunkcyjnymi ASCII:

| Bajt | Znak ASCII | Polski znak | Unicode  |
|------|-----------|-------------|----------|
| 0x40 | `@`       | ę (eogonek) | U+0119   |
| 0x5B | `[`       | ź (zacute)  | U+017A   |
| 0x5C | `\`       | Ł (Lstrok)  | U+0141   |
| 0x5D | `]`       | ń (nacute)  | U+0144   |
| 0x5E | `^`       | ś (sacute)  | U+015B   |
| 0x60 | `` ` ``   | ą (aogonek) | U+0105   |
| 0x7B | `{`       | ó (oacute)  | U+00F3   |
| 0x7C | `\|`      | ł (lstrok)  | U+0142   |
| 0x7D | `}`       | ż (zdot)    | U+017C   |
| 0x7E | `~`       | ć (cacute)  | U+0107   |

Dodatkowo część plików ma uszkodzony 8. bit (przypadkowo ustawiony), co wymaga
czyszczenia przed konwersją.

### Skrypt konwersji

W katalogu `bin/` znajduje się skrypt `convert-polish-chars.py`, który konwertuje
pliki z kodowania BOSMAN-8 do UTF-8.

```bash
# Konwersja pojedynczego pliku
python3 bin/convert-polish-chars.py -p dokument.txt

# Konwersja z zapisem do pliku .md
python3 bin/convert-polish-chars.py -p -s .md dokument.txt

# Konwersja całego katalogu
python3 bin/convert-polish-chars.py -p -o output_dir/ *.txt
```

## Kategorie oprogramowania

### [Turbo Pascal](turbo-pascal/)
Środowisko programistyczne Borland Turbo Pascal dla CP/M. Kompilator z wbudowanym
edytorem IDE. Znajduje się na 9 dyskietkach. Pliki: TURBO.COM (31 KB), TURBO.MSG,
TURBO.OVR. Dokumentacja: [turbo-pascal-opis.md](turbo-pascal/turbo-pascal-opis.md).

### [Algol-M](algol-m/)
Kompilator podzbioru języka ALGOL dla CP/M. Dwa programy: ALGOLM.COM (kompilator,
13.5 KB) i RUNALG.COM (interpreter, 14 KB). Pełna dokumentacja w języku polskim:
[algolm-podrecznik.md](algol-m/algolm-podrecznik.md) (25 KB),
[algolm-wprowadzenie.md](algol-m/algolm-wprowadzenie.md).

### [Kompilator C](c-compiler/)
Aztec C (Manx Software Systems) — pełny kompilator C dla CP/M/Z80. Dwóchprzebiegowy
(CC/C2), z kompletną biblioteką standardową (LIBC.REL, 57 KB), źródłami biblioteki
(ALLOC.C, STDIO.C i in.) oraz skryptami budowania. Znajduje się na 10 dyskietkach.

### [WordStar](word-star/)
Najpopularniejszy edytor tekstu dla CP/M. Używany przez użytkownika do pisania
dokumentów urzędowych, notatek akademickich i dokumentacji. Pełna instrukcja:
[wordstar-instrukcja.md](documents/wordstar-instrukcja.md) (124 KB!).

### [dBase II](dbase-ii/)
System zarządzania bazami danych — jeden z najważniejszych programów biznesowych
lat 80. Zawiera narzędzia generacji aplikacji (dGEN) i aplikacje użytkownika:
KONTAKTY (baza kontaktów), BARCLONA (Barcelona '92), MEDALE (tabela medalowa).

### [Multiplan](multiplan/)
Microsoft Multiplan — arkusz kalkulacyjny, prekursor Excela. Polska wersja
z przetłumaczonymi menu, komunikatami i pomocą. Kompletny zestaw: program
(PLAN.COM, 25 KB), 6 nakładek, pliki pomocy (MPHELP.FIL, 29 KB) i konfiguracja.
Opis: [multiplan-opis.md](documents/multiplan-opis.md) (40 KB).

### [LOGO](logo/)
Edukacyjny język programowania z grafiką żółwia. Aż **124 programy** .LOG
na 8 dyskietkach! Tematyka: fraktale (krzywe Hilberta, Peano, Wirtha),
optyka geometryczna, wykresy funkcji, fizyka (drgania, rzuty, tory ruchu),
wzory dekoracyjne. Do tego 12 obrazów .OBR (po 16 KB).

### [Forth](forth/)
Trzy wersje języka Forth: fig-Forth (FORTH.COM, 6.5 KB), Forth DOS (FORTHDOS.COM,
15 KB) i Forth EA (FORTHEA.COM, 10 KB).

### [BASIC](basic/)
Interpretery BASIC: Microsoft BASIC-80 (MBASIC.COM, 24 KB), S-BASIC (SBASIC.COM,
26 KB) i X-BASIC (XBASIC.COM, 19 KB). Oraz programy użytkownika: **BRIDGE.BAS**
(38 KB, pełna gra w brydża z AI, 1987), PAWEL.BAS (gra zręcznościowa).

### [Narzędzia asemblerowe](assembly-tools/)
Profesjonalne narzędzia Microsoft: M80 (asembler makro, 20 KB), L80 (linker,
11 KB), LIB80 (bibliotekarz, 5 KB), F80 (FORTRAN-80, 27 KB), CREF80,
RAZ80 (deasembler Z80 v3.0), REZILOG (analizator logiczny). Dokumentacja:
[m80-dokumentacja.md](documents/m80-dokumentacja.md),
[l80-dokumentacja.md](documents/l80-dokumentacja.md).

### [Gry](games/)
Kolekcja 19 gier: **SZACHY** (35 KB), **BLOCK** (Tetris, 42 KB), **SOKOBAN**,
**CATCHUM**, **HANOI** (Wieże Hanoi), **KRZYZE** (kółko i krzyżyk), **MASTER**
(Mastermind), **LADDER**, **PACZKI** (Pacman-like), **PIANINO1** (pianino),
**LIFE2** (Gra w życie), **TOTO** (totolotek), **CMACIERZ**/**MACIERZ**
(macierze), **LOSOWANI** (losowanie).

### [Edytor KOMPLET](komplet/)
Polski edytor tekstu dla CP/M — odpowiednik WordStara z polskim interfejsem.
Funkcje: makra, definiowalne klawiatury, obsługa cyrylicy (CYRYLICA.COM).
Dokumentacja: [komplet-opis.md](documents/komplet-opis.md),
[komplet-uzupelnienie.md](documents/komplet-uzupelnienie.md).

### [System KN](kn-system/)
Polski system kart katalogowych (Kartoteka Nabytków). Program KN.COM (11 KB)
z 4 plikami łańcuchowymi (.CHN, łącznie 116 KB). Służył do katalogowania
zbiorów z numerami inwentarzowymi NZO i PZO. Skrypt AUTOEXEC.SUB automatycznie
uruchamiał system po włożeniu dyskietki.

### [Programator EPROM](eprom-programmer/)
Najbardziej zaawansowany technicznie projekt użytkownika. Zestaw programów
w Pascalu i asemblerze Z80 do programowania pamięci EPROM przez port równoległy
(adres 098H, układ 8255 PPI). Zawiera też programy do projektowania filtrów
cyfrowych FIR (WFCN.PAS — obliczanie współczynników, okna raised cosine).

### [Narzędzia CP/M](cpm-utilities/)
Standardowe narzędzia systemowe: PIP (kopiowanie), ED (edytor), SID/ZSID
(debuggery), STAT (status), FORMAT, DUU (narzędzie dyskowe), SUBMIT/XSUB
(wsadowe), UNERASE (odzyskiwanie plików) oraz polskie narzędzia: KATALOG
i WYDRUK.

### [Programy użytkownika](user-programs/)
Najciekawsza część kolekcji — autorskie programy:

- **Mini-Prolog** — system ekspertowy w C (autor: Rafał Wojciechowski).
  Silnik wnioskowania z unifikacją, obsługa faktów i reguł, zapis/odczyt bazy.
- **Symulacja banku** — obiektowa symulacja kolejki w C++ (klasy: TBank,
  TKlient, TOkienko, TPortier).
- **Brydż** (BRIDGE.BAS, 38 KB) — pełna gra z AI: licytacja (Stayman, Gerber),
  rozgrywka, wist, punktacja turniejowa i robrowa.
- **Aplikacje dBase**: KONTAKTY (baza kontaktów), BARCLONA (Igrzyska Barcelona
  '92 — baza 53 KB!), MEDALE (tabela medalowa).

### [Dane giełdowe GPW](stock-market-data/)
Historyczne dane finansowe z GPW w Warszawie (początek lat 90.). Notowania
16 spółek: BIG, BRE, ELEKTRIM, EXBUD, KROSNO, OKOCIM, PROCHNIK, SWARZEDZ,
TONSIL, WEDEL, WOLCZANKA, ŻYWIEC i inne. Oraz indeks WIG i tabela zbiorcza.

### [Dokumenty użytkownika](documents/)
Dokumenty WordStar (.TWS) tworzone przez użytkownika:

- **Pisma urzędowe** — opinie o zezwoleniach na sprzedaż alkoholu (seria
  RMG*.TWS), plan budowy sieci telefonicznej w Gdyni (1992), informacja
  o sytuacji telekomunikacyjnej (1991)
- **Plan finansowy** — Komitetu Rodzicielskiego Przedszkola nr 44 w Gdyni
  na rok 1991/92
- **Skrypt metalograficzny** — notatki akademickie o badaniach metalograficznych
  (metalografia makro- i mikroskopowa, analiza przełomów, techniki trawienia)
- **Spis mienia** — dokument osobisty (MIENIE, 7 KB)

## Struktura katalogów

```
soft/
  README.md                  ← ten plik
  turbo-pascal/              ← TURBO.COM, TURBO.MSG, TURBO.OVR, dokumentacja
  algol-m/                   ← ALGOLM.COM, RUNALG.COM, podręcznik
  c-compiler/                ← Aztec C: kompilator, źródła, biblioteki, skrypty
  word-star/                 ← WS.COM, WSMSGS.OVR, WSOVLY1.OVR, WSPRINT.COM
  dbase-ii/                  ← DBASE.COM, narzędzia generacji
  multiplan/                 ← PLAN.COM, 6 nakładek, pomoc, tabele
  logo/                      ← LOGO.COM + 31 programów/fraktali + obrazy .OBR
  forth/                     ← FORTH.COM, FORTHDOS.COM, FORTHEA.COM
  basic/                     ← MBASIC, SBASIC, XBASIC, programy BASIC
  assembly-tools/            ← M80, L80, LIB80, F80, MAC, RAZ80, CREF80...
  games/                     ← 19 gier: szachy, tetris, sokoban, hanoi...
  komplet/                   ← KOMPLET.COM + nakładki + definicje klawiatur
  kn-system/                 ← KN.COM, łańcuchy .CHN, KNPAR.TXT, AUTOEXEC
  eprom-programmer/          ← PPROM, READPROM, WFCN, LADPCM + źródła
  cpm-utilities/             ← PIP, ED, SID, ZSID, STAT, FORMAT, SUBMIT...
  user-programs/             ← Mini-Prolog, symulacja banku, BRIDGE, KONTAKTY...
  stock-market-data/         ← Dane GPW: notowania 16 spółek, WIG
  documents/                 ← Dokumenty .TWS + skonwertowana dokumentacja
```

## Ciekawostki

1. **Największy plik tekstowy**: WORDSTAR.TXT — 124 584 bajty (122 KB po konwersji) —
   pełna instrukcja edytora WordStar w języku polskim.

2. **Największa baza danych**: BARCLONA.DBF — 52 736 bajtów (53 KB) — baza Igrzysk
   Olimpijskich Barcelona 1992, zawierająca dane o krajach, zawodnikach i medalach.

3. **C++ na CP/M!** — dyskietka disc-045-a zawiera programy w C++ (BANK.CPP,
   KLIENT.CPP, OKIENKO.CPP) — to rzadkość na systemach 8-bitowych.

4. **Polski Prolog** — system mini-Prolog napisany w C przez Rafała Wojciechowskiego
   to działający shell ekspertowy z polskojęzycznym interfejsem i pomocą.

5. **Brydż z AI** — BRIDGE.BAS (1987) implementuje pełną grę w brydża z licytacją
   (konwencje Stayman i Gerber), rozgrywką i punktacją — niezwykle ambitny program
   jak na BASIC w 64 KB pamięci.

6. **Dane giełdowe z lat 90.** — kolekcja zawiera historyczne notowania spółek
   z pierwszych lat istnienia GPW w Warszawie (po 1991 r.).

7. **Telefonizacja Gdyni** — w dokumentach znajduje się plan budowy lokalnej sieci
   telefonicznej dla Gdyni z 1992 roku, kiedy w Polsce był ogromny deficyt linii
   telefonicznych.

8. **Metalurgia** — obszerne notatki o badaniach metalograficznych wskazują,
   że użytkownik miał wykształcenie inżynierskie w dziedzinie metalurgii.

## Zobacz też

- [PLAN.md](../PLAN.md) — główny plan projektu
- [images/](../images/) — oryginalne pliki z dyskietek wraz z opisami (disc-*.md)
- [bin/convert-polish-chars.py](../bin/convert-polish-chars.py) — skrypt konwersji
  polskich znaków
- [list.txt](../list.txt) — pełna lista wszystkich 878 plików