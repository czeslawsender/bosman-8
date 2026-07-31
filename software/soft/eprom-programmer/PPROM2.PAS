Program PPROM (input,output);
{Program obslugi programatora PROM-TTL; odczytuje dane z pliku
tekstowego 'PPROMD.TXN', zapisane w postaci heksadecymalnej;
format danych :
AAAA    MM    SS<CR><LF>
(adres slowa 4<SP> wart. slowa 4<SP> suma kontrolna)}
  label
    Linend, Prend;
  type
    HexStr = string[4];
  var
    Mbyte, Chbyt, Chsum : Byte;
    MeRd : Byte;
    MMask, OutN, Adr, I : Integer;
    Prdata : Text;
    LinPr : String[16];
    AdrSt, MemSt, ChkSt : HexStr;
    MeErr, FormErr, NumErr : Boolean;
    Lpp : File of Char;
    Jp, BMask : Byte;

procedure AsOut ( Bout : Byte );
{ Byte to paralell port (098H) }
  begin
    inline ( $F5/$3A/Bout/$D3/$98/   {Bout->port rown>}
      $DB/$98/$17/$30/$FB/$F1 )      {test BUSY;odtw>rej.}
  end; {procedury AsOut}

procedure AsInp ( var Binp : Byte );
{ Byte from paralell port (098H) }
  var
    Bx : Byte;
  begin
    inline ( $F5/$DB/$98/$32/Bx/$F1 ); {port rown.->Binp}
    Binp:= Bx ;
  end; {procedury AsInp}

procedure Prini ;
 { inicjalizacja programatora }
 begin
   AsOut ( 0 );
   AsOut ( $07 );
   AsOut ( $80 );    { 080H do rej. sterujacego}
   AsOut ( 0 );
   AsOut ( $01 );
   AsOut ( 0 );      {  0 do portu A }
   AsOut ( 0 );
   AsOut ( $03 );
   AsOut ( 0 );      {  0 do portu B }
   AsOut ( 0 );
   AsOut ( $05 );
   AsOut ( $88 );    { 088H do portu C }
   Writeln ( 'INICJALIZACJA PROGRAMATORA' )
 end; { of Prini }

function Mprrd ( Wadr : integer ) : Byte;
{ odczytuje slowo pamieci o adresie = Wadr }
  var
    Bout, Breg, ByDat : Byte;
    Nb : integer;
  begin
    AsOut ( 0 );
    AsOut ( $03 );
    AsOut ( Lo ( Wadr) ); {do portu B}
    AsOut ( 0 );
    Breg:= ( Hi ( Wadr ) and $07) or $88;
    Bout:= 0;
    for Nb:= 7 downto 0 do begin
      AsOut ( 0 );
      AsOut ( $05 );
      ByDat:= ( Nb shl 4 ) or Breg;
      AsOut ( ByDat );  {nowy nr bitu do portu C}
      delay ( 10 );
      AsInp ( ByDat );
      ByDat:= ByDat and $10; {maska - odczyt b4}
      Bout:= Bout shl 1;
      if ByDat = 0 then Bout:= Bout + 1;
    end; { Nb }
    Mprrd:= Bout;
  end; {funkcji Mprrd}

procedure PrBit ( PrAdr : integer; NrBit : Byte);
{procedura programowania bitu NrBit pamieci: "1" => (PrAdr) }
  var
    Nb : Byte;
    ByDat, Breg : Byte;
  begin
    AsOut ( 0 );
    AsOut ( $03 );
    AsOut ( Lo ( PrAdr) ); {do portu B}
    AsOut ( 0 );
    AsOut ( $05 );
    Breg:= (Hi ( PrAdr ) and $07) or $88; {10001aaa}
    AsOut ( Breg );  {do portu C}
    Nb:= NrBit;
      AsOut ( 0 );
      AsOut ( $05 );
      ByDat:= ( Nb shl 4 ) or Breg;
      AsOut ( ByDat );  {nowy nr bitu do portu C}
      AsOut ( 0 );
      AsOut ( $07 );
      AsOut ( $06 );  {do rej. ster.}
      AsOut ( 0 );
      AsOut ( $07 );
      AsOut ( $0E );  {do rej.ster.}
      AsOut ( 0 );
      AsOut ( $07 );
      AsOut ( $0F );  {do rej.ster.=> impuls na c7}
      delay ( 10 );
      Inline ( $F5/$DB/$98/$17/$30/$FB/$F1 ); {petla oczek. na BUSY=0}
      AsOut ( 0 );
      AsOut ( $07 );
      AsOut ( $07 );  {do rej.ster.}
      delay ( 40 );
      write ( '*' );
