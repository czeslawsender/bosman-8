

                                  WSTEP                        
                      

   WORDSTAR jest jednym z najbardziej rozpowszechnionych programów służących 
do przetwarzania tekstów, pracujących pod systemem operacyjnym CP/M. Jego 
poplarność spowodowała, }e stał się on pewnym standardem dla przetwarzania
plików tekstowych, zarówno typu dokumentacyjnego (prowadzenie korespondencji,
pisanie książek) jak i typu tekstów programów dla komputera. Typy te wymagają
nieco różnych metod redagowania tekstu. Dla przykładu redagowanie tekstu typu
dokumentacyjnego będzie wymagało kilku funkcji porządkujących, jak justacja
tekstu, porządkowanie akapitów, podział na strony. Funkcje te wprowadzają 
często do tekstu znaki specjalne, które w przypadku umieszczenia w tekście
programu spowodowałyby trudne czasem do wykrycia błędy. Z tych właśnie wzglę-
dów przyjmujemy, }e pliki typu dokumentacyjnego oraz teksty programów są róż-
nymi obiektami przetwarzania i wymagają nieco różnych trybów pracy programu
redagującego (edytora).
   WORDSTAR operuje pełnym repertuarem 128 znaków ASCII. Znaki nie mające od-
powiedników alfanumerycznych używane są do sterowania programem. Najczęściej
są to znaki typu CONTROL. Sposób wprowadzenia ich na klawiaturze zależy od
sprzętu  na  jakim  zainstalowany jest program.  W  dalszej  części  instrukcji 
poprzez  CTRL/X,  CTRL/C  etc.  będziemy rozumieć wciśnięcie odpowiednio  znaku 
CONTROL X, CONTROL C etc.. Tab oznaczać będzie znak tabulacji, DEL znak DELETE,
a ESC znak ESCAPE.
   Dialog   użytkownika  z  programem  zorganizowany  jest  w  systemie   kilku 
skorowidzów (menu) wzajemnie przez siebie wywoływanych. Uruchomienie jednej z
wyświetlanych  opcji następuje poprzez wciśnięcie jednego znaku.  Opcje  często 
wymagają  podania dodatkowej informacji (np.  nazwa pliku),  którą  wprowadzamy 
jako tekst zakończony wciśnięciem klawisza ENTER. Podczas wprowadzania tekstu
dłuższej odpowiedzi istnieje czasem potrzeba prostej jego edycji. Zapewniają to
znaki :
   
   CTRL/Y , CTRL/x        - usuń wprowadzony tekst,
   CTRL/S , CTRL/H , DEL  - usuń ostatnio wprowadzony znak,
   CTRL/R                 - odtwórz ostatnio wprowadzony tekst,
   CTRL/F                 - wyświetl katalog dysku,
   CTRL/P                 - nie traktuj następnego znaku jako znaku sterującego
                
Całość wprowadzanego tekstu usuwa znak CTRL/U. Wszystkie skorowidze wyświetlane
są   w   górnej  części  ekranu,   zależnie  od  rodzaju  stosowanej   konsoli, 
wytłuszczonym lub negatywnym drukiem. W lewym górnym rogu ekranu podawane jest
echo   ostatnio   wprowadzonego  znaku.   W   przypadku   zawieszenia   dialogu 
spowodowanego wykonaniem przez program jakichś czynności w górnej linii ekranu,
wyświetlane  jest  słowo WAIT.  Czynności te można przerwać poprzez  wciśnięcie 
klawisza ESC. Niektóre pytania zadawane przez program wymagają jedynie akcepta-
cji lub negacji.  Swą decyzję podajemy wciskając klawisz Y lub  N.  Jakikolwiek 
inny klawisz oznacza odpowiedź negatywną.




                                  SPIS TRESCI

ROZDZIAŁ 1. Zaczynamy pracę z edytorem........................................1
   1.1 Uruchomienie programu                                                  1
   1.2 Menu wstępne NO FILE MENU                                              1

ROZDZIAŁ 2. Zasady pracy z programem..........................................4
   2.1 Format ekranu                                                          4
   2.2 Sposób wprowadzenia dla tekstów typu dokumentacyjnego                  4
   2.3 Linia stanu                                                            6
   2.4 Linijka                                                                6
   2.5 Znaczniki linii                                                        6

ROZDZIAŁ 3. Redagowanie tekstu................................................8
   3.1 Ruch kursora                                                          
   3.2 Przesuwanie tekstu na ekranie                                          8
   3.3 Wprowadzanie tekstu                                                    9 
   3.4 Znaki specjalne w tekście                                              9    
   3.5 Usuwanie tekstu                                                        9
   3.6 Zakończenie redagowania tekstu                                         9

ROZDZIAŁ 4. Format tekstu - menu ekranowe ONSCREEN MENU......................10
  4.1 Formatowanie tekstu                                                    10
  4.2 Sterowanie pracą WORDSTAR'a                                            12

ROZDZIAŁ 5. Przeszukiwanie, operacje na blokach i plikach....................13
   5.1 Znaczniki                                                             13
   5.2 Wyszukiwanie i zamiana tekstów                                        13
   5.3 Operacje na blokach                                                   14
   5.4 Operacje na plikach                                                   14

ROZDZIAŁ 6. Informacje dodatkowe o redagowaniu tekstu........................15
   6.1 Menu pomocnicze HELP MENU                                             15
   6.2 Sterowanie przebiegiem wykonywania komend                             15
   6.3 Redagowanie plików o typie innym niż dokumentacyjny                   15

ROZDZIAŁ 7. Sterowanie wydrukiem.............................................16
   7.1 Znaki sterujące wydrukiem                                             16
   7.2 Komendy sterujące wydrukiem                                           16
   7.2.1. Format pionowy strony                                              17
   7.2.2. Format poziomy strony                                              17
   7.2.3. Stronicowanie tekstu                                               17
   7.2.4. Nagłówek i stopka strony                                           17
   7.2.5. Sterowanie numeracją stron                                         18
   7.2.6. Inne komendy                                                       18
   7.3 Czynności przy drukowaniu tekstu                                      18

ROZDZIAŁ 8. Program wspomagający redagowanie korespondencji MAILMERGE........20




*********************************  ROZDZIAŁ 1 *********************************
  


                          ZACZYNAMY PRACE Z PROGRAMEM

1.1 URUCHOMIENIE PROGRAMU

   Po uruchomieniu komputera i systrmu operacyjnego CP/M zakładamy dyskietkę z
