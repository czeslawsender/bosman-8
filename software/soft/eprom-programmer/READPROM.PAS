Program READPROM (input,output);
{Program odczytu zawartosci pamieci PROM-TTL;
, zawartosc zapisana w postaci heksadecymalnej;
format danych :
AAAA    MM    SS<CR><LF>
(adres slowa 4<SP> wart. slowa 4<SP> suma kontrolna)}
  type
    HexStr = string[4];
  var
    Mbyte, Chsum : Byte;
    MeRd : Byte;
    Ap, Ak, Adr : Integer;
    AdSp, AdSk, ChStr, AdrSt, MemSt : HexStr;

procedure AsOut ( Bout : Byte );
{ Byte to paralell port (098H) }
  begin
    inline ( $E5/$F5/$C5/$D5/           {rejestry na stos}
      $3A/Bout/$D3/$98/$DB/$98/         {Bout->port rown>}
      $17/$30/$FB/$D1/$C1/$F1/$E1 )     {test BUSY;odtw>rej.}
  end; {procedury AsOut}

procedure AsInp ( var Binp : Byte );
{ Byte from paralell port (098H) }
  var
    Bx : bYTE;
  begin
    inline ( $E5/$F5/$C5/$D5/  {rejestry na stos}
      $DB/$98/$32/Bx/        {port rown.->Binp}
      $D1/$C1/$F1/$E1 );        {odtw.rejestrow}
    Binp:= Bx;
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
    Bout, Binp, Breg, ByDat : Byte;
    Nb : integer;
  begin
    AsOut ( 0 );
    AsOut ( $03 );
    AsOut ( Lo ( Wadr) ); {do portu B}
    AsOut ( 0 );
    Breg:= Hi ( Wadr ) and $07 or $88;
    Bout:= 0;
    for Nb:= 7 downto 0 do begin
      AsOut ( 0 );
      AsOut ( $05 );
      ByDat:= Nb shl 4 or Breg;
      AsOut ( ByDat );  {nowy nr bitu do portu C}
      AsInp ( Binp );
      Binp:= Binp and $10; {maska - odczyt b4}
      Bout:= Bout shl 1;
      if Binp = 0 then Bout:= Bout + 1;
    end; { Nb }
    Mprrd:= Bout;
  end; {funkcji Mprrd}

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

begin
  repeat
    writeln ( 'adres poczatkowy ( HEX! ) : ' );
    readln ( Con, AdSp );
    writeln ( 'adres koncowy ( HEX! ) : ');
    readln ( Con, AdSk );
    Ap:= NumHex ( AdSp );
    Ak:= NumHex ( AdSk );
    writeln ( 'Ap = ', Ap, '      Ak = ', Ak );
    writeln;
  until (Ap>=0) and (Ak>=0) and (Ap<=Ak);
  prini;
  writeln ( '- ODCZYT ZAWARTOSCI PAMIECI ( HEX ) -' );
  for Adr:= Ap to Ak do begin
{    -:- GLOWNA PETLA PROGRAMU -:-    }
{ odczyt zawartosci pamieci PROM  }
    MeRd:= Mprrd ( Adr ); {odczyt bajtu z pamieci}
    writeln ( 'Adres :  ',Hex (Adr,2), '      Pamiec :  ',
      Hex (MeRd,1));
  end; {linii danych}
{------ koniec glownej petli programowania ------}
  writeln (' KONIEC PROGRAMU ')
end.