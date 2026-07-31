Program WFCN (input, output);
{ Wspolczynniki filtru cyfrowego nadajnika }
{Program generuje zawartosc pamieci PROM-TTL;
, zawartosc zapisana w postaci heksadecymalnej;
format danych :
AAAA    MM    SS<CR><LF>
(adres slowa 4<SP> wart. slowa 4<SP> suma kontrolna)}

  type
    HexStr = string[4];
    VecFt =  array [0..31] of real;
    VecFi = array [0..31] of integer;
  var
    Zapis : text;
    MemCon : array [0..511, 1..2] of HexStr; {zaw.pamieci}
    FilQ : VecFi;
    FiCo : VecFt;
    Mbyte, Chsu1, Chsu2 : Byte;
    MeRd : Byte;
    Yq, Ap, Ak, Adr : Integer;
    WStr, AdSp, AdSk, ChSt1, ChSt2, AdrSt, MemSt : HexStr;
    Lbit, It : integer;
    yp :real;
    Tpr, Wpr, Ro, Xpr : real; { okres probk.; ..., wsp.strom.zbocza, wart.probki}
    Npr, Nmx, I, Swe, Xwe : integer; {numer probki, liczba wsp., zm.ster., sygn.wej. }

{1. obl. wartosci wspolczynnikow
 2. kwantowanie wspolczynnikow
 3. obliczenie wartosci dla sygn.wej.
 4. przedstawienie w postaci bin.->hex.
 5. rozdzial na pamieci
 6. zapis zawartosci pamieci do programowania}

function Quant ( Samp : real; var Lbit : integer ) : integer;
{ funkcja dokonuje kwantyzacji probki Samp ( <-1;1> )
  dla liczby bitow Lbit <= 14, wynik jako liczba calkowita
  - numer przedzialu kwantyzacji w zapisie Z/M }
  const
    Eps = 1e-5;
  var
    Iq : integer;
    Lev, Nlev : integer; {liczba i numer przedz.kwant. }
    Sx : real;
  begin
    Sx:= Samp;
    if Lbit > 14 then Lbit := 14 ;
    Lev:= 1;
    for Iq:= 1 to Lbit do Lev:= Lev + Lev; {l.prz.kwant.= 2 exp Lbit}
    if abs (Sx) >= 1 then Sx:= round (Sx)/abs ( round (Sx)) - Eps;
    Nlev:= trunc ( Sx * Lev );
    Quant:= Nlev;
  end; { of function Quant }

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

procedure WspFt ( Npr : integer; Ro, Tpr : real; var Ftr : VecFt );
{ Npr-liczba probek, Ro-wsp.stromosci, Tpr-znorm. okres probkow.,
  Ftr- wektor wsp. filtru }
  label
    Wend;
  const
    Epw = 1e-6;
  var
    Wpr, Apr, Xpr : real;
    Iw, Nw : integer;

  begin
    if odd ( Npr ) then Nw:= trunc( 0.5 * Npr )
      else Nw:= trunc ( 0.5 * (Npr - 1 ) );
    for Iw:= -Nw to Nw do begin { kolejne wspolczynniki filtru cyfrowego}
      Wpr:= Iw * Tpr * pi;
      Apr:= Iw * Tpr * Ro;
      if abs ( abs (Apr) - 0.5 ) < Epw then
        Xpr:= 0.25 * pi * ( sin (Wpr) / Wpr )
      else begin
        Xpr:= 1.0;
        if abs ( Wpr ) > Epw then
          Xpr:= ( sin (Wpr)/Wpr ) * cos (pi*Apr) / (1-4*Apr*Apr);
      end;
      Ftr [ Iw+Nw+1 ]:= Xpr;
    end; { Iw - koniec obliczania wspolczynnika }
  end; { WspFt }

function MaxPr ( WekWs : VecFi; Nm : integer ) : integer;
{ funkcja oblicza maksymalna wart.probki dla wekt.wsp.filtru WekWS }
  var
    Mxp, Im : integer;
  begin
    Mxp:= 0;
    for Im:= 1 to Nm do Mxp:= Mxp + abs ( WekWs[Im] );
    MaxPr:= Mxp
  end; { of MaxPr }

begin { program glowny }
  assign ( Zapis,'PPROMD.TWN' );
  rewrite ( zapis );
{ wpis danych dla filtru }
  writeln ('podaj wartosci:');
  writeln (' Nmx = ? ;ro = ? ;Tpr = ? ;Lbit = ?');
  readln ( Nmx, Ro, Tpr, Lbit );
  writeln (' Nmx = ',Nmx:2,'  ;ro = ',ro:6:4,'  ;Tpr = ',
  Tpr:6:4,'  ;Lbit = ',Lbit:2);
  WspFt ( Nmx, ro, Tpr, FiCo );
  Ak:= 0;
  for I:= 1 to 7 do begin { wart.sygn.we. }
    Ak:= Ak + 32;
    WRITELN ( Zapis,' Nmx = ',Nmx:2,'  ;ro = ',ro:6:4,'  ;Tpr = ',
        Tpr:6:4,'  ;Lbit = ',Lbit:2,'  ;Swe = ',I:1);
    for It:= 1 to Nmx do begin { numery wsp.filtru }
      yp:= FiCo[It];
      FilQ[It]:= Quant ( yp, Lbit );
      Yq:= FilQ[It];
      Swe:= I * Yq; { probka we * wsp.filtru }
      Xwe:= abs ( Swe );
      if Swe < 0 then Xwe:= Xwe or (-1-MaxInt);
      WStr:= Hex ( Xwe, 2 );
      Adr:= It + Ak;
      AdrSt:= Hex ( Adr, 2 );
      Chsu1:= Hi ( Adr ) + Lo ( Adr ) + Hi ( Xwe );
      Chsu2:= Hi ( Adr ) + Lo ( Adr ) + Lo ( Xwe );
      ChSt1:= Hex ( Chsu1, 1);
      ChSt2:= Hex ( Chsu2, 1);
      writeln (Adr :3,Swe :8, Xwe :9,'      ',AdrSt,'    ',
        Wstr[1],Wstr[2],'    ',ChSt1,'      ',AdrSt,'    ',
        Wstr[3],Wstr[4],'    ',ChSt2);
      WRITELN (Zapis, Adr :3,Swe :8, Xwe :9,'      ',AdrSt,'    ',
        Wstr[1],Wstr[2],'    ',ChSt1,'      ',AdrSt,'    ',
        Wstr[3],Wstr[4],'    ',ChSt2);
    end; { 1 to Nmx = wspolczynniki }
  end; { 1 to 7 = wart.sygn.wej. }
  close ( Zapis );
  Yq:= MaxPr (FilQ, 29);
  writeln ( 'MaxPr = ', Yq :5 )
end.