programem WORDSTAR. Na dyskietce tej znajdują się następujące pliki robocze:
     WS. COM      - główny plik zawierający program,
     WSMGS. DVR   - plik zawierający komunikaty programu,
     WSOVLY1. DVR - plik zawierający dodatkowe podprogramy,
     MAILMGE. DVR - plik programu wspomagającego redagowanie korespondencji.
Program uruchamiamy poprzez wprowadzenie tekstu w następującej postaci:
     WS ( < S: > < filename . typ > < d: > )
tekst w nawiasach okrągłych jest opconalny i zawiera
     < S: >                  - identyfikator dysku ( A: lub B: ), na którym 
                               znajduje się przetwarzany plik tekstowy,
     < filename . typ >      - nazwę przetwarzanego pliku tekstowego w formacie
                               takim, jak dla każdego pliku w systemie CP/M,
     < d: >                  - identyfikator dysku < A: lub B: >, na którym ma
                               znaleźć się plik tekstowy stanowiący wynik prze-
                               twarzania.
Wyspecyfikowanie jedynie < B: > < filename . typ > umożliwia redagowanie pliku
zajmującego całą  pojemność dysku B:,  co w przypadku plików o dużej  objętości 
jest  dosyć  istotne.  W przypadku niewyspecyfikowania  nazwy  plików roboczych 
WORDSTAR przechodzi do dialogu wymuszającego podanie przez operatara tych nazw
( tzw. NO FILE MENU ).

1.2. MENU WSTEPNE - NO FILE MENU  
  
   Określany jest tu dalszy sposób pracy programu oraz specyfikowane są pliki
podlegające  przetwarzaniu.  Umożliwione  są również proste opercje na  plikach 
odpowiadające  zleceniom systemowym jak  usunięcie,  kopiowanie,  zmiana  nazwy 
pliku.
   A oto opis poszczególnych opcji:
     
     L  - zmiana  dysku  domyślnego.  Dysk  ten  będzie  dyskiem  wybieranym  w 
          przypadku  podania nazwy pliku bez nazwy dysku.  Jego katalog  będzie 
          wyświetlony w przypadku każdego wejścia w NO FILE MENU. Zmiana dysku
          polega  na podaniu jego nazwy ( litera + dwukropek ) oraz  wciśnięciu 
          klawisza ENTER.
    
     F  - przełącznik  wyświetlania  katalogu  dysku  domyślnego.  Zależnie  od 
          poprzedniego  ustawienia  wyświetlanie jest włączone  lub  wyłączone. 
          Opis zawartości katalogu przesuwamy w górę i w dół za pomocą klawiszy
          CTRL/W lub CTRL/Z.
    
     H - ustawienie poziomu podpowiadania ( HELP LEVEL ). 
         Poziom 3 - wyświetlana jest pełna dostępna informacja.
         Poziom 2 - jak  poziom  3  z tym,  }e  w  przypadku  MAIN  MENU  nie 
                    wyświetlana jest lista dostępnych opcji, zwiększa to pojem-
                    ność ekranu zawierającego przetwarzany tekst. 
         Poziom 1 - w przypadku przejścia do menu nie jest wyświetlana  lista 
                    opcji,   natomiast  są  wyświetlane  informacje   dotyczące 
                    niektórych bardziej skomplikowanych opcji.
         Poziom 0 - cała informacja pomocnicza jest eliminowana, poza pytaniami
                    o dane i komunikatami o błędach.

     D - rozpoczęcie redagowania pliku typu dokumentacyjnego.  Wymaga  podania 
         nazwy pliku. W przypadku pliku nieistniejącego na dysku tworzony jest
         plik o podanej nazwie. Następuje przejście do MAIN MENU.
     
     N - rozpoczęcie redagowania pliku typu tekst programu. Jak w przypadku D
         należy podać nazwę pliku przetwarzanego. Następuje przejście do MAIN
         MENU.

     P - wydruk zawartości pliku na drukarce. Podczas wydruku naciskanie klawi-
         sza P powoduje jego zatrzymanie lub wznowienie.
   
     E - zmiana nazwy pliku. Należy podać starą i nową nazwę pliku.

     O - kopipwanie pliku.Stosowanie domyślnych nazw plików jest niedopuszczal-
         ne.   W   przypadku  kopiowania  do  pliku  istniejącego  wymaga   ono 
         dodatkowego potwierdzenia.

     Y - usunięcie pliku z dysku.

     M - uruchomienie  programu  wspomagającego  redagowanie  korespondencji
         MAILMERGE ( patrz dalsza część instrukcji ).
     
     S - kontrola poprawności tekstu. Wymaga obecności osobno  sprzedawanego
         pliku SPELSTAR . OVR.

     R - wykonanie dowolnego programu pod systemem CP/M. Po jego wykonaniu na
         dole ekranu pojawia się komunikat nakazujący wciśnięcie dowolnego kla-
         wisza w celu powrotu do WORDSTAR'a. Opcja użyteczna przy uruchamianiu
         programu, którego tekst jest aktualnie redagowany.

     X - powrót do systemu operacyjnego. Koniec pracy z WORDSTAR'em.




********************************  ROZDZIAŁ 2  *********************************



                           ZASADY PRACY Z PROGRAMEM

2.1. FORMAT EKRANU

   Ekran podczas redagowania tekstu ( MAIN MENU ), oprócz tekstu podlegającego
przetwarzaniu, zawiera informacje pomocnicze. Pierwszy wiersz od góry zawiera
tzw. linię stanu. Dalsze 7 wierszy zajmuje spis aktualnie dostępnych opcji.
Następny  wiersz jest tzw.  "linijką",  określającą prawy i lewy margines  oraz 
aktualnie ustawione pozycje tabulatora. Dalsze wiarsze zawierają już redagowa-
ny tekst.

2.2. SPOSOB WPROWADZANIA DLA TEKSTOW TYPU DOKUMENTACYJNEGO

   Wprowadzenie  tekstu  odbywa  się  podobnie jak w  maszynie  do  pisania.  W 
momencie  dojścia  do prawego marginesu ostatnio napisane przenoszone  jest  do 
następnej linii, a w poprzedniej linii słowa zostają "rozsunięte" dla zachowa-
nia lewego i prawego marginesu.  Rozsunięcie to zwane jest  justacją.  Zachodzi 
ona dla obszaru zwanego akapitem. Jego koniec zaznaczony jest znakiem ENTER.
Dlatego  też  znak ten może być wstawiany do tekstu JEDYNIE w  przypadku  końca 
akapitu.
   Poprawienie  wprowadzonego  tekstu może odbywać się w dwojaki  sposób.  Nowy 
