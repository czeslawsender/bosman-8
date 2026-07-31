

          UZUPELNIENIE DO OPISU EDYTORA K O M P L E T          1989.07.12
          -------------------------------------------          ----------

1.1 Polecenie WI: (znak : zamiast nazwy nakladki) powoduje usuniecie z pamieci
    aktualnie rezydujacej nakladki. ( str. 120 podrecznika )

1.2 Szukanie  tekstu  przez  polecenia  F  i  S ( str. 100 i 103 podrecznika )
    moóe byc przerwane przez nacisniecie klawisza ESC.

1.3 Polecenie F wywolane z liczba > 256 ( np. 300Fxył ) umoóliwia odnalezienie
    podanego  tekstu  w dlugim zbiorze, nie mieszczacym sie w pamieci edytora.
    Tekst  szukany  jest  najpierw  w  pamieci  edytora.  Jeóeli  nie zostanie
    znaleziony,  to  zawartosc  pamieci  bedzie  zapisana na pliku wyjsciowym,
    edytor  wczyta  nowa  porcje  tekstu  z pliku wejsciowego. Szukanie bedzie
    kontynuowane do skutku, lub do konca pliku wejsciowego.

1.4 Polecenie  nWB  (strona  111 podrecznika ) rozbudowane zostalo o moóliwosc
    podania ilosci kolumn dla linii wyswietlanych na ekranie w trybie binarnym.
    Moóna  podac  ilosc  2-80. Podanie innej ilosci zostanie przyjete jako 80.

1.5 Nowe polecenie nNPO pozwala ustawic numer kolumny tekstu, od ktorej bedzie
    wyswietlany  kadr.  Numer bedzie zaokraglany do wartosci podzielnych przez
    16.  Polecenie  to  jest przeznaczone do wykorzystania w makropoleceniach.

1.6 Wystapienie  w  tekscie  linii  rozpoczynajacej  sie od znaku 1E (linia ta
    zawiera  parametry  druku),  spowoduje  podczas drukowania wyslanie  znaku
    nowej  strony  do drukarki.

1.7 Znaki  przelaczajace  rodzaj  pisma zmienily dzialanie. Ustawienie rodzaju
    pisma   "elite"  (^KśR)  kasuje  rodzaj pisma "pica" (^KśS)  i  odwrotnie.
    Jednoczesnie  kasowane sa atrybuty proporcjonalnosci i zageszczenia pisma.
    Natomiast  ustawienie  pisma  zageszczonego  (^KśT) i/lub proporcjonalnego
    (^KśU)   powoduje   w  koncowym efekcie zsumowanie atrybutow. Moóliwe jest
    ustawienie jednego z nastepujacych rodzajow pisma:
      - pica
      - pica/zageszczony
      - pica/proporcjonalny
      - pica/zageszczony/proporcjonalny.
      - elite
      - elite/zageszczony
      - elite/proporcjonalny
      - elite/zageszczony/proporcjonalny
    Uwaga!  Niektore  rodzaje  pisma nie dzialaja w poszczegolnych drukarkach.

1.8 W  poleceniu  "^K  ^Ł  n" znak "n" oznacza powiekszony o 20H odstep miedzy
    znakami  liczony w punktach, ktorych wielkosc wyznacza aktualnie ustawiony
    kroj  pisma  (dla  kroju  "elite"  szerokosc  punktu rowna sie 1/72 cala).

2.0 Uwagi dotyczaca nakladki SH.EDT

    - Zmienil sie wyglad ekranu w poleceniu TP. Jest to konsekwencja sumowania
      atrybutow przy ustawianiu rodzaju pisma.
    - Drukarka  SEIKOSHA  1000 nie przyjmuje pisma elite/zageszczony. Pismo to
      dziala na drukarce SEIKOSHA 1200.
    - Wlaczenie  opcji "graficzne ))))" spowoduje wydrukowanie calego tekstu w
      sposob   graficzny;   powoduje  to  przyspieszenie  drukowania  tekstow,
      w ktorych wystepuje mieszaniana znakow dostepnych w repertuarze drukarki
      ze znakami, ktore musza byc drukowane w sposob graficzny.

