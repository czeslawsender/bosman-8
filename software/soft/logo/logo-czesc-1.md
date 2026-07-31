1. Pliki dyskowe obslugiwane przez LOGO
   




































LOGO.COM         program LOGO

*.LOG            pliki z programami w jezyku LOGO
*.OBR            pliki z trescia obrazkow zapamietanych przez LOGO

2. Wywolanie programu LOGO
   























A>LOGO cr        LOGO zglosi sie bez wpisanego programu.
                 Oczekuje na zlecenia z klawiatury.

A>LOGO PROG1 cr  Plik PROG1 powinien miec rozszerzenie .LOG
                 LOGO wykona wszystkie zlecenia zapisane na pliku
                 tak, jakby byly napisane z klawiatury podczas
                 pracy. W szczegolnosci zostana zdefiniowane procedury
                 i zmienne.

A>LOGO cr        Jeóeli na dysku istnieje plik    STARTUJ.LOG ,
                 LOGO zachowa sie tak, jakby bylo wywolane
                 A>LOGO STARTUJ cr.
UWAGA !
Program  LOGO.COM rezerwuje drugi bank pamieci dla programow uóytko-
wych. Powoduje to zmniejszenie pojemnosci dysku krzemowego, zostawia-
jac natomiast do dyspozycji programow uóytkowych kompilatora LOGO 60 KB
pamieci. Pamiec uóytkownika (tzw operacyjna) jest wtedy podzielona na
pamiec skompilowanej czesci programu, stos i bufor edytora.

3. Praca z programem LOGO
   






















Po wywolaniu LOGO zglosi sie do pracy znakiem ? umieszczonym na pustym
ekranie.
Jest  to  tryb :  ts - caly ekran przeznaczony jest na tekst.
Pozostale tryby:  de - na dole ekranu wydzielone jest okienko tekstowe,
                       gorna czesc ekranu przeznaczona jest na grafike.
                  gr - caly ekran przeznaczony jest na grafike.
                       Polecenia z klawiatury przyjmowane sa bez pisania
                       echa na ekranie.
Zmiany trybow moóna wywolywac poleceniami: ts  de  gr  ^Z  ^W.
W pewnych wypadkach zmiany trybow wykonywane sa automatycznie.
Powoduja je przykladowo:
                     - wydanie polecenia "graficznego" w trybie TS
                     - odwolanie sie do edytora w trybie DE i GR
                     - wystapienie bledu w trybie GR

Przejscie z trybow graficznych DE i GR na tryb TS nastepuje z zapamietaniem
tresci obrazu graficznego. Po powrocie do trybu graficznego obraz jest
odtwarzany na ekranie.
LOGO wywolane z jakims programem przystepuje natychmiast do jego
wykonania. Dopiero po wykonaniu tego programu zglasza sie znakiem ?
w oczekiwaniu na zlecenia. Zgloszenie nastepuje w trybie wynikajacym
z wykonanego programu.
Wykonywanie programu moóna w kaódej chwili przerwac naciskajac klawisz ESC.
Jest to przerwanie bez moóliwosci kontynuacji.
Innym przerwaniem jest nacisniecie ^Z. Po przerwaniu tym moóna wykonac
jakies zlecenie lub procedure, a nastepnie poleceniem: ( dalej ), wrocic do
przerwanego programu. Przerwania ^Z moóna zaglebiac, tzn przerwac procedure
wykonywana podczas innego przerwania. Przerwanie to moóe byc wywolane
w programie przez zlecenie: ( pauza ).
Program w jezyku LOGO sklada sie z prymitywow, zaimplementowanych na stale,
oraz procedur i funkcji zdefiniowanych przy pomocy prymitywow i innych zdefi-
niowanych procedur i funkcji. Moóliwe jest rownieó definiowanie rekurencyjne.




                                 -1- 



















       Eś       
     Stala e

                

 
















Przyklad:
?Eś
2.71828182845904
?



















       +        
     Operator lub funkcja dodawania

                

 
















Przyklad:
?+ 2 3
5
?4 + 5 + 6 + 7
22
?(+ 12 34 4 6 7)
63
?



















       -        
     Operator lub funkcja odejmowania

                

 
