tekst można wpisywać pomiędzy znaki starego (tryb INSERT ON) lub na stary takst
(tryb  INSERT  OFF).  Przełączanie między tymi trybami realizowane  jest  przez 
klawisz CTRL/U.
   Usuwanie znaku zachodzi poprzez usunięcie znaku znajdującego się na 
pozycji
kursora  (CTRL/G - delete right) wraz z przesunięciem kursora  w  prawo.  Można 
usunąć  całe słowo (CTRL/T) lub cały wiersz (CTRL/U).  Wprowadzane poprawki  na 
ogół powodują,  }e akapit nie ma wyrównanych marginesów.  Wyrównania dokonujemy 
komendą  porządkowania  akapitu (CTRL/B).  Kursor musi znajdować  się  wewnątrz 
akapitu.
   Podczas   wpisywania   tekstu  jest  on  dzielony  na   strony   zawierające 
zdefiniowaną  dla  konkretnej  drukarki ilość ta wynosi  55.  Po  przekroczeniu 
ilości  linii przypadającej na kolejną stronę WORDSTAR ustawia specjalną  linię 
wskazującą  miejsce  przesuwu  papieru do  nowej  strony.  Podczas  redagowania 
istnieje  możliwość przeglądania tekstu w górę lub w dół wiersz po wierszu  lub 
całymi  stronami.  W  przypadku  tekstu o ilości znaków w  linii  większej  niż 
długość linii ekranu,  można obejrzeć pełną linię przesuwając ekran wzdłuż  jej 
długości.
   Oprócz komend menu głównego istnieje dostęp do innych menu :
    * przez  CTRL/Q - do menu szybkiego (QUICK MENU), które służy do  szybkiego 
      przesuwania kursora w obrębie tekstu, przeszukiwania tekstu i powtarzania 
      tej samej komendy,
    * przez  CTRL/K - do menu  blokowego (BLOCK MENU) służącego  do operacji na
      większych fragmentach (blokach) tekstu lub na całym tekście, jak również
      odpowiedniego zakończenia redagowania tekstu,
    * przez  CTRL/O  - do   menu  ekranowego  (ONSCREEN  MENU)   służącego   do 
      formatowania dokumentu (szerokość i długość strony) jak również do zmiany 
      parametrów procesu redagowania tekstu,
    * przez  CTRL/P - do menu drukarki (PRINT MENU) służącego do sterowania wy-
      drukiem,
    * przez  CTRL/J  - do menu pomocniczego (HELP MENU)  umożliwiającego zmianę
      poziomu podpowiadania oraz wyświetlenie informacji o wyszczególnionych  w
      menu funkcjach.

2.3. LINIA STANU

   Opiszemy tu zawartość linii stanu. Zawiera ona:
    - aktualnie wykonywaną komendę
    - nazwę przetwarzanego zbioru
    - pozycję kursora.  Dla pliku typu dokumentacyjnego  wyświetlany jest numer
      strony, wiersza i kolumny.  W przeciwnym  wypadku  wyświetlany jest numer
      znaku w pliku, numer linii oraz numer znaku w aktualnej linii.
    - dodatkowe wskaźniki określające stan programu:

    WAIT           - program wykonuje operację dyskową. Należy wstrzymać dialog
                    
    MAR REL        - można wpisywać tekst w obszar poza wskazaniami marginesami

    DECIMAL        - kursor znajduje się w pozycji tabulacji dziesiętnej,

    INSERT ON      - wpisywanie tekstu odbywa się pomiędzy  znaki istniejącego
                     tekstu,

    LINE SPACING n - odstęp międzyliniowy równy n,

    PRINT PAUSED   - wydruk został wstrzymany,

    REPLACE (Y/N)  - pytanie o zmianę łańcucha znakowego.

2.4. LINIJKA

   Określa  ona format redagowanego tekstu.  Pozycje,  w których  znajdują  się 
litery  "L" i "R",  wskazują położenie odpowiednio lewego i prawego  marginesu. 
Znaki  "!" i "#" wskazują opcje tabulacji,  przy czym znak "#" wskazuje pozycję 
tabulacji dziesiątnej.

2.5. ZNACZNIKI LINII

   W  prawej  skrajnej kolumnie znajdują się znaki  specjalne  wskazujące  stan 
linii,  które  dalej  nazywane  będą  znacznikami  linii.  Ich  znaczenie  jest 
następujące:

    SPACJA - linia należy do większego akapitu,
       
       <   - linia zakończona znakiem ENTER. Jest to ostatnia linia akapitu lub 
             suma stanowiąca osobny akapit.                                          
             
       +   - linia jest dłuższa niż szerokość ekranu.

       .   - linia znajduje się poza końcem pliku.

       :   - linia znajduje się poza początkiem pliku.

       P   - następna linia zostanie wydrukowana po wysunięciu papieru od nowej
             strony.

       J   - linia zawiera znak LF bez znaku CR - plik stworzony poza programem
             WORDSTAR.

       M   - linia zawiera komendę MAILMERGE.




******************************  ROZDZIAł 3 ************************************



                              REDAGOWANIE TEKSTU

   Niniejszy rozdział zawierać będzie opis podstawowych komend stosowanych przy
redagowaniu tekstu.

3.1. RUCH KURSORA

   Do  sterowania  ruchem  kursora służy 6 klawiszy tworzących  na  klawiaturze 
układ łatwy do zapamiętania:

    CTRL/E - kursor w górę.
    CTRL/X - kursor w dół.
    CTRL/S - kursor o 1 znak w lewo.
    CTRL/D - kursor o 1 znak w prawo.
    CTRL/A - kursor na początek poprzedniego słowa.
    CTRL/F - kursor na początek następnego słowa.

   Bardziej zaawansowane komendy dostępne są za pośrednictwem QUICK MENU:

    CTRL/Q,S - kursor na początek linii.
    CTRL/Q,D - kursor na koniec linii.
    CTRL/Q,E - kursor na początek ekranu.
    CTRL/Q,X - kursor na koniec ekranu.
    CTRL/Q,R - kursor na początek pliku.
    CTRL/Q,C - kursor na koniec pliku.
    CTRL/Q,0...CTRL/Q,9 - kursor na pierwszy znak za podanym znacznikiem.
    CTRL/Q,B - kursor na początek bloku wraz z wyświetlaniem znacznika początku
               bloku.
    CTRL/Q,K - kursor na koniec bloku.
    CTRL/Q,P - przywrócenie ostatniej pozycji kursora.
    CTRL/Q,V - przywrócenie pozycji sprzed ostatniej czynności przeszukiwania.
    
