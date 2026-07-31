PROGRAM FSRV;
{
  CP/M File Server dla Bosman-8  v1.1  (Turbo Pascal 2.0)
  Protokol binarny, lacze szeregowe przez BIOS PUNCH/READER (SIO-B).

  Kompilacja: uruchom TP i skompiluj do FSRV2.COM
}
{$I-}

TYPE
  Sector = ARRAY [0..127] OF BYTE;

VAR
  Running  : BOOLEAN;
  Filename : STRING [12];
  WorkFCB  : ARRAY [0..35] OF BYTE;
  DMABuf   : Sector;

{ ------------------------------------------------------------------ }
{ BIOS PUNCH  = wpis nr 6 w tablicy wektorow (offset 18)             }
{ BIOS READER = wpis nr 7 w tablicy wektorow (offset 21)             }
{ BIOS CONST  = wpis nr 2 (offset  6)                                }
{ BIOS CONIN  = wpis nr 3 (offset  9)                                }
{ ------------------------------------------------------------------ }

FUNCTION SerIn : BYTE;
BEGIN
  SerIn := LO(BIOS(7, 0))
END;

PROCEDURE SerOut(B : BYTE);
BEGIN
  BIOS(6, B)
END;

FUNCTION ConStat : BOOLEAN;
BEGIN
  ConStat := BIOS(2, 0) <> 0
END;

FUNCTION ConIn : CHAR;
BEGIN
  ConIn := CHR(LO(BIOS(3, 0)))
END;

{ ------------------------------------------------------------------ }
{ Odbierz nazwe pliku (null-terminated) ze lacza                     }
{ ------------------------------------------------------------------ }

PROCEDURE RecvFilename;
VAR B : BYTE;
BEGIN
  Filename := '';
  REPEAT
    B := SerIn;
    IF (B <> 0) AND (LENGTH(Filename) < 12) THEN
      Filename := Filename + CHR(B)
  UNTIL B = 0;
  WRITE(Filename)
END;

{ ------------------------------------------------------------------ }
{ Zbuduj WorkFCB z Filename (format NAZWA.EXT)                       }
{ ------------------------------------------------------------------ }

PROCEDURE BuildFCB;
VAR I, J : INTEGER;
BEGIN
  FILLCHAR(WorkFCB, 36, 0);
  FOR I := 1 TO 11 DO WorkFCB[I] := ORD(' ');

  { nazwa — max 8 znakow do kropki lub konca }
  J := 1; I := 1;
  WHILE (I <= LENGTH(Filename)) AND (Filename[I] <> '.') AND (J <= 8) DO BEGIN
    WorkFCB[J] := ORD(Filename[I]); INC(I); INC(J)
  END;

  { przeskocz nadmiarowe znaki nazwy }
  WHILE (I <= LENGTH(Filename)) AND (Filename[I] <> '.') DO INC(I);

  { rozszerzenie — max 3 znaki }
  IF (I <= LENGTH(Filename)) AND (Filename[I] = '.') THEN BEGIN
    INC(I); J := 9;
    WHILE (I <= LENGTH(Filename)) AND (J <= 11) DO BEGIN
      WorkFCB[J] := ORD(Filename[I]); INC(I); INC(J)
    END
  END
END;

{ ------------------------------------------------------------------ }
{ GET — wyslij plik do klienta                                       }
{ ------------------------------------------------------------------ }

PROCEDURE CmdGet;
VAR
  F    : FILE OF Sector;
  Buf  : Sector;
  Nrec : INTEGER;
  Crc  : BYTE;
  I, J : INTEGER;
BEGIN
  WRITE('GET: '); RecvFilename; BuildFCB;
  ASSIGN(F, Filename); RESET(F);
  IF IORESULT <> 0 THEN BEGIN
    SerOut(ORD('E')); WRITELN(' BLAD')
  END ELSE BEGIN
    Nrec := FILESIZE(F);
    SerOut(ORD('K')); SerOut(LO(Nrec)); SerOut(HI(Nrec));
    Crc := 0;
    FOR I := 1 TO Nrec DO BEGIN
      READ(F, Buf);
      FOR J := 0 TO 127 DO BEGIN
        Crc := Crc XOR Buf[J]; SerOut(Buf[J])
      END
    END;
    SerOut(Crc); CLOSE(F); WRITELN(' OK')
  END