Przyklad:
?- 10 4
6
?10-4
6
?10-6-1
3
?



















       -        
     Znak liczby  (mnoóenie przez -1)

                

 
















Przyklad:
?-10 4
-10
4
?-127
-127
?



















       *        
     Operator lub funkcja mnozenia

                

 
















Przyklad:
?* 2 3
6
?4 * 5 * 6 * 7
840
?(* 2 4 4 6 7)
1344
?



















       /        
     Operator lub funkcja dzielenia

                

 
















Przyklad:
?/ 6 2
3
?/ 15 3
5
?

                                 -3-



















      ln        
     Funkcja logarytm naturalny

                

 
















Przyklad:
?ln 2
0.693147180559947
?



















      log       
     Funkcja logarytm dziesietny

                

 
















Przyklad:
?log 2
0.301029995663981
?



















    stopnie     
     Funkcja zamieniajaca radiany na stopnie

                

 
















Przyklad:
?stopnie 3.14
179.908747671078
?



















    radiany     
     Funkcja zamieniajaca stopnie na radiany

                

 
















Przyklad:
?radiany 360
6.28318530717958
?



















ilorazcalkowity 
     Funkcja - czesc calkowita z dzielenia

    ilorazc     
                argumentow
 
















Przyklad:
?ilorazcalkowity 14 4
3
?



















    reszta      
     Funkcja - reszta z dzielenia argumentow

                

 
















Przyklad:
?reszta 7 3
1
?



















    zaokr       
     Funkcja - zaokragla argument do najbliószej

                
               liczby calkowitej
 
















Przyklad:
?zaokr 3.44337
3
?zaokr 3.5
4
?



















    losowa      
     Funkcja - nieujemna liczba losowa calkowita

                
               nie wieksza nió podany argument
 
















Przyklad:
?losowa 20
7
?
                                 -5-



















       <        
     Operator lub funkcja dajaca w wyniku wartosc prawda

                
              jeóeli pierwszy argument jest mniejszy nió drugi
 















               W przeciwnym wypadku wynikiem jest falsz.
Przyklad:
?< "AAAA "LOGO
prawda
?1<2
prawda
?< "a "a               :znak a w operacji porownania znajduje sie pomiedzy a i b
prawda
?< "b "a
falsz
?
                    *******************************************
                    * PRZETWARZANIE SLOW I STRUKTUR LISTOWYCH *
                    *******************************************
   



















    ascii       
     Funkcja - zamienia na liczbe kod pierwszej litery

                
               slowa bedacego argumentem
 
















Przyklad:
?ascii "G
71
?ascii :z                        :zmienna  z  ma wartosc "grtyu
103
?



















     znak       
     Funkcja - zamienia liczbe calkowita z zakresu 0-255

                
               na znak o podanym kodzie
 
















Przyklad:
?znak 83
S
?



















    dlugosc     
     Funkcja - daje w wyniku liczbe elementow wprowadzonego

                
               argumentu
 
















Przyklad:
?dlugosc "six
3
?dlugosc :z
5
?dlugosc [0 1 2 3]
4
?dlugosc 1234
4                              : ilosc znakow liczby 1234
?



















    bezpierw    
     Funkcja - daje w wyniku argument pozbawiony pierwszego

                
               elementu 
 
















Przyklad:
?bezpierw 124
24
?bezpierw ekranś               : funkcja ekranś omowiona bedzie nióej
[TS 5 OKNO 0.75]
?bezpierw "abcdef
bcdef
?ekranś
[0 TS 5 OKNO 0.75]             : przykladowa wartosc funkcji ekranś
?


                                -7-



















     lista      
     Funkcja - daje w wyniku liste swoich argumentow

                
               dwa argumenty moga byc podane bez nawiasow
 















                uóycie zmiennych jako argumentow powoduje
                                 umieszczenie na liscie ich aktualnych wartosci