3.2. PRZESUWANIE TEKSTU NA EKRANIE

    CTRL/Z   - przesunięcie w górę o 1 linię.
    CTRL/W   - przesunięcie w dół o jedną linię.
    CTRL/G   - przesunięcie o 1 ekran w górę.
    CTRL/R   - przesunięcie o 1 ekran w dół.

   Za pośrednictwem QUICK MENU istnieje możliwość ciągłego przesuwania tekstu z
prędkością regulowaną klawiszami 1-9. Dla klawisza 1 prędkość jest największa.
Czynność trwa aż wciśnięcia dowolnego klawisza.

    CTRL/Q,Z - ciągły przesuw w górę.
    CTRL/Q,W - ciągły przesuw w dół.

3.3. WPROWADZENIE TEKSTU

    CTRL/V   - przełącznik trybu wstawiania tekstu. Omówiony wcześniej.
    ENTER    - koniec akapitu.
    CTRL/N   - wstawianie znaku CR w miejscu wskazanym przez kursor.
    CTRL/I   - przesunięcie kursora do następnej pozycji tabulacji. Przy włą -
               czonym trybie tekst w linii, znajdujący się na prawo od kursora
               zostaje również przesunięty w prawo.
    
3.4. ZNAKI SPECJALNE W TEKSCIE

   Znaki te służą do sterowania drukarką.

    CTRL/P,O - wstawienie pojedyńczej spacji, stanowiącej odstęp nie ulegający
               zwiększeniu podczas justacji tekstu.
    CTRL/P,H - następny znak będzie nadrukowany na poprzednim.
    CTRL/P,M - następna linia będzie nadrukowana na aktualnej.

3.6. USUWANIE TEKSTU

    CTRL/G   - usuń znak, na którym stoi kursor i przesuń kursor w prawo.
    CTRL/T   - usuń słowo na prawo od kursora.
    CTRL/Q   - usuń linię, na której  stoi kursor wraz  z liniamii, które mają
               być na niej nadrukowane.
    CTRL/K,Q - usuń ostatnio zaznaczony blok.

3.7. ZAKONCZENIE REDAGOWANIA TEKSTU

    CTRL/K,S - zamknięcie pliku na dysku z naniesieniem zmian i ponowne rozpo-
               częcie redagowania. Użyteczne przy dużych plikach.
    CTRL/K,O - zamknięcie pliku na dysku z naniesieniem zmian i przejściem do
               NO FILE MENU.
    CTRL/K,X - zamknięcie  pliku  na dysku z naniesieniem zmian  i  powrót  do 
               systemu operacyjnego.
    CTRL/K,Q - przerwanie redagowania i zamknięcie pliku bez nanoszenia zmian.

Po zakończeniu pracy z WORDSTAR'em poprzednia wersja zostaje na pliku typu BAK.





********************************  ROZDZIAŁ 4 **********************************




                 FORMAT TEKSTU - MENU EKRANOWE (ONSCREEN MENU)

   Komendy  opisane  w  tym rozdziale umożliwiają  formatowanie  przetwarzanego 
tekstu.  Można  je podzielić na komendy formatujące sam tekst oraz  na  komendy 
określające sposób pracy WORDSTAR'a.

4.1. FORMATOWANIE TEKSTU

    CTRL/O,C - centrowanie tekstu linii, na której znajduje się kursor pomiędzy
               aktualnymi marginesami.
    CTRL/O,L - określenie lewego marginesu. Należy podać kolumnę, od której ma
               się zaczynać linia lub wcisnąć klawisz ESCAPE.
    CTRL/O,R - określenie prawego marginesu w sposób jak wyżej,
    CTRL/O,F - ustawienie  marginesów i tabulacji wg linii znajdującej  się  w 
               pliku. Marginesy można ustawić wg dowolnej linii pliku wskazanej
               przez kursor. W celu ustawienia tabulacji należy użyć specjalnej
               linii wzorcowej. Zawiera ona znaki "!", "#" oraz "-", gdzie znak
               "!" oznacza tabulację zwykłą,  znak "#" tabulację dziesiętną,  a 
               "-" jest seperatorem. Linię wzorcową można ukryć przed wydrukiem
               za   pomocą  specjalnych  komend  sterujących  drukarką   (linia 
               komentarza).
    CTRL/O,G - przesunięcie  akapitu do następnej  pozycji  tabulacji.  Akapit 
               zostanie faktycznie przesunięty dopiero po CTRL/B.
    CTRL/O,S - zmiana odstępu między liniami.  Nowy odstęp może być cyfrą od 1 
               do 9.
    CTRL/B   - porządkowanie akapitu (omówione wcześniej).
    CTRL/O,I - wprowadzenie nowej pozycji tabulacji.  Dialog podobny jak  przy 
               ustawianiu marginesów.
    CTRL/O,N - usuniącie  pozycji  tabulacji  o  wskazanym  numerze   kolumny, 
               kolumnie wskazanej przez kursor lub wszystkich pozycji.
    CTRL/O,X - włącznik/wyłącznik możliwości pisania tekstu poza marginesami.

4.2. STEROWANIE PRACA WORDSTAR'a

   Odbywa   się   to  za  pomocą  przełączania.   Podanie  komendy   dotyczącej 
przełącznika wprowadza go w stan przeciwny do poprzedniego. Jego stan wyświtla-
ny jest w ONSCREEN MENU. Stan ON oznacza stan aktywny przełącznika.

    CTRL/O,W - przenoszenie  słów z linii do linii  przy  wprowadzaniu  tekstu 
               (word wrap).
    CTRL/O,J - automatyczne justowanie tekstu.
    CTRL/O,V - zmienna  tabulacja.   Położenie  pozycji  tabulacji  zależy  od 
               uprzedniego zdefiniowania. Tryb stałej tabulacji będzie omówiony
               później.
    CTRL/O,T - wyświetlenie LINIJKI na ekranie.
    CTRL/O,P - wyświetlanie linii wskazujących początek strony .
    CTRL/O,D - wyświetlanie znaków sterujących wydrukiem. Użyteczne, gdy chcemy
               zobaczyć  tekst  w  postaci takiej,  w jakiej  znajdzie  się  na 
               papierze.
    CTRL/O,H - pomoc  przy  przenoszeniu  długich  słów  podczas  porządkowania 
               akapitu.
    CTRL/O,E - sposób  traktowania znaku "-".  W stanie  aktywnym  przełącznika 
               znak  ten jest traktowany jako znak przeniesienia i  wyświetlany 
               jest tylko wtedy, gdy znjduje się na końcu linijki. Znak innego
               rodzaju należy wprowadzić jako CTRL/P,- .

Początkowe  ustawienie  powyższych przełączników może być zmienione  za  pomocą 
programu instalującego.