end; {procedury PrBit}

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
     end; { D }
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
    end; { I }
  if NumErr then Hn:=-1;
  NumHex:=Hn
  end;{of function NumHex}

begin{odczyt danych dla programatora z pliku PPROMD.TXN)}
{    -:- GLOWNA PETLA PROGRAMU -:-    }
  Assign ( PrData, 'PPROMD.TXN' );
  Reset (PrData);
  LowVideo;
  writeln ( ' PROGRAMOWANIE PROM 82S114' );
  NormVideo;
  write ( ' Podaj numer programowanego wyjscia:' );
  readln ( OutN );
  writeln ( 'DOLACZ NAPIECIE PROGRAMUJACE DO WYJSCIA o',OutN );
  writeln ( 'Nacisnij jakis klawisz' );
  repeat until KeyPressed;
  while not EOF(PrData) do begin {kolejne linie}
    AdrSt:=''; {wart poczatkowe}
    MemSt:='';
    ChkSt:='';
    FormErr:=false;
    MeErr:=false;
    NumErr:=false;
    Readln (PrData, LinPr );{wczytanie linii danych z pliku}
    if LinPr[1] = '@' then begin {inicjalizacja programatora}
      Prini;
      writeln (' => WYLACZ BLOKADE  i  NACISNIJ KLAWISZ   ! ');
      repeat until KeyPressed;
      goto linend; {przejscie do nowej linii}
    end; {inicjalizacji}
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
    MeRd:= Mprrd ( Adr ); {odczyt bajtu z pamieci}
    MMask:= 1;
    for I:= 1 to OutN do MMask:= MMask + MMask;
    MMask:= MMask shr 1;
    BMask:= Lo ( MMask );
    if (MMask and MeRd and not Mbyte) >0 then MeErr := true; {blad ukladu PROM }
    if MeErr then begin
      writeln('Nie mozna wpisac bitu o', OutN);
      writeln ( 'Adr: ', Hex(Adr,2),'  - slowo: ', Hex(Mbyte,1),
         '   w pamieci: ',Hex(MeRd,1))
    end; { MeErr }
    if FormErr then begin
      writeln ('Blad formatu danych w pliku PPROMD.TXN !!!')
    end;
    if MeErr or FormErr then Goto Prend; {blad => koniec}

{ zapis slowa do programowania: }
    Mbyte:= Mbyte and MMask; { program.gdy bit=1 }
    if Mbyte > 0 then PrBit ( Adr, OutN ) else write (' ');
    MeRd:=Mprrd ( Adr );  { odczyt slowa }
    if ( MeRd and MMask ) <> Mbyte then begin
      MeErr:=true; {bit zle zaprogram.}
      writeln (' Blad programowania bitu o',OutN, ' pamieci !!!');
      writeln ( Hex (Adr,2), '    slowo: ', Hex (Mbyte,1),
       '   pamiec: ', Hex (MeRd,1));
    end {- bledu programowania -}
    else begin { OK }
      writeln ( 'Adres : ',Hex (Adr,2), '    Pamiec : ',
      Hex (MeRd,1), '   bit o',OutN,'  OK !');
    end; {- OK -}
    Delay ( 250 );  {opoznienie nowego slowa}
Linend: { miejsce skoku po bledzie }
  end; {--- koniec linii danych ---}
  writeln ( 'Koniec danych do programowania !');
{------ koniec glownej petli programowania ------}
Prend: writeln (' KONIEC PROGRAMOWANIA BITU o', OutN );
  writeln ( ' => WLACZ BLOKADE !!!' )
end.