.PO 10
WWW       WWW                                                 DDD
WWW       WWW                                                 DDD
WWW       WWW                                                 DDD
WWW       WWW                                                 DDD
WWW       WWW                                                 DDD
WWW  WWW  WWW         OOOO         RR  RRRRRR         DDDDDDDDDDD
WWW WWWWW WWW      OOOOOOOOOO      RR RRRRRRRR      DDDDDDDDDDDDD
WWWWWW WWWWWW     OOOO    OOOO     RRRR    RRR     DDDD       DDD
WWWWW   WWWWW     OOO      OOO     RRR             DDD        DDD
WWWW     WWWW     OOOO    OOOO     RRR             DDDD       DDD
WWW       WWW      OOOOOOOOOO      RRR              DDDDDDDDDDDDDD
WW         WW         OOOO         RRR                DDDDDDDDDDDD



   SSSSSSS            TTT
 SSSSSSSSSSS          TTT
SSSS      SSS         TTT
SSS                   TTT
SSSS                  TTT            
 SSSSSSSSS        TTTTTTTTTTT         AAAAAA   AAA     RR  RRRRRR 
   SSSSSSSSS      TTTTTTTTTTT       AAAAAAAAAA AAA     RR RRRRRRRR
         SSSS         TTT          AAAA    AAAAAAA     RRRR    RRR
          SSS         TTT          AAA       AAAAA     RRR           
SSS      SSSS         TTT          AAAA    AAAAAAA     RRR        
 SSSSSSSSSSS           TTTTTT       AAAAAAAAAA AAA     RRR        
   SSSSSSS              TTTTTT        AAAAAA   AAA     RRR











   P O D R E C Z N I K      U Z- Y T K O W A N I A      " V-20 "




                =================================
                *                               *
                *   NA  KOMPUTER  B O S M A N   *
                *                               *
                =================================












                                                   .
                                  GZE-UNIMOR    GDANSK  1990-11-28
.FO WordStar - podręcznik użytkowania                          str. #

WordStar - podręcznik użytkowania                

                             ROZDZIAŁ 1               
                            WPROWADZENIE               
                          ================                           
W rozdziale tym  wyjaśnimy , w jaki sposób należy wywoływać system
WordStard  oraz  opiszemy komendy , których można używać  pomiędzy
kolejnymi zadaniami edycji zbiorów. Rozdział ten zawiera wszystko, 
co użytkownik powinien wiedzieć przed rozpoczęciem edycji tekstów.

                       WYWOŁYWANIE PROGRAMU                                   
                       --------------------
Przed wywołaniem programu należy:                      
  - Wygenerować  dysk , na którym znajdą się następujące  zbiory : 
    WS.COM /Lub zbiór o innej nazwie utworzony podczas instalacji/
    WSMSGS.OVR
    WSOVLY1.OVR
    MAILMRGE.OVR   /Opcjonalnie , gdy chcemy użyć tego generatora/ 
  - Zapoznać  się  z  procesem  instalacji  systemu  WordStar  dla 
    mikrokomputera  IMP-85 / IMP-86  oraz  wprowadzić  odpowiednie 
    poprawki o ile są one konieczne.

Ogólnie wywołanie programu ma postać: WS <s:> < FILENAME.TYP> <d:>
gdzie:  <s:>  jest  opcjonalnym identyfikatorem  dysku , na którym 
        znajduje się zbiór tekstowy.
        <FILENAME.TYP>  jest nazwą zbioru tekstowego, który ma być 
        przetwarzany  /nazwa zbioru ma do 8 znaków , a typ do 3 /.
        <d:> jest opcjonalnym identyfikatorem dysku , na którym ma 
        zostać wygenerowany poprawiony zbiór tekstowy.

Najprostszym  sposobem  wywołania  jest  podanie  wyłącznie  nazwy 
programu  "WS" /lub innej o ile program został przemianowany  pod
czas  instalacji/. Wówczas WordStar wyświetli , tak zwane "NO-FILE 
MENU" zawierające  zestaw  komend nie  zwiazanych  bezpośrednio  z 
edycją zbiorów tekstowych.             Na przyklad:  A>WS <RETURN>

Umieszczenie nazwy zbioru w wywołaniu programu  powoduje automaty
czne rozpoczęcie jego edycji.     Na przyklad:  A>WS B:LITERKI.DOC 
<RETURN> spowoduje rozpoczęcie edycji zbioru LITERKI.DOC znajdują
cego się na dysku w bramce B. 

Ostatnia metoda wywołania jest użyteczna w przypadku edycji bardzo 
dużych zbiórow , które nie mogą być przetwarzane na jednym dysku z 
uwagi  na zbyt małą jego pojemność . Wówczas  drugi  identyfikator 
dysku określa gdzie ma być umieszczony zbiór zawierający poprawio
ny  tekst. Po dwukropku znajdującym się za  identyfikatorem  dysku 
nie wolno wpisać }adnego znaku / nawet spacji /.      Na przyklad:
A> WS B:LITERKI.DOC C: <RETURN> spowoduje rozpoczęcie edycji zbio
ru  LITERKI.DOC znajdującego się na dysku w bramce B i  zachowanie 
tego zbioru po zakończeniu edycji na dysku w bramce C . Oraz prze
mianowanie go na LITERKI.BAK na dysku w bramce B.

                           KODY FUNKCJI
                           ------------
WordStar  potrafi  operować  wszystkimi  128-ma  znakami  alfabetu 
ASCII . Część  z nich jest wykorzystana jako kody funkcji sterują
cych. Są to najczęściej znaki , których wprowadzenie wymaga równo
czesnego  naciśnięcia dwóch klawiszy:  klawisza  oznaczonego  jako 
"CTRL"  oraz   jednego   klawisza   ze   znaków  alfanumerycznych.
W niniejszym opracowaniu zamiast symbolu "CTRL" używamy znaku "^".
Tak  więc  należy  pamiętać , }e symbol np. ^Z oznacza równoczesne 
naciśnięcie dwóch klawiszy: CTRL i Z . Dla niektórych kodów steru
jących  istnieją pojedyńcze klawisze  je  reprezeniujące . Wówczas 
opis   takiego   klawisza   znajduje  się   w  nawiasach   "<..>".

                         KOMENDY WSTEPNE
                         ---------------
Po  wywołaniu ,  w którym nie określono nazwy zbioru lub po zakoń
czeniu  edycji WordStar wyświetla  w linii na górze ekranu komuni
kat "editing no file" oraz zestaw komend wstępnych tzw.  "NO  FILE 
MENU" . Poniżej  opisu  komend wstępnych wyświetlany jest  katalog 
aktualnie wybranego /dowolnego/ dysku.  
Aby  wybrać  funkcję należy nacisnąć  klawisz  jej  odpowiadajacy. 
Litera  odpowiadająca funkcji zostanie wyswietlona w lewym  górnym 
rogu  ekranu i  natychmiast  rozpoczyna  się wykonywanie  komendy.

          WordStar wykonuje następujące komendy wstępne:
          ----------------------------------------------
                  Komendy ogólnego zastosowania:
                  ------------------------------
Zmień  dysk domyślny <L> . Funkcja ta służy do zmiany dysku domyś
lnego . Użycie jej umożliwia również wyswietlenie zawartości kata
logu innego dysku niż aktualnie wybrany . Po wybraniu tej funkcji, 
na  ekranie jest wyświetlany identyfikator dysku  domyślnego  oraz 
pytanie  o  nowy  dysk domyślny . W celu zmiany  dysku  domyślnego 
należy wpisać literę odpowiadającą danemu dyskowi oraz dwukropek i 
nacisnąć <RETURN>.

Ustaw tryb wyświetlania katalogu dysku <F>. Komenda  ta  umożliwia 
włączanie i wyłączanie  katalogu dysku . Działanie jej jest oparte 
na zasadzie przełącznika tj. pierwsze naciśnięcie F powoduje wyłą
czenie  opcji wyświetlania katalogu , druge naciśnięcie włączenie, 
kolejne ponowne wyłączenie itd. Komenda ta nie wymaga wprowadzenia 
}adnych dodatkowych informacji. 

Ustaw  poziom HELP <H> . Komenda ta umożliwia zmianę  wyświetlanej 
informacji  pomocniczej o funkcjach WordStara dostępnych  w  danym 
momencie . Jeżeli  ustawiony jest poziom "0" wówczas nie jest wyś
wietlane  objaśnienie   działania  wszystkich  poziomów  " HELP ".
W  celu zmiany poziomu należy wpisać odpowiednią liczbę z  zakresu 
od 0 do 3 . Poniżej omówiono własności wszystkich poziomów "HELP".
Poziom  3 - zapewnia wyświetlanie całej informacji  niezbędnej  do 
wykonania  dowolnej  funkcji  i obejmuje  wyświetlanie  wszystkich 
spisów  komend , informacji o redakcji wszystkich komunikatów kie
rowanych  do programu < np. podczas wpisywania nazwy zbioru > oraz 
kilkuwierszowych objaśnień do dużej części komend.
Poziom  2 - różni się od poziomu  3 usunięciem z  ekranu  głównego 
spisu komend używanych podczas edycji tekstu tzw. "MAIN MENU", nie 
zmienia   natomiast   pojawienia   się   informacji   pomocniczej.
Poziom  1 - na tym poziomie nie są wyświetlane }adne spisy  komend 
WordStara , natomiast  w  dalszym ciągu są  wyświetlane  niezbędne 
opisy  bardziej skomplikowanych  funkcji  podczas ich wykonywania.
Poziom  0 - poziom ten eliminuje całą informację  dodatkową kiero
waną do  użytkownika poza  pytaniami czy  komunikatami o  błędach.

                    Komendy inicjujące edycję
                    -------------------------
Otwórz  zbiór tekstowy <D>. Komenda ta służy do rozpoczęcia edycji 
zbioru tekstowego . Podana  w odpowiedzi nazwa zbioru dotyczy  za
równo zbioru istniejącego jak i nowo tworzonego.

Otwórz zbiór inny niż tekstowy <N>. Komenda ta umożliwia rozpoczę
cie  edycji  zbiorów innych niż tekstowe  np.  zbiorów  [ródłowych 
zawierających programy . W dalszych partiach niniejszego opracowa
nia zostanie wyjaśniona szczegółowo różnica pomiędzy zbiorami typu 
tekstowego i nietekstowego. Otwieranie zbioru nietekstowego odbywa 
się identycznie jak zbioru tekstowego.

                  Komendy działające na zbiorach
                 ------------------------------
P  Drukuj zbiór . Komenda ta służy do inicjacji drukowania  zbioru 
   tekstowego . Po rozpoczęciu drukowania każde następne naciśnię
   cie P spowoduje wstrzymanie drukowania, a kolejne naciśnięcie P 
   kontynuację wydruku. Komenda ta zostanie szczegółowo omówiona w 
   następnych rozdziałach.
E  Przemianuj zbiór. Komenda ta umożliwia zmianę nazwy zbioru. Jej 
   działanie  jest  identyczne jak rozkazu REN  systemu  CP/M  lub   
   PC-DOS . WordStar pyta się o nazwę zbioru do przemianowania , a 
   następnie o nową nazwę tego zbioru. W nazwie zbioru można umie
   ^cić identyfikator dysku , na którym ma  być wykonana operacja.
D  Kopiuj zbiór . Komenda ta umożliwia skopiowanie zbioru bez uży
   cia  systemu operacyjnego . Zbiory mogą być kopiowane z jednego 
   dysku na drugi. WordStar pyta najpierw o nazwę zbioru, który ma 
   być kopiowany a następnie o nazwę zbioru docelowego. W przypad
   ku, gdy zbiór docelowy już istnieje na ekranie wyświetlany jest 
   komunikat informacyjny o tym, wraz z pytaniem, czy stary  zbiór 
   zastąpić nowym. Przy podaniu nazwy zbioru nie można używać zna-
   ków "*" lub "?" jak to ma miejsce w systemie CP/M  lub  PC-DOS.
Y  Usuń zbiór z dysku . Działanie tej komendy jest identyczne  jak 
   komendy  ERA systemu CP/M lub DEL systemu PC-DOS . W odpowiedzi 
   na to pytanie  należy  podać nazwę zbioru i nacisnąć  <RETURN>.

                           Opcje WordStara
                           ---------------
M  Uruchom  generator  MAILMERGE . Komenda ta służy  do  wywołania 
   programu  mieszającego dane ze zbiorami tekstowymi podczas dru
   kowania  zbiorów . Przed  jej użyciem  należy sprawdzić, czy na 
   dysku z WordStarem znajduje się zbiór MAILMRGE.OVR . Opis dzia
   łania tego programu znajduje się w dalszej części opracowania .
S  Sprawdż poprawność wprowadzonego tekstu. Opcja ta jest sprzeda-
   wana  jako osobny program i nie będzie przedmiotem opracowania.

                          Komendy systemowe
                          -----------------
R  Wykonanie programu. Komenda ta umożliwia wykonanie innego prog
   ramu obok WordStara . Poza nazwą programu wywołanie może zawie
   rać również dodatkowe parametry. Po wykonaniu programu na ekra
   nie  zostanie wyświetlony komunikat "hit any key to  return  to 
   WordStar" . Po naciśnięciu dowolnego klawisza na ekranie pojawi 
   się  ponownie główne MENU WordStara . Pozwala to na  obejrzenie 
   wyników  działania   programu  przed  powrotem  do   WordStara.
X  Powrót do systemu operacyjnego . Komenda ta jest wykorzystywana 
   do zakończenia działania WordStara.
                      .        .
                   CZESCIOWE WYSWIETLANIE KATALOGU
                   -------------------------------
W  przypadku gdy na dysku znajduje się wiele zbiorów , na  ekranie 
pokazana  jest tylko część z nich . W celu obejrzenia  pozostałych 
zbiorów  należy  użyć ^Z w celu przesunięcia  wyświetlanej  części 
katalogu  o  wiersz w górę lub ^W o wiersz w  dół .  Spowoduje  to 
ukazanie  się nowej linii  zawierającej  opisy zbiorów na ekranie.

                     ODPOWIADANIE NA PYTANIA
                     -----------------------
Wiele  komend powoduje pojawienie się na ekranie dodatkowych pytań
o  informacje  pomocnicze . Niektóre z nich wymagają odpowiedzi  w 
postaci  jednego  znaku , niektóre  zaś  wieloznakowej  informacji 
zakończonej przez naciśnięcie klawisza <RETURN> . Wszystkie jednak 
umożliwiają przerwanie aktualnie wykonywanej komendy przez  naciś
nięcie klawisza <ESC> lub ^U.

                     Odpowiedzi jednoznakowe
                     -----------------------
Pytania  wymagające  jednoznakowej odpowiedzi można  łatwo  rozpo
znać. Kończą się one zawsze dwukropkiem. Odpowiedz jest przyjmowa
na natychmiast, bez  czekania na klawisz <RETURN> . Pewne  pytania 
kończą się zadaniem akceptacji lub negacji "...(Y/N):". W odpowie
dzi na nie należy podać "Y" gdy odpowiedź jest twierdząca. Podanie 
"N"   lub   jakiegokolwiek  innego  klawisza  powoduje   negatywną 
odpowiedż na zadane pytanie.

                     Odpowiedzi wieloznakowe
                     -----------------------
Pytania  wymagające długiej odpowiedzi kończą się  zawsze  znakiem 
zapytania. Podczas wprowadzenia długiej odpowiedzi popełniony błąd 
można skorygować za pomocą następujących znaków:
  ^Y   usuń wprowadzony komunikat (również ^X )
  ^S   usuń ostatnio wprowadzony znak (również ^H,<BS>,<DEL>),
  ^D   przesuń  kursor w prawo .  Odpowiedni znak poprzednio  usu-
       niętego komunikatu ulega odtworzeniu,
  ^R   odtwórz poprzednio usunięty komunikat . Umożliwia to powie-
       lenie odpowiedzi na kolejne pytania,
  ^F   wyświetl katalog dysku domyślnego,
  ^Z   przesuń wyświetlony katalog dysku o wiersz w górę,
  ^W   przesuń wyświetlony katalog dysku o wiersz w dół,
  ^P   nie traktuj następnego znaku wprowadzonego komunikatu jako 
       znaku sterującego.
Akceptacja   komunikatu  następuje  przez  naciśnięcie   klawisza 
<RETURN> lub <LF>.

                            ROZDZIAŁ 2
                 ZAWIERAMY ZNAJOMOSC Z WORDSTAREM
               ====================================
W  rozdziale tym przedstawimy informacje , które są niezbędne  dla 
zrozumienia, w jaki sposób jest prowadzona redakcja tekstu poprzez
system WordStar , oraz w jaki sposób posługiwać się tym  systemem.
                      .
                   ZBIOR TEKSTOWY I NIETEKSTOWY
                   ----------------------------
Jak wspomniano w poprzednim rozdziale istnieją dwa sposoby  rozpo
częcia  edycji  zbioru . Edycja zbioru tekstowego i  nietekstowego 
niczym  się  nie  różni zarówno w  aspekcie  sposobu  wprowadzenia 
informacji jak i struktury zbioru . Różnice występują natomiast  w 
wykorzystaniu specjalnych udogodnień stwarzanych przez  WordStara,
ukierunkowanych na redakcję wszelkiego rodzaju dokumentów . Udogo
dnienia  te nie mają zastosowania w przypadku np.  wprowadzenia  i 
poprawiania programów , a wręcz przeciwnie mogą stać się przyczyną
poważnych błedów syntaktycznych.
                           .
                   KILKA SŁOW O FORMACIE EKRANU
                   ----------------------------
Podczas  edycji zbioru na ekranie jest wyświetlany nie tylko reda
gowany tekst, ale również informacja pomocnicza oraz dane o stanie 
WordStara . W  górnym wierszu ekranu wyświetlana jest  tzw.  linia 
statusu zawierająca opis aktualnego stanu edycji . Poniżej , osiem 
kolejnych wierszy zajmuje spis aktualnie dostępnych komend (o  ile 
jest on wyświetlany na aktualnie ustawionym poziomie "HELP"),nazy
wany  dalej MENU . W kolejnym wierszu na ekranie znajduje się tzw. 
"linijka"  wskazująca ustawienie prawego i lewego  marginesu  oraz 
pozycje , w  których zatrzymuje się kursor po naciśnięciu klawisza 
<TAB> lub <HT>. Znajdująca się poniżej "linijki" część ekranu jest 
przeznaczona na redagowany tekst. Zarezerwowana jest ponadto skra
jna prawa kolumna na ekranie. Są w niej wyświetlane znaki określa
jące  rodzaj  informacji  w danym wierszu . Noszą one nazwę  flag.
                     .
                   OGOLNE ZASADY PISANIA TEKSTU
                   ----------------------------
W przypadku pracy ze zbiorem tekstowym WordStar wykonuje automaty
cznie szereg funkcji redakcyjnych . Pisanie zaczyna się zawsze  od 
lewego marginesu. Do zbioru można wpisywać wszystkie znaki alfanu
meryczne . Kiedy przekroczony zostanie   prawy margines  następuje 
automatyczne  przeniesienie  oststnio  napisanego słowa  do  nowej 
linii . Ta  własność nazywa się "przerzucaniem"  słów  (ang.  word 
wrap) . Jednocześnie następuje takie wstawienie spacji do poprzed
niej linii aby został zachowany zarówno lewy jak i prawy margines. 
Proces  ten nosi nazwę justowania tekstu . Justowanie zachodzi  na 
sciśle określonym obszarze, którego granicą jest  koniec  akapitu. 
Jest  on  zaznaczony przez naciśnięcie  klawisza <RETURN>. Oznacza 
to, }e każdorazowe użycie tego klawisza spowoduje przerwanie reda
gowania  i  co za tym idzie pozostawienie  niewyrównanego  prawego 
marginesu  w danej linii . Wszystkie końce akapitów są  zapamięty
wane , tak więc późniejsze  próby  przeredagowania tekstu zakończą 
się  niepowodzeniem  o  ile linie  kończono  za  pomocą  <RETURN>.

                      Poprawianie dokumentu
                      ---------------------