******************************  ROZDZIAŁ 5 ************************************



             PRZESZUKIWANIE TEKSTU, OPERACJE NA BLOKACH I PLIKACH

5.1. ZNACZNIKI

   Znaczniki służą do szybkiego przemieszczania kursora w obrębie przetwarzane-
go  tekstu  o dużej objętości.  WORDSTAR umożliwia umieszczenie  w  tekście  10 
znaczników o kolejnych numerach od 0 do 9. Służą do tego następujące komendy:

     CTRL/K,0 - CTRL/K,9 - ustaw  znacznik  o wskazanym  numerze  na  pozycji 
                           wskazanej   przez   kursor.   Poprzednie   położenie 
                           wskaźnika o podanym numerze zostanie wymazane.
     CTRL/Q,0 - CTRL/Q,9 - przesuń kursor do wskańnika o podanym numerze.

Znaczniki nie są pamiętane w zbirze tekstowym.

5.2. WYSZUKIWANIE I ZAMIANA TEKSTOW

   Przez wyszukanie rozumieć będziemy przesunięcie kursora do miejsca, w którym
występuje  dany  ciąg  znaków.  Wyszukanie i zamiana  ciągów  znaków  mogą  być 
wykonane kilkakrotnie.

    CTRL/Q,F - wyszukiwanie tekstu. Kursor ustalony jest za  wyszukanym ciągiem
               słów.  Jako  argument  podajemy  wyszukiwany  tekst  kończąc  go 
               znakiem  ENTER  lub  ESCAPE zależnie od tego  czy  chcemy  podać 
               parametry dodatkowe czy też nie.
    CTRL/Q,A - zamiana  tekstów.  Jako argument podajemy ciągi  zastępowany  i 
               zastępujący.
    CTRL/L   - wznowienie operacji szukania lub zamiany tekstów.
    CTRL/Q,V - ustawienie  kursora  w pozycji na jakiej znajdował  się  kursor 
               przed operacją wyszukiwania.

   A oto informacje dodatkowe dla komend wyszukiwania i zamiany tekstów:

    cyfra    - ilość powtórzeń operacji  wyszukania/zamiany.  W  szczególności 
               oznacza  to  "znajdź n-te wystąpinie tekstu" lub "zamień n  razy 
               dany tekst innym tekstem".
      G      - przeszukaj cały plik lub zamiany przeprowadź w  obrębie  całego 
               pliku.
      N      - zamiana bez dodatkowego potwierdzenia.
      B      - przeszukiwanie w przód a nie wstecz.
      U      - ignoruj różnicę między dużymi a małymi literami.
      W      - uwzględnij całe słowa, a nie ich fragmenty.

5.3. OPERACJE NA BLOKACH

   Przez  blok  rozumieć  będziemy fragment przetwarzanego  tekstu  posiadający 
dowolnie dużą długość. Blok określany jest znacznikami początku  i końca bloku.
A oto lista operacji na blokach:

    CTRL/K,B - ustaw znacznik początku bloku. Znak , na którym stoi kursor jest
               ostatnim znakiem bloku.
    CTRL/K,K - ustaw znacznik  końca bloku.  Znak,  na którym stoi kursor  jest 
               ostatnim znakiem bloku.
    CTRL/K,H - zapal/zgaś znaczniki bloku.
    CTRL/K,N - tryb bloków  kolumn.  W trybie tym przez blok rozumie się  ilość 
               kolumn zawartą między znacznikami bloku.
    CTRL/K,V - przesuń blok pod aktualne położenie kursora (na lewo od niego).
    CTRL/K,C - kopiuj blok pod aktualne położenie kursora (na lewo od  niego); 
               znaczniki przenoszone są w nowe miejsce.
    CTRL/K,Y - usuń blok. Wskoźniki pozostają nie usunięte.
    CTRL/K,W - zapisz blok do pliku na dysku.

   Wielkość  bloku  zależna jest od długości przetwarzanego tekstu  i  rozmiaru 
pamięci operacyjnej.

5.4. OPERACJE NA PLIKACH

   BLOCK MENU kilku operacji na plikach dyskowych bez koniczności wyjścia do NO
FILE MENU.

    CTRL/K,R - czytaj plik  w miejsce wskazane przez kursor.
    CTRL/K,J - usuń plik z dysku.
    CTRL/K,L - zmień nazwę dysku domyślnego.
    CTRL/K,F - przełącznik wyświetlania katalogu dysku.
    CTRL/K,P - wydruk  pliku  na  drukarkę .   Dotychczasowe  poprawki  ulegają 
               zgubieniu
    CTRL/K,O - skopiwanie pliku.
    CTRL/K,E - zmiana nazwy pliku.




********************************  ROZDZIAŁ 6  *********************************



                   INFORMACJE DODATKOWE O REDAGOWANIU TEKSTU

6.1. MENU POMOCNICZE - "HELP MENU"

   WORDSTAR potrafi udzielić  informacji o swoim działaniu. Służy do tego "HELP
MENU". Możliwe do wyświetlenia informacje pomocnicze dotyczą:

    CTRL/J,H - poziomu podpowiadania (HELP MENU) wraz z jego ustawieniem.
    CTRL/J,B - sposobu porządkowania akapitu.
    CTRL/J,F - znaczników linii.
    CTRL/J,D - komend sterowonia wydrukiem (DOT COMMANDS).
    CTRL/J,I - dostępu do poszczególnych komend.
    CTRL/J,S - linii stanu programu.
    CTRL/J,R - LINIJKI i sposobu korzystania z niej.
    CTRL/J,M - sposobu ustawienia marginesów i tabulacji.
    CTRL/J,P - sposobu ustawienia znaczników w tekście.
    CTRL/J,V - sposobu wykonywania operacji na blokach.

6.2. STEROWANIE PRZEBIEGIEM WYKONYWANIA KOMEND

    CTRL/Q,Q - następna komenda będzie powtarzana z prędkością regulowaną przez
               operatora aż do wciśnięcia dowolnego klawisza różnego od cyfry.
    CTRL/U   - przerwanie  wykonywania  dowolnej  komendy .  Również  może  być 
               wciśnięty klawisz ESCAPE.

6.3. REDAGOWANIE PLKOW O TYPIE INNYM NIZ DOKUMENTACYJNY

   Zachodzą tu następujące różnice:
- nie ma możliwości automatycznego wyznaczenia początku nowej strony,
- inna jest linia stanu (patrz opis linni stanu),
- komendy sterujące drukarką są ignorowane,
- nie sosuje się raczej justowania,  przesuwania słów,  zmiennej tabulacji oraz 
  LINIJKI lecz można te funkcje uaktywnić,
