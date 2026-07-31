# Kompilator C (Aztec/Manx C)

## Opis

Aztec C (Manx Software Systems) — kompilator języka C dla systemu CP/M z procesorem Z80.
Dwóchprzebiegowy: CC (CC1) — pierwszy przebieg, C2 (CC2) — drugi przebieg.
Współpracuje z asemblerem M80 i linkerem L80.

## Pliki

### Kompilator
- **CC.COM** / **CC1.COM** (37 KB) — pierwszy przebieg kompilatora
- **C2.COM** / **CC2.COM** (40 KB) — drugi przebieg kompilatora

### Biblioteki
- **LIBC.REL** (57 KB) — standardowa biblioteka C (duży model)
- **LIBCN.REL** (33 KB) — biblioteka C (model kompaktowy)
- **C2POST.REL**, **C2PRE.REL** — pliki pomocnicze kompilatora

### Źródła biblioteki standardowej (BDS C / SuperSoft)
- ALLOC.C, BCD80.C, CRUNT2.C, DOUBLE.C, FORMATIO.C, FUNC.C, LONG.C, STDIO.C
- STDIO.H, CUSTOMIZ.H

### Skrypty budowania (.SUB)
- CCC.SUB, CCN.SUB, CA.SUB, C.SUB, D.SUB, E.SUB, REL.SUB

## Dyskietki źródłowe

disc-014-a, disc-014-b, disc-018-a, disc-026-a, disc-026-b, disc-029-b, disc-032-a, disc-045-b, disc-046-a, disc-046-b