W celu wprowadzenia poprawek do dokumentu należy umieścić kursor w 
zadanym miejscu i rozpocząć wpisywanie nowego tekstu . Piszący  ma 
tu dwie możliwości:  pisanie na tekście już wprowadzonym (zastępo
wanie jednych znaków  innymi) lub wstawienie znaków pomiędzy tekst 
już wprowadzony. Podobna sytuacja ma miejsce przy usunięciu znaków 
lub słów . Można je usunąć zarówno "w prawo" jak i "w lewo" . Usu
nięcie  znaku "w prawo" polega na wymazaniu znaku znajdującego się 
w  pozycji  kursora  i lewostronnym dosunięciu  pozostałej  części 
linii , tak }e kursor wskazuje teraz następny znak . Usunięcie  "w 
lewo" oznacza wymazanie znaku znajdującego się na lewo od  kursora 
i lewostronne dosunięcie pozostałej części linii. Istnieje również 
możliwość usuwania całych slów z tekstu. Wprowadzone poprawki mogą 
spowodować odstępstwa od zasady wyrownywania marginesów. Aby przy
wrócić  prawy margines należy ustawić kursor na początku poprawia
nego akapitu i wykonać funkcję przeredagowania akapitu (ang. para
graf  reform) . Poza przywróceniem marginesów  funkcja ta  stwarza 
możliwość  pół automatycznego  przenoszenia  słów . Polega  to  na 
wskazywaniu  redagującemu  przez WordStara  możliwości  wstawienia 
znaku  przenoszenia  w długie słowo , o ile nie mieści się  ono  w 
linii . Propozycja  ta  może zostać zaakceptowana  po  ewentualnej 
zmianie pozycji znaku przeniesienia lub odrzucona . WordStar stwa
rza  oczywiście  takie możliwości jak wtrącenie pustej  linii  czy 
utworzenie w tekście nowego akapitu.

                     Podział tekstu na strony
                     ------------------------
Innym  istotnym ustaleniem oferowanym użytkownikowi WordStara jest 
automatyczne  wskazywanie końca strony podczas edycji . W  miejscu 
odpowiadającym  końcowi  strony jest wyświetlana  specjalna  linia 
wskazująca, }e tekst od tego miejsca będzie drukowany na następnej 
stronie . Spósob  w  jaki WordStar wyznacza końce kolejnych  stron 
zależy  od  ustalenia pewnych parametrów  związanych  ze  sposobem 
drukowania , które omówimy później.
                       Przeglądanie tekstu
                       -------------------
W przypadku gdy redagowany przez nas  dokument nie  mieści się  na 
ekranie  WordStar zapewnia możliwość  jego przeglądania . Slużą do 
tego  funkcje polegające na "podrzucaniu" ekranu w dół lub w górę. 
Proces  ten nosi nazwę scrollingu . Dopuszczalne jest  przesuwanie 
tekstu zarówno o pojedynczy wiersz jak i o cały  ekran . Umożliwia 
to szybkie przeglądanie dużych dokumentów.

                  Dokumenty o długich wierszach
                  -----------------------------
Dotychczas mówiliśmy wyłącznie o takich dokumentach , których sze
rokość była mniejsza od szerokości ekranu . W przypadku gdy szero
kość naszego dokumentu przekracza szerokość ekranu WordStar reali
zuje  tzw . poziomy scrolling . Polega on na przesuwaniu ekranu  w 
poziomie po dokumencie . Kolumny z lewej <prawej> strony ekranu są 
usuwane z ekranu , następuje lewostronne <prawostronne> dosunięcie 
tekstu  do krawedzi ekranu i wypisanie na ekranie kolejnej  partii 
wiersza . Tekst  usunięty z ekranu nie znika z naszego  dokumentu. 
Ponowne przesunięcie  kursora w przeciwnym kierunku spowoduje , }e 
pojawi się on znowu.
                           .
                  KOMENDY UZYWANE PODCZAS EDYCJI
                  ------------------------------
Przeważająca część znaków  innych niż drukowalne jest  wykorzysty
wana  przez WordStara do celów sterowania . Znaki takie są genero
wane przez równoczesne naciśnięcie dwóch klawiszy:  CTRL oraz kla
wisza alfanumerycznego. Są to komendy WordStara. Ponieważ WordStar 
wykonuje  o wiele więcej komend niż jest znaków  sterujących  nie
ktore  z  nich są opisywane przez kody dwuznakowe . Pierwszy  znak 
nazywany jest przedrostkiem komendy i wskazuje jedną z pięciu grup 
komend . Po zadaniu  przedrostka komendy (jeden ze znaków: ^Q, ^J, 
^K,^O lub ^P) WordStar czeka na drugi znak i wyświetla spis komend 
z  danym  przedrostkiem tzw. PREFIX MENU ( o ile  aktualny  poziom 
"HELP" na to zezwala ) . Jeżeli przedrostek  komendy został zadany 
przypadkowo lub przez pomyłkę wystarczy nacisnąć spację lub dowol
ny  inny  znak nie zdefiniowany  w danym spisie , i w  ten  sposób 
skasować komendę . W dalszych partiach tego rozdziału przedstawimy 
krótko wszystkie grupy komend dwuznakowych . Ponadto WordStar roz
poznaje komendy umieszczone  na trwałe w zbiorze . Są one związane 
przede  wszystkim z organizacją  wydruku z nagłówkami i  numeracją 
stron oraz efektami specjalnymi podczas drukowania . Komendy takie 
charakteryzują  się tym , }e  rozpoczynają się zawsze  od  kropki. 
Będziemy je nazywali komendami DOT.

                 Komendy szybkie (QUICK MENU): ^Q
                 --------------------------------
Komendy  należące do tej grupy słuą  do szybkiego  przemieszczania 
kursora po dokumencie, wielokrotnego wykonywania tej samej funkcji 
oraz przeszukiwania tekstu.

    Komendy działające na partiach dokumentu (BLOCK MENU): ^K
    ---------------------------------------------------------
Ta  grupa komend służy do wykonywania operacji na większych  frag
mentach  dokumentu , na całych dokumentach oraz na zbiorach dysko
wych. W szczególności komendy z tej grupy są wykorzystywane w celu 
zakończenia edycji i zachowania poprawionych dokumentów  na dysku. 

    Komendy redakcji dokumentu na ekranie (ONSCREEN MENU): ^O
    ---------------------------------------------------------
Komendy  te służą do określenia formatu dokumentu ( np.  szerokość 
strony, ustawienia prawego i lewego marginesu, pozycji tabulacji ) 
oraz określają szereg parametrów  związanych z automatycznym reda
gowaniem tekstu.

           Komendy sterujące wydrukiem (PRINT MENU): ^P
           --------------------------------------------
To  menu opisuje zbiór znaków specjalnych używanych do  sterowania 
wydrukiem na drukarce oraz przynosi informację o efektach specjal
nych  jakie  można  używać podczas drukowania  zbioru , a które są 
niewidoczne podczas edycji dokumentu na ekranie.

     Komendy sterujące informacją pomocniczą (HELP MENU): ^H
     -------------------------------------------------------
Komendy  należące do tej grupy umożliwiają zmianę aktualnie  usta
wionego  poziomu  HELP  oraz wyświetlają na  }ądanie  opisy  zasad 
działania poszczególnych funkcji WordStara.

                          LINIA STATUSU
                          -------------
Podczas edycji linia statusu zawiera następujące dane:
- komendę ( jezeli takowa jest aktualnie wykonywana ),
- nazwę zbioru,
- aktualny adres kursora,
- dodatkowe wskaźniki.
Aktualnie  wykonywana komenda jest wyświetlana w postaci kodu zna
kowego  w  lewym górnym rogu ekranu . Jeżeli zadano kilka  komend, 
wówczas wszystkie one są wyświetlane w odpowiednim porzadku. Wyją
tkiem  są  jednoznakowe  komendy służące do  poruszania  kursorem, 
które nigdy nie są wyświetlane . Nazwa zbioru jest  wyświetlana na 
ekranie dopóki jest wystarczająco dużo miejsca w linii statusu . W 
przypadku  gdy  wskaźniki dodatkowe i informacja adresowa są  zbyt 
długie , wówczas jest ona usuwana z ekranu. Aktualny adres kursora 
jest wyświetlany w dwóch możliwych postaciach:
Dla zbioru tekstowego:                      PAGE pp LINE ll COL cc
gdzie:   PAGE określa numer strony, na której znajduje się kursor.
         LINE określa numer linii na stronie ,  na której znajduje 
              się kursor.
         COL  określa numer kolumny, w której znajduje się kursor.
    
Wszystkie te dane dotyczą postaci dokumentu, która będzie drukowa
na , a nie aktualnej  pozycji  kursora na ekranie .  Ponadto numer 
strony może mieć wzgledny charakter ( tj. numer strony od  pewnego 
miejsca w dokumencie ) ponieważ WordStar dopuszcza przenumerowanie 
stron podczas wydruku. 
Dla zbioru nietekstowego:                          FC=ccc   FL=lll
gdzie:  FC   określa  numer znaku w zbiorze , liczony od  poczatku 
             zbioru plus jeden , uwzględniając  wszystkie znaki CR 
             i LF znajdujące sie w zbiorze.
        FL   określa  numer  linii w zbiorze liczony  od  początku 
             zbioru niezależnie od zawartości linii.

Wskaźniki dodatkowe wskazują na wystepowanie warunków:
WAIT            Wskazuje , }e WordStar  wykonuje operację dyskową.
                Należy wówczas wstrzymać się z pisaniem , ponieważ
                znaki mogą być gubione.
MAR REL         Wskazuje, }e w chwili obecnej można wpisywać tekst 
                przed  i  za  aktualnie  ustawionymi  marginesami.
DECIMAL         Wskazuje , }e  znajdujemy się w punkcie  tabulacji 
                dziesiętnej  ( wprowadzane znaki są  przesuwane  w 
                lewo ).
INSERT ON       Wskazuje , }e aktualnie obowiązuje tryb wstawiania 
                znaków. Oznacza to, }e znaki  które  piszemy  będą 
                wstawiane w uprzednio wpisany tekst.
LINE SPECING n  Wskazuje , }e  aktualnie  jest   ustawiony  odstęp 
                międzyliniowy równy n (różny od 1).
PRINT PAUSED    Wskazuje , }e wydruk na drukarce został wstrzymany 
                (z uwagi na zadanie drukującego, np. w celu zmiany 
                papieru  po  zakończeniu  każdej  strony  druku) .
REPLACE (Y/N):  Pytanie to ukazuje się każdorazowo ,  gdy  używamy 
                komendy zamiany łańcuchów znaków.

                             LINIJKA
                             -------
