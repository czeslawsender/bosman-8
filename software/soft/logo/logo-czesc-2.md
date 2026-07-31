4. Typy stalych i zmiennych w jezyku LOGO 
   





































 
    - liczby calkowite i rzeczywiste
    - zmienne o wartosciach liczbowych
    - lancuchy znakow ascii
    - zmienne o wartosciach lancuchowych
    - stale Boolowskie "prawda i "falsz
    - zmienne o wartosciach Boolowskich
    - listy skladajace sie z wartosci stalych roónych typow
      typy stalych na liscie moga byc pomieszane

5. Wyraóenia
   









W jezyku LOGO moóna budowac wyraóenia uóywajac stalych, zmiennych, operatorow
arytmetycznych ^ + - * / , logicznych = < > , nawiasow () 
oraz nazw funkcji z ich parametrami.
Typ wartosci wyraóenia zaleóy od uóytych elementow skladowych.
Funkcje w LOGO wywolywane sa z parametrami bez nawiasow.
Znaki operatorow ^ + - * /   = < >  maja pierwszenstwo nad funkcjami.
Chcac dodac np. sin 30  i  1.2 naleóy napisac  (sin 30)+1.2
Znak - oznacza odejmowanie, jeóeli jest oddzielony spacja od drugiego
argumentu, lub mnoóenie przez -1 jeóeli nie jest oddzielony spacja.
Operator ^ trzeba oddzielic od nastepnego argumentu teó znakiem spacji.
Operatory ^ + - * / < > = moga byc uóywane w wyraóeniach normalnie, tzn:
2 + 3  8 / 2   4 * 5 * 3 , lub jako operatory dwuargumentowe w notacji 
beznawiasowej np: * 2 3   / 4 5       * 2+3 6-4 .
Operatory + * oraz niektore funkcje moga byc rozumiane jako wieloargumentowe
w wyraóeniach o postaci :     (* 2 3 4 5 6 7)    (+ 23 45 4 67 2) .

UWAGA !
Przyklady wyraóen beda podane podczas omawiania prymitywow.

6. Prymitywy zdefiniowane na stale w jezyku LOGO
   













































Prymitywy w jezyku LOGO moóna podzielic na :

   - procedury     wykonujace jakas czynnosc
   - funkcje       dajace w wyniku jakas wartosc
   - operatory     ^ + - * / = < >

Operatory moga byc uóyte dwojako - jako operatory i jako funkcje.
Prymitywy moga byc bezargumentowe, lub wymagaja argumentow okreslonych
typow.
Funkcje i operatory daja w wyniku wartosc okreslonego typu.
W niektorych wypadkach typ wartosci zaleóy od typu argumentow.
Wartosc wynikowa funkcji moóe byc argumentem innych funkcji, procedur,
operatorow, moóe byc uóyta jako wartosc w procedurze przypisania.
Jeóeli funkcja zostanie wywolana samodzielnie, to jej wartosc zostanie
wydrukowana na ekranie.

                          *************************
                          * OPERACJE ARYTMETYCZNE *
                          *************************





















       pi       
     Stala pi

                

 
















Przyklad:
?pi
3.14159265358979
?



                                    -2-



















       ^        
      Operator lub funkcja potegowania, za operatorem

                
      trzeba umiescic znak spacji
 
















Przyklad:
?^ 6 2
36
?



















      sin       
      Funkcja sinus z argumentem w stopniach

                

 















 
Przyklad:
?sin 30
0.5
?



















      cos       
	Funkcja cosinus z argumentem w stopniach

                

 
















Przyklad:
?cos 60
0.5
?



















     arctg      
      Funkcja arcus tangens - wynik w stopniach

                

 
















Przyklad:
?arctg 1
45
?



















 entier    ent  
      Funkcja - czesc calkowita argumentu

                

 
















Przyklad:
?entier 4/3
1
?



















       !        
      Operator silnia

                

 
















Przyklad:
?4 !
24
?



















pierwiastek pwk 
      Funkcja - pierwiastek kwadratowy z argumentu

                

 
