END;

{ ------------------------------------------------------------------ }
{ PUT — odbierz plik od klienta                                      }
{ ------------------------------------------------------------------ }

PROCEDURE CmdPut;
VAR
  F      : FILE OF Sector;
  Buf    : Sector;
  Nrec   : INTEGER;
  Lo, Hi : BYTE;
  Crc    : BYTE;
  RxCrc  : BYTE;
  I, J   : INTEGER;
  WOk    : BOOLEAN;
BEGIN
  WRITE('PUT: '); RecvFilename;
  Lo := SerIn; Hi := SerIn;
  Nrec := INTEGER(Lo) + INTEGER(Hi) * 256;
  BuildFCB;
  ASSIGN(F, Filename); REWRITE(F);
  IF IORESULT <> 0 THEN BEGIN
    { odczytaj i odrzuc dane, zeby odebrac caly pakiet przed odpowiedzia }
    I := Nrec;
    WHILE I > 0 DO BEGIN
      FOR J := 0 TO 127 DO Lo := SerIn; DEC(I)
    END;
    Lo := SerIn; { CRC }
    SerOut(ORD('E')); WRITELN(' BLAD TWORZENIA')
  END ELSE BEGIN
    Crc := 0; WOk := TRUE;
    FOR I := 1 TO Nrec DO BEGIN
      FOR J := 0 TO 127 DO BEGIN
        Buf[J] := SerIn; Crc := Crc XOR Buf[J]
      END;
      IF WOk THEN BEGIN
        WRITE(F, Buf);
        IF IORESULT <> 0 THEN WOk := FALSE
      END
    END;
    RxCrc := SerIn; CLOSE(F);
    IF WOk AND (Crc = RxCrc) THEN BEGIN
      SerOut(ORD('K')); WRITELN(' OK')
    END ELSE BEGIN
      BDOS(19, ADDR(WorkFCB)); { usun bledny plik }
      SerOut(ORD('E'));
      IF NOT WOk THEN WRITELN(' BLAD ZAPISU')
      ELSE WRITELN(' BLAD CRC')
    END
  END
END;

{ ------------------------------------------------------------------ }
{ DIR — wyslij liste katalogu                                        }
{ ------------------------------------------------------------------ }

PROCEDURE CmdDir;
VAR
  Slot, I, Base : INTEGER;
BEGIN
  WRITELN('DIR');
  FILLCHAR(WorkFCB, 36, 0);
  FOR I := 1 TO 11 DO WorkFCB[I] := ORD('?');

  BDOS(26, ADDR(DMABuf));
  Slot := BDOS(17, ADDR(WorkFCB)) AND $FF;

  WHILE Slot <> $FF DO BEGIN
    Base := Slot * 32 + 1; { poczatek wpisu w buforze DMA }
    FOR I := 0 TO 10 DO
      SerOut(DMABuf[Base + I] AND $7F); { zeruj bit atrybutu }
    BDOS(26, ADDR(DMABuf)); { przywroc DMA przed SNXT }
    Slot := BDOS(18, ADDR(WorkFCB)) AND $FF
  END;

  SerOut(0); { znacznik konca listy }
  WRITELN(' OK')
END;

{ ------------------------------------------------------------------ }
{ Glowna petla serwera                                               }
{ ------------------------------------------------------------------ }

BEGIN
  WRITELN('CP/M File Server v1.1  [TP2]');
  WRITELN('Lokalnie: Q = wyjscie');

  Running := TRUE;
  WHILE Running DO BEGIN
    WRITELN; WRITELN('< czekam >');

    { sprawdz klawiature bez blokowania }
    IF ConStat THEN
      IF UPCASE(ConIn) = 'Q' THEN Running := FALSE;

    { czekaj na komende przez lacze (blokujace) }
    IF Running THEN
      CASE CHR(SerIn) OF
        'G' : CmdGet;
        'P' : CmdPut;
        'D' : CmdDir;
        'Q' : BEGIN
                SerOut(ORD('K')); WRITELN('Koniec pracy serwera.');
                Running := FALSE
              END
      ELSE
        SerOut(ORD('E'))
      END { CASE }
  END { WHILE }
END.
