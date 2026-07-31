Program PPROM (input,output);
{Program obslugi programatora PROM-TTL; odczytuje dane z pliku
tekstowegoPPROMD.TXN, zapisane w postaci heksadecymalnej;
format danych:AAAA    MM    SS<CR><LF>
 (adres slowa 4<SP> wart. slowa 4<SP> suma kontr)}
  label
    Linend, Prend;
  type
    HexStr = string[4];
  var
    Mbyte, Chbyt, Chsum : Byte;
    MeRd : Byte;
    Adr, I : Integer;
    Prdata : Text;
    LinPr : String[16];
    AdrSt, MemSt, ChkSt : HexStr;
    MeErr, FormErr, NumErr : Boolean;

{ deklaracje procedur w assemblerze : }
{ - deklaracja procedury inicjalizacji: }
procedure Prini;
   external $6000; { ?wartosc? - 'PRINI.COM' }
{ - deklaracja funkcji czytajacej slowo w pamieci: }
procedure Mprrd ;
   external $6100; { ?wartosc? - 'MPRRD.COM' }
{ - deklaracja procedury ustawiajacej slowo do program.}
procedure Mprsd ;
   external $6200; { ?wartosc? - 'MPRSD.COM' }
{ - procedura programowania slowa}
procedure Prbit ;
   external $6300; { ?wartosc? - 'PRBIT.COM' }

function Hex (Number : Integer; Bytes : Integer) : HexStr;
 { converts integer to string for number in hex form }
 const
     T : array[0..15] of Char =  '0123456789ABCDEF';
  var
     D : Integer;
     H : HexStr;
  begin
     H[0]:=Chr(Bytes+Bytes);
     for D:=Bytes+Bytes downto 1 do begin
       H[D]:=T[Number and 15];
       Number:=Number shr 4
     end;
     Hex:=H
  end; {of function Hex}

function NumHex(HexDig: HexStr): Integer;
  {converts string for number in Hex form to Integer}
  var
    Hd, Hl : Byte;
    I, Hn  : Integer;
    NumErr : Boolean;
  begin
    Hl:=ord(HexDig[0]);
    NumErr:=false;
    Hd:=0;
    Hn:=0;
    for I:=1 to Hl do begin
      Hd:=Ord(HexDig[I]);
      if (Hd>=$30) and (Hd<=$39) then Hd:=Hd-$30 else
        if (Hd>=$41) and (Hd<=$46) then Hd:=Hd-$37 else
          NumErr:=true;
      Hn:=Hn shl 4;
      Hn:=Hn+Hd
    end;
  if NumErr then Hn:=-1;
  NumHex:=Hn
  end;{of function NumHex}
begin{odczyt danych dla programatora z pliku PPROMD.TXN)}
{    -:- GLOWNA PETLA PROGRAMU -:-    }
  Assign ( PrData, 'PPROMD.TXN' );
  Reset (PrData);
  while not EOF(PrData) do begin
    AdrSt:=''; {wart poczatkowe}
    MemSt:='';
    ChkSt:='';
    FormErr:=false;
    MeErr:=false;
    NumErr:=false;
    Readln (PrData, LinPr );{wczytanie linii danych z pliku}
    if LinPr[1] = '@' then begin
      Prini; {poczatek - inicjalizacja programatora}
      goto linend;
    end;
    if Ord (LinPr[0]) <16 then FormErr := true;{blad formatu}

    AdrSt:= Copy (LinPr,1,4); {odczyt adresu}
    if Copy(LinPr,5,4) = '    ' then MemSt:= Copy(LinPr,9,2)
      else FormErr:= true; {odczyt slowa pamieci}
    if Copy(LinPr,11,4) = '    ' then ChkSt:= Copy(LinPr,15,2)
      else FormErr:= true; {odczyt sumy kontrolnej}
    Adr:= NumHex( AdrSt ); {konwersja na integer}
    Mbyte:= NumHex(MemSt);
    Chbyt:= NumHex(ChkSt);
    if (Adr<0) or (Mbyte<0) or (Chbyt<0) then FormErr:= true;
      { sprawdzenie sumy kontrolnej :}
    Chsum:= Hi( Adr ) + Lo( Adr ) + Mbyte;
    if Chsum <> Chbyt then FormErr := true; {blad}
   { sprawdzenie zawartosci pam. przed programowaniem }
    Inline ($2A/Adr);{ LD HL,Adr - dana dla MPRRD.com }
    Mprrd;
{ ->    MeRd:= Mprrd; ?odczyt bajtu z pamieci }
 inline ($16/$00);{->TEST}
    Inline ($7A/$32/MeRd); {LD A,D; LD MeRd,A}
    if MeRd <> 0 then MeErr := true; {blad ukladu PROM }
    if MeErr then begin
      writeln('Blad wykonania pamieci !!! ');
      writeln ( 'Adr: ', Hex(Adr,2),' - slowo: ', Hex(MeRd,1))
    end;
    if FormErr then begin
      writeln( 'Blad formatu danych w pliku PPROMD.TXN !!!')
    end;
    if MeErr or FormErr then Goto Prend; {blad => koniec}

{ zapis slowa do programowania: adres->HL, slowo->D }
{ LD HL,Adr; LD A,Mbyte; LD D,A }
    Inline ( $2A/Adr/$3A/Mbyte/$57 );
(*    Mprsd; {? ustawienie slowa do programowania }
    Prbit; { programowanie slowa }
{=>    MeRd:=Mprrd; ? odczyt slowa }
    Mprrd; *)
{=>  Inline ($55); ?TEST=>}
    Inline ($7A/$32/MeRd); {LD A,D; LD MeRd,A}
{  merd:=merd+1;TEST->}
    if MeRd <> Mbyte then begin
      MeErr:=true; {slowo zle zaprogram.}
      writeln (' Blad programowania pamieci !!!');
      writeln ( Hex (Adr,2), '    slowo: ', Hex (Mbyte,1),
       '   pamiec: ', Hex (MeRd,1));
    end {- bledu programowania -}
    else begin { OK }
      writeln ( 'Adres : ',Hex (Adr,2), '    Pamiec : ',
      Hex (MeRd,1), '   slowo OK !');
    end; {- OK -}
Linend: { miejsce skoku po bledzie }
  end; {--- koniec linii danych ---}
  writeln ( 'Koniec danych do programowania !');
 {------ koniec glownej petli programowania ------}
(*
  begin{test procedur}
    for I:=25500 to 25516 do
      writeln( I:2,'   ', Hex(I,2),'   ', NumHex(Hex(I,2)));
  end;*)
Prend: writeln (' KONIEC PROGRAMU ')
end.