Bezpośrednio powyżej tekstu, znajduje się specjalny wiersz opisuj
`cy  w  pewnym  stopniu format dokumentu , nad  którym  pracujemy. 
Pokazuje ona aktualne ustawienie prawego i lewego marginesu (ozna
czone  literami  R i L) oraz szerokość linii . Ponadto  za  pomocą 
znaków "!" i "#" wskazuje ona aktualnie ustawione pozycje tabulac
ji (miejsca, w których zatrzyma się kursor po naciśnięciu klawisza 
<TAB> lub  ^I . Pozycje tabulacji dziesiętnej są oznaczone znakiem 
"#" . Poszczególne elementy linijki mogą być zmienione  pojedynczo 
(np.ustawienie lewego marginesu czy też wprowadzenie nowej pozycji 
tabulacji) lub też razem poprzez wpisanie całej linijki do zbioru. 
Ponadto  w  celu ustawienia marginesów można  wykorzystać  dowolną 
uprzednio zredagowaną linię.

                              FLAGI
                              -----
W  skarajnej prawej kolumnie na ekranie wyświetlane  są  specjalne 
znaki  noszące  nazwę  flag . Identyfikują one  rodzaj  informacji 
zawartej w danej linii w następujący sposób:
spacja   Linia  ta należy do większego  akapitu . Występuje  tutaj 
         domyślne przejście  do następnej linii , które  może ulec 
         zmianie podczas póżniejszej redakcji akapitu.
  <      Linia ta kończy się znakiem CR. Oznacza to koniec akapitu
         lub linięa nie podlegającą  póżniejszemu przeredagowaniu.
  +      Ta linia jest kontynuowana poza ekranem. Próba przesunię
         cia kursora w prawo poza ekran spowoduje wprowadzenie jej 
         pozostałej części na ekran.
  -      Następna linia  zostanie podczas wydruku napisana na tej.
  .      Ta linia znajduje się poza końcem dokumentu . Pojawia się 
         również  w oststniej linii dokumentu o ile nie kończy się 
         on znakiem CR.
  :      Ta linia leży przed początkiem dokumentu.
  P      Następna linia na ekranie zostanie wydrukowana na począt
         ku kolejnej strony tekstu.
  ?      Ta linia zawiera nierozpoznaną komendę DOT.
  J      Ta linia zawiera znak LF (Line Feed) bez znaku  CR . Jest 
         to  zbiór  niestandardowy , jakiego nie można wygenerować 
         posługując się normalnie WordSrarem.
  M      Ta linia zawiera komendę MallMerge.

                            ROZDZIAŁ 3
                    PODSTAWOWE ZASADY EDYCJI.
                  =============================
W rozdziale tym przedstwiamy podstawowe komendy stosowane  podczas 
edycji   zbiorów  oraz  nieomówione  dotychczas  reguły   rządzące 
redagowaniem tekstów.

                       PRZESUWANIE KURSORA
                       -------------------
Komendy   służące  do  przesuwania  kursora  są  używane  w   celu 
ustawienia  go w }ądanym miejscu przed poprawieniem  danej  partii 
tekstu . Przesunięcia kursora są realizowane natychmiastowo tj. po 
naciśnięciu klawiszy definiujących komendę WordStar ustawia kursor 
w zadanym miejscu w tekście. Podstawowe komendy służące do przesu
wania  kursora na ekranie znajdują się w lewej części klawiatury i 
zostały tak zaprogramowane,}e pozycje klawiszy odpowiadają wykony
wanym ruchom kursora.
                              ^E
                            w górę 
                           o wiersz
         ^A           ^S              ^D          ^F
       w lewo       w lewo         w  prawo    w  prawo
      o  słowo      o znak          o znak     o  słowo
                              ^X
                            w  dół
                           o wiersz

Skrajne klawisze przesuwają kursor o słowo odpowiednio w prawo lub 
lewo . Pod pojęciem słowa WordStar rozumie dowolny łańcuch  znaków 
mogący zawierać na końcu znak interpunkcyjny (.  ,  :  :  ! lub ?) 
zakończony dowolną ilością spacji albo znaków tabulacji . Ponieważ 
znak  CR jest traktowany również jako słowo kursor zatrzymuje  się 
również na końcu każdej linii , tak jak na początku każdego słowa.
Kursora nie można przesuwać poza koniec linii , koniec zbioru oraz 
przed  początek  zbioru . Nie może on zostać również ustawiony  na 
znacznikach  ( pojęcie   to  omówimy  szczegółowo   w   następnych 
rozdziałach )  oraz  na  liniach  sygnalizujących  koniec  strony.

Przedstawimy  teraz spis wszystkich komend WordStara służących  do 
przesuwania kursora.

^S        Przesuń  kursor  w lewo o jeden znak . W  przypadku  gdy 
          kursor  jest  ustawiony  na początku linii  cofa  go  do 
          ostatniego  znaku w poprzedniej linii . Identyczny efekt           
          daje naciśnięcie klawisza <BS>.
^D        Przesuń   kursor w prawo o jeden znak . W przypadku  gdy           
          kursor  ustawiony na ostatnim znaku w linii  zostaje  on           
          przesunięty do pierwszego znaku następnej linii.
^E        Przesuwa kursor w górę o jedną linię . Kursor jest prze
          suwany na ekranie o linię w górę , do kolumny , w której 
          był ustawiony albo na koniec wiersza.
^X        Przesuwa kursor w dół o jedną linię. Kursor jest przesu
          wany  na ekranie o jedną linię w dół oraz w lewo  jeżeli 
          jest to konieczne (tak aby nie przekraczał końca linii).
^A        Przesuwa kursor do początku poprzedniego słowa.
^F        Przesuwa kursor do początku następnego słowa.
^QS       Przesuwa kursor do pierwszego znaku w linii.
^QD       Przesuwa kursor za ostatni znak w linii.
^QE       Przesuwa kursor do pierwszej linii tekstu na ekranie, do 
          kolumny, w której był ustawiony albo do końca pierwszego 
          wiersza.
^QX       Przesuwa  kursor  do ostatniej linii tekstu  na  ekranie            
          (podobnie do ^QE).
^QR       Przesuwa  kursor  do  pierwszego  znaku  dokumentu . Dla             
          długich  dokumentów  szybciej daje taki efekt  i  zużywa 
          mniej  przestrzeni dyskowej zachowanie zbioru  na  dysku 
          (^KS) i ponowne rozpoczęcie edycji.
^QC       Ustawia kursor za ostatnim znakiem dokumentu.
^Q0..Q9   Przesuwa  kursor do pierwszego znaku za podanym znaczni
          kiem.Sposób ustawiania znaczników omówimy w rozdziale 6.
^QB       Przesuwa  kursor do początku bloku i wyświetla  znacznik             
          początku bloku o ile został on wygaszony. Sposób tworze
          nia bloku omówimy w rozdziale 6.
^QK       Przesuwa kursor do ostatniego znaku  w bloku.
^QP       Przesuwa  kursor do pozycji jaką zajmował on poprzednio. 
          Komenda  ta jest szczególnie przydatna  po  przejściowym 
          zachowaniu  dokumentu na dysku , gdy chcemy powrócić  do 
          miejsca, w którym była prowadzona edycja.
^QV       Przesuwa kursor do miejsca, skąd rozpoczęła się ostatnia 
          operacja  przeszukiwania  tekstu  lub do  miejsca  gdzie 
          znajdował  się  ostatnio przesuwany  lub  usuwany  blok. 
          Funkcje te są opisane w rozdziale 5 i 6.

              KOMENDY PRZESUWAJACE TEKST NA EKRANIE.
              --------------------------------------
Ta grupa komend nie zmienia położenia kursora w tekście. Służą one 
dowprowadzenia  nowych linii dokumentu na ekran , niejako "podrzu
cając" tekst na ekranie. Jest to w pewnym sensie przesuwanie doku-
mentu po ekranie.Istnieją następujące komendy służące dotego celu:

^Z   Przesuwa dokument o linię w dół na ekranie. Powoduje to znik
     nięcie  ostatniej  aktualnie wyświetlanej linii i  pojawienie 
     się linii znajdującej się przed początkiem tekstu na ekranie.
^W   Przesuwa  dokument  o linię w górę na  ekranie . Powoduje  to 
     znikinięcie pierwszej aktualnie wyświetlanej linii i pojawie
     nie się linii  znajdującej się  za końcem tekstu na  ekranie.
^C   Przesuwa dokument o "ekran" w  dół (w kierunku końca zbioru).
     Przesunięcie  jest realizowane w taki sposób aby ekran w  3/4
     wypełnił  się nowym tekstem (pewna partia poprzednio wyświet
     lonego tekstu pozostaje na ekranie).
^R   Przesuwa  dokument  o "ekran" w górę  (w  kierunku  początku 
     dokumentu) działając podobnie jak ^C.
^QZ  Rozpoczyna  ciągle przesuwanie tekstu o linię w dół na  ekra
     nie . Proces  ten trwa tak długo , aż nie zostanie naciśnięty 
     dowolny  inny  klawisz reprezentujący znak  różny  od  cyfry.      
     Podczas ciągłego przesuwania tego dokumentu można szybko tego      
     procesu podając cyfry od 1 do 9 (1 oznacza najszybsze przesu
     wanie dokumentu).
^QW  Rozpoczyna ciągłe przesuwanie dokumentu o linie w górę na ek-
     ranie. Proces ten przebiega identycznie jak, opisany powyżej.

                          WPROWADZENIE TEKSTU
                          -------------------
Generalnie  rzecz biorąc wprowadzenie tekstu polega na  wpisywaniu 
kolejnych  znaków . Jednakże istnieje kilka komend pomocnych  przy 
wprowadzeniu tekstu, które ustawiają tryb redagowania tekstu przez 
WordStara.                        Poniżej prezentujemy te komendy.

^V       Ustaw/Skasuj tryb wstawiania znaków. Jak już wspomniano w 
         poprzednich rozdziałach WordStar pozwala na pracę w dwóch
         trybach: pisania na  uprzednio wprowadzonym  tekście albo
         wstawiania  znaków . Komenda ta służy do zmiany  trybu na  
         zasadzie przełącznika tj. kolejne  jej wykonanie  zmienia
         tryb na przeciwny.
<RETURN> Koniec akapitu . Przy ustawionym trybie wstawiania znaków
         naciśnięcie tego klawisza spowoduje wstawienie "twardego"
         znaku CR ( końca akapitu ) w to miejsce w linii, w którym
         znajduje się kursor . Gdy tryb wstawiania znaków nie obo
         wiązuje  wówczas nastąpi wpisanie "twardego" znaku CR  za 
         końcem linii, w której znajduje się kursor i przesunięcie 
         kursora do początku następnej linii.
^N       Wstawia zawsze w miejscu ustawienia kursora "twardy" znak
         CR . Znaki  znajdujące  się na prawo od kursora ( wraz ze 
         znakiem  wskazywanym  przez  kursor ) są  przesuwane   do 
         następnej  linii . Kursor  nie  zmienia  swojej  pozycji.
^I       Działanie tej komendy polega  na  przesunięciu kursora do
         następnej pozycji tabulacji. Gdy w danej linii nie ma już
         dalej }adnej pozycji tabulacji kursor zostaje przesunięty
         do  początku  następnej  linii . Przy  wyłączonym  trybie 
         wsatwiania znaków tabulacja powoduje przesunięcie kursora
         po tekście . Gdy tekst w linii kończy  się przed następną 
         pozycją tabulacji następuje wstawienie odpowiedniej licz
         by  spacji  lub  "twardego" znaku CR  (gdy  w  tej  linii          
         nie  jest dalej  ustawiona pozycja  tabulacji , do której          
         można przesunąć kursor. Przy ustawionym trybie wstawiania
         znaków  następuje  wtrącenie w tekst odpowiedniej  liczby 
         spacji lub być może "twardego" znaku CR. Zamiast ^I można
         używać również klawiszy <TAB> lub <HT>.

            Wprowadzenie znaków specjalnych do tekstu
            -----------------------------------------
Dotychczas omówiliśmy wyłącznie wprowadzenie zwykłych znaków alfa
numerycznych . Niekiedy jednak występuje potrzeba wpisania do tek
stu  znaków  specjalnych (również tych  należących  do  repertuaru 
komend WordStara) np. w celu sterowania drukarką. Możliwości takie 
stwarza  komenda ^Px gdzie x jest dowolnym znakiem o kodzie różnym 
od 1Ah (=Z). Kody specjalne dla drukarek przedstawiamy w rozdziale 
7.Komenda ^P ma jednak zastosowanie w czterech przypadkach podczas 
wprowadzenia czy też poprawienia tekstu.                  Oto one:

^P   Komenda  ta umożliwia  wpisanie trwałego  myślnika . Jak  już
     wspomniano  uprzednio WordStar umożliwia przenoszenie wyrażów 
     podczas justowania tekstu . Wstawiane  wówczas  myślniki mają 
     charakter przejściowy i mogą zmieniać swoje położenie w trak
     cie kolejnych redakcji tekstu . Jeżeli korzystamy z tego udo
     godnienia (ang. soft hyphen) wówczas  w celu wpisania myślni
     ka , króry ma  pozostać  w  tekście należy użyć tej  komendy.
^PO  Komenda ta służy do wsatawiania pojedynczego odstępu (spacji) 
     pomiędzy słowa, które nie mogą być rozsuwane podczas justowa
     nia tekstu.
^PH  Komenda ta umożliwia napisanie następnego znaku na znaku zna-
     jdującym się przed komendą podczas drukowania dokumentu. Jest 
     ona wyświetlana na ekranie jako ^H.
^PM  Komenda ta umożliwia wydrukowanie następnej linii na linii, w 
     której  jest umieszczona . Podczas wydruku na  drukarce  jest 
     wysłany  znak  CR ( powrotu karetki ) bez znaku LF  (  wysuwu 
     papieru ) . Identyczny efekt daje ^P <RETURN>.

               Komendy usuwające tekst z dokumentu
               -----------------------------------
Poniższe   zestawienie   przedstawia   komendy   usuwające  tekst:

^G      Komenda  ta  usuwa znak znajdujący się w  pozycji kursora.
        Pozostała  zawartość  linii jest przesuwana o jeden znak w          
        lewo . W  przypadku usunięcia "twardego"  lub  "miękkiego"          
        znaku  CR następna linia jest dołączona do  tej , w której 
        znajduje się kursor. Kursor nie zmienia swojego położenia.
<DEL>   Komenda  ta usuwa znak znajdujący się na lewo od  kursora. 
        Pozostała  część  linii  jest przesuwana o  jeden  znak  w          
        lewo . Gdy kursor wskazuje pierwszy znak w linii , znak CR 
        jest  usuwany  i zawartość danej linii jest  dołączona  do          
        linii poprzedniej . Kursor jest  przesuwany o znak w lewo.
^T      Komenda  ta usuwa najbliższe słowo znajdujące się na prawo 
        od  kursora  i następuje po nim spacje . Gdy  kursor  jest          
        ustawiony  w  ^rodku słowa komenda ta  usuwa  część  słowa          
        znajdująca  się  na  prawo  od  kursora  wraz  ze  znakiem          
        wskazywanym  przez  kursor . W przypadku gdy  kursor  jest          
        umieszczony  pomiędzy  słowami  usuwane  są  tylko  spacje          
        znajdujące  się  na  prawo od kursora . Gdy  przed  końcem          
        linii  nie ma już }adnego słowa zostanie usunięty znak  CR 
        wraz  z poprzedzającymi go spacjami . Kursor  nie  zmienia 
        swojego położenia.
^Y      Komenda  ta usuwa linie wraz ze wszystkimi liniami , które         
        mają  być na niej nadrukowane . Pozostała część  dokumentu          
        jest przesuwana o wiersz w górę. Kursor nie zmienia swoje
        go położenia.
^QY     Komenda  ta usuwa zawartość linii znajdującą się na  prawo 
        od  kursora . Nie usuwa ona znaku CR ani }adnej  następnej        
        linii , która  miała być na niej nadrukowana . Kursor  nie 
        zmienia swojego położenia.
^Q<DEL> Komenda ta usuwa tekst znajdujący się pomiędzy początkiem
        linii  a  kursorem . Kursor jest przesuwany  do  początku 
        wiersza.
^KY     Komenda  ta  usuwa z dokumentu ostatnio  zaznaczony  blok. 
        Zasady  tworzenia bloku zostaną przedstawione w  rozdziale 
        6. Kursor nie zmienia swojego położenia.

                      KONCZYMY EDYCJE ZBIORU
                      ----------------------
Redagowane  dokumenty  są przez nas przechowywane  w  zbiorach  na 
dysku . Co więcej , drukować można wyłącznie zbiory znajdujące się 
na  dysku.Tak  więc ostatnią naszą czynnością musi być  zachowanie 
poprawionego  zbioru  na  dysku .  Poniżej  przedstawiamy  komendy 
służące do tego celu.

^KS  Komenda ta zachowuje zaktualizowaną treść dokumentu w zbiorze 
     na  dysku i ponownie inicjuje edycję tego  samego  dokumentu. 
     Jest  ona znacznie krótsza od zachowywania zbioru i ponownego 
     otwierania  go za pomocą komendy D (N) . Szczególnie  celowym 
     jest wykonywanie tej komendy przy wprowadzeniu długich  zbio
     rów. Uchroni to nas od utraty wprowadzonego tekstu w przypad
     ku poważnej awarii sprzętu czy  też zaniku napięcia  w sieci.
^KD  Komenda  ta  zachowuje zaktualizowany dokument w  zbiorze  na 
     dysku i powraca do głównego poziomu WordStara (NO FILE MENU).
^KX  Komenda  ta  zachowuje zaktualizowany dokument w  zbiorze  na 
     dysku   oraz   wymusza  powrót   do   systemu   operacyjnego.
^KQ  Komenda  ta umożliwia przerwanie edycji bez zachowywania  na
     niesionych poprawek w zbiorze na dysku. Po wywołaniu WordStar 
     upewnia się dodatkowo czy naprawdę nie chcemy zachować  nowej 
     wersji  dokumentu . Komenda  ta jest użyteczna gdy  wyłącznie 
     przeglądaliśmy zbiór nie  wnosząc do niego }adnych  poprawek.

Wszystkie  opisane powyżej komendy z wyjątkiem ostatniej  powodują 
zastąpienie zbioru zawierającego starą treść dokumentu nowym zbio
rem  o  tej samej nazwie . Poprzednią wersją dokumentu  jednak nie 
znika z dysku. Znajduje się ona w zbiorze o tej samej nazwie ale z 
typem "BAK" . Wymazaniu ulega natomiast zbiór zawierający  przedo
statnią wersję dokumentu.

                            ROZDZIAŁ 4
                    REDAKCJA TEKSTU NA EKRANIE
                  ==============================
Rozdział   ten   zawiera  opis  komend  niezbędnych   do   nadania 
dokumentowi dowolnej postaci . Komendy te  można podzielić na dwie 
grupy:  określające  bezpośrednio format dokumentu na ekranie oraz 
modyfikujące   zasady   redagowania    tekstu   przez   WordStara.

                  DEFINIOWANIE FORMATU DOKUMENTU
                  ------------------------------
Poniżej  przedstawiono spis komend służących do ustalania  formatu 
dokumentu na ekranie.
^OC  Komenda  ta służy do centrowania tekstu na  ekranie  pomiędzy 
     aktualnie ustawionymi marginesami . Centrowaniu podlega wyłą
     cznie zawartość linii,w której aktualnie znajduje się kursor. 
     Centrowanie tekstu polega na umieszczeniu odpowiedniej ilości 
     "twardych"  spacji  przed pierwszym znakiem w danej  linii  i 
     umieszczeniu na jej końcu "twardego" znaku CR.
^OL  Komenda ta służy do ustawienia lewego marginesu. Po jej wywo-
     łaniu  WordStar  pyta się o numer kolumny , w której  ma  być 
     ustawiony  lewy  margines . Istnieją dwa sposoby  odpowiedzi. 
     Pierwszy  z nich polega na podaniu wprost numeru  kolumny , w 
     której  ma  być  ustawiony  lewy  margines . Drugi  natomiast       
     zakłada  }e kursor jest aktualnie ustawiony w kolumnie  odpo
     wiadającej  zadanemu ustawieniu lewego  marginesu . Wystarczy 
     wówczas nacisnąć klawisz <ESC>.
^OR  Komenda ta służy do ustawienia prawego marginesu. Jej działa
     nie  jest  takie  same  jak  w  przypadku  lewego  marginesu.
^OF  Komenda  ta umożliwia ustawienie zarówno obu marginesów jak i 
     pozycji tabulacji za pomocą linii wchodzącej w skład dokumen
     tu . W  celu ustawienia wyłącznie marginesów (bez  zmieniania 
     pozycji tabulacji) można użyć dowolnej linii uprzednio  sfor
     matowanego tekstu. Należy w tym celu ustawić kursor na począ
     tku  linii wzorcowej i nacisnąć OF . W celu ustawienia  całej 
     linijki   należy   przygotować   jej   wzorzec   w   zbiorze.  
Przy przygotowywaniu wzorca można korzystać wyłącznie z następują-
cych znaków: 
  !  - znak ten oznacza ustawienie w danej kolumnie pozycji norma-
       lnej tabulacji,
  #  - znak ten oznacza ustawienie w danej kolumnie pozycji  dzie
       siętnej  tabulacji ( wyrównywanie  prawostronne  zawartości 
       pola zatubolowanego ).
  -  - znak  myślnika  należy umieścić we  wszystkich  pozostałych 
       kolumnach pomiędzy lewym i prawym marginesem . Zwracamy  tu 
       uwagę na fakt istnienia trwałych i przejściowych myślników. 
       Należy  upewnić  się czy myślniki , z  których  składa  się 
       wzorzec linijki są trwałymi myślnikami.
Po  takim  przygotowaniu należy ustawić kursor w dowolnym  miejscu 
wzorca i nacisnąć OF . Gdy chcemy wzorzec linijki zachować w zbio-
rze  ale jednocześnie uczynić go niewidocznym podczas wydruku wów
czas musimy skorzystać z komendy DOT wskazującej na linie komenta
rza. Komenda taka składa się z dwóch bezpośrednio następujących po 
sobie kropek na początku linii . Umieszcenie bezpośrednio za krop
kami ^P <RETURN> spowoduje , }e wzorcowa linijka będzie traktowana 
przez WordStara jako ciąg dalszy komentarza , który nie jest umie
szczony na wydruku.

^OG  Komenda ta umożliwia przesunięcie do najbliższej pozycji  ta-
     bulacji całego akapitu. Przesuwa ona cały akapit redagowanego 
     lub  wprowadzonego  tekstu do najbliższej pozycji  tabulacji. 
     Komenda ta nie wprowadza trwałego przesunięcia , przy przere
     dagowaniu akapitu przesunięcie zniknie o ile nie zostanie ona 
     powtórzona. Działanie jej obowiązuje do naciśnięcia <RETURN>.
^OS  Komenda ta umożliwia zmianę odstępu międzyliniowego w przere
     dagowaniu  lub  wprowadzanym tekście . WordStar pyta  o  nową 
     wielkość  odstępu  mieędzyliniowego (od 1  do  9) . Ustawiony 
     odstęp międzyliniowy jest honorowany podczas przesuwania słów 
     pomiędzy  liniami przy automatycznej redakcji akapitu oraz po 
     naciśnięciu klawisza <RETURN>.
^B   Komenda ta umożliwia przeredagowanie akapitu zgodnie z aktua
     lnie obowiązującym formatem dokumentu . Po ustawieniu kursora 
     na  początku akapitu należy nacisnąć ^B i WordStar samodziel
     nie  zredaguje  akapit zgodnie z utawieniem  wszystkich  jego 
     opcji . Komenda ta umożliwia również półautomatyczne  przeno
     szenie słów podczas przeredagowania dokumentu. O ile ustawio
     no  taki tryb pracy wówczas podczas wykonywania  tej  funkcji 
     WordStar  proponuje piszącemu przenoszenie długich słów  wyś
     wietlając odpowiedni komunikat . Mamy wówczas możliwość  bądz 
     to  zaakceptowania przeniesienia poprzez  wprowadzenie  znaku 
     przenienienia (-), po uprzednim skorygowaniu miejsca gdzie ma 
     być  umieszczony , bądz to rezygnacji z tej możliwości  przez 
     powtórne  naciśnięcie  ^B . Komenda ta  uwzględnia  WSZYSTKIE 
     aktualnie ustawione parametry redakcji akapitu.
^OI  Komenda ta służy do wskazania nowej pozycji tabulacji . Prze
     bieg  ustawienia pozycji tabulacji jest identyczny jak  usta
     wiania  lewego czy prawego marginesu . Jeżeli chcemy  ustawić 
     dziesiętną pozycję tabulacji wówczas numer kolumny lub  naci
     ^nięcie  <ESC>  należy  poprzedzić wprowadzeniem  znaku  "#". 
     Identyczny efekt daje komenda ^O <TAB>.
^ON  Komenda ta umożliwia usunięcie niepożądanych pozycji  tabula
     cji  może nastąpić przez podanie numeru kolumny , nacisnięcie 
     <ESC> gdy pozycja tabulacji,którą chcemy usunąć znajduje  się 
     w  tej samej kolumnie co kursor lub wprowadzenie litery "A" i 
     zaakceptowanie jej klawiszem <RETURN> gdy chcemy usunąć wszy
     stkie pozycje tabulacji.
^OX  Komenda ta umożliwia umieszczenie tekstu poza kolumnami  wyz
     naczonymi  przez aktualne ustawienie  marginesów . Obowiązuje 
     ona dopóki poruszamy się kursorem poza obszarem przeznaczonym 
     na  tekst lub nie wyłączymy jej działania przez ponowne wpro
     wadzenie ^OX . Komendy DOT, które obowiązkowo muszą rozpoczy
     nać  się w pierwszej kolumnie są w niej umieszczane automaty
     cznie , bez konieczności uprzedniego zezwplenia na wpisywanie 
     tekstu przed lewym marginesem.

                           PRZEŁACZNIKI
                           ------------
Działanie WordStara podczas redagowania tekstu jest uzależnione od 
wyboru niektórych zasad formatowania tekstu na ekranie.Wyboru tego 
dokonuje się poprzez ustawienie bądź zgaszenie przełączników  zez
walających  na  automatyczne wykonywanie danych  funkcji . Komendy 
zmieniające stan przełączników działają na zasadzie negacji  stanu 
aktualnego tj. jeżeli dany przełącznik był ustawiony (dana funkcja 
działała)  to wykonanie komendy  oddziaływającej na niego zgasi go
(dana funkcja przestanie działać). Aktualne stany przełączników są 
wyświetlane w "ONSCREEN MENU". Przedsatwione poniżej komendy służą 
do zmiany zasad redakcji dokumentu.

^OW  Komenda  ta  zezwala lub zabrania przenoszenia  słów  podczas 
     wprowadzenia  tekstu . Jeżeli przełącznik ten jest w  pozycji 
     "włączony" wówczas słowa nie mieszczące się w danej lini będą 
     przenoszone do następnej linii aż do osiągnięcia końca akapi
     tu  (naciśnięcie  <RETURN>) . Gdy wyłączymy  ten  przełącznik 
     wówczas WordStar nie będzie przenosił słów tj.  tekst  będzie 
     umieszczony  w  jednej  linii  aż  do wprowadzenia znaku  CR.
^OJ  Komenda  ta  zezwala lub zabrania  automatycznego  justowania 
     tekstu . Jeżeli  zezwolono  na justowanie tekstu  wówczas  do       
     dokumentu będą wprowadzone dodatkowe spacje w celu wyrównania 
     prawego  marginesu . Gdy zabroniono justowania wówczas  prawy 
     margines  będzie niewyrównany . Dodatkowo  wprowadzone spacje 
     podczas  justowania są odróżnione od spacji wpisanych  wprost 
     do dokumentu . Podczas dalszej redakcji akapitu mogą one  być 
     automatycznie  usunięte lub zmienić swoje położenie w zależn-
     ości od nowej treści akapitu.
^QV  Komenda  ta  ustawia tryb zmiennej lub  stałej  tabulacji . W 
     trybie  zmiennej tabulacji położenie  poszczególnych  pozycji       
     tabulacji  zależy  od uprzedniego zdefiniowania komendy  ^OI,         
     (  ON i   OF ) , tak jak to omówiono poprzednio . Tryb stałej       
     tabulacji omówimy szczegółowo w rozdziale 6. Należy tu jednak 
     zwrócić uwagę na fakt,}e po ustawieniu trybu stałej tabulacji 
     linijka  dalej będzie wskazywała ustawione poprzednio pozycje 
     zmiennej tabulacji.
^OT  Komenda  ta  zezwala  lub zabrania  wyświetlania  na  ekranie       
     linijki. Oczywiście w przypadku jej zgaszenia wszystkie poka
     zane przez nią parametry dalej obowiązują.
^OP  Komenda  ta  zezwala lub zabrania wskazywania podczas  edycji 
     tekstów  końców  stron (linie "----""----" z  flaga  P)  oraz       
     powoduje  zastąpienie adresu kursora w linii statusu "PAGE" i       
     "LINE" przez "FL=" i "FC=".
^OD  Komenda ta powoduje wyświetlanie lub pomijanie znaków  steru
     jących wydrukiem podczas redakcji tekstu. Jeżeli znaki steru
     jące  są  pomijane przy wyświetlaniu tekstu na ekran  podczas 
     jego edycji wówczas na ekranie widzimy dokument  taki , jakim 
     zostanie  on  wydrukowany . W przypadku  wyświetlania  znaków 
     sterujących  wydrukiem (omówimy je w rozdziale 7) na  ekranie 
     pojawia  się  nieco zniekształcony obraz  dokumentu . Ponadto 
     podczas  edycji  tekstu pojawiają  się   wówczas  na  ekranie 
     wszystkie  nieaktualne znaki przeniesienia powstałe przy roz
     dzieleniu słów podczas redakcji dokumentu oraz znaki sygnali
     zujące   miejsca   gdzie  wstawiono   nienaruszalne   spacje.
^OH  Komenda  ta  zezwala  lub  zabrania  pomocy  w   przenoszeniu        
     długich  słów  podczas redakcji akapitu . Proces  ten  został         
     omówiony podczas komendy ^B.
^OE  Komenda ta definiuje sposób traktowania przez WordStara  zna
     ków  przeniesienia (-) . Jeżeli przełącznik ten jest włączony 
     wówczas  znaki przeniesienia będą traktowane  jako  "miękkie" 
     tj. zostaną wydrukowane tylko wtedy gdy podczas redakcji tek-
     tu  znajdą się bezpośrednio przed końcem linii (będą  trakto
     wane   na  zasadzie  znaków przeniesienia  wstawianych  przez 
     WordStara) . W  celu wpisania "twardego" znaku  przeniesienia 
     trzeba używać wówczas komendy ^P-. Po wyłączeniu tego przełą
     cznika wszystkie znaki przeniesienia wprowadzone z klawiatury 
     są traktowane jako "twarde"i są zawsze drukowane. 

Inicjacyjne  ustawienie  parametrów w  standardowo  zainstalowanej 
wersji  WordStara zależy od trybu w jakim rozpoczeliśmy  edycje  i 
jest następujące:

Parametr                  Zbiór tekstowy         Zbiór nietekstowy
------------------------------------------------------------------
Lewy margines                    kol.1                  kol.1
Prawy margines                   kol.65                 kol.65
Pozycje tabulacji         kol.6,11,16,..,56      kol.9,17,25,..,73
Zmienna tabulacja                ON                     OFF
Przenoszenie słów                ON                     OFF
Justowanie tekstu                ON                     OFF
Wyświetlanie linijki             ON                     OFF
Wyświetlanie końca strony        ON                     nieaktywne
Wyświetlanie znaków sterujących  ON                     ON
"miękkie" znaki przeniesienia    OFF                    OFF
Przenoszenie słów                ON                     OFF

Przedstawione   powyżej   ustawienie  niektórych  parametów   może 
być zmienione  za  pomocą  programu  instalacyjnego  WINSTALL.COM.
                                                  
                            ROZDZIAŁ 5
                      PRZESZUKIWANIE TEKSTU
                    =========================
Rozdział ten zawiera omówienie komend umożliwiających wyszukiwanie 
uprzednio zaznaczonych miejsc oraz odszukiwanie zadanych łańcuchów 
znaków.
                                         .
                      USTAWIENIE ZNACZNIKOW
                      ---------------------
W  pierwszej kolejności omówimy sposób umieszczenia  znaczników  w 
tekście. Jak już wspomniano w rozdziale 3 WordStar przewiduje moż
liwość   przesuwania  kursora  do  pewnych  uprzednio  określinych 
miejsc . Właściwość  ta jest przydatna w przypadku edycji  długich 
dokumentów, których proste przeglądanie w celu odszukania odpowie
dniego  fragmentu jest procesem długotrwałym  i  męczącym . Jeżeli 
istnieją w naszym dokumencie fragmenty,do których będziemy chcieli 
się w przyszłości odwoływać WordStar umożliwia oznakowanie takiego 
miejsca numerem od 0 do 9. Poniżej przedstawimy komendy służące do 
tego celu.

^K0..K9  Ustaw znacznik. Komenda ta umieszcza  znacznik o  zadanym 
         numerze  w pozycji kursora . Znaczniki są wyświetlane  na            
         ekranie w postaci "(x)", gdzie x jest numerem  znacznika. 
         Jeżeli w miejscu ustawienia kursora znajduje się już zna-
         cznik , zostanie  on zgaszony na ekranie ale jego pozycja 
         będzie  dalej pamiętana i próba przesunięcia  kursora  do 
         niego zakończy się powodzeniem.
^Q0..Q9  Przesuń  kursor do znacznika . Komenda ta przesuwa kursor 
         do wyspecyfikowanego znacznika . O ile był on  poprzednio 
         zgaszony , teraz   zostanie   ponownie   wyświetlany   na            
         ekranie. Jeżeli znacznik o danym numerze nie został umie
         szczony  w  tekście , zostanie  wyświetlony  komunikat  o 
         błędzie.

Znaczniki nie są zapamiętywane w zbiorze wraz z dokumentem . Word
Star  pamięta  o nich tylko podczas edycji  danego  zbioru . Każde 
zakończenie procesu edycji poza komendą  KS , powoduje konieczność 
ponownego  ustawienia  znaczników o ile  mają być  wykorzystywane.
                                             .      .
           WYSZUKIWANIE I ZAMIENIANIE LANCUCHOW ZNAKOW
           -------------------------------------------
Komendy  wyszukiwania  łańcucha  znaków  umożliwiają  automatyczne 
przesunięcie kursora do miejsca , w którym występuje  dany  wyraz, 
fraza  lub dowolna inna sekwencja bez przeglądania tekstu na ekra
nie . Komendy  zamiany  łańcuchów znaków  umożliwiają zastępowanie 
jednych wyrazów innymi bez konieczności }mudnego ^ledzenia  tekstu 
na ekranie. Ponadto funkcja tych komend nie ogranicza się do poje
dynczego wykonania danej operacji . Może ona być powtarzana wielo
krotnie bez konieczności ponownego podawania parametrów wyszukiwa
nia lub zamiany .  Do powyżej przedstawionych celów służą komendy:

^QF  Komenda ta służy do szukania wystąpień zadanego łańcucha zna-
     ków . Po  jej  wprowadzeniu WordStar pyta o  łańcuch  znaków, 
     który ma  zostać odszukany. Po jego wpisaniu można zaakcepto
     wać go jednym z dwóch klawiszy: <ESC> lub <RETURN>. W przypa
     dku naciśnięcia klawisza <ESC> kursor zostanie  automatycznie 
     przesunięty  do  następnego  znaku  za  pierwszym  napotkanym 
     wystąpieniem  danego łańcucha . Gdy akceptacja następuje pop
     rzez  klawisz <RETURN> WordStar zgłasza pytanie  o  dodatkowe 
     parametry  przeszukiwania . Parametry  te omówimy  w  dalszej 
     części tego rozdziału.
^QA  Komenda  ta  służy  do zastępowania jednego  łańcucha  znaków 
     innym  łańcuchem . Po  jej wprowadzeniu następuje  pytanie  o       
     łańcuch, który  ma być zastąpiony, a następnie pytanie o nowy       
     łańcuch , który  ma go zastąpić . Gdy zrezygnowano z  podania       
     dodatkowych parametrów , kursor jest ustawiony przed najbliż
     szym  wystąpieniem wskazanego łańcucha i na  ekranie  pojawia 
     się  pytanie "REPLACE (Y/N):" . Po nim można bądż to  dokonać 
     zamiany bądż zrezygnować z niej.
^L   Komenda  ta umożliwia powtórzenie ostatnio wykonywanej opera
     cji szukania lub zamiany łańcuchów . Powtarzana komenda  jest 
     pewnie  wykonywana  z  tymi  samymi  parametrami  jak  zadano 
     poprzednio.
^QV  Komenda ta przesuwa kursor do pozycji, w której znajdował się 
     on przed rozpoczęciem procesu zamieniania lub szukania łańcu
     cha . Jest ona szczególnie użyteczna gdy na skutek błędu  nie 
     odszukano  wskazanego  tekstu i musimy dany proces  powtórzyć 
     ponownie . Należy  tu pamiętać , }e w przypadku używania ope-
     racji na blokach komenda ta ma inne znaczenie.

             PARAMETRY KOMEND WYSZUKIWANIA I ZAMIANY
             ---------------------------------------
Po  wprowadzeniu komendy szukania lub zamiany na  ekranie  pojawia 
się  pytanie "OPTIONS?" . W odpowiedzi można podać jeden lub kilka 
parametrów oddzielonych przecinkami z przedstawionych  poniżej . W 
pewnych  sytuacjach ułatwiają one w istotny sposób wykonanie zada
nej operacji.            WordStar dopuszcza następujące parametry:

Liczba (n)  Gdy w parametrach zostanie podana liczba , określa ona 
            ile razy ma zostać automatycznie powtórzona dana kome
            nda . W szczególności , w przypadku szukania  łańcucha 
            znaków  znaczy  to "odnaleź n-te wystąpienie  zadanego 
            łańcucha", natomiast w przypadku zamienienia łańcuchów 
            "zamień  n razy dany łańcuch innym" . W przypadku  gdy 
            komenda  nie  może  być  wykonana  zadaną  ilość  razy 
            wyświetlany  jest  odpowiedni   komunikat  o  błędzie.
G  Parametr ten oznacza ,  }e proces przeszukiwania dotyczy całego 
   zbioru . W przypadku zamieniania łańcuchów , zamianie podlegają 
   (po  każdorazowej akceptacji) wszystkie takie łańcuchy w  zbio
   rze . W  przypadku  przeszukiwania zbioru parametr ten  oznacza  
   "znajdż  ostatnie  w zbiorze  wystąpienia  zadanego  łańcucha". 
   Przeszukiwanie rozpoczyna się od początku zbioru niezależnie od 
   aktualnego kursora.
N  Gdy  użyto  tego parametru przy zamienianiu  łańcuchów  wówczas 
   zamiana  będzie  dokonywana  automatycznie , bez  każdorazowego       
   }ądania potwierdzenia tego.
B  Parametr ten oznacza, }e przeszukiwanie ma się odbywać w kieru
   nku  przeciwnym do normalnego tj.  w kierunku początku  zbioru. 
   Wraz  z  parametrem G oznacza przeszukiewanie całego zbioru  od 
   końca do początku.
U  Gdy  podano ten parametr wówczas podczas przeszukiwania ignoro
   wana będzie różnica pomiędzy małymi i dużymi literami alfabetu. 
   Lańcuch "ala" równoważny będzie łańcuchowi "ALA".
W  Parametr ten powoduje , }e podczas przeszukiwania zbioru  brane 
   będą pod uwagę wyłącznie całe słowa . Na przykład przy szukaniu 
   łańcucha  "ala" napotkany łańcuch "lala" zostanie  zignorowany. 
   Należy tu  zwrócić uwagę , }e komenda z parametrem  nie  wskaże 
   pierwszego ( ostatniego ) słowa w zbiorze o ile przed  nim ( za 
   nim )  nie  ma  }adnego  innego  znaku  (np.  spacji  lub  CR).

Parametr  N może być użyty wyłącznie w komendzie zamiany łańcuchów 
znaków . Wszystkie pozostałe parametry mogą być użyte zarówno pod
czas wyszukiwania jak i zamiany łańcuchów.
                                            .
               ZNAKI SPECJALNE W SZUKANYM LANCUCHU
               -----------------------------------
Podczas definiowania łańcucha , który ma być znaleziony można uży
wać czterech znaków sterujących posiadających specjalne znaczenie:
A   Oznacza dowolny pojedyńczy znak w szukanym łańcuchu. Na przyk
    ład  wpisanie sekwencji "x Ax" spowoduje  odnalezienie zarówno 
    łańcucha "xxx" jak i "x+x" . Aby wpisać  A do łańcucha , który 
    ma być szukany należy użyć sekwencji PA.
S   Oznacza dowolny znak nie będący literą lub cyfrą . Na przykład 
    wpisanie  sekwencji  podobnej jak poprzednio "x Sx"  spowoduje 
    znalezienie łańcucha "x+x", ale nie wskaże łańcucha "xxx". Aby 
    wpisać  S  do łańcucha  wzorcowego należy  użyć  sekwencji PS.
Ox  Oznacza  dowolny znak inny niż "x" , gdzie "x" jest  następnym       
    znakiem  po   O .  Na  przykład  wpisanie  sekwencji  "x  O+x"       
    spowoduje  znalezienie łańcucha "xxx" i "x,x" ale  nie  wskaże       
    łańcucha "x+x".
N   Oznacza koniec wiersza. Znak ten identyfikuje sekwencje znaków 
    CR  i  LF  znajdującą się na końcu  każdego  wiersza . Różnica 
    pomiędzy "twardym" i "miękkim" CR jest ignorowana. Może on być 
    użyty zarówno podczas podawania łańcucha , który ma być znale
    ziony jak i nowego łańcucha, który ma być wpisany do zbioru. W 
    drugim  przypadku powoduje  on zawsze wpisanie "twardego"  CR.
                                                    .      .
        KILKA DODATKOWYCH UWAG O ZAMIENIANIU LANCUCHOW ZNAKOW
        -----------------------------------------------------
W końcowej partii tego rozdziału przypomnimy o kilku faktach które 
pośrednio  wynikają z przedstawionego uprzednio materiału , a mają 
istotny wpływ na procesy szukania i zamieniania łańcuchów  znaków. 
Po  pierwsze należy wspomnieć tu o możliwości powstania nieporozu
mień pomiędzy użytkownikiem a WordStarem na tle traktowania  znaku 
przeniesienia . Jeżeli  pracujemy  z ustawioną  opcją  "miękkiego" 
znaku  przeniesienia wówczas nie znajdziemy w dokumencie sekwencji 
"x-x" o ile nie została ona wpisana w sposób "utwardzający" (x  P-
x") . Tak  samo  zamieniania łańcuchów znak "-" będzie  traktowany 
jako  "miękkie" przeniesienie i ukaże się na ekranie tylko  wtedy, 
gdy  będzie bezpośrednio poprzedzał koniec linii  na  ekranie . Po 
drugie  podczas  przeszukiwania dokumentu WordStar  nie  rozróżnia 
"miękkich"  i  "twardych" spacji . Oznacza to,}e łańcuchy,w  skład 
których  wchodzą  zarówno spacje  wprowadzone z klawiatury  jak  i 
spacje powstałe podczas justowania tekstu będą traktowane  identy
cznie . Po  trzecie należy zwócić uwagę , }e najprostszym sposobem 
zmieniania  zbioru przetwarzanego uprzednio w trybie  nietekstowym 
lub utworzonego innym edytorem na zbiór tekstowy jest  zamienienie 
wszystkich  końców  linii (można je wskazać przez  N) na spacje  i 
następnie ponowne ustawienie końców akapitów i zredagowanie całego 
dokumentu za pomocą WordStara.

                            ROZDZIAŁ 6
           TO CZEGO JESZCZE NIE POWIEDZIELISMY O EDYCJI
         ================================================
W poprzednich rozdziałach zawarliśmy to wszystko co jest niezbędne 
aby skutecznie posługiwać się WordStarem. Posiada on jednak dodat
kowe właściwości , czyniące prace z nim bardziej przyjemną. Przed
stawimy je w niniejszym rozdziale.

                       OPERACJE NA BLOKACH
                       -------------------
Poza  wykonywaniem  różnorodnych  działań  na  znakach ,  słowach, 
liniach i stronach WordStar umożliwia swobodne manipulowanie dowo
lnymi fragmentami dokumentów . Służą do tego celu operacje na blo-
kach . Po  pojęciem bloku ukrywa się dowolna,uprzednio odpowiednio 
oznakowana partia dokumentu . Poniżej przedstawimy komendy służące 
do wykonywania operacji na blokach.

^KB  Ustaw znacznik początku bloku . Komenda ta służy do wskazania       
     pierwszego  znaku w bloku . Początek bloku jest  ustawiony  w 
     miejscu ustawienia kursora i sygnalizowany jest przez  "<B>". 
     Symbol  ten jest wyświetlany na ekranie ale nie jest  wprowa
     dzany do treści dokumentu. Jeżeli uprzednio w pozycji kursora 
     znajdował się już początek bloku ale został zgaszony zostanie 
     on zapalony ponownie.
^KK  Ustaw znacznik końca bloku . Komenda ta ustawia lub wznawia w      
     pozycji  kursora znacznik końca bloku . Zostaje w ten  sposób      
     wskazany ostatni znak w bloku.
^KH  Zapal lub zgaś znaczniki początku i końca bloku . Jeżeli zna-
     czniki  są wyświetlane komenda ta powoduje ich wygaszanie ale 
     nie usunięcie z obrębu dokumentu . Jeżeli znaczniki są  wyga
     szane zostanie odtworzone ich ostatnie ustawienie. W przypad
     ku gdy są one błędne zadeklarowane (np.  wskaznik końca bloku 
     przed początkiem) lub nie  zdefiniowano ich położenia wówczas 
     może  zostać  wyświetlony  odpowiedni  komunikat  o  błędzie.
^KN  Ustaw  lub  skasuj tryb operowania blokami  kolumn . WordStar      
     umożliwia definiowanie bloków na dwa sposoby . W pierwszym  z      
     nich w skład bloku wchodzi cały tekst znajdujący się pomiędzy 
     początkiem  a końcem bloku . Wówczas blok może składać się  z      
     wielu wierszy. Drugi z trybów zakłada, }e w skład bloku wcho-
     dzą  wyłącznie kolumny pomiędzy znacznikiem początku bloku  i 
     końca bloku . Znaczniki te wyznaczają "ramkę" , która określa 
     zawartość  bloku . W tym trybie zamiast znaczników początku i 
     końca  bloku na ekranie jest wyświetlana  kolumna  znaczników 
     początku i kolumna znaczników końca zbioru.
^KV  Przesuń blok . Komenda ta umożliwia przesunięcie tekstu znaj
     dującego  się  pomiędzy znacznikami początku i końca bloku  w 
     inne  miejsce w dokumencie . Znaczniki są przesuwane  wraz  z      
     zawartością  bloku do nowej pozycji . Blok jest przesuwany do      
     miejsca  wskazywanego  przez aktualne  ustawienie  kursora  i      
     zostanie on wpisany na lewo od niego (przed kursor). Operacja 
     przesunięcia bloku nie powoduje automatycznego  przeredagowa
     nia  tekstu . Po jej wykonaniu w zasadzie należy powrócić  do 
     miejsca  skąd pobrano blok i sprawdzić czy dany fragment jest 
     poprawnie  zredagowany . Podobnie  należy postąpić  z  partią 
     tekstu, do której przeniesiono blok.
^KC  Kopiuj blok . Komenda ta powoduje przepisanie bloku tekstu do      
     miejsca wskazywanego przez aktualne ustawienie kursora.Orygi
     nalny tekst pozostaje na swoim miejscu natomiast przesunięciu 
     do  miejsca przeznaczenia ulegają znaczniki początku i  końca 
     bloku. Blok jest kopiowany przed znak wskazywany przez aktua
     lne położenie kursora. Akapit, w obręb którego został skopio
     wany blok należy powtórnie przeredagować o ile to  konieczne. 
     Znaczniki  początku  i  końca  bloku są  takrze  przenoszone.
^KY  Usuń blok . Komenda ta służy do usuwania większych partii do-
     kumentu . Aktualnie  oznaczony blok tekstu  ulega  wymazaniu. 
     Operacja  ta jest wykonywana niezależnie od aktualnego  usta
     wienia  kursora . Po jej wykonaniu kursor nie zmienia  swojej 
     pozycji . Znaczniki nie ulegają wymazaniu i pozostają w  pop
     rzednio ustawionym miejscu (aczkolwiek blok przez nie wskazy
     wany jest pusty).
^KW  Zapisz  blok  do zbioru . Komenda ta umożliwia  zapisanie  do 
     innego  zbioru  niż aktualnie przetwarzany . Komenda ta  jest      
     wykonywana niezależnie od aktualnego ustawiania kursora i nie 
     zmienia jego położenia jak i samego dokumentu. Po jej wywoła
     niu należy podać nazwę zbioru zgodnie z omówionymi w poprzed
     nich rozdziałach zasadami . W przypadku , gdy zbiór o podanej 
     nazwie , już  istnieje na dysku , na ekranie wyświetlany jest 
     komunikat  z  pytaniem czy istniejący zbiór  zastąpić  nowym.

Wielkość  bloku jest uzależniona od dostępnej pamięci  operacyjnej 
oraz długości przetwarzanego dokumentu. W przypadku mikrokomputera 
IMP-85  wynosi  ona  statystzcznie rzecz biorąc do  kilku  tysięcy 
znaków . W przypadku IMP-86 praktycznie można przyjąć }e jest nie-
ograniczona  (w  całej dotychczasowej praktyce nie spotkano się  z 
takim przypadkiem). Należy tu ponadto przypomnieć, }e istnieją ko-
mendy  ^QB  i ^QK przesuwające kursor do pierwszego  i  ostatniego 
znaku w bloku oraz }e komenda ^QV po wykonaniu dowolnej z operacji 
na  bloku wskaże miejsce gdzie znajdował się blok przed wykonaniem 
danej funkcji.

             DODATKOWE KOMENDY DZIAŁAJACE NA ZBIORACH
             ----------------------------------------
Poza  omówionymi w rozdziale 1 komendami wchodzącymi w  skład  "NO 
FILE  MENU" WordStar pozwala ponadto na wykonywanie szeregu opera
cji na zbiorach podczas edycji dokumentu . W większości przypadków 
komendy  te działają identycznie jak komendy poprzednio  omówione. 
Tam gdzie to jest niezbędne wyraźnie wskażemy  istniejące różnice.

^KR  Wczytaj zbiór do aktualnie redagowanego dokumentu. Komenda ta      
     nie ma swojego odpowiednika na głównym poziomie edycji. Umoż
     liwia ona włączenie dowolnego zbioru do redagowanego dokumen
     tu . Zawartość  zbioru  jest wstawiana w miejsce   ustawienia 
     kursora (na lewo od niego) . Wczytywany  zbiór mógł powstać w 
     skutek  osobnego procesu edycji lub zostać zapisany na  dysku 
     za pomocą komendy  ^KW . Nazwę  zbioru należy podać zgodnie z 
     omawianymi poprzednio regułami.
^KJ  Komenda ta umożliwia usunięcie zbioru z dysku i działa  iden
     tycznie jak komenda Y w "NO FILE MENU".
^KL  Komenda ta służy do zmiany aktualnie wybranego dysku i działa      
     identycznie jak komenda L w "NO FILE MENU".
^KF  Komenda ta służy do ustawienia i kasowania wyświetlania kata
     logu  dysku . Jej działanie jest identyczne jak  w  przypadku 
     komendy F z "NO FILE MENU".
^KP  Komenda  ta służy do zaincjowania drukowania zbioru i  działa       
     jak komenda P z "NO FILE MENU". Obie te komendy zostaną omów-
     ione w rozdziale 8 . Trzeba tu jednak zaznaczyć }e komenda ta 
     powoduje  przerwanie edycji zbioru i zgubienie  wprowadzonych 
     poprawek  ( wydrukowany zostanie  nie  aktualnie  zredagowany 
     dokument ale jego ostatnia postać zapisana na dysku ).
^KO  Komenda  ta umożliwia skopiowanie zbioru i działa identycznie       
     jak komenda O z "NO FILE MENU".
^KE  Komenda  ta umożliwia zmianę nazwy zbioru na dysku  i  działa        
     identycznie jak komenda E z "NO FILE MENU".

                 KOMENDY OPISUJACE DZIAŁANIE WORDSTARA
                 -------------------------------------
Jak  wspomniano w rozdziale 1 WordStar potrafi udzielić informacji 
o  swoim działaniu . Służy temu wyświetlanie zestawień  dostępnych 
komend , opisów  znaków  sterujących oraz krótkich  komunikatów  o 
działaniu niektórych funkcji. Poza tym WordStar dysponuje komenda
mi  pozwalającymi  uzyskać informacje o jego  działaniu  w  formie 
niemalże  książkowej . Spis  tych komend nazywa się "HELP MENU"  i 
jest wyświetlany po wprowadzeniu przedrostka ^J o ile obowiązuje 2 
lub  3 poziom  "HELP" ( omówiono to w rozdziale 1 ) . Prezentujemy 
tutaj opis komend dostępnych w ramach funkcji "HELP":

^JH  Komenda  ta  ustawia poziom "HELP" i działa  identycznie  jak       
     komenda H "NO FILE MENU". Należy ją jednak dokładnie zapamię
     tać ponieważ jeżeli zagubiliśmy się w jakikolwiek sposób pod-
     czas  edycji i spowodowaliśmy uprzednio blokadę  wyświetlania 
     opisów  komend przez ustawienie zbyt niskiego poziomu  "HELP" 
     może ona ustrzec nas od popełnienia błędów rujnujących efekty 
     dotychczasowej pracy.
^JB  Komenda  ta wyświetla opis procesu redagowania  akapitu  przy        
     pomocy komendy ^B.
^JF  Komenda  ta  wyświetla  zestawienie flag  ukazujących  się  w       
     skrajnej  prawej  kolumnie  na  ekranie  wraz  z ich  opisem.
^JD  Komenda   ta  wyświetla  zestawienie  dostępnych  komend  DOT       
     ( omówimy  je w rozdziale 8 )  wraz  z  ich  krótkim  opisem.
^JI  Komenda  ta wyświetla zestawienie grup komend w powiązaniu  z       
     ich przedrostkami . O ile nie możemy znaleść jakiejś  funkcji       
     a  wiemy  }e  na pewno istnieje za pomocą tego  spisu  możemy       
     zorientować się , do której grupy poszukiwana komenda należy.
^JS  Komenda  ta wyświetla opis informacji ukazującej się w  linii       
     statusu ( skrajnej górnej linii ekranu ).
^JR  Komenda  ta podaje opis linijki oraz wskazuje w  jaki  sposób       
     można ją wykorzystać podczas redakcji tekstu.
^JM  Komenda   ta  wyjaśnia  ustawienia  marginesu  oraz   pozycji       
     tabulacji.
^JP  Komenda  ta  opisuje zasady ustawiania znaczników  w  tekście       
     oraz podaje do jakich  celów  mogą  one  być  wykorzystywane.
^JV  Komenda ta  opisuje  sposób wykonywania  operacji na blokach.

Opisane  powyżej  komendy wyświetlają informacje partiami . O  ile 
chcemy  zrezygnować  z dalszego ich przeglądania  należy  nacisnąć 
klawisz U lub <ESC>.
                          .
               DWIE NIE OMOWIONE DOTYCHCZAS KOMENDY
               ------------------------------------
Dotychczas  nie omówiliśmy jeszcze dwóch komend  WordStara . Stało 
się tak dlatego, }e }adna z nich sama nie  wykonuje  jakiejkolwiek 
operacji. Służą one bowiem do sterowania wielokrotnym wykonywaniem 
innych komend.                            Przedstawimy je poniżej.

^QQ  Komenda  ta umożliwia wielokrotne powtarzanie następnej wpro
     wadzonej komendy z szybkością kontrolowania przez  piszącego. 
     Po zadaniu komendy , która ma być powtarzana na ekranie  jest 
     wyświetlany komunikat "TYPE 1-9 TO VARY SPEED, SPACE TO STOP" 
     i  rozpoczyna się wykonywanie zadanej komendy . Odstęp  czasu 
     pomiędzy  kolejnymi wykonaniami może być kontrolowany za  po
     mocą cyfr od 1 do 9. Jedynka oznacza najszybsze powtarzanie a 
     dziewiątka najwolniejsze. WordStar inicjacyjnie ustawia szyb
     kość powtarzania na 3. Należy tu zwrócić uwagę na fakt, }e po   
     ^QQ można również podać zwykły znak alfanumeryczny. Będzie on 
     wówczas powielany w dokumencie zgodnie z obowiązującymi zasa
     dami redakcji.
^U   Komenda ta przerywa wykonanie dowolnej innej komendy. Komendy 
     o  długim  czasie  wykonania są  przerywane  bez  zakończenia 
     swoich funkcji i po przerwaniu kursor jest ustawiany w sposób 
     losowy. Ten sam efekt daje naciśnięcie klawisza <ESC>.

                      EDYCJA ZBIORU NIETEKSTOWEGO
                      ---------------------------
W  końcowej części tego rozdziału podsumujemy  różnice  istniejące 
podczas  edycji zbioru tekstowego i nietekstowego . Poniżej przed
stawiamy ich kompletną liste.

- Dynamiczne wyznaczanie końców stron jest wyłączone podczas  edy-
  cji  zbioru  nietekstowego  i nie może być  włączone  za  pomocą 
  komendy ^OP.
- W  linii  statusu wyświetlany jest numer znaku w obrębie  zbioru 
  oraz numer  znaku w linii  zamiast  strony i linii  na  stronie.
- Komendy DOT znajdujące się w zbiorze nietekstowym są ignorowane.
- Justowanie , przesuwanie  słów , zmienna tabulacja oraz  linijka   
  powinny  być  raczej wyłączone ale można załączyć każdą  z  tych   
  funkcji w razie potrzeby.
- Redakcja  akapitu (komenda ^B) może być używana również na zbio
  rach nietekstowych. Ponieważ jednak ustawia ona w pewnych  miej
  scach najstarszy , 8 bit , jej użycie może spowodować np.  błędy   
  komplikacji.

Nie  wyjaśniliśmy dotychczas różnicy pomiędzy zmiennymi i  stałymi 
pozycjami tabulacji.                           Są one następujące:

- W  przypadku używania stałych pozycji tabulacji , po wpisaniu do   
  dokumentu znaku <TAB> zamiast odpowiedniej ilości spacji wprowa
  dzny jest znak  I (09h).
- Stałe  pozycje tabulacji  są zawsze  ustawione co osiem  kolumn.
- Kursor  nie  może zostać przesunięty do obszaru  pustych  spacji 
  reprezentującego znak tabulacji.
- Pojedynczy  znak   napisany  na  znaku   tabulacji  niszczy  go.
- Znak tabulacji jest usuwany z dokumentu jak każdy inny  pojedyń
  czy znak.
- W przypadku wpisywania znaków przed znak tabulacji, będzie on co 
  pewien czas przesuwany do następnej pozycji tabulacji.

                               ROZDZIAŁ 7      ..
                      STEROWANIE WYDRUKIEM: CZESC 1
                    =================================
W rozdziale tym przedstawimy komendy WordStara służące do sterowa
nia drukowaniem zbioru . Są one umieszczone w zbiorze podczas jego 
edycji i dzielą się na dwie grupy: znaków sterujących i tzw. kome-
nd DOT.

                    ZNAKI STERUJACE WYDRUKIEM
                    -------------------------
Znaki  sterujące  są pojedyńczymi znakami wprowadzonymi do  zbioru 
podczas  jego edycji w celu uzyskania efektów  specjalnych  takich 
jak podkreślenie, wytłuszczony druk, dopisywanie pod czy nad pozo
stałą  częścią  tekstu . Komendy  tego rodzaju są  wprowadzone  do 
tekstu  przez  naciśnięcie ^P , a następnie kodu zadanej  funkcji. 
Mogą one być wprowadzone w dowolnym miejscu w linii i nie powodują 
}adanych  dodatkowych  efektów  podczas redagowania  akapitu . Nie 
należy  również zwracać uwagi na wydłużenie się linii poza  zadane 
marginesy przy wprowadzeniu znaków sterujących. Wynika to stąd, }e 
WordStar  umieszcza dodatkowe znaki w linii aby uwzgędnić  komendy 
sterujące wydrukiem , które nie są włączane do długości linii . Po 
wydrukowaniu zobaczymy, }e przesunięcia te znikną z tekstu. Jeżeli 
jednak utrudnia to nam znacznie proces redagowania tekstu  wówczas 
należy użyć komendy ^OD, która spowoduje usunięcie znaków sterują
cych wydrukiem z ekranu (ale nie ze zbioru) . Poniżej przedstawimy 
pełną listę znaków sterujących wydrukiem. Należy pamiętać,}e wpro
wadzenie ich do zbioru  musi być poprzedzone przez naciśnięcie ^P.

S   Komenda ta powoduje podkreślenie fragmentu tekstu znajdującego 
    się pomiędzy dwoma kolejnymi znakami S . Tylko znaki nie puste 
    są podkreślone , nie dotyczy to spacji czy  znaków  tabulacji.
B   Komenda ta powoduje wytłuszczenie fragmentu tekstu znajdujące
    go  się pomiędzy znacznikami B . Jest to  realizowane  poprzez 
    wielokrotne powtarzane drukowania tekstu w tym samym  miejscu.
D   Komenda  ta powoduje podwójne wydrukowanie tekstu znajdującego     
    się pomiędzy znacznikami D. Daje to w efekcie druk ciemniejszy
    od normalnego ale jasniejszy od druku wytłuszczonego.
X   Komenda ta służy do przekreślenia fragmentów tekstu . Powoduje 
    ona nadrukowanie znaku "-" na tekście znajdującym się pomiędzy 
    znacznikami  X  i może być używana do  wskazywania  usuniętych 
    podczas edycji partii tekstu.
H   Komenda  ta  powoduje napisanie następującego po nim znaku  na     
    znaku poprzednim i może być używana np. do budowy znaków naro-
    dowych o ile drukarka ich nie przewiduje.
O   Komenda ta umożliwia wprowadzenie do tekstu podczas drukowania
    spacji  niewidocznej  podczas drukowania  spacji  niewidocznej 
    podczas  edycji tekstu . Jest to przydatne gdy nie chcemy roz
    dzielenia kolenych słów np. wchodzących w skład nazwy własnej.
K   Komenda  ta jest używana przy definiowaniu nagłówków  stron  i     
    lokacji  numerów stron . Jej użycie powoduje , }e numer strony     
    jest drukowany przy prawej krawędzi dla stron nieparzystych  i     
    i przy lewej krawędzi dla stron parzystych.
L   Komenda ta powoduje przejście do nowej strony w miejscu  gdzie 
    została użyta.
C   Komenda ta powoduje zatrzymanie wyduku w miejscu , gdzie umie
    szczono  ten  znak . Wydruk  jest wznawiany  przez  operatora.     
    Po zatrzymaniu wydruku w linii statusu pojawia się tekst PRINT
    PAUSED . Drukowanie  może  być wznowione przez funkcje  P  dla 
    głównego poziomu edycji lub przez  ^KP gdy rozpoczęto  podczas     
    edycji zbioru . Funkcja ta jest niezbędna w przypadku stosowa
    nia  np.  specjalnych  rodzajów druku  wymagających  uprzednio 
    ręcznej obsługi drukarki.

Działanie  komend sterujących wydrukiem jest w dużej mierze uzale
}nione  od  właściwości drukarki . Komendy  przedstawione  powyżej 
działają  zawsze w opisany sposób . Poniżej przedstawimy pozostałe 
znaki sterujące wydrukiem zastrzegając jednak , }e funkcje te  nie 
są realizowane przez  wszystkie drukarki  znajdujące się na rynku.

U   Komenda  ta  umożliwia wydrukowanie  zdefiniowanego  fragmentu 
    tekstu  o  połowie odstępu międzyliniowego poniżej  pozostałej 
    części wiersza . Jest to przydatne przy redagowaniu wszelkiego 
    rodzaju formuł matematycznych, fizycznych czy chemicznych. Po-
    dobny efekt można uzyskać przez zastosowanie podwójnego odstę
    pu międzyliniowego i  wykorzystanie dodatkowych linii pustych.
T   Komenda ta spełnia podobną funkcję jak opisana powyżej , z tym      
    }e  faza  jest drukowana  powyżej  pozostałej  części  tekstu.
Y   Komenda  ta  umożliwia zmianę koloru taśmy  barwiącej  podczas      
    drukowania . Następne  jej użycie przywraca  podstawowy  kolor      
    taśmy barwiącej.
A   Komenda  ta pozwala na wybór jednej z dwóch szerokości  znaków      
    używanych  podczas  wydruku .  Alternatywna  szerokość  znaków      
    można zdefiniować za pomocą komendy DOT.CW.
N   Komenda ta przywraca podstawową szerokość znaku.
F   Komenda ta umożliwia drukowanie znaku specjalnego, który część     
    drukarek posiada w miejscu spacji (kod 20h) . Spacja jest rea-
    lizowana za pomocą specjalnej sekwencjisterującej  przesuwają
    cej głowice drukującą o znak w prawo.
G   Komenda ta umożliwia wydrukowanie znaku odpowiadającego klawi
    szowi DEL (kod 7Fh).

Poza opisami powyżej znakami sterującymi wydrukiem WordStar  umoż
liwia użycie czterech innych . Są to Q , W , E i R . Ich znaczenie 
jest  całkowicie  definiowane podczas  instalacji  dla  komkretnej 
drukarki. Najczęściej nie powodują one }adnych działań.

                           KOMENDY DOT
                           -----------
Komenda  DOT to specjalne linie wtrącane w tekst,które są pomijane 
podczas drukowania zbioru . Służą one do ustalania ogólnych  zasad 
redakcji tekstu,takich jak format strony czy treść nagłówka. Kome
ndy  te  są  opcjonalne i nie trzeba ich koniecznie  umieszczać  w 
zbiorze. W przypadku nie użycia ich WordStar przyjmie pewne warto
^ci zastępcze. Komenda DOT składa się z dwóch znaków poprzedzonych 
kropką  w pierwszej kolumnie i jest zawsze wyświetlana na  ekranie 
podczas  edycji tekstu . Poza zwykłymi komendami DOT dopuszczonymi 
przez WordStara generator pocztowy MailMerge posiada własne komen
dy DOT. Omówimy je w rozdziale 9.

                      Pionowy format strony
                      ---------------------
Przedstawimy tu komendy DOT określające ułożenie wierszy na  stro
nie. Są one następujące.

LH n  Komenda ta określa wysokość druku dla danej drukarki . Para
      metr  n definiowany jest następująco:  liczba linii na cal = 
      n/48 i może zmieniać się od 1 do 24 . Wartość domyślna  tego 
      parametru  wynosi 8 (odpowiada to 6 wierszom na cal) . Usta
      wienie  komendy  LH zależy wyłącznie od  wysokości  czcionki 
      używanej drukarki.
PL n  Komenda ta określa fizyczną długość strony w liniach . Para
      metr n należy traktować jako ilość znaków LF ,  które należy 
      wysłać, aby papier ustawił się na początku następnej strony. 
      Ustawienie  tej komendy zależy zarówno od wielkości czcionki 
      drukarki, jak i użytego papieru . Wartość domyślna parametru 
      n wynosi 66 linii na stronę.
MT n  Komenda  ta określa odległość pomiędzy fizycznym  początkiem        
      strony, a pierwszą linią tekstu . Odległość ta jest mierzona       
      liczbą linii. Domyślna wartość parametru n wynosi 3.
MB  n Komenda  określa odległość pomiędzy ostatnią linią tekstu na 
      stronie,a pierwszą linią następnej strony. Odległość ta jest 
      mierzona liczbą linii. Domyślna wartość parametru  wynosi 8.
HM n  Komenda  ta określa odległość pomiędzy nagłówkiem  strony, a        
      pierwszą linią tekstu mierzoną ilością pustych linii. Domyś
      lna wartość tego parametru wynosi 2.
FM n  Komenda  ta  określa  odległość pomiędzy  linią  zawierającą 
      numer strony , a ostatnią linią tekstu na stronie . Domyślna        
      wartość parametru wynosi 2.

                      Poziomy format strony 
                      ---------------------
Większość  komend określających poziomy format strony jest wykony
wany na bieżąco podczas edycji tekstu. Istnieją tylko dwie komendy 
DOT określające położenie tekstu na stronie w poziomie .    Są to:

PC n  Komenda ta określa numer kolumny,w której ma  być  drukowany        
      numer strony,o ile numeracja stron jest włączona i nie zada-
      no innego sposobu jej drukowania .  Numer kolumny jest usta
      wiany  domyślnie  tak,aby pokrywał się  ze ^rodkową  kolumną 
      tekstu na stronie.
PO n  Komenda ta określa ile spacji ma być drukowanych przed każdą        
      linią tekstu na stronie . Umożliwia to przesuwanie tekstu  w        
      poziomie. Domyślna wartość parametru n wynosi 8.

                      Stronicowanie tekstu
                      --------------------
Stronicowanie tekstu jest realizowane w oparciu o komendy określa
jące format strony. Istnieją jednak dwie komendy DOT umożliwiające 
zmianę zasad , według jakich wyznaczone są końce stron.

PA  Komenda  ta  wprowadza bezwarunkowy koniec strony w  linii , w      
    której została umieszczona. Koniec strony zostanie wygenerowa
    ny , o ile  liczba linii od miejsca  umieszczenia  komendy  do 
    aktualnego końca strony jest mniejsza niż n.
Przedstawione powyżej komendy umożliwiają automatyczne generowanie 
przesunięć tekstu do nowej strony po zakończeniu rozdziału czy też 
w  celu zapewnienia ciągłości podrozdziałów na stronie (aby podty
tuł nie znajdował się na innej stronie niż treść).

                            ROZDZIAŁ 8     ..
                  STEROWANIE WYDRUKIEM: CZESC 2
                =================================
W rozdziale tym przedstawimy pozostałe komendy DOT oraz  inicjowa
nie drukowania dokumentu.
                                   .
           KOMENDY DEFINIUJACE NAGŁOWEK I STOPKE STRONY
           --------------------------------------------
WordStar  umożliwia  automatyczną generację nagłówka i  stopki  na 
każdej  stronie . Przedstawimy tutaj komendy służące do  generacji 
tych opcji.                                                 Są to:

HE tekst  Komenda ta definiuje nagłówek jaki,będzie umieszczany na
          każdej stronie od  następnej poczynając . Nagłówek można            
          zmieniać tak często jak to potrzebne. Inicjacyjnie zawa
          rtość nagłówka jest pusta.W celu zaprzestania umieszcza
          nia  nagłówków na kolejnych stronach należy podać  pustą 
          komendę HE . Należy tu zwrócić uwagę na fakt , }e jeżeli 
          górny  margines  został zdefiniowany jako 0 , nie będzie 
          drukowany }aden nagłówek ( musi on być drukowany  pomię
          dzy pierwszą linią na stronie,a pierwszą linią tekstu ).
FO tekst  Komenda ta definiuje  "stopkę" umieszczoną u dołu każdej
          strony, poczynając od strony,na której umieszczono kome-
          ndę . Treść stopki może być wielokrotnie zmieniana . Gdy 
          nie zdefiniowano stopki lub zadano pustą stopkę (komenda 
          FO  bez tekstu) będzie w jej miejscu  drukowany  kolejny 
          numer strony,o ile nie zablokowano jego drukowania spec
          jalną komendą , którą omówimy póżniej. Gdy zadeklarowano 
          stopkę , numer strony nie jest automatycznie  drukowany. 
          Analogicznie  do komendy  HE stopka nie jest drukowana , 
          gdy dolny margines został ustawiony na 0 (MB 0).

Zarówno  w nagłówku jak i w stopce może być drukowany numer  stro
ny.Jest  on umieszczony w miejscu wskazanym w tekście  przez  znak 
"#".Ponadto w celu sterowania wydrukiem numeru strony można używać 
znaku K . Wspomniano o nim w poprzednim rozdziale . Jego znaczenie 
jest następujące: jeżeli numer strony jest parzysty,ignoruj spacje 
umieszczone w tekście nagłówka lub stopki, aż do napotkania pierw
szego  znaku różnego od spacji . Umożliwia to  drukowanie  numerów 
strony  w  lewym  rogu dla stron parzystych i w prawym  dla  stron 
nieparzystych . Jeżeli w nagłówku lub stopce ma znajdować się znak 
"#"  należy poprzedzić go znakiem "/" ("/#") . Należy  tu  zwrócić 
uwagę , }e  umieszczenie  numeru  strony w nagłówku  nie  powoduje 
automatycznie  wstrzymania  druku numerów stron  w  linii  stopki. 
Należy w tym celu użyć specjalnej komendy. Tekst nagłówka i stopki 
może zawierać  również wszystkie znaki sterujące wydrukiem , jakie 
opisano w poprzednim rozdziale.

                KOMENDY STERUJACE NUMERACJA STRON
                ---------------------------------
Istnieją trzy komendy  DOT  sterujące procesem numerowania stron :

OP    Komenda ta powoduje  zawieszenie numerowania stron , gdy nie     
      zdefiniowano linii stopki.
PN    Komenda  ta przywraca numerowanie  stron , jeżeli  uprzednio 
      użyto komendy PO . W przypadku, gdy zdefiniowano stopkę inną
      niż , pusta nie daje ona }adnego efektu.
PN n  Komenda ta powoduje rozpoczęcie numerowania stron z bieżącym 
      numerem n . WordStar dopuszcza numery stron od 1 do  65333 ,
      jednak maksymalny numer strony  zadany za pomocą tej komendy
      nie może być większy niż 255. W przypadku, gdy zadeklarowano 
      uprzednio stopkę,wówczas aktualny numer strony ( uwzględnia
      jący zmianę numeracji ) jest umieszczany w miejscu wskazanym 
      przez znak "#".

                      POZOSTAŁE KOMENDY DOT
                      ---------------------
Poza  przedstawionymi dotychczas WordStar rozpoznaje kilka  innych 
komend  DOT . Wszystkie  one z wyjątkiem  jednej  (identyfikującej 
komentarz  ),są uzależnione od typu zastosowanej w mikrokomputerze 
drukarki . Drukarki znajdujące się obecnie na polskim rynku nie są 
przystosowane do wykonywania tych komend.

tekst  Komenda ta umożliwia wstawianie do zbioru komentarzy, które 
       nie są uwzględniane podczas drukowania tekstu.
CW n   Komenda  ta umożliwia ustawienie  alternatywnej  szerokości 
       druku . Parametr n jest definiowany jako: szerokość znaku = 
       n/120 cala. Jego inicjacyjna wartość wynosi 12.
SR n   Komenda ta definiuje przesunięcie wykorzystywane przy dopi
       saniu  fraz  poniżej lub powyżej linii tekstu . Parametr  n 
       jest zdefiniowany jako:  wysokość przesunięcia = n/48  cala         
       Jego inicjacyjna wartość wynosi 3.
UJ 0/1 Komenda ta służy do załączania lub wyłączania mikrojustowa
       nia  tekstu . Proces ten polega na wracaniu w tekst  mikro
       odstępów o szerokości 1/128 cala podczas wyrównywania  pra-
       wego marginesu. Inicjacyjnie przełącznik ten jest włączony.        
       Zamiast UJ 0/1 można używać UJ OFF/ ON.
BP 0/1 Komenda ta służy do załączania i wyłączania dwukierunkowego        
       drukowania  tekstu  (podczas wysuwu głowicy jest  drukowana         
       pierwsza linia , a podczas jej powrotu następna). Przyśpie
       sza to znacznie proces drukowania . Dla drukarek posiadają
       cych  tą  własność  przełącznik ten jest  włączany  podczas 
       inicjalizacji WordStara . Analogicznie do komendy UJ  można 
       jej używać w postaci BP OFF/ON.

                  PROCEDURA DRUKOWANIA DOKUMENTU
                  ------------------------------
Funkcje  drukujące  WordStara   powodują  wydrukowanie  zawartości 
zbioru dyskowego. Jeżeli podczas inicjacji drukowania nie zdecydo
wano inaczej , wówczas do wydruku dodawane są  nagłówki  i  stopki 
stron oraz górny i dolny margines . Ogólniej,wszystkie komendy DOT 
i   znaki  sterujące  wydrukiem  są  odpowiednio   interpretowane. 
WordStar dopuszcza również drukowanie zbioru "na , dysk" . Jest to 
przydatne   w celu zachowania zbioru dla wielu pózniejszych wydru
ków lub gdy zachodzi konieczność dodatkowego zweryfikowania druko
wanego  tekstu . W takim przypadku komendy DOT są  interpretowane, 
natomiast większość znaków sterujących wydrukiem pozostaje w zbio
rze wynikowym w postaci niezmienionej. Gdy, taki zbiór nie zawiera 
znaków  sterujących  wydrukiem ,  może on być pózniej drukowany  z 
dysku wprost na drukarkę bez użycia WordStara.

                 Inicjalizacja procedury wydruku
                 -------------------------------
Wydruk dokumentu może być rozpoczęty za pomocą komendy P ("NO FILE 
MENU")  lub  komendy ^KP dostępnej w  czasie  edycji.  Po  zadaniu 
komendy  WordStar  pyta o  nazwę  zbioru , który ma być drukowany:

                      NAME OF FILE TO PRINT?

W odpowiedzi należy podać nazwę zbioru zgodnie z zasadami  obowią
zującymi  przy rozpoczynaniu edycji dokumentu (wszystkie  dostępne 
tam  funkcje  sterujące  obowiązują tu również) . Gdy  nie  chcemy 
zmieniać  }adnej z opcji procedury drukowania należy  upewnić  się 
czy  drukarka  jest właściwie ustawiona i nacisnąć  klawisz  <ESC> 
(lub  U). W celu wymuszenia pytań o kolejne opcje procedury druko
wania należy zaakceptować nazwę za pomocą klawisza RET. Na kolejne 
pytania  należy odpowiadać pamiętając,}e naciśnięcie klawisza  "Y" 
lub  "y" oznacza odpowiedż "TAK",naciśnięcie dowolnego innego kla
wisza odpowiedż "nie", <RET> powoduje przyjęcie odpowiedzi domyśl
nej (dla  danego pytania jest ona taka wtedy , gdy rezygnujemy  ze 
zmieniania opcji drukowania) . Naciśnięcie w odpowiedzi na dowolne 
pytanie  klawisza  <ESC>  oznacza rezygnację z  dalszych  pytań  o 
kolejne opcje . Poniżej przedstawiamy szczegółowy opis  wszystkich 
opcji procedury drukowania.

                     DISK FILE OUTPUT (Y/N):

Odpowiedż  NIE jest odpowiedzią domyślną na to pytanie i  powoduje 
skierowanie wydruku na drukarkę . Odpowidż TAK powoduje umieszcze
nie  wydruku w zbiorze dyskowym i WordStar zadaje pytanie pomocni
cze o nazwie zbioru:
                         DISK FILE NAME:

na które należy odpowiedzieć zgodnie z podanymi uprzednio zasadami 
wprowadzania nazwy zbioru.

          START AT PAGE NUMBER (RETURN FOR BEGINNING) ?

W odpowiedzi należy podać numer strony,od której ma być rozpoczęty 
wydruk. Umożliwia to drukowanie fragmentów dokumentu lub reinicja
lizację  wydruku po skończeniu się papieru w  drukarce . Odpowiedź 
pusta,0 lub 1 spowoduje rozpoczęcie drukowania od początku zbioru. 
W  przypadku  podania odpowiedzi  nienumerycznej  pytanie  zostaje 
powtórzone.

              STOP AT PAGE NUMBER (RETURN for end) ?

W odpowiedzi należy podać numer strony, po osiągnięciu której dru
kowanie zbioru ma być przerwane . Umożliwia to automatyczne zakoń
czenie  drukowania fragmentu dokumentu bez manualnego  przerywania 
procesu drukowania . Odpowiedź pusta oznacza,}e drukowanie  będzie 
kontynuowane aż do osiągnięcia końca zbioru.

                      USE FORM FEEDS (Y/N):

W normalnym trybie drukowania WordStar wysyła na drukarkę odpowie
dnią  ilość pustych linii w celu przesunięcia papieru do  początku 
nowej strony. Gdy odpowiemy TAK na to pytanie zamiast wielu znaków 
LF  po zakończeniu drukowania strony zostanie wysłany znak FF (kod 
OCh) . Jeżeli  drukarka  potrafi automatycznie wysuwać  papier  do 
początku nowej strony przyśpiesza to znacznie proces drukowania  i 
zwalnia użytkownika od definiowania liczby linii na stronie (kome
nda .PL).

                 SUPPRESS PAGE FORMATTING (Y/N):

Od  odpowiedzi na to pytanie zależy czy komendy DOT znajdujące się 
w zbiorze zostaną odpowiednio zintepretowane , czy też zostaną one 
wydrukowane w takiej postaci,w jakiej zostały wprowadzone do zbio
ru . Marginesy , nagłówki, stopki czy numery stron nie są dodawane 
do drukowanego tekstu . Znaki sterujące  wydrukiem są w większości 
interpretowane  niezależnie od  odpowiedzi na to pytanie . Radzimy 
używać tego  sposobu drukowania zbioru , gdy  chcemy  zweryfikować 
ustawienie komend DOT, lub gdy drukujemy za pomocą WordStara zbiór 
wygenerowany przez inny edytor.

           PAUSE FOR PAPER CHANGE BETWEEN PAGES (Y/N):

Gdy  używamy papieru w pojedynczych arkuszach ,  wówczas opcja  ta 
jest konieczna.  Powoduje ona przerwę po wydrukowaniu każdej stro
ny , co umożliwia podłożenie następnego arkusza papieru . Domyślna 
odpowiedź na to pytanie brzmi NIE.

                   Ready printer, press RETURN:

Po  udzieleniu  odpowiedzi na wszystkie poprzednio omówione  pyta
nia , jeżeli nasza drukarka jest włączona należy  nacisnąć klawisz 
<RETURN> i proces drukowania dokumentu zostanie rozpoczęty. Jeżeli 
podczas  drukowania nie używamy wysuwu papieru do nowej  strony  , 
upewnić się czy , papier jest ustawiony  na początku nowej strony.

                Zawieszenie i przerywanie wydruku
                ---------------------------------
Ponowne  zadanie komendy P (lub  KP podczas  edycji) , gdy  proces 
drukowania  jest  w toku spowoduje wstrzymanie wydruku i  ukazanie 
się pytania:
      TYPE"Y" TO ABANDON PRINT, "N" TO RESUME , U  TO HOLD:
gdzie:                        "Y" powoduje  przerwanie  drukowania
                              "N" spwoduje  wznowienie  drukowania   
                              "U" spowoduje zawieszenie drukowania
      
Po  zawieszeniu drukowania w linii statusu pojawia  się  komunikat 
PRINT PAUSED . Drukowanie może być wznowione przez ponowne podanie 
komendy  drukowania (odpowiednio  KP lub P) . Gdy chcemy  przerwać 
aktualnie  zawieszony proces drukowania należy podać komendę wzna
wiającą drukowanie dwukrotnie i na pytanie o przerwanie drukowania 
odpowiedzieć TAK.






             ========================================
             !              ROZDZIAŁ 9              !
             !  GENERATOR KORESPONDENCJI MAILMERGE  !
             ========================================
MailMerge  jest programem uzupełniającym i działa tylko w połącze
niu z WordStarem . Pozwala on na generowanie listów z  nazwiskami, 
adresami lub inną informacją,która jest automatycznie wstawiana do 
korespondencji.Informacja ta może być wprowadzona z klawiatury lub 
może   pochodzić  z  przygotowanego  wcześniej  zbioru  dyskowego. 
Działanie generatora MailMerge polega na tworzeniu wielu  dokumen
tów  skierowanych do różnych adresatów w oparciu o  przygotowywany 
za  pomocą WordStara zbiór,który zawiera podstawową treść  oraz  o 
informację indywidualizującą każdy dokument.

                             ZMIENNE
                             -------
Zmienna  generatora MailMerge to symboliczna nazwa łańcucha znaków 
(fragmentu tekstu),który może być różny dla rozmaitych listów  lub 
innych  dokumentów generowanych w oparciu o ten sam zbiór zawiera
jący podstawową treść . Nazwa zmiennej składa się z co najwyżej 39 
liter lub cyfr i musi rozpoczynać się od litery. Ponadto w nazwach 
można  używać  "twardych" myślników  (znaków  przeniesienia  "-"). 
Nazwy  zmiennych są używane w komendach DOT MailMerge w celu przy
porządkowania im konkretnych tekstów . Poniżej przedstawiamy kilka 
przykładów nazw:        NAZWISKO
                        ADRES1
                        DATA-CZAS
Odwołania  do  nazw są umieszczane w zbiorze  zawierającym  bazową 
treść  dokumentu i wskazują miejsca , w których ma być umieszczony 
tekst  aktualnie przyporządkowany danym nazwom.Odwołanie do  nazwy 
składa  się  ze znaku "&",nazwy zmiennej i  kolejnego  znaku  "&". 
Spacje oraz znaki <CR> znajdujące się pomiędzy znakami "&" i nazwą 
zmiennej są ignorowane . Należy tu zwrócić uwagę na fakt,}e użycie 
jakiegokolwiek  z  tych znaków w obrębie nazwy zmiennej  spowoduje 
błąd. Poniżej przedstawiamy kilka przykładów odwołań do nazw zmie
nnych:           & NAZWISKO &
                 & ADRES 1 &
                 & DATA-CZAS &
Długość tekstu reprezentowanego przez zmienną nie może być większa 
niż 200 znaków. Zmiennej  można  przyporządkować  tekst  za pomocą 
trzech  metod:

- wykorzystując specjalny zbiór danych , zawierający kolejne "war
  tości" zmiennych:
- wprowadzając odpowiednie dane z konsoli:
- przyporządkowując zmiennej  tekst  w dokumencie  podstawowym lub   
  dodatkowym, który będzie dołączany podczas generacji.

Zmiennej należy  nadać  wartość , nim nastąpi  odwołanie  do niej. 
Odwołania do  niezdefiniowanych zmiennych są ignorowane i  zostaną 
wydrukowane  w  ostatecznej postaci dokumentu wraz ze  znacznikami 
("&").  Pozwala to na używanie znaku "&" bez obawy, }e zostanie on 
zawsze potraktowany jako znacznik odwołania do nazwy zmiennej.

                   ZBIORY DANYCH DLA MAILMERGE
                   ---------------------------
Zbiory  danych  zawierają pogrupowane  wartości  zmiennych , które 
zostaną wykorzystane przez MailMerge podczas generowania kolejnych 
kopii  listów  (lub innych dokumentów).Pojedynczy  wiersz  takiego 
zbioru zawiera aktualne wartości zmiennych oddzielone przecinkami.
Po ostatniej pozycji w wierszu musi znajdować się znak <CR>. Można 
pominąć aktualną wartość zmiennej, należy jednak pamiętać o pozos
tawieniu  odpowiadającego jej przecinka (w wierszu,w którym  pomi
nięto  wartość zmiennej musi być zasygnalizowana taka sama  liczba 
pozycji jak w pozostałych wierszach). W przypadku gdy tekst będący 
wartością zmiennej zawiera przecinek,spacje poprzedzające pierwszy 
znak lub następujące po ostatnim znaku należy go oznaczyć apostro
fami (znakami "przed pierwszym i po ostatnim znaku tekstu). W celu 
przygotowania  zbioru  danych dla MailMerge można  użyć  WordStara 
otwierając taki zbiór w trybie nietekstowym (N) lub dowolnego sta-
ndardowego  edytora (np. edytora ED sys. CP/M lub EDLIN sys. DOS).

                         KILKA PRZYKŁADOW
                         ---------------
Przed szczegółowym omówieniem komend MailMerge omówimy kilka przy
kładów ilustrujących sposób przygotowywania zbiorów  zawierających 
podstawową  postać dokumentu.  Przykłady te opisują sposób,w  jaki 
należy  umieszczać kolejne komendy DOT WordStara i MailMerge  pod
czas tworzenia takich zbiorów.

                Generacja w oparciu o zbiór danych
                ----------------------------------
OP -- Komenda ta powoduje wyłączenie numeracji stron.  Nie  użycie 
      jej  spowoduje , }e  kolejne listy będą numerowane  tak  jak 
      strony tekstu.
DF filename  -- Komenda  ta definiuje nazwę  zbioru  zawierającego       
      wartości zmiennych dla kolejnych listów.
RV zmienna 1,zmienna 2,...,zmienna k -- Komenda  ta powoduje wczy
      tanie  k  kolejnych  pozycji  ze  zbioru  danych  i  przypo      
      rządkowanie ich kolejnym zmiennym.
treść listu -- Kolejne wiersze powinny zawierać treść listu  wyko
      rzystując odwołania do zmiennych (&zmienna i &)  tam , gdzie 
      jest to potrzebne.
A --  Komenda  ta  spowoduje przesunięcie  papieru w  drukarce  do       
      nowej strony przed rozpoczęciem drukowania następnego listu.

         Generacja w oparciu o dane wprowadzane z konsoli
         ------------------------------------------------
OP -- Komenda ta powoduje wyłączenie numeracji stron.
CS -- Komenda ta spowoduje wymazanie zawartości ekranu przed  roz
      poczęciem  zadawania  pytań o  kolejne  wartości  zmiennych.
      AV "komunikat", zmienna 1
      AV "komunikat", zmienna 2
      AV "komunikat", zmienna k
      Każda  z  tych komend spowoduje wyświetlenie  komunikatu  na 
      ekranie i wczytanie wartości zmiennej.
treść listu -- Kolejne wiersze powinny zawierać treść listu, wyko
      rzystując  odwołania do zmiennych (&zmienna i&)  tam , gdzie 
      jest to potrzebne.
A --  Komenda  ta  spowoduje przesunięcie papieru do nowej  strony 
      przed rozpoczęciem drukowania następnego listu.
FI filename -- Gdy wyspecyfikowana nazwa jest nazwą opisywanego tu         
      zbioru , komenda  ta spowoduje wygenerowanie kolejnego listu         
      (listy  będą  generowane  tak  długo , jak  długo  działanie 
      MeilMerge nie zostanie przerwane).

                    Wydrukowanie zbioru danych
                    --------------------------
DF filename -- Komenda ta definiuje nazwę zbioru danych, który będzie 
      drukowany.
RV zmienna  1,zmienna  2,....,zmienna k  -- Komenda  ta  spowoduje 
      wczytanie  k kolejnych pozycji ze zbioru i danych i  przypo
      rządkowanie ich wskazanym zmiennym.
CP k -- Komenda ta spowoduje przesunięcie papieru do nowej strony, 
      o  ile  wszystkie  wczytane  teksty  nie  zmieszczą  się  na 
      bieżącej stronie.
      &zmienna 1&
      &zmienna 2&
      &zmienna 3&
      Odwołania do zmiennych spowodują wydrukowanie ich aktualnych 
      wartości (tekstów odpowiadających im w danej chwili).

        Wczytanie pojedynczego parametru dla wielu listów
        -------------------------------------------------
AV "komunikat",zmienna -- Komenda ta spowoduje wczytanie  pojedyn
      czej zmiennej.
FI filename -- Komenda ta spowoduje wczytanie zbioru o wyspecjali
      zowanej   nazwie.  Zbiór ten może zawierać  również  komendy 
      MailMerge  ( w szczególności  może on być  zbudowany  według 
      dowolnej, z poprzednio omówionych, zasad ) oraz odwołania do 
      zmiennej , której wartość wczytano przy pomocy  komendy  AV.

                 Wczytanie z konsoli nazwy zbioru
                 --------------------------------
AV "Dokument:",DOCFILE / AV "Dane:",DATFILE -- komendy te spowodu
      ją   wczytanie   z   konsoli   wartości   dwóch   zmiennych:
      DOCFILE  i  DATFILE.
FI &DOCFILE&  -- Komenda  ta spowoduje wczytanie zbioru  o  nazwie 
      podanej  przez operatora w odpowiedzi na pytanie  o  wartość 
      pierwszej  zmiennej.  Jeżeli  zbiór ten zawiera  komendę  DF 
      &DATFILE& , wówczas  zostanie wygenerowany  zestaw listów  w 
      oparciu  o zbiór , którego nazwę podał operator w odpowiedzi 
      na pytanie o wartość drugiej zmiennej.

                 KOMENDY DOT GENERATORA MAILMERGE
                 --------------------------------
Przedstawimy  teraz  szczegółowy opis  komend  wykonywanych  przez 
generator MailMerge. Postać tych komend jest identyczna jak komend 
DOT WordStara.

               Komendy sterujące procesem generacji
               ------------------------------------
Ta grupa komend służy do nadawania wartości zmiennych oraz do two-
rzenia ostatecznej postaci generowanej korespondencji.

DF <filename> CHANGE -- Komenda ta określa zbiór danych zawierają
      cy zestaw wartości zmiennych , który ma być użyty do genero
      wania danej partii listów.  Komenda ta może również zawierać 
      opcjonalny parametr CHANGE podany po nazwie zbioru i oddzie
      lony od niej spacją . Umożliwia on wymianę dysków , gdy  nie 
      można zapewnić równoczesnej dostępności zbiorów tekstowych i
      zbioru danych.
RV var1,...,  varK -- Komenda ta służy do nadawania wartości zmie
      nnym i definiuje sposób uporządkowania zbioru danych.  Lista             
      zmiennych musi odpowiadać ilości pozycji i ich  uporządkowa
      niu w zbiorze danych.
RP n -- Komenda  ta definiuje ile razy dany dokument ma być przet
      warzany. Jeżeli pominięto parametr n, wówczas proces genera
      cji  będzie  powtarzany  aż do  wyczerpania  zbioru  danych. 
      Komenda  DF implikuje komendę RP bez parametru n.  Tak  więc 
      komenda  RP  jest niezbędna tylko , gdy chcemy  wielokrotnie 
      wstawić inny dokument do podstawowego tekstu.
SV var,val -- Komenda ta umożliwia nadanie wartości  zmiennej.  Po 
      jej wykonaniu , zmiennej zostanie przypisana pozostała część
      wiersza.
AV "msg",var,lgth  -- Komenda  ta  umożliwia wczytanie  z  konsoli 
      wartości zmiennej. Komunikat "msg"jest opcjonalny. Zawarty w 
      apostrofach komunikat zostanie  wyświetlony na ekranie przed 
      wczytaniem wartości zmiennej. Opcjonalny parametr lgth okre
      ^la  maksymalną długość  tekstu , który  zostanie  wczytany.
DM msg -- Komenda  ta  powoduje  wyświetlenie  pozostałej   części 
      wiersza na ekranie.
CS msg -- Komenda  ta  powoduje  wymazanie ekranu  i  wyświetlenie 
      pozostałej części wiersza. 
FI filename CHANGE -- Komenda ta powoduje wczytanie zdefiniowanego 
      zbioru  do generowanego dokumentu.  Treść tego  zbioru  jest  
      umieszczana w miejscu,gdzie znajduje się komenda FI.  Jeżeli 
      wyspecyfikowany zbiór zawiera jedną z komend: DF,RV; wczyty
      wanie może być powtarzane wielokrotnie.

                   Komendy sterujące wydrukiem
                   ---------------------------
W  zasadzie sterowanie wydrukiem podczas generacji  korespondencji 
odbywa się za pomocą standardowych komend WordStara. Wszystkie one 
obowiązują i są poprawnie interpretowane podczas działania MailMe
rge. Jednak z uwagi na możliwości zmian w formacie wydruku wskutek 
np. wstawiania do dokumentu długich tekstów , MailMerge przewiduje 
szereg komend korygujących potencjalne błędy.Poniżej przedstawiamy 
ich  kompletną  listę.  Jeżeli dowolna z  przedstawionych  poniżej 
komend  nie została użyta , domyślnie obowiązuje stan  DIS , który 
oznacza  zachowanie  formatu  określonego  w  zbiorze  wejściowym.

PF ON/OFF/DIS  -- Komenda ta określa sposób  formatowania  tekstu. 
      Jeżeli którakolwiek  z podanych poniżej komend  ma działać ,
      przełącznik formatowania musi być ustawiony na ON.  Ustawie
      nie  go  na OFF powoduje  brak  jakiegokolwiek  formatowania 
      tekstu  przez MailMerge.  Stan DIS oznacza , }e formatowaniu 
      podlegają wyłącznie partie tekstu od odwołania się do  zmie
      nnej do najbliższego końca akapitu.
RM n/DIS -- Komenda ta  ustawia prawy margines formatowanego  tek
      stu. Można go zmieniać w przedziale od 1 do 240.
LM n/DIS -- Komenda ta ustawia lewy margines formatowanego tekstu.          
      Można go zmieniać w przedziale od 1 do 240.
LS n/DIS -- Komenda  ta ustawia wielkość odstępu  międzyliniowego.          
      Można go zmieniać w przedziale od 1 do 9.
 OJ ON/OFF/DIS  -- Komenda ta włącza lub wyłącza justowanie tekstu 
      podczas drukowania . Stan DIS oznacza, }e justowaniu podlega           
      wyłącznie partia tekstu od odwołania się do zmiennej do naj-
      bliższego  końca akapitu .  IJ ON/OFF/DIS Komenda ta określa 
      sposób  traktowania przez MailMerge tekstu   wejściowego . W 
      przypadku gdy, przełącznik ten jest ON, tekst wejściowy jest 
      traktowany jako prawostronnie wyrównany. Gdy przełącznik ten 
      jest OFF, tekst wejściowy jest traktowany jako niewyrównany.

           URUCHAMIAMY PROCES GENERACJI KORESPONDENCJI
           -------------------------------------------
Generator  MailMerge  uruchamiany jest z głównego  poziomu  edycji 
(tzw. NO-FILE MENU) przy pomocy komendy M . Po jej wprowadzeniu na 
ekranie pojawia się pytanie:

                  NAME OF FILE TO MERGE - PRINT?

W odpowiedzi należy podać nazwę zbioru zawierającego zestaw komend 
MailMerge oraz podstawową treść dokumentu . Po wprowadzeniu  nazwy 
zbioru  na  ekranie kolejno pojawiają się identyczne  pytania  jak 
podczas  inicjalizacji normalnego drukowania dokumentu oraz  jedno 
pytanie dodatkowe:

                 NUMBER OF COPIES (RETURN for 1)?

W  odpowiedzi należy podać zadaną liczbę kopii każdego wygenerowa
nego listu (a nie liczbę listów, które będą generowane).

















                     INDEKS KOMEND WORDSTARA
==================================================================



                       Przesuwanie kursora
                       -------------------
    ^ S       w lewo
    ^ D       w prawo o znak
    ^ A       w lewo o słowo
    ^ F       w prawo o słowo
    ^ E       w górę o wiersz
    ^ X       w dół o wiersz
    ^ Q S     do początku wiersza
    ^ Q D     do końca wiersza
    ^ Q E     do początku obszaru tekstu na ekranie
    ^ Q X     do końca obszaru tekstu na ekranie
    ^ Q R     do początku zbioru
    ^ Q C     do końca zbioru
    ^ Q B     do początku bloku
    ^ Q K     do końca bloku
    ^ Q0..Q9  do podanego znacznika
    ^ Q P     do pozycji zajmowanej przed wykonaniem ostatniej
              komendy


                  Przesuwanie tekstu na ekranie
                  -----------------------------
    ^ Z       w górę o wiersz
    ^ W       w dół o wiersz
    ^ R       w górę o ekran
    ^ C       w dół o ekran
    ^ Q Z     ciągłe przesuwanie w górę o wiersz
    ^ Q W     ciągłe przesuwanie w dół o wiersz


             Wyszukiwanie i zamiana łańcuchów znaków
             ---------------------------------------
    ^ Q F     wyszukiwanie łańcuchów znaków
    ^ Q A     zamiana łańcuchów znaków
    ^ L       powtórne wyszukiwanie lub zamiana
    ^ Q V     przywracanie pozycji kursora sprzed ostatniej
              komendy wyszukiwania lub zamiany             


                            Parametry:
                            ----------
    n         szukanie powtarzać n razy
    U         traktowanie małych i dużych liter identycznie
    W         wyszukiwanie całych słów
    B         szukanie w tekście poprzedzającym pozycję kursora
    G         szukanie lub zamiana aż do końca zbioru
    N         autoamtyczne zamienianie łańcuchów znaków


                         Znaki specjalne:
                         ----------------
    ^ A       oznacza dowolny znak
    ^ S       oznacza dowolny znak specjalny
    ^ Ox      oznacza dowolny znak różny od podanego
    ^ N       oznacza <CR> <LF>

              Podstawowe komendy wprowadzania tekstu
              --------------------------------------
    ^ V       wstawianie znaków ON/OFF
    RETURN    koniec akapitu
    ^ N       "twardy" znak <CR>
    ^ Px      wpisywanie znaków sterujących
    ^ I       tabulacja
    ^ O I     ustawianie pozycji tabulacji
    ^ O N     kasowanie pozycji tabulacji 
    ^ O F     ustawianie marginesów i tabulacji wg. dowolnego
              wiersza zbioru


                     Komendy usuwające znaki
                     -----------------------
    <DEL>     usuwanie znaku znajdującego się przed kursorem
    ^ G       usuwanie znaku z pozycji kursora
    ^ T       usuwanie znaków od kursora do końca słowa
    ^ Q<DEL>  usuwanie znaków od początku wiersza do kursora
    ^ Q Y     usuwanie znaków od kursora do końca wiersza
    ^ Y       usuwanie wybranego wiersza
    ^ K Y     usuwanie bloku


     Komendy zachowania zbioru na dysku i zaniechania edycji
     -------------------------------------------------------
    ^ K S     zachowanie zbioru i powrót do jego edycji
    ^ K D     zachowanie zbioru i powrót na główny poziom edycji
    ^ K X     zachowanie zbioru i oddanie sterowania do CP/M
    ^ K Q     zaniechanie edycji


              Komendy redakcji dokumentu na ekranie
              -------------------------------------
    ^ O C     centrowanie tekstu wiersza
    ^ O L     ustawianie lewego marginesu
    ^ O R     ustawianie prawego marginesu
    ^ O X     zezwolenie na pisanie poza ustawionymi marginesami
    ^ O G     zadanie tabulacji akapitu
    ^ O S     ustawienie odstępu międzyliniowego
    ^ B       przeredagowanie akapitu


            Przełączniki dotyczące formatowania tekstu
            ------------------------------------------
    ^ O W     przenoszenie słów do następnego wiersza
    ^ O T     wyświetlanie "linijki"
    ^ O J     justowanie tekstu
    ^ O V     zmienna tabulacja
    ^ O H     automatyczne przenoszenie wyrazów
    ^ O E     "miękkie" znaki przeniesienia
    ^ O D     wyświetlanie znaków sterujących wydrukiem
    ^ O P     wyświetlanie granic stron


                   Komendy dotyczące znaczników
                   ----------------------------
    ^ KO..K9  ustawienie /gaszenie znacznika o podanym numerze
    ^ QO..Q9  przesuwanie kursora do podanego znacznika



                     Komendy dotyczące bloków
                     ------------------------
    ^ K B     zaznaczenie początku bloku
    ^ K K     zaznaczenie końca bloku
    ^ K V     przemieszczenie bloku
    ^ K C     kopiowanie bloku
    ^ K Y     usuwanie bloku
    ^ K H     gaszenie i zapalanie znaczników początku i końca
              bloku
    ^ Q B     przesuwanie kursora do początku bloku
    ^ Q K     przesuwanie kursora do końca bloku


               Komendy dotyczące zbiorów dyskowych
               -----------------------------------
    ^ K W     zapisywanie bloku do zbioru
    ^ K O     skopiowanie zbioru
    ^ K J     usunięcie zbioru z dysku
    ^ K F     włączanie / wyłączanie opcji wyświetlania katalogu
              dysku
    ^ K R     wstawienie tekstu ze zbioru dyskowego
    ^ K E     zmiana nazwy zbioru
    ^ K L     zmiana wybranego dysku
    ^ K P     drukowanie zbioru


              Komendy opisujące działanie WordStara
              -------------------------------------
    ^ J H     ustawienie poziomu HELP
    ^ J B     opis redakcji akapitu
    ^ J P     opis ustawiania znaczników
    ^ J D     opis komend DOT
    ^ J M     opis ustawiania marginesów i pozycji tabulacji
    ^ J S     opis linii statusu
    ^ J R     opis linijki
    ^ J F     opis znaczenia flag
    ^ J V     przenoszenie fragmentów tekstu


               Funkcje specjalne drukarki / ^ P _ /
               ------------------------------------
    S         podkreślenie
    B         wytłuszczenie
    D         podwójny druk
    X         przekreślenie
    V         pół odstępu międzyliniowego w dół
    T         pół odstępu międzyliniowego w górę
    H         nakładanie znaków
    O         pojedyncza spacja
    Y         zmiana koloru taśmy barwiącej


               Znaki sterujące wydrukiem / ^ P _ /
               -----------------------------------
    C         przerwanie drukowania
    K         ustawienie warunkowej pozycji numeru strony
    L         przesunięcie papieru do nowej strony
    A         ustawienie alternatywnej szerokości czcionki
    N         ustawienie normalne / standardowe /
    F         pisanie kodu spacji
    G         pisanie kodu <DEL>
    M         nakładanie linii
                        Komendy dodatkowe
                        -----------------
    ^ Q Q     powtórzenie następnej komendy
    ^ U       przerwanie komendy


                           Komendy DOT
                           -----------
    .LH       wysokość czcionki
    .PL       długość arkusza papieru
    .MT       górny margines
    .MB       dolny margines
    .HM       margines nagłówka
    .FM       margines stopki
    .PC       kolumna z numerem strony
    .PO       prawy margines drukarki
    .PA       koniec strony
    .CP       warunkowy koniec strony
    .HE       nagłówek
    .FO       stopka
    .OP       wstrzymanie numerowania stron
    .PN       numer strony
    .CW       szerokość czcionki
    .SR       wielkość przesunięcia pionowego frazy
    .UJ       mikrojustowanie
    .BP       dwukierunkowe drukowanie
    ..        komentarz
   



                        Komendy MailMerge
                     =======================
    DF        definicja zbioru danych
    RV        wczytanie rekordu zmiennych
    RP        powtórzenie przetwarzania dokumentu
    SV        nadanie zmiennej wartości
    AV        wczytanie zmiennej z konsoli
    DM        wyświetlenie wiadomości
    CS        wymazanie ekranu
    FI        wczytanie dodatkowego tekstu
    PF        formatowanie tekstu podczas drukowania
    RM        prawy margines
    LM        lewy margines
    LS        odstęp międzyliniowy
    OJ        justowanie tekstu
    IJ        interpretacja tekstu wejściowego














                                                           Piotruś