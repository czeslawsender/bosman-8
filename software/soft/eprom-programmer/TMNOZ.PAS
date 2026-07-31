program Tabliczka (input, output);
{ trening tabliczki mnozenia }

var
  M1,M2,Wynik,Odp,Zakr,Limit: integer;
begin
  Zakr:= 50; {zakres wynikow}
  Limit:=8;
  repeat
  begin
    M1:=2+Random(Limit);{mnozna 2..9}
    Limit:= (Zakr div M1);
    if limit > 8 then Limit:=8;
    M2:= 2+Random(Limit-1);
    Wynik:= M1*M2;
    ClrScr;
    Writeln(M1:2,' * ',M2:2,' = ?');
    repeat
     begin
       Read(Odp);
       DelLine;
       GotoXY(1,3);
       Write(M1:2,' * ',M2:2,' = ')
       end;
    until
      Wynik=Odp;
    Writeln(Odp:2);
    Writeln('B A R D Z O   D O B R Z E  !',char(7));
    Delay(3000);
end;
  until M1=0

end.