- porządkowanie  akapitu  może  być [ródłem błędów  ze  względu  na  ustawienie 
  najstarszego bitu w znakach tekstu,
- w  przypadku  stosowania stałej tabulacji zamiast odpowiedniej liczby  spacji 
  wstawiany jest znak CTRL/I (09H),  będący znakiem identycznym z każdym  innym 
  znakiem alfanumerycznym.





********************************  ROZDZIAŁ 7  *********************************



                             STEROWANIE WYDRUKIEM

   Rozdział  ten  zawiera opis komend i znaków sterujących wydrukiem  pliku  na 
drukarce oraz opis sposobu generacji wydruków.

7.1. ZNAKI STERUJACE WYDRUKIEM

   Są  to  znaki znajdujące się w ^rodku tekstu i mają na celu  zmianę  sposobu 
pracy   drukarki  związanego  z  takimi  funkcjami  jak  zmiana  kroju   pisma, 
podkreślenia,  wytłuszczenia itp.  Wprowadzamy K poprzez wciśnięcie CTRL/P oraz 
znaku odpowiadającego kodowi danej funkcji. Oto spis tych kodów:
    
    CTRL/S   - podkreślenie tekstu znajdującego się pomiędzy znakami CTRL/S.
    CTRL/B   - wytłuszczenie (kilkukrotne wydrukowanie) tekstu pomiędzy znakami
               CTRL/B.
    CTRL/D   - dwukrotne wydrukowanie tekstu między  znakami CTRL/D. Daje  druk 
               jaśniejszy niż druk wytłuszczony.
    CTRL/X   - przekreślenie tekstu  (nadrukowanie znaków "-") pomiędzy znakami 
               CTRL/X.
    CTRL/H   - nadrukowanie następnego znaku na poprzednim.
    CTRL/O   - wprowadzenie do wydruku spacji niewidocznej podczas redagowania.
    CTRL/K   - numer strony drukowany jest z prawej strony dla stron nieparzys-
               tych i z lewej dla stron parzystych.
    CTRL/L   - przejście do nowej strony.
    CTRL/C   - zatrzymanie wydruku np. dla pewnych czynności operatora.
    CTRL/V   - dalszy tekst jest drukowany o połowę linii niżej.
    CTRL/T   - podobnie, lecz o pół linii wyżej.
    CTRL/Y   - zmiana koloru taśmy drukarki.
    CTRL/A   - wybór jednej z dwóch szerokości znaków.
    CTRL/N   - przywrócenie normalnej szerokości znaków.
    CTRL/G   - wydruk kodu (7F#).

7.2. KOMENDY STERUJACE WYDRUKIEM

   Są  to osobne linie wstawiane w tekst,  zaczynające się od  kropki.  Nie  są 
drukowane na papierze lecz sterują sposobem drukowania.

   7.2.1. Format pionowy strony.
   .LH n  ustawienie wysokości czcionki drukarki przy czym 
                   liczba linii na cal = n / 48
          n  jest z zakresu od 1 do 24.                                      
          Standardowa wartość n wynosi 8 (6 wierszy na cal).
   .PL n  ilość linii na stronę. Wartość zainstalowana wynosi 66.
   .MT n  ilość linii między początkiem  strony i początkiem  tekstu.  Domyślna 
          wartość wynosi 3.
   .MB n  ilość linii  pomiędzy  ostatnią linią tekstu na  stronie  a  pierwszą 
          linią następnej strony. Wartość domyślna = 8.
   .HM n  odległość między nagłówkiem a pierwszą linią tekstu mierzoną w ilości 
          pustych linii. Wartość domyślna wynosi 2.
   .FM n  ilość linii pomiędzy linią numeru strony  a ostatnią linią tekstu  na 
          stronie. Wartość domyślna wynosi 2.

   7.2.2. Format poziomy strony.
   .PC n  numer kolumny, w której ma być drukowany numer strony.
   .PO n  ilość spacji przed każdą linią tekstów  na stronie.  Wartość domyślna
          wynosi 8.
   
   7.2.3. Stronicowanie tekstu.
   .PA    bezwarunkowy koniec strony.
   .CP n  jeżeli liczba linii do aktualnego końca strony  będzie mniejsza od n,
          to generuj koniec stony.

   7.2.4. Nagłówek i stopka strony.
   .HE <tekst>  nagłówek  zawierający  <tekst>  będzie  drukowany  na  początku 
          każdej   strony  od  następnej  poczynając.   Wydruk  nagłówka  można 
          zablokować podając pustą komendę .HE . Nagłówek musi  znajdować się w
          obrębie odstępu między początkiem strony, a początkiem tekstu.
   .FO <tekst>  stopka zawierająca  <tekst> będzie  umieszczona na dole  każdej 
          następnej drukowanej strony.  Wydruk stopki można zablokować (komenda
          pusta)  lub zmienić (nowa komenda .FO).  W przypadku  wydruku  stopki 
          numer nie jest drukowany. Podobnie jak dla nagłówka , dla stopki musi
          być zarezerwowane miejsce.

   7.2.5. Sterowanie numeracją stron.
   .OP    zawieś numerowanie stron, gdy nie zdefiniowano linii stopki.
   .PN    przywróć numerowanie stron po komendzie .OP .
   .PN n  rozpocznij  numerowanie  stron od  numeru n.  Liczba n nie  może  być 
          większa od 255.

   7.2.6. Inne komendy.
   .<tekst>  komenda komentarza.   <tekst> nie  jest drukowany,  choć  znajduje 
          się w pliku.
   .CW n  ustaw  szerokość druku,  gdzie szerokość znaku = n/120 cala.  Wartość 
          domyślna wynosi 12.
   .SR n  określenie wysokości  przesunięcia dla trybu dopisywania fraz powyżej 
          lub ponżej linii tekstu na n/48 cala. Wartość domyślna wynosi 3.
   .UJ 0/1  wyłączanie / włączanie  opcji mikrojustowania tekstu.
   .BP 0/1  wyłączanie / włączanie  opcji druku dwukierunkowego.

7.3. CZYNNOSCI PRZY DRUKOWANIU TEKSTU

   Przed właściwym wydrukiem WORDSTAR zadaje operatorowi szereg pytań inicjują-
cych wydruk:
a) NAME OF FILE TO PRINT ?
   Należy podać nazwę drukowanego zbioru w standardowym formacie.
b) DISK FILE OUTPUT ?
   Istnieje możliwość "drukowania na dysk" . Podczas takiej czynności interpre-
   towane są komendy sterujące wydrukiem, a znaki sterujące wydrukiem pozostają
   nie  zmienione. Opcja ta umożliwia wygenerowanie pliku możliwego do wydruko-
   wania bez pośrednictwa WORDSTAR'a.