Przyklad:
?lista ekranś {olwś
[ź0 TS 5 OKNO 0.75] [0 0 0 OPU 1 prawdańń  :lista dwoch list
?lista ekranś {olwś ekranś
[ź0 TS 5 OKNO 0.75] [0 0 0 OPU 1 prawdańń
[0 TS 5 OKNO 0.75]                         :trzeci argument nie wszedl do listy
?(lista ekranś {olwś ekranś)
[ź0 TS 5 OKNO 0.75] [0 0 0 OPU 1 prawdań [0 TS 5 OKNO 0.75]ń
?lista
za malo parametrow dla lista
?(lista)
[ń
?lista 1
za malo parametrow dla lista
?lista 1 2
[1 2]
?



















     zdanie     
     Funkcja - daje w wyniku liste utworzona z elementow

                
               swoich argumentow.
 















                Dwa argumenty moga byc podane bez nawiasow
                                 uóycie zmiennych jako argumentow powoduje
                                 umieszczenie na liscie ich aktualnych wartosci.
Przyklad:
?zdanie [1] [3]
[1 3]
?zdanie [12] [23] [34]
[12 23]
[34]                           : trzeci argument nie wszedl do listy
?(zdanie [12] [34] [56])
[12 34 56]
?zdanie {olwś ekranś
[0 0 0 OPU 1 prawda 0 TS 5 SKLEJ 0.75]
?



















    fragment    
     Funkcja - daje w wyniku obiekt skladajacy sie z podanych

                
               przez pierwszy i drugi argument elementow
 















                trzeciego argumentu
Przyklad:
?fragment 1 2 ekranś
[0 TSń
?fragment 2 4 ekranś
[TS 5 SKLEJń
?fragment 3 5 "asdfgh
dfg
?fragment 6 7 "asdft
za malo danych w asdft
?



















     tasuj      
     Funkcja - daje w wyniku liste, na ktora skladaja sie

                
               losowo ustawione elementy listy - argumentu
 
















Przyklad:
?tasuj [1 2 3 4 5 6 7 8 9]
[4 2 6 1 5 8 3 9 7]
?tasuj ekranś
[0 TS 5 0.75 SKLEJń
?



                                 -9-



















     gdzieś     
     Funkcja - daje w wyniku numer obliczony podczas

                
               ostatniego obliczania  element?  zakonczonego
 















                wynikiem prawda. Jest to poloóenie pierwszego
                                 argumentu funkcji element?  w drugim.
Przyklad:
?ekranś
[0 TS 5 SKLEJ 0.75]
?element? "SKLEJ ekranś
prawda
?gdzieś
4
?



















    liczba?     
     Funkcja - daje w wyniku wartosc prawda jeóeli argument

                
               jest liczba. Inaczej daje falsz.
 
















Przyklad:
?liczba? 12
prawda
?:x
[ń
?liczba? :x
falsz
?liczba? pierw ekranś
prawda
?



















    slowo?      
     Funkcja - daje w wyniku wartosc prawda jeóeli argument

                
               jest slowem lub liczba
 
















Przyklad:
?slowo? 1234
prawda
?slowo? a1234
nie wiem co zrobic z a1234
?slowo? "a1234
prawda
?slowo? ekranś
falsz
?slowo? #12
nie wiem co zrobic z #12
?slowo? "#12
prawda
?



















     jest?      
     Funkcja - daje w wyniku wartosc prawda jeóeli argument

                
               jest identyfikatorem zmiennej.
 















                Inaczej daje falsz.
Przyklad:
?jest? "xloc
falsz
?:x
x nie ma nadanej wartosci
?jest? "x
falsz
?
                   **********************************************
                   * DEFINIOWANIE ZMIENNYCH, FUNKCJI I PROCEDUR *
                   **********************************************




















przypisz   przyp
   Procedura - tworzy zmienna o nazwie podanej przez 

                
                 pierwszy argument i/lub nadaje zmiennej
 















                  wartosc okreslona przez drugi argument

                                -11-



















 wynik       wy 
     Komenda - wskazuje na zmienna, ktorej wartosc ma byc

                
               wynikiem funkcji - konczy obliczanie funkcji
 
















Przyklad:
>wynik wartosc funkcji
>
?



















    powtorz     
   Polecenie - powtorzenia podanej listy operacji.

                
               Pierwszy argument - ilosc powtorzen
 















                drugi argument - lista operacji.
Przyklad:
?powtorz 4 [naprzod 100 prawo 90 ]
?



















     jesli      
   Polecenie - wykonania jednej z dwu list instrukcji

                
               w zaleónosci od wartosci wyraóenia stojacego
 















                za slowem  jesli. Instrukcje musza byc listami
                                 skladajacymi sie z liter,zamknietych nawiasami.
Przyklad:
?jesli (:x>:y) [pisz [x jest wiekszeńń  [pisz [y jest wiekszeńń
x jest wieksze
?



















     stop       
   Polecenie - przerwania dzialania procedury i powrotu

                
               do poziomu nadrzednego
 
















Przyklad:
?stop
?



















    czekaj      
   Procedura - odczekiwania czasu. Czas = argument * 1/60 sek.

                

 
















Przyklad:
?czekaj 200
?



















     zrob       
   Polecenie - wykonania podanej listy instrukcji

                

 
















Przyklad:
?przypisz "instr  [naprzod 40 prawo 90]
?zrob :instr
?



















    etykieta    
     Komenda - identyfikuje linie, ktora ma byc wykonana 

                
               po komendzie  skocz
 
















Przyklad:
?oto petla
>przypisz "x 0
>etykieta "loop  pisz sin :x
>przypisz "x :x+1
>jesli :x>90 [stopń [skocz "loopń
>juó
Procedura petla zdefiniowana
?



















     skocz      
     Komenda - wykonanie jako nastepnej tej sposrod linii

                
               wewnatrz procedury, ktora po wyraóeniu
 















                etykieta ma taki sam wyraz jak argument 
                                 komendy  skocz.
Przyklad:  jak wyóej 1

                                 -13-
?przypisz "qq [11 abc 34]
?przypisz "ww [b56 9dc asdń
?wpisz :qq wpisz :ww
11 abc 34b56 9 dc asd
?



















     wpiszgr    
   Procedura - drukuje podane obiekty od pozycji {olwia.

                
               Usuwa nawiasy ograniczajace.
 



































     format     
   Procedura - okresla ilosc cyfr znaczacych przy wydruku

                
               Dla liczb, ktorych czesc calkowita nie miesci
 















                sie w formacie, stosuje sie postac wykla-
                                 dnicza. Argument procedury z zakresu 1-15.
Przyklad:
?format 5 pi
3.1416
?



















   wlaczdruk    
   Procedura - powoduje rozpoczecie powielania tekstu

                
               na drukarce
 
















Przyklad:
?wlaczdruk
?



















   wylaczdruk   
   Procedura - powoduje zaprzestanie powielania tekstu

                
               na drukarce
 
















Przyklad:
?wylaczdruk
?



















     wolneś     
     Funkcja - daje w wyniku liczbe wolnych wezlow bufora

                
               zmiennych i procedur
 
















Przyklad:
?wolneś
3418
?



















    odsmiec     
   Procedura - zwalnia moóliwie najwieksza liczbe wezlow

                
               w buforze i reorganizuje go
 
















Przyklad:
?odsmiec
?wolneś
3876
?



















   .zobaczp     
     Funkcja - daje w wyniku aktualna zawartosc portu

                
               o podanym numerze
 
















Przyklad:
?.zobaczp 56
127



















   .umiescp     
   Procedura - wysyla podana wartosc do portu

                
               o wskazanym numerze
 
















Przyklad:
?.umiescp 41 56
?



                                  -15-



















     pisak      
   Procedura - powoduje ustawienie koloru pisaka w

                
               ploterze
 
















Przyklad:
?pisak 2
?



















     pisakś     
     Funkcja - daje w wyniku liczbe odpowiadajaca ustawio -

                
               nemu kolorowi pisaka
 
















Przyklad:
?pisakś
2
?



















 rozdzielczosc  
   Procedura - powoduje ustawienie skali 1 lub 2 dla osi x,y.

                
               Ustawienie skali 2 umoóliwia odzwierciedlenie
 















                polowkowych krokow {olwia.
Przyklad:
?rozdzielczosc 2
?



















 rozdzielczoscś 
     Funkcja - daje w wyniku liczbe rowna ustawionej skali

                

 















 
Przyklad:
?rozdzielczoscś
2
?
                            **********************
                            * STEROWANIE GRAFIKA *
                            **********************




















 teksty     ts  
   Procedura - definiuje caly ekran jako okienko tekstowe.

                
               Obraz graficzny zostanie zapamietany
 















                w terminalu.
Przyklad:
?teksty
?ekranś
[0 TK 24 OKNO 1]
?



















 dzielekran  de 
   Procedura - na ekranie tworzone jest okienko tekstowe

                
               o ilosci linii ustawionej ostatnim
 















                wywolaniem procedury  wiersze.
                                 Odtwarzany jest obraz graficzny zapamietany
                                 podczas wykonywania procedury teksty.
                                 Procedura dzielekran wykonuje sie rownieó
                                 automatycznie, jeóeli w stanie teksty nasta-
                                 pilo wywolanie procedury graficznej.
Przyklad:
?dzielekran
?ekranś
[0 DE 5 OKNO 1]
? 



















 grafika    gr  
   Procedura - definiuje caly ekran jako okienko graficzne.

                
               Normalne wydruki tekstowe sa pomijane.
 















                W wypadku bledu, wykonywana jest procedura
                                 teksty, a nastepnie drukowany jest komunikat.
Przyklad:
?grafika
                      : znika tekst z ekranu, pojawia sie {olw


                                 -17-



















  czysc     cs  
   Procedura - kasuje czesc graficzna ekranu. [olw zostaje

                
               umieszczony w pozycji  0-0 i skierowany
 















                na polnoc. Pioro {olwia zostaje opuszczone.
Przyklad:
?czysc
?



















      zmaó      
   Procedura - kasuje czesc graficzna ekranu. [olw zostaje

                
               w pozycji dotychczasowej 
 
















Przyklad:
?zmaó
?



















    kursor      
   Procedura - umieszcza kursor w miejscu podanym w liscie

                
               wspolrzednych. Moóe byc ustawiony w miejscu
 















                poza aktualnym okienkiem tekstowym.
Przyklad:
?kursor [0 14]
?kursor lista :x :y
?



















    kursorś     
     Funkcja - daje w wyniku liste wspolrzednych kursora 

                

 
















Przyklad:
?kursorś
[0 23]
?zmaótekst
?kursorś
[0 1]
?kursorś
[0 2]
?



















     ekranś     
     Funkcja - daje w wyniku liste danych o ekranie.

                
               Poszczegolne elementy listy :
 















                - kolor tla  (zawsze 0)
                                 - stan ekranu
                                 - ilosc linii w okienku tekstowym
                                 - ograniczenie ekranu (tryb grafiki)
                                 - pionowa skala ekranu
Przyklad:
?ekranś
[0 DE 5 OKNO 0.75]
?



















      {olw      
     Funkcja - daje w wyniku liste danych o {olwiu 

                
               Poszczegolne elementy listy :
 















                - wspolrzedna x
                                 - wspolrzedna y
                                 - kat odchylenia {olwia od polnocy w prawo
                                 - stan piora
                                 - nr koloru piora (zawsze 1)
                                 - czy {olw jest widoczny
Przyklad:
?{olw
[0 0 0 OPU 1 prawdań
?



















 opusc      opu 
   Procedura - opusc pioro

                

 
















Przyklad:
?opu
?                                -19-



















 lewo       lw  
   Procedura - obraca {olwia w lewo o podana ilosc stopni

                

 
















Przyklad:
?lewo 45
?



















      kat       
   Procedura - ustawia {olwia pod zadanym katem, podanym

                
               w stopniach
 
















Przyklad:
?kat 90
?



















      katś      
     Funkcja - daje w wyniku kat ustawienia {olwia w

                
               stopniach
 
















Przyklad:
?katś
90
?



















    azymut      
     Funkcja - daje w wyniku kat, pod jakim trzeba by 

                
               ustawic {olwia, aby mogl dojsc do punktu o
 















                podanych wspolrzednych
Przyklad:
?azymut [20 30]
33.6900675259799
?



















      poz       
   Procedura - przesuwa {olwia na podana pozycje 

                

 
















Przyklad:
?poz [ 30 20 ]
?poz lista :x :y
?



















      pozś      
     Funkcja - daje w wyniku liste okreslajaca pozycje

                
               {olwia
 
















Przyklad:
?pozś
[30 20]
?



















     xpoz       
   Procedura - przesuwa {olwia na pozycje o wspolrzednej x

                
               podanej jako argument komendy
 
















Przyklad:
?xpoz 120
?



















     xpozś      
     Funkcja - daje w wyniku liczbe okreslajaca wspolrzedna

                
               x {olwia
 
















Przyklad:
?xpozś
120
?



















     ypoz       
   Procedura - przesuwa {olwia na pozycje o wspolrzednej y

                
               podanej jako argument komendy
 
















Przyklad:
?ypoz 40                          -21-



















     dyskś      
     Funkcja - daje w wyniku nazwe aktualnego napedu dysku

                

 
















Przyklad:
?dyskś
A:
?



















     dysk       
   Procedura - ustawia jako aktualny dysk, ten ktorego nazwa

                
               jest podana jako argument
 
















Przyklad:
?dysk "c:
?dyskś
C:
?katalog
[TTT RRRR RRRń
?dysk "a:
?



















      uspl      
   Procedura - kasuje na aktualnym dysku plik o podanej

                
               nazwie i rozszerzeniu .LOG
 
















Przyklad:
?uspl "TTT
?



















      usplo     
   Procedura - kasuje na aktualnym dysku plik o podanej

                
               nazwie i rozszerzeniu .OBR
 
















Przyklad:
?usplo "ROZETA
?
                           **********************************
                           * OPERACJE W BUFORZE PROGRAMOWYM *
                           **********************************




















      pow       
   Procedura - wyswietla definicje wszystkich procedur,

                
               funkcji i  zmiennych, znajdujacych sie
 















                w buforze programu
Przyklad:
?pow
oto kolo
powtorz 180 [naprzod 2 prawo 2]
juó
oto roóa
powtorz 4 [powtorz 45 [naprzod 2 prawo 2] prawo 180]
juó
oto rrr
powtorz 30 [prawo 12 roóań
juó
z ma wartosc 55.9192895889282
y ma wartosc -96.5925812721252
x ma wartosc 500
qq ma wartosc [11 abc 34]



















       po       
   Procedura - wyswietla definicje podanej procedury,

                
               funkcji lub zmiennej
 
















Przyklad:
?po "proc
oto proc
przypisz "xloc 123
pisz :xloc
juó                              -23-



















    okresl      
   Procedura - nadaje nazwie procedury (pierwszy argument)

                
               tresc listy bedacej drugim argumentem
 
















Przyklad:
?okresl "zzz [źń [naprzod 100]ń
?po "zzz
oto zzz
naprzod 100
juó
?tresc "zzz
[źń [naprzod 100]ń
?okresl "zzz [źń [naprzod 100 prawo 90]ń
?tresc "zzz
[źń [naprzod 100 prawo 90]ń
?



















     tresc      
     Funkcja - daje w wyniku liste definiujaca procedure,

                
               ktorej nazwe wskazuje argument
 
















Przyklad:
?tresc "zzz
[źń [naprzod 100 prawo 90]ń
?



















     spakuj     
   Procedura - usuwa formatowanie procedur wraz

                
               z komentarzami w celu uzyskania wolnych
 















                pozycji bufora na nowe obiekty 
Przyklad:
?spakuj
?
                        *******************
                        * LISTY ATRYBUTOW *
                        *******************




















 listujobiekty  
     Funkcja - daje w wyniku liste wszystkich obiektow

                
               w buforze, ktore w swojej liscie atrybutow
 















                maja podany atrybut 
Przyklad:
?listujobiekty ".def
[ń
?listujobiekty ".DEF
[priom rrr roóa kolo przes lisa wykres ukladń
?listujobiekty ".WART
[z y x ww qq bb aań
?



















 listujatrybuty 
     Funkcja - daje w wyniku liste atrybutow podanego

                
               obiektu
 
















Przyklad:
?listujatrybuty "priom
[.DEF [źń [powtorz 200 [poz lista (riom 512) - 256 (riom 256) - 128]ńńń
?listujatrybuty "z
[.WART 55.9192895889282]
?



















  podajatrybut  
     Funkcja - daje w wyniku wartosc podanego atrybutu

                
               podanego obiektu
 
















Przyklad:
?podajatrybut "z ".WART
55.9192895889282
?

                                  -25-

                        **************************
                        * URUCHAMIANIE PROGRAMOW *
                        **************************






















   wlaczslad    
   Procedura - wlacza sledzenie wykonania procedury

                

 
















Przyklad:
?wlaczslad
?



















   wylaczslad   
   Procedura - wylacza sledzenie wykonania procedury

                

 
















Przyklad:
?wylaczslad
?



















  wlaczpodglad  
   Procedura - wlacza podglad wszystkich lub podanych

                
               procedur
 
















Przyklad:
?wlaczpodglad
?



















  wylaczpodglad 
   Procedura - wylacza podglad wszystkich lub podanych

                
               procedur
 
















Przyklad:
?wylaczpodglad
?



















    pulapka     
   Procedura - powoduje ustawienie pulapek programowych

                
               w wypadku wystapienia bledow i pewnych
 















                specjalnych warunkow, ktore moga pojawic sie
                                 w czasie wykonywania podanej listy komend
Przyklad:
>pulapka "blad [pisz 2/1 pisz 2/0]
?



















     blad       
   Procedura - wyswietla liste, ktorej elementy opisuja

                
               ostatni blad, jaki wystapil w programie
 
















Przyklad:
>pulapka "blad [pisz 2/1 pisz 2/0]
>pokaó blad
?



















  przeskocz     
   Procedura - powoduje wykonanie linii okreslonej przez

                
               nazwe wprowadzona przy poprzednim wyraóeniu
 















                pulapka
Przyklad:
?przeskocz "poziom0
?oto test
>przyp "i 1
>pulapka "ety [powtorz 10[przyp "i :i +1 wpisz :i jesli (:i>5)
 [przeskocz "ety ]ńń
>pisz "tekst1
>juó
?


                                  -27-
Dzialanie polecen ( ESC F - szukanie tekstu ) oraz ( ESC S - szukanie i
zamiana tekstu ) moóe byc wielokrotnie powtarzana za pomoca polecenia ( ^L ).
W poleceniach ( ESC F i ESC S ) wzorzec tekstu szukanego i zamienianego
zostanie wypisany w gornej linii. Wzorce te naleóy zakonczyc znakiem ESC.



















   

      red       
   Procedura - powoduje zaladowanie podanych procedur i

                
               zmiennych do bufora edytora, anastepnie 
 















                przejscie do edycji. Bez podawania nazw
                                 powoduje przejscie do pustego edytora.
Przyklad:
?red "kolo




















      redw      
   Procedura - powoduje zaladowanie wszystkich procedur

                
               i zmiennych do bufora edytora ekranowego,
 















                a nastepnie przejscie do edycji.
Przyklad:
?redw


                       *************************
                       * POLECENIA EDYTORA red *
                       *************************

ESC A	wczytaj tekst z pliku otwartego do czytania
ESC B	przesun kursor na poczatek zbioru
ESC Fxyz ESC
	ustaw kursor za lancuchem xyz
	lancuch "xyz" moóe miec dlugosc 1-18 znakow i musi byc zakonczony
	znakiem ESC
ESC P	zapisz tekst pomiedzy wskaznikami na pliku dyskowym, zamknij
	plik dyskowy
ESC OR ESC nazwa ESC
	otworz do czytania lub wczytania plik "nazwa"
ESC OW ESC nazwa ESC
	otworz do pisania lub zapisu plik "nazwa"
ESC Sxyz ESC abc ESC
	w miejsce lancucha "xyz" wstaw lancuch "abc"
	kursor zostanie ustawiony za lancuchem "abc"
ESC U ESC
	zapisz na plik dyskowy tekst od poczatku zbioru do wskaónika-kursora,
	usun zapisany tekst, zamknij plik dyskowy (tylko na plik otwarty do
	zapisu)
ESC W	zapisz tekst pomiedzy wskaznikami do drugiego zbioru, usun tekst
	pomiedzy wskaznikami
ESC Z	przesun kursor na koniec zbioru


^ę	wlacz wskazniki
^ń	zamien wskazniki
^A	kursor o slowo w lewo
^B	  "    na poczatek wiersza
^C	  "    o kadr w dol
^D	  "    w prawo o znak
^E	  "    w gore o wiersz
^F	  "    o slowo w prawo
^G	kasuj znak pod kursorem
^H	kasuj znak wstecz
DEL	kasuje znak wstecz
TAB	odstep co 8 kolumn
LF	dopisuje nowa linie, kursor zostaje w starej linii



                                  -29-
                     **************************
                     * SKOROWIDZ ALFABETYCZNY *
                     **************************




!		 4 str	kursorś		19 str	
.pierwotneś	24	lewo	lw	21	pó		20 str
.umiesc		16	liczba?		11	radiany		 5
.umiescp	15	lista		 9	red   -   redw	29
.zobacz		16	lista?		10	reszta		 4
.zobaczp	15	listujatrybuty	25	rozdzielczosc	17
*		 3	listujobiekty	25	rozdzielczoscś	17
+		 3	ln		 5	rowne?		 6
-		 3	log	 	 5	sin		 4
/		 3	lokalne		12	sklej		18
<		 7	losowa		 5	skocz		13
=		 6	losuj		 6	slowo		10
>		 6	lub		 6	slowo?		11
^		 4	laduj		22	spakuj		25
arctg		 4	ladujo		22	stop		13
ascii		 7	ml		10	stopnie		 5
atrybutwartosc	26	nak		 8	só		20
azymut		21	nap		 8	scieranie	20
bezost		 8	naprzod	  np	20	tasuj		 9
bezpierw	 7	nie		 6	teksty	 ts	17
blad		27	odsmiec		15	tresc		25
cos		 4	odwracanie	20	us		24
czekaj		13	okno		18	usn		24
czysc	cs	19	okresl		25	uspl		23
czytajliste  cl 16	opusc	opu	19	usplo		23
czytajwiersz cw 16	ost		 8	ustawatrybut	26
czytajznak   cz 16	oto		12	usunatrybut	26
dalej		28	pauza		28	usw		24
dl		10	pi		 2	wartosc	  war	14
dlugosc		 7	pierw		 8	wiersze		18
dosc		28	pierwiastek  pwk 4	wlaczdruk	15
dysk		23	pisak		17	wlaczpisak	16
dyskś		23	pisakś		17	wlaczpodglad	27
dzielekran   de 17	pisz	pp	14	wlaczslad	27
Eś		 3	piszgr	ppgr	14	wolneś		15
ekranś		19	pkt		22	wpisz	     14-15
element		 8	pktś		22	wpiszgr		15
element?	10	po		23	wroc		20
entier	ent	 4	podajatrybut	25	wstecz	  ws	20
etykieta	13	podnies	pod	20	wylaczdruk	15
exp		 4	pokaó		14	wylaczpisak	16
format		15	pokaógr		14	wylaczpodglad	27
fragment	 9	pole		18	wylaczslad	27
gdzieś		11	potp		24	wynik	  wy	13
grafika	gr	17	pow		23	xpoz		21
i		 6	pown		24	xpozś		21
ilorazcalkowity  5	powp		24	ypoz		21
	ilorazc		powtorz		13	ypozś		22
jest?		11	poz		21	zaokr		 5
jesli		13	pozś		21	zapisz		22
juó		12	prawo	pw	20	zapiszo	  	22
katalog		22	proporcja	18	zdanie		 9
katalogo	22	proporcjaś	18	zmaó		19
kat		21	przeskocz	27	zmaótekst  zt	18
katś		21	przypisz  przyp 11	znak		 7
klawisz?	16	pulapka		27	zrob		13
kursor		19	puste?		10	{olwś		19


                                  -31-