3.0 Uwagi dotyczace nakladki D100.EDT
3.1 Znaki sterujace
    
    - Pomijany  jest  znak  o  kodzie  18  (polecenie  ^KśX), ktory mial byc w
      nakladce D100.EDT wlacznikiem pisma o podwojnej wysokosci.
    - Dodatkowo interpretowane sa znaki o kodach:
        05 (polecenie ^KśE) - druk z podkresleniem
        
        19 (polecenie ^KśY) - zmiana gestosci wierszy.
                              Za  znakiem  o  kodzie  19  naleóy  wpisac znak,
                              okreslajacy  gestosc  wierszy, o kodzie:
                              27 (')  dla 10   wierszy/cal
                              2C (,)  dla  6   wierszy/cal
                              2E (.)  dla  5   wierszy/cal
                              35 (5)  dla  3.3 wierszy/cal.
      W  celu  dopisania  znaku  o  kodzie  np.  27  moóna  teó uóyc polecenia
      CTRL-K27.

3.2 Drukowanie tekstow, wykorzystujacych dodatkowe alfabety znakow, wykonywane
    jest w sposob graficzny.

    - proste  rysunki  (wykonane  makroprogramem   RYSUJ), wskazane drukowanie
      z gestoscia 10 wierszy/cal.
    - cyrylica, wskazane drukowanie z gestoscia 5 wierszy/cal.
    
3.3 Drukowanie tekstow z gestoscia 6 wierszy/cal
    
    - drukowanie w/g podstawowego alfabetu
      1. znaki: C S [ Z beda obnióone.
      2. pomijany jest znak ustawiajacy podkreslenie.

    - drukowanie w/g dodatkowego alfabetu - cyrylicy
      1. nie beda drukowane dolne czesci znakow.
      2. pomijany jest znak ustawiajacy podkreslenie.

3.4 Drukarka  D-100  nie  drukuje  rodzaju  pisma  elite ani proporcjonalnego.

4.  Opracowano  nakladke  dla  drukarki  NX-15 firmy STAR o nazwie NX-15.EDT .
    Ponióej przedstawiono kilka uwag dotyczacych tej nakladki.

    - Zalecane ustawienie przelacznikow rodzaju pracy:
    
               
         ON
?

?



?

  
    
 



 
ON
        OFF
?
 
?
 
 
 
?
 
  
    

 
 
 

OFF
           
1
2
3
4
5
6
7
8
  
    
1
2
3
4
5

           								    				


    - Generator  polskich znakow diakrytycznych jest kaódorazowo przesylany do
      drukarki po zainicjowaniu procesu drukowania.

    - W trybie NLQ dostepny jest tylko jeden rodzaj pisma - "pica", nie dziala
      rownieó  ustawianie  rodzaju  druku  "pogrubiony  w  poziomie"   (^KśB).
      Polecenie  ^KśB nie dziala rownieó przy ustawieniu rodzaju druku "elite"
      lub druku zageszczonego w trybie DRAFT.
      Ograniczenia te narzuca sama drukarka.

    - Gestosc druku jest inicjalnie ustawiona na 12 punktow/wiersz; dopasowana
      ona jest do wielkosci znakow tabelkowych, znajdujacych sie w generatorze
      znakow  drukarki. Przy wydruku rysunkow utworzonych za pomoca makropole-
      cenia  "RYSUJ"  wskazane  jest  ustawienie  gestosci 10 punktow/wiersz i
      wlaczenie opcji  " graf ))))" - graficznego drukowania znakow tabelko-
      wych.

    - Wlaczenie  opcji "graficzne ))))" spowoduje wydrukowanie calego tekstu w
      sposob   graficzny;   powoduje  to  przyspieszenie  drukowania  tekstow,
      w ktorych wystepuje mieszaniana znakow dostepnych w repertuarze drukarki
      ze znakami, ktore musza byc drukowane w sposob graficzny.
      
    - W  celu  wykorzystania  moóliwosci  drukarki,  ktore nie sa bezposrednio
      dostepne  za  pomoca  polecen:  ^K..., naleóy uóyc polecenia ^kś_, ktore
      powoduje,  {e wszystkie kody sterujace, znajdujace sie w bieóacej linii,
      sa wysylane bezposrednio do drukarki.
      Przyklad:
      ^Kś_ ^K1B "h" ^K04 (1F 1B 68 04) - wlaczenie powiekszania znakow (4 razy)
      
      ^Kś- ^K1B "h" ^K04 (1F 1B 68 00) - skasowanie powiekszania znakow
      

5.  Biblioteka makropolecen zostala wzbogacona o 3 kolejne programy:

    - KALKULACJE - sluóy do ukladania makropolecen wykonujacych zaprogramowane
                   obliczenia  na wierszu tabeli i umieszczajacych wyniki tych
                   obliczen w tym wierszu. 
                   Zaklada  sie,  {e  liczby w wierszu przedzielone sa znakami
                   "
",  oraz  {e wiersz uóyty jako wzorcowy nie jest pierwsza
                   linia w zbiorze.
                   Po  zaladowaniu  wyswietlany  jest  opis  dzialania  makro-
                   polecenia   "KALKULACJE".   Nacisniecie   dowolnego   znaku
                   powoduje przejscie do trybu tworzenia nowego makropolecenia.
                   Przykladowo  w celu utworzenia makro, ktore bedzie sumowalo
                   3  kolejne  liczby  i wynik umieszczalo w czwartej kolumnie
                   naleóy nacisnac 3 razy klawisz "+" oraz klawisz "=".
                   Nacisniecie  znaku  "ESC"  powoduje  zakonczenie  polecenia
                   "KALKULACJE"  i  wykonanie  makropolecenia,  ktore  zostalo
                   utworzone.  Kolejne  polecenia  "^ś"  umoóliwiaja wykonanie
                   utworzonego makropolecenia dla roónych wierszy tabeli.
                   
    -SUMA - umoóliwia  sumowanie  liczb  umieszczonych  w  kolumnie.  Wskaznik
            dodatkowy naleóy umiescic w linii, gdzie ma byc umieszczony wynik,
            natomiast  wskaznik glowny w pierwszej linii, w kolumnie obejmuja-
            cej najwieksza z liczb z lewej strony.
            
    -PRZESUN - umoóliwia  przesuwanie "prostokata" z tekstu, ktorego przekatna
               wyznaczona jest wskaznikami. Po wywolaniu makropolecenia kieru-
               nek  przesuniecia  wybierany  jest przez polecenia ^S ^D ^E ^X.

    Znak  ?  w  niektorych  makropoleceniach  pozwala  obejrzec dostepne menu.

6.  W  zwiazku  z  naniesieniem  poprawek w programach edytora KOMPLET, naleóy
    skopiowac caly pakiet programow, wchodzacych w jego sklad.
