# Programator EPROM

## Opis

Zestaw programów do programowania pamięci EPROM przez port równoległy (adres 098H) w komputerze BOSMAN-8. Jeden z najbardziej zaawansowanych technicznie projektów użytkownika — łączy programy w Pascalu, asemblerze Z80 i obliczenia inżynierskie.

## Pliki

### Programy główne (Pascal)
- **PPROM.PAS** / **PPROM.COM** (5 KB / 10 KB) — programowanie pamięci PROM
- **PPROM1.PAS** / **PPROM1.COM** (7 KB / 11 KB) — rozszerzona wersja programatora
- **PPROM2.PAS** (7 KB) — wariant programatora
- **READPROM.PAS** / **READPROM.COM** (4 KB / 10 KB) — odczyt zawartości PROM

### Projektowanie filtrów cyfrowych (Pascal)
- **WFCN.PAS**, **WFCN0.PAS** — obliczanie współczynników filtru FIR (sin(x)/x, okno raised cosine)

### Procedury asemblerowe Z80
- **PPRAS.MAC**, **PPRAS1.MAC** — procedury programowania PROM (PRINI, PRBYT, MPRRD) przez port 098H (8255 PPI)
- **PRGAS.MAC** — dodatkowe procedury

### Narzędzia pomocnicze
- **LADPCM.COM** (17 KB) / **LADPCM.PAS** (8 KB) — pomocnicze narzędzie
- **TMNOZ.PAS** (664 B) — tabliczka mnożenia (program testowy)
- **TEST.PAS** (5 KB), **TEST1.PAS**, **TEST2.PAS**, **TESTX.PAS** — programy testowe

## Dyskietki źródłowe

disc-022-a, disc-022-b, disc-028-a, disc-033-a, disc-033-b, disc-047-a, disc-047-b