c) START AT PAGE NUMBER (RETURN for beginning) ?
   Trzeba podać numer strony,  od  której  należy zacząć wydruk.  Można  w  ten 
   sposób wydrukować fragment tekstu. Wartością domyślną jest początek tekstu.
d) STOP AT PAGE NUMBER (RETURN for end) ?
   Należy  podać  numer ostatniej drukowanej strony.  Wartością  domyślną  jest 
   koniec tekstu.
e) USE FORM FEEDS ?
   Odpowiedź twierdząca oznacza, }e zamiast odpowiedniej ilości znaków wysuwu o
   jedną linię, WORDSTAR będzie wysyłał na drukarkę znak wysuwu strony.
f) SUPRESS PAGE FORMATTING ?
   Odpowiedź twierdząca spowoduje pominięcie przez WORDSTAR'a komend określają-
   cych nagłówki, stopki, marginesy oraz nie będą drukowane numery stron. Znaki
   sterujące wydrukiem nie będą pomijane.
g) PAUSE FOR PAPER CHANGE BETWEEN PAGES ?
   Odpowiedź twierdzącą podajemy, gdy używamy pojedynczych arkuszy papieru.
h) READY PRINTER, PRESS RETURN ?
   Należy uaktywnić drukarkę i wcisnąć klawisz ENTER.

   Wydruk  można  przerwać  wciskając klawisz  P.  Wznowienie  następuje  przez 
wciśnięcie  klawisza  N,  zaś  przerwanie całkowite przez  wciśnięcie  klawisza 
CTRL/U.




********************************  ROZDZIAŁ 8  *********************************



                PROGRAM WSPOMAGAJACY REDAGOWANIE KORESPONDENCJI
                                   MAILMERGE

   MAILMERGE jest programem uzupełniającym, który pozwala na generowanie listów
z nazwiskami, adresami lub inną informacją. Jest ona automatycznie wstawiana do
korespondencji  i  może  być  wprowadzona z  klawiatury  lub  z  przygotowanego 
wcześniej  zbioru  dyskowego.  Działanie  programu polega  na  tworzeniu  wielu 
dokumentów skierowanych do różnych adresatów w oparciu o przygotowany za pomocą
WORDSTAR'a   zbiór,   który   zawiera  podstawową  treść  oraz   o   informację 
indywidualizującą każdy dokument.

   ZMIENNE
   Zmienna  to  nazwa fragmentu tekstu,  który może być  różny  dla  rozmaitych 
listów lub innych dokumentów generowanych w oparciu o ten sam zbiór zawierający
podstawową  treść.  Nazwa zmiennej składa się z co najwyżej 39 liter lub cyfr i 
musi  rozpoczynać  się od litery.  Ponadto w nazwach można używać  znaków  "-". 
Nazwy  zmiennych  są używane w komendach programu w celu  przyporządkowania  im 
konkretnych tekstów. Poniżej przedstawiamy kilka przykładów :
   NAZWISKO        
   ADRES1
   DATA-CZAS
Odwołania do nazw są umieszczone w zbiorze zawierającym bazową treść  dokumentu
i   wskazującą  miejsca,   w  których  ma  być  umieszczony   tekst   aktualnie 
przyporządkowany  danym  nazwom.  Odwołanie do nazwy składa się ze  znaku  "&", 
nazwy  zmiennej  i kolejnego znaku "&".  Spacje oraz znaki <CR> znajdujące  się 
pomiędzy znakami "&" i nazwa zmiennej są ignorowane.  Należy tu jednak  zwrócić 
uwagę na fakt,  }e użycie jakiegokolwiek z tych znaków w obrębie nazwy zmiennej 
spowoduje  błąd.   Poniżej  przedstawiamy  kilka  przykładów  odwołań  do  nazw 
zmiennych :
   &NAZWISKO&
   & ADRES &
   & DATA-CZAS &
Długość  tekstu  reprezentowanego  przez zmienną nie może być większa  niż  200 
znaków.
   Zmiennej można przyporządkować tekst za pomocą trzech metod :
   - wykorzystując  specjalny  zbiór  danych,  zawierający  kolejne  "wartości" 
     zminnych;
   - wprowadzając odpowiednie znaki z konsoli;
   - przyporządkowując zmiennej tekst w dokumencie podstawowym lub  dodatkowym, 
     który będzie dołączony podczas generacji.
Zmiennej  należy  nadać  wartość nim nastąpi odwołanie do  niej.  Odwołania  do 
niezdefiniowanych  zmiennych są ignorowane i zostaną wydrukowane w  ostatecznej 
postaci dokumentu wraz ze znacznikami ("&").
   
   ZBIORY DANYCH DLA MAILMERGE

   Zbiory  danych  zawierają  pogrupowane  wartości  zmiennych,  które  zostaną 
wykorzystane  przez  MailMerge podczas generowania kolejnych kopii  listu  (lub 
innych dokumentów). Pojedynczy wiersz takiego zbioru zawiera aktualne  wartości
zmiennych oddzielone przecinkami. Po ostatniej pozycji w wierszu musi znajdować
się znak <CR>.  Można pominąć aktualną wartość zmiennej, należy jednak pamiętać 
o  pozostawieniu odpowiadającego jej przecinka (w wierszu,  w którym  pominięto 
wartość  zmiennej  musi  być zasygnalizowana taka sama  liczba  pozycji  jak  w 
pozostałych wierszach). W przypadku gdy tekst będący wartością zmiennej zawiera
przecinek, spacje poprzedzające pierwszy znak lub następujące po ostatnim znaku
należy  go oznaczać apostrofami (znakami " przed pierwszym i po ostatnim  znaku 
tekstu).
   W  celu przygotownia zbioru danych MailMerge można użyć WordStar'a otwierając 
taki zbiór w trybie (N) lub dowolnego standardowego edytora (np. edytora ED).

   KILKA PRZYKŁADOW

   Przed  szczegółowym  omówieniem  komend MailMerge omówimy  kilka  przykładów 
ilustrujących  sposób  przygotowania zbiorów  zawierających  podstawową  postać 
dokumentu.  Przykłady  te  opisują  sposób,  w jaki należy  umieszczać  kolejne 
komendy sterujące wydrukiem podczas tworzenia takich zbiorów.