Przyklad:
?pwk 49
7
?



















      exp       
      Funkcja e do potegi x

                

 
















Przyklad:
?exp 2
7.38905609893065
?


                                 -4-



















      losuj     
     Procedura - ustawia generator liczb losowych

                
                 w stan poczatkowy
 
















Przyklad:
?losuj
?
                               *********************
                               * OPERACJE LOGICZNE *
                               *********************




















       i        
     Funkcja - daje w wyniku iloczyn logiczny dwoch

                
               argumentow
 
















Przyklad:
?i  3<4 7>4
prawda
?



















      lub       
     Funkcja - daje w wyniku sume logiczna dwoch

                
               argumentow
 
















Przyklad:
?lub 3=4  1=2
falsz
?lub "prawda "falsz "prawda
prawda
prawda                        <--trzeci argument nie bral udzialu
?(lub "prawda "falsz "prawda)
prawda
?



















      nie       
      Funkcja jednoargumentowa - daje w wyniku wartosc

                
              zanegowana w stosunku do argumentu
 
















Przyklad:
?nie 3=4
prawda
?



















     rowne?     
     Funkcja dajaca w wyniku wartosc prawda jeóeli oba

                
             argumenty sa identyczne (rowne).
 















              W przeciwnym wypadku wynikiem jest falszu.
Przyklad:
?rowne? "LOGO "LOGO1
falsz
?



















       =        
     Operator lub funkcja dajaca w wyniku wartosc prawda

                
              jeóeli oba argumenty sa identyczne (rowne).
 















               W przeciwnym wypadku wynikiem jest falsz.
Przyklad:
?= "LOGO "LOGO
prawda
?1=2
falsz
?



















       >        
     Operator lub funkcja dajaca w wyniku wartosc prawda

                
              jeóeli pierwszy argument jest wiekszy nió drugi
 















               W przeciwnym wypadku wynikiem jest falsz.
Przyklad:
?> "LOGO "AAAA
prawda
?1>2
falsz                            -6-



















    bezost      
     Funkcja - daje w wyniku argument pozbawiony ostatniego

                
               elementu.
 
















Przyklad:
?bezost ekranś
[0 TS 5 OKNOń
?



















    pierw       
     Funkcja - daje w wyniku pierwszy element argumentu

                

 
















Przyklad:
?pierw {olwś                   : funkcja {olwś bedzie omowiona nióej
0
?pierw 1245
1
?pierw 3*56
1
?{olwś
[0 0 0 OPU 1 prawdań           : przykladowa wartosc funkcji {olwś
?



















      ost       
     Funkcja - daje w wyniku ostatni element argumentu

                

 
















Przyklad:
?ost {olwś
prawda
?ost 9*8
2
?3*ost 9*8
6
?ascii ost "qwer
114
?



















      nap       
     Funkcja - dolacza pierwszy argument jako pierwszy

                
               element drugiego argumentu
 
















Przyklad:
?nap "a "qwerty
aqwerty
?nap 12 ekranś
[12 0 TS 5 OKNO 0.75]
?nap :x {olw
[źń 0 0 0 OPU 1 prawdań
?



















      nak       
     Funkcja - dolacza pierwszy argument jako ostatni

                
               element drugiego argumentu
 
















Przyklad:
?nak "a "ghjk
ghjka
?



















    element     
     Funkcja - daje w wyniku element drugiego argumentu

                
               wskazany przez pierwszy argument
 
















Przyklad:
?element 4 ekranś
OKNO
?element 0 ekranś
element nie przyjmuje 0 jako parametru
?
                               -8-



















     slowo      
     Funkcja - daje w wyniku slowo utworzone ze zlaczenia

                
               slow - argumentow
 
















Przyklad:
?przyp slowo "d :x + 100 85
?:x :d200
100 85
?



















       ml       
     Funkcja - zamienia w podanym slowie wszystkie litery

                
               duóe na male
 
















Przyklad:
?ml "aGtUfT
agtuft
?



















       dl       
     Funkcja - zamienia w podanym slowie wszystkie litery

                
               male na duóe
 
















Przyklad:
?dl "AgTuFt
AGTUFT
?



















    puste?      
     Funkcja - daje w wyniku wartosc prawda jeóeli argument

                
               jest obiektem pustym. Inaczej daje falsz.
 
















Przyklad:
?puste? "
prawda
?puste? "a
falsz
?puste? [ń
prawda
?puste? :x
x nie ma wartosci
?



















    lista?      
     Funkcja - daje w wyniku wartosc prawda jeóeli argument

                
               jest lista. Inaczej daje falsz.
 
















Przyklad:
?lista? {olwś
prawda
?lista? 1
falsz
?lista? [1 2]
prawda
?lista? [ń
prawda
?



















    element?    
     Funkcja - daje w wyniku wartosc prawda jeóeli pierwszy

                
               argument jest elementem drugiego.
 















                Inaczej daje falsz.
Przyklad:
?element? "w "qwerty
prawda
?element? "OKNO ekranś
prawda
?ekranś
[0 TS 5 SKLEJ 0.75]
?element? "OKNO ekranś
falsz
?                               -10-
Przyklad:
?przypisz "x 1234
?:x                            : oznacza wartosc zmiennej
1234
?przypisz "aa [0 1 2 3 4]
?:aa
[0 1 2 3 4]
?



















      oto       
   Polecenie - przyjecia definicji procedury lub funkcji.

                
               Za slowem  oto  nastepuje nazwa procedury
 















                (funkcji) oraz opcjonalnie nazwy parametrow
                                 formalnych poprzedzone znakiem  : .
                                 W nastepnych liniach podawana jest tresc.
                                 W ostatniej linii wystepuje slowo  juó
                                 oznaczajace koniec definicji.
Przyklad:
?oto proc
>(lokal "xloc)                 : xloc bedzie zmienna lokalna - niedostepna
>przypisz "xloc 123              poza procedura
>pisz :xloc                    : zmienna lokalna wystepujaca sama
>juó                             nie bedzie wydrukowana na ekranie
Procedura proc zdefiniowana
?
?po "proc                      : pokazuje tresc procedury
oto proc
(lokalne "xloc)
przypisz "xloc 123
pisz :xloc
juó
?
?proc                          : wykonanie procedury
123
?
?:xloc
xloc nie ma nadanej wartosci   : zmienna lokalna poza procedura nie ma wartosci
?
?oto kolo :wiel                : wiel jest parametrem procedury
>powtorz 360 [naprzod :wiel prawo 1]
>juó
Procedura kolo zdefiniowana
?kolo 1.2                      : rysowane jest na ekranie kolo z zadanym
?                                parametrem 1.2
?oto fun :x                    : definicja funkcji
>przypisz "y :x * :x
>wynik :y                      : wskazuje na zmienna, ktorej wartosc ma byc
>juó                             wynikiem funkcji - konczy obliczanie
Procedura fun zdefiniowana
?
?



















      juó       
       Slowo : konczace definicje procedury lub funkcji

                
               powinno wystepowac samodzielnie na poczatku
 















                ostatniej linii definicji





















    lokalne     
     Komenda - nadaje podanym zmiennym charakter lokalny

                

 
















Przyklad:
(lokalne "xloc)
?



                                 -12-



















 wartosc    war 
     Funkcja - daje w wyniku wartosc zmiennej bedacej

                
               argumentem
 
















Przyklad:
?wartosc "x
1234
?war "xloc
xloc nie ma nadanej wartosci
?



















 pisz       pp  
   Procedura - drukuje podane obiekty w miejscu kursora

                
               tekstowego. Usuwa nawiasy ograniczajace.
 















                Za ostatnim obiektem dodaje znak nowej linii.
Przyklad:
?pisz [sin 30 cos 30 23.4]
sin 30 cos 30 23.4
?pisz [ :sin 30 :cos 30 24.5]
:sin 30 :cos 30 24.5
?przypisz "aa sin 30
?przypisz "bb cos 30
?pisz [:aa :bbń
:aa :bb
?pisz lista :aa :bb
0.5 0.866025388240814
?pisz (lista :aa :bb :aa+3 12.45)
0.5 0.866025388240814 3.5 12.45
?pisz [1 2 3] pisz [4 5 6]
1 2 3
4 5 6
?



















 piszgr    ppgr 
   Procedura - drukuje podane obiekty od pozycji {olwia.

                
               Usuwa nawiasy ograniczajace.
 
















Przyklad:
piszgr [ANDRZEJ CH.]
ANDRZEJ CH                     : tekst zostanie napisany od pozycji {olwia
?



















     pokaó      
   Procedura - drukuje podane obiekty w miejscu kursora

                
               tekstowego. Utrzymuje nawiasy ograniczajace.
 















                Za ostatnim obiektem dodaje znak nowej linii.
Przyklad:
?pokaó (lista :aa :bb :aa+3 12.45)
[0.5 0.866025388240814 3.5 12.45]
?pokaó [1 2 3] pokaó [4 5 6]
[1 2 3]
[4 5 6]
?



















    pokaógr     
   Procedura - drukuje podane obiekty od pozycji {olwia.

                
               Utrzymuje nawiasy ograniczajace.
 
















Przyklad:
?pokaógr (lista :aa :bb :aa+3 12.45)
[0.5 0.866025388240814 3.5 12.45]
?



















     wpisz      
   Procedura - drukuje podane obiekty w miejscu kursora

                
               tekstowego. Usuwa nawiasy ograniczajace.
 















                Nie dodaje znaku nowej linii.
Przyklad:
?wpisz (lista :aa :bb :aa+3 12.45)
0.5 0.866025388240814 3.5 12.45
?wpisz [1 2 3] wpisz [4 5 6]
1 2 34 5 6                      -14-                            { cd 1 str15}



















    .zobacz     
     Funkcja - daje w wyniku zawartosc podanej komorki

                
               pamieci komputera 
 
















Przyklad:
?.zobacz 1
3
?



















    .umiesc     
   Procedura - wpisuje do podanej komorki pamieci komputera

                
               podana wartosc 
 
















Przyklad:
?.umiesc 1 3
?



















    klawisz?    
     Funkcja - daje w wyniku wartosc prawda, jeóeli byl

                
               nacisniety jakis klawisz na klawiaturze
 
















Przyklad:
?klawisz?
falsz
?



















czytajznak   cz 
     Funkcja - daje w wyniku znak z klawiatury

                

 
















Przyklad:
?przypisz "kk czytajznak
?:kk                           : naciskam klawisz w
w
?



















czytajliste  cl 
     Funkcja - daje w wyniku liste, ktora zawiera ciag

                
               znakow z klawiatury zakonczony znakiem CR
 
















Przyklad:
?czytajliste
1 qq 3 44 55
[1 qq 3 44 55]



















czytajwiersz cw 
     Funkcja - daje w wyniku slowo, ktore zawiera ciag

                
               znakow z klawiatury zakonczony znakiem CR
 

















                         *************************
                         * WSPOLPRACA Z PISAKIEM *
                         *************************

W opisywanej wersji programu LOGO.COM umieszczono procedury pozwalajace na
obsluge ploterka firmy SONY typ PRN-C41.
Wspolpraca z pisakiem ploterka odbywa sie w trybie tekstowym za pomoca 
polecen: " wlaczdruk "," wylaczdruk " oraz w trybie graficznym za pomoca
polecen opisanych ponióej.




















   wlaczpisak   
   Procedura - powoduje ustawienie trybu graficznego

                
               pisaka
 
















Przyklad:
?wlaczpisak
?



















   wylaczpisak  
   Procedura - powoduje wylaczenie trybu graficznego

                
               pisaka
 
















Przyklad:  jak wyóej 1.          -16-



















   proporcja    
   Procedura - ustala skale ekranu w kierunku pionowym 

                

 
















Przyklad:
?ekranś
[0 TK 5 OKNO 0.75]
?proporcja 2
?ekranś
[0 TK 5 OKNO 2]
?proporcja .75
?ekranś
[0 TK 5 OKNO 0.75]
?



















   proporcjaś   
   Procedura - okresla ilosc linii w okienku tekstowym 

                

 















 
Przyklad:
?proporcjaś
1
?



















    wiersze     
   Procedura - okresla ilosc linii w okienku tekstowym

                

 
















Przyklad:
?ekranś
[0 TK 5 OKNO 0.75]
?wiersze 10
?ekranś
[0 TK 10 OKNO 0.75]



















     sklej      
   Procedura - ustawia tryb grafiki, w ktorym {olw znikajac

                
               po jednej stronie ekranu, pojawia sie po
 















                stronie przeciwnej 
Przyklad:
?sklej
?ekranś
[0 DE 5 SKLEJ 0.75]
?



















     pole       
   Procedura - ustawia tryb grafiki, w ktorym przekroczenie

                
               przez {olwia granic ekranu sygnalizowane jest
 















                jako blad 
Przyklad:
?pole
?ekranś
[0 DE 5 POLE 0.75]
?



















     okno       
   Procedura - ustawia tryb grafiki, w ktorym ekran

                
               traktowany jest jako okno na plaszczyznie.
 















                [olw moóe byc widoczny na ekranie, lub
                                 znajdowac sie poza nim.
Przyklad:
?okno
?ekranś
[0 DE 5 OKNO 0.75]
?



















 zmaótekst   zt 
   Procedura - kasuje tekst w okienku tekstowym i umieszcza

                
               kursor na poczatku najwyószej linii 
 
















Przyklad:
?zmaótekst
?                               -18-



















 podnies    pod 
   Procedura - podnies pioro

                

 
















Przyklad:
?podnies
?



















   scieranie    
   Procedura - ustawia pioro w kolorze tla - wymazywanie

                

 
















Przyklad:
?scieranie
?



















   odwracanie   
   Procedura - powoduje, {e {olw na swojej drodze zamienia

                
               kolor napotkanych punktow na przeciwny 
 
















Przyklad:
?odwracanie
?



















      pó        
   Procedura - powoduje, {e {olw staje sie widoczny 

                

 
















Przyklad:
?pó
?



















      só        
   Procedura - powoduje, {e {olw staje sie niewidoczny 

                

 
















Przyklad:
?só
?



















     wroc       
   Procedura - powoduje ustawienie {olwia w pozycji 0-0

                
               i w kierunku polnocy
 
















Przyklad:
?wroc
?



















 naprzod    np  
   Procedura - przesuwa {olwia w przod o podana ilosc

                
               krokow
 
















Przyklad:
?naprzod 100
?



















 wstecz     ws  
   Procedura - przesuwa {olwia wstecz o podana ilosc krokow

                

 
















Przyklad:
?wstecz 200
?



















 prawo      pr  
   Procedura - obraca {olwia w prawo o podana ilosc stopni

                

 
















Przyklad:
?prawo 90
?
?pw 30
?

                                  -20-



















     ypozś      
     Funkcja - daje w wyniku liczbe okreslajaca wspolrzedna

                
               y {olwia
 
















Przyklad:
?ypozś
40
?



















      pkt       
   Procedura - rozjasnia punkt o podanych wspolrzednych

                

 
















Przyklad:
?pkt [20 130]
?pkt lista :x :y
?



















      pktś      
     Funkcja - daje w wyniku stan punktu o podanych

                
               wspolrzednych. Jeóeli punkt leóy poza
 















                ekranem wynikiem jest -1.
Przyklad:
?pktś [20 130]
1
?pktś [21 130]
0
?pktś [1000 2000]
-1
?
                           ********************
                           * OPERACJE DYSKOWE *
                           ********************




















     laduj      
   Procedura - laduje z dysku plik z programem w jezyku

                
               LOGO
 
















Przyklad:
?laduj "ROZETA 



















     ladujo     
   Procedura - laduje z dysku plik z trescia obrazka

                
               zapamietany za pomoca polecenia  
 















                zapiszo "nazwa
Przyklad:
?ladujo "ROźAR



















    zapisz      
   Procedura - zapisuje na dysku wszystkie zdefiniowane

                
               procedury i zmienne
 
















Przyklad:
?zapisz "ROZETA 



















    zapiszo     
   Procedura - zpisuje na dysku aktualnie wyswietlany

                
               obrazek
 
















Przyklad:
?zapiszo "KWIAT



















    katalog     
     Funkcja - daje w wyniku liste nazw plikow z rozszerze-

                
               niem LOG znajdujacych sie na aktualnym dysku
 
















Przyklad:
?katalog
[TTT RRRń
?


                                  -22-



















     potp       
   Procedura - wyswietla nazwy i naglowki wszystkich

                
               procedur i funkcji w obszarze roboczym
 















                pamieci
Przyklad:
?potp
oto proc
oto zzz
?



















     pown       
   Procedura - wyswietla nazwy i wartosci wszystkich

                
               zmiennych globalnych, jakie znajduja sie
 















                w buforze 
Przyklad:
?pown
ww ma wartosc [b56 9 dc asdń
qq ma wartosc [11 abc 34]
bb ma wartosc 0.866025388240814
aa ma wartosc 0.5
?



















     powp       
   Procedura - wyswietla nazwy i definicje wszystkich

                
               procedur i funkcji, jakie sa w buforze
 
















Przyklad:
?powp
oto kolo
powtorz 180 [naprzod 2 prawo 2]
juó
oto roóa
powtorz 4 [powtorz 45 [naprzod 2 prawo 2] prawo 180]
juó
oto rrr
powtorz 30 [prawo 12 roóań
juó
?



















  .pierwotneś   
   Procedura - wyswietla zawartosc tablicy symboli LOGO

                

 
















Przyklad:
?



















      us        
   Procedura - usuwa podane procedury lub funkcje z bufora

                

 
















Przyklad:
?us "kolo
?



















      usw       
   Procedura - usuwa wszystkie procedury, funkcje i zmienne

                
               z bufora programu.
 
















Przyklad:
?



















      usn       
   Procedura - usuwa podane zmienne z bufora 

                

 
















Przyklad:
?





                                   -24-



















  ustawatrybut  
   Procedura - wprowadza podana pare   atrybut - wartosc

                
               na liste atrybutow wyspecyfikowanego obiektu
 
















Przyklad:
?ustawatrybut "ddd ".WART 128
?:ddd
128
?podajatrybut "naprzod ".PRM
8162
?listujatrybuty "naprzod
[.PRM 8162]
?listujatrybuty "(
[.PRM 1625]
?ustawatrybut "www ".RRR 124
?ustawatrybut "rrr "azx "qwerty
?



















 atrybutwartosc 
   Procedura - wyswietla niestandardowe pary

                
               atrybut - wartosc  wszystkich obiektow
 















                w buforze
Przyklad:
?atrybutwartosc
rrr's azx ic qwerty
?



















  usunatrybut   
   Procedura - usuwa podany atrybut z listy atrybutow

                
               podanego obiektu
 
















Przyklad:
?listujatrybuty "www
[.RRR 124]
?usunatrybut "www ".RRR
?listujatrybuty "www
[ń
?


   ******************
   Atrybuty systemowe           <-- ( nie sprawdzone ? )
   ******************

.WART    wartosc zmiennej globalnej
.DEF     definicja procedury
.KON     koniec linii definicji procedury, zakonczonej znakiem CR lub spacjami
.POC     poczatek linii definicji procedury, zakonczonej znakiem CR i spacjami
.PRM     znacznik prymitywu
.KOM  ;  komentarz



   *************************
   Zmienne i stale systemowe
   *************************

BLAD     jeóeli ma wartosc  prawda  - powoduje wstrzymanie przy wystapieniu
         bledu i powrot na poziom przyjmowania komend.
poziom0  komenda przeskocz  "poziom0  powoduje natychmiastowe przerwanie
         wszystkich aktywnych procedur.
prawda   stala systemowa.
falsz    stala systemowa.





                                   -26-



















     pauza      
   Procedura - zawiesza wykonanie procedury w celu ingeren-

                
               cji interpretera lub edytora.
 















                Po przycisnieciu  ^Z .
Przyklad:
?pauza
rrr ?



















     dalej      
   Procedura - przerywa pauze wprowadzona przez nacisniecie

                
               ^Z 
 
















Przyklad:
?pauza
rrr ?dalej
?



















      dosc      
   Zakonczenie pracy programu  LOGO

                

 
















Przyklad:
?dosc
A>

                *********************************************
                * EDYCJA I PRZEGLAD PROGRAMU W EDYTORZE red *
                *********************************************

Istnieje moóliwosc edycji jednej lini za pomoca programu edycji lini oraz
calego programu lub jego czesci za pomoca edytora.
Jeóeli program zglasza sie znakiem zapytania lub znakiem  " > "  wowczas
dziala program edycji linii. Wprowadzenie znaku CR ,spowoduje w tym wypadku
kompilacje i wykonanie polecen w linii.

Edytor zglasza sie napisami w dwoch gornych liniach:

	COL - nr kolumny
	CHR - kod znaku pod kursorem
	FA  - wielkosc pamieci zajetej przez tekst
	M   - wielkosc wolnej pamieci
        :---  od lewej nazwa pliku otwartego do czytania
        :---  dalej, nazwa pliku otwartego do zapisu

            - w dolnej lini od lewej graficzny obraz zajetej pamieci zbioru 
              widoczneg, gorny znacznik (ruchomy) obrazuje miejsce kursora w
              zbiorze
            - dalej, graficzny obraz zajetej pamieci zbioru niewidocznego


W edytorze istnieja dwa rodzaje polecen, wywolywane za pomoca:

	    - jednoczesnego nacisniecia klawisza CTRL zinnym klawiszem np  ^A
	    - kolejnego nacisniecia dwoch klawiszy np  ESC B

UWAGA!
Nacisniecie klawisza ESC spowoduje wypisanie w gornej linii tekstu- "Polecenie"
do, ktorego dopisujemy tresci polecenia.
W programie edycji linii dostepne sa tylko polecenia wywolane z uóyciem
klawisza  CTRL .

	Wprowadzono dwa wskazniki: podstawowy - zmieniajacy poloóenie wraz z
kursorem oraz dodatkowy, ktory moóe przyjac wartosc wskaznika podstawowego
( ESC @ ) lub zamienic wartosc ze wskaznikiem podstawowym ( ESC \ ).
Istnieje moóliwosc przeslania tekstu pomiedzy wskaznikami do drugiegu zbioru
( ESC W ) oraz pobranie tego tekstu za pomoca polecenia ( ^_ ).
Kolejne polecenia ( ESC W ) spowoduja skasowanie starej zawartosci drugiego
zbioru i wpisanie nowego tekstu.
                                   -28-
^K	koniec edycji zbioru
CR	koniec edycji linii
^L	powtorz wykonanie poprzedniego polecenia ESC F lub ESC S
^N	kursor na koniec wiersza
^O	przesun kadr o 16 kolumn w lewo
^P	przesun kadr o 16 kolumn w prawo
^Q	przelacznik zamienianie/dopisywanie znaku
	w trybie zamienianie w gornej linii pojawi sie napis "zamieniam"
^R	kursor o kadr w gore
^S	kursor w lewo o znak
^T	kasuj slowo w prawo
^U	kasuj tekst miedzy wskaznikami
^V	wpisz w miejscu kursora ostatnio skasowana porcje (wyraz) tekstu
^W	przesuniecie tekstu na ekranie o jeden wiersz w dol
^X	kursor w dol
^Y	kasuj linie od kursora w prawo
^Z	przesuniecie tekstu na ekranie o jeden wiersz w gore
^_	przywroc poprzednia linie w programie edycji linii
	przepisz tekst z drugiego zbioru w edytorze



        Dodatkowo w programie edycji linii:

^Z	zwieksz okienko tekstowe o jedna linie
^W	zmniejsz okienko tekstowe o jedna linie








                                  -30-
