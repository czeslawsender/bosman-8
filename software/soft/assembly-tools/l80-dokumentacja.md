                            Linker L80

Uruchomienie

>L80
*Rozkaz

lub

>L80 Rozkaz
*

Rozkazy:

<urz1:>(zbiórwynikowy1><, urz2:zbiórwynikowy2>,..

Przełączniki

R -  Ustawia loader w stanie początkowym. 

E:Nazwa
E  - Wyjście  z  linkera.  Przed  wyjściem linker  wyświetla  trzy 
     liczby: 
          adres startu programu,
          adres następnego dostępnego bajtu,
          numer używanej strony (256 bajtów).
     Forma E:nazwa używa nazwy jako adresu startu programu.  Nazwa 
     musi być etykietą globalną.

G:Nazwa
G -  rozpoczęcie wykonywania programu po zakończeniu interpretacji 
     bieżącego  rozkazu.  Przed  wyjściem  linker  wyświetla  trzy 
     liczby: 
          adres startu programu,
          adres następnego dostępnego bajtu,
          numer używanej strony (256 bajtów).
     i  tekst  BEGIN EXECUTION.  Forma G:nazwa  używa  nazwy  jako 
     adresu startu programu. Nazwa musi być etykietą globalną.

N -  Występuje  po  nazwie  zbioru i powoduje zapisanie  zbioru  z 
     rozszerzeniem .COM na wybranym urządzeniu. 

P:adres,nazwa
D:adres,nazwa
  -  Ustawienie  adresu  dla relokowalnych segmentów  kodu  (P)  i 
     danych  (D)  dla następnego ładowanego do  pamięci  programu. 
     Adresy podaje heksalnie. Można podawać również oktalnie, lecz 
     trzeba  użyć przełącznika O do zmiany podstawy  wprowadzanych 
     liczb.  Jeżeli  nie jest podawany przełącznik D,  to dane  są 
     umieszczane przez kodem programu.

U  - Wyświetlenie  adresu początku i końca obszaru programu i  da
     nych  oraz wyświetla wszystkie niezdefiniowane etykiety  glo
     balne.
     (Przełącznik wymaga dalszych wyjaśnień).

M  - Wyświetlenie  adresu początku i końca obszaru programu i  da
     nych oraz wyświetla wszystkie zdefiniowane etykiety  globalne 
     z  ich wartościami i etykiety niezdefiniowane z gwiazdką  za
     miast ich wartości.
     (Przełącznik wymaga dalszych wyjaśnień).

S -  Przypisuje  wartości niezdefiniowanych etykietom globalnym  w 
     zbiorze, po którym pojawia się przełącznik.

X -  Powoduje,  w  przypadku użycia przełącznika N,  }e zapisywany 
     zbiór  jest zapisywany w formacie INTEL ASCII HEX  i  posiada 
     rozszerzenie .HEX.

Y  - Powoduje  utworzenie obok zbioru .COM zbioru  o  rozszerzeniu 
     .SYM  zawierającego wszystkie etykiety globalne i ich wartoś
     ci. Zbiór ten jest wykorzystywany przez debagery symboliczne.


 