Generacja w oparciu o zbiór danych :                                           

    .OP            wyłączenie numeracji stron ;

    .DF filename   definicja nazwy zbioru zawierającego wartości zmiennych  dla 
                   kolejnych listów ;

    .RV zmienna 1, zmienna 2,..., zmienna k
                   wczytanie kolejnych pozycji ze zbioru danych i przyporządko-
                   wanie ich kolejnym zmiennym ;

    treść  listu   kolejne wiersze powinny zawierać treść listu  wykorzystując 
                   odwołania  do zmiennych (& zmienna i &) tam,  gdzie jest  to 
                   potrzebne ;

    .PA            przesunięcie  papieru  w drukarce  do  nowej  strony  przed 
                   rozpoczęciem drukowania następnego listu ;

Generacja w oparciu o dane wprowadzone z konsoli :

    .OP            wyłączenie numeracji stron ;

    .CS            wymazanie  zawartości ekranu przed  rozpoczęciem  zadawania 
                   pytań o kolejne wartości zmiennych ;

    .AV "komunikat", zmienna 1
    .AV "komunikat", zmienna 2
    .....
    .AV "komunikat" zmienna k
                   wyświetlanie  komunikatów  na ekranie i  wczytanie  wartości 
                   zmiennej ;

    treść listu    kolejne wiersze powinny zawierać treść listu, wykorzystując
                   odwołania  do zmiennych (& zmienna i &) tam,  gdzie jest  to 
                   potrzebne ;

    .PA            przesunięcie  papieru  do nowej  strony  przed  drukowaniem 
                   następnego listu ;

    .FI filename   gdy wyspecyfikowana nazwa jest nazwą opisywanego tu zbioru,
                   komenda ta spowoduje wygenerowanie kolejnego listu (listy te
                   będą generowane tak długo, jak długo działanie MailMerge nie
                   zostanie przerwane).

Wydrukowanie zbioru danych :

    .DF filename   definicja nazwy zbioru danych, który będzie drukowany ;

    .RV zmienna 1, zmienna 2,..., zmienna k
                   wczytanie kolejnych pozycji ze zbioru danych i przyporządko-
                   wanie ich wskazanym zmiennym ;

    .CP  k         przesunięcie   papieru  do nowej  strony,  o  ile  wszystkie 
                   wczytane teksty nie zmieszczą się na bieżącej stronie ;

    & zmienna 1&   
    & zmienna 2&
    .....
    & zmienna k&   odwołania do zmiennych spowodują wydrukowanie ich aktualnych
                   wartości (tekstów odpowiadających im w danej chwili).

Wczytanie pojedynczego paramrtru dla wielu listów :

    .AV "komunikat", zmienna
                   komenda ta spowoduje wczytanie pojedynczej zmiennej ;

    .FI filename   wczytanie zbioru o wyspecyfikowanej nazwie.  Zbiór ten  może 
                   zawierać również komendy dla MailMerge (w szczególności może
                   on być zbudowany według z poprzednio omówionych zasad)  oraz
                   odwołania  do zmiennej,  której wartość wczytano przy pomocy 
                   komendy .AV .

Wczytanie z konsoli nazwy zbioru :

    .AV "Dokument:", DOCFILE
    .AV "Dane:", DATFILE
                  powyższe komendy powodują wczytanie z konsoli wartoćci  dwóch 
                  zmiennych : DOCFILE i DATFILE ;

    .FI  &DOCFILE&    wczytanie  zbioru  o  nazwie  podanej  przez  opertora  w 
                  odpowiedzi  na pytanie o wartość pierwszej zmiennej ;  jeżeli 
                  zbiór  ten  zawiera komendę .DF  &DATFILE&  wówczas  zostanie 
                  wygenerowany  zestaw listów w oparciu o zbiór,  którego nazwę 
                  podał  operator  w odpowiedzi na pytanie  o  wartość  drugiej 
                  zmiennej

   KOMENDY DOT GENERATORA MAILMERGE

   Przedstawiamy  teraz  szczegółowy  opis komend  wykonywanych  przez  program 
MailMerge. Postać tych komend jest identyczna jak komend sterujących  wydrukiem
w programie WORDSTAR.
   Komendy sterujące procesem generacji korespondencji :
   Ta  grupa  komend  służy do nadawania wartości zmiennym  oraz  do  tworzenia 
ostatecznej postaci generowanej korespondencji.

    .DF <filename> CHANGE
                   określenie   zbioru  danych  zawierającego  zestaw  wartości 
                   zmiennych,  który  ma być użyty do generowania danej  partii 
                   listów. Komenda ta może również zawierać opcjomalny parametr
                   CHANGE  podany po nazwie zbioru i odzielony od niej  spacją. 
                   Umożliwia  on  wymianę  dysków,   gdy  nie  można   zapewnić 
                   równoczsnej dostępności zbiorów tekstowych i zbiorów danych.

    .RV var 1,..., var k
                   nadawanie   wartości   zmiennym   i   definiowanie   sposobu 
                   uporządkowania   zbioru   danych.   Lista   zmiennych   musi 
                   odpowiadać  ilości  pozycji i ich uporządkowaniu  w  zbiorze 
                   danych.

    .RP  n         definicja,ile razy dany dokument ma być przetwarzany. Jeżeli
                   pominięto   parametr  n  wówczas  proces  generacji   będzie 
                   powtarzany  aż  do wyczerpania zbioru  danych.  Komenda  .DF 
                   implikuje komendę .RP bez parametru n.  Tak więc komenda .RP 
                   jest niezbędna tylko wtedy,  gdy chcemy wielokrotnie wstawić 
                   inny dokument do podstawowego tekstu.

    .SV var, val   nadanie wartości zmiennej.Po jej wykonaniu zmiennej zostanie
                   przypisana pozostała część wiersza.

    .AV "msg", var, igth
                   wczytanie z konsoli wartości zmiennej.  Komunikat "msg" jest 
                   opcjonalny.   Zawarty   w  apostrofach  komunikat   zostanie 
                   wyświetlony  na ekranie przed wczytaniem wartości  zmiennej. 
                   Opcjonalny parametr igth określa maksymalną długość  tekstu, 
                   który zostanie wczytany.

    .DM msg        wyświetlenie pozostałej części wiersza na ekranie.

    .CS msg        wymazanie ekranu i wyświetlenie pozostałej części wiersza.

    .FI filename CHANGE
                   wczytanie  zdefiniowanego zbioru do generowanego  dokumentu. 
                   Treść tego zbioru jest umieszczona w miejscu, gdzie znajduje
                   się komenda .FI . Jeżeli wyspecyfikowany zbiór zawiera jedną
                   z  komend  :  .DF  ,  .RV lub .RP  ;  wczytywanie  może  być 
                   powtarzane wielokrotnie.
