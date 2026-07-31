                                                                         * 1 *
1.1     ORGANIZACJA SYSTEMU CP/M.
        ------------------------

        CP/M 2.2 jest uniwersalnym , jednoterminalowym systemem operacyjnym dla
mikrokomputerów  wyposażonych  w procesor INTEL 8080;  8085;  lub Z80  i  pamięć 
masową na dyskach elastycznych /format IBM . System CP/M 2.2 wraz ze zleceniami
realizowanymi przez standardowe programy usługowe umożliwia swobodne korzystanie
z pamięci dyskowej zorganizowanej w pliki oraz przygotowanie, edycję, kompilację
i uruchamianie programów.
Umożliwia  on  efektywne wykorzystanie we własnych programach  pamięci  dyskowej 
poprzez procedury systemowe realizujące podstawowe operacje zarządzania plikami
i  operowania danymi.  Pozwala również na swobodne dołączenie własnych programów 
do systemu.

        System CP/M 2.2 jest logicznie podzielony na cztery części :
        
        BIOS  -  Basic I/O System - zestaw procedur obsługi podstawowych 
                 urządzeń zewnętrznych .
        BDOS  -  Basic Disc Operating System - zestaw procedur obsługi
                 pamięci dyskowej i zarządzania plikami .
        CCP   -  Console Command Processor - zestaw procedur realizujących
                 zlecenia użytkownika .
        TPA   -  Transient Program Area - obszar PaO nie wykorzystany przez
                 w/w części CP/M i przeznaczony dla programów użytkowych .

        BIOS   umożliwia obsługę urządzeń peryferyjnych dołącznych do systemu ,  
zarównopodstawowych : monitor z klawiaturą (czy inny rodzaj konsoli operatora),
czytnik  ,  perforator ,  drukarka jak i dodatkowych  urządzeń  skonfigurowanych 
przez urzytkownika.
Elementem  BIOS  są  także  programy  realizujące  współpracę  z  dyskiem  (tzn. 
umożliwjające odczyt i zapis) oraz tablice charakteryzujące użyty rodzaj pamięci
dyskowej i liczdę dołączonych do systemu aktywnych mechanizmów pamięci.
        BIOS jest częścią systemu CP/M 2.2 zależną od użytkownika ,  dlatego też 
możliwe  są  zmiany tej części (przez dołączenie odpowiednich programów  obsługi 
urządzeń peryferyjnych) w zależności od konfiguracji systemu mikroprocesorowego.
        Część  CP/M  2.2 BDOS jest zestawem procedur realizujących współpracę  z 
pamięcią  dyskową  (odczyt  zapis  rekordu,  odczyt  zapis  pliku  i.t.p.)  oraz 
zarządzających plikami poprzez sterowanie jedną z lub więcej jednostkami pamięci
dyskowej,  z których każda posiada niezależną bibliotekę pików .  Proste funkcje 
realizowane    przez   BDOS   (np.    szukanie   zbioru   o   podanej    nazwie, 
otwarcie/zamknięcie zbioru, zmiana nazwy zbioru i.t.p.) są wyróżnione i zalecane 
do wykorzystania przez użytkownika w programach współpracujących z dyskiem .

        Zestaw tych funkcji oraz sposób ich wykorzystania opisany jest w roz. 2.

        Część  CCP  można określić jako programowy  interfejs  pomiędzy  konsolą 
użytkownika  a pozostałą cześcią systemu operacyjnego .  Procedury CCP realizują 
odczyt  znaków z konsoli użytkownika,  edycję liniową wprowadzanych zleceń  oraz 
wykonywanie  zleceń  systemowych takich,  jak listowanie  zawartości  biblioteki 
plików, listowanie treści pliku i innych .
CCP   umożliwia  i  nadzoruje  również  wykonanie  zleceń  realizowanych   przez 
standardowe programy usługowe oraz programów użytkownika dołączonych do systemu.
Opis zleceń systemowych i standardowych programów usługowych zamieszczony jest w
punkcie 1.5 .

        Największą  częściąskładową  CP/M 2.2 jest  obszar  pamięci  operacyjnej 
nazywany  obszarem programów użytkowych (TPA) .  W opszarze tym przechowywane są 
programy załadowane z pamięci dyskowej pod kontrolą programu CCP . Na przykład w
czasie edycji programów w TPA przechowywany jest kod maszynowy edytora tekstu  i 
jego bazy danych .
                                                                       * 2 *
W  obszarze  tym  są  również  przechowywane  i  możliwe  do  wykonania programy 
użytkownika dołączone do systemu CP/M 2.2 . 
Należy  zwrócić  uwagę,  }e  programy użytkowe mogą być nakładkowane  na  obszar 
zajmowany  przez  części  CP/M:  BDOS,  CCP i  BIOS  .  Jedynym  warunkiem  jest 
umieszczenie  w  programie użytkowym łącznika do programu booterap'u  ładującego 
system CP/M z pamięci dyskowej do pamięci operacyjnej .


1.2     ORGANIZACJA PAMIECI SYSTEMU  CP/M 2.2
        -------------------------------------

        Rozmieszczenie  systemu CP/M 2.2 w pamięci operacyjnej zależne  jest  od 
konfiguracji PaP systemu mikrokomputerowego . Przedstawiono je na poniższym rys.
Tablica  podaje  odpowiednie  adresy  części  składowych  systemu  dla  częściej 
używanych pojemności pamięci operacyjnej .


        Mapa pamięci systemu CP/M
        -------------------------

         tb ---------------------
            !                   !  ( Basic I/O System )
            !     BIOS          !  Procedury obsługi podstawowych
            !                   !  urządzeń zewnętrznych .
         bb ---------------------
            !                   !  ( Basic Disc Operating System )
            !     BDOS          !  Procedury realizujące procedury 
            !                   !  dyskowe .
            !                   !
         fb ---------------------
            !                   !  ( Console Command Procesor )
            !     CCP           !  Procedury obsługi zleceń 
            !                   !  użytkownika .
            !                   !
         cb ---------------------
            !                   !
            !   Obszar          !
            !   programów       !
            !   użytkowych      !
            !     TPA           !
            !                   !
            !                   !
        FFH ---------------------
            !                   !
            !                   !  Obszar parametrów systemowych .
            !                   !
        00H ---------------------

        TABELA    Bazowe adresy elementów CP/M 2.2 dla 
        ------    różnych konfiguracji PaO .
 ==============================================================================
 !  CP/M 2.2   Część : !   20 K   !  24 K    !  32 K    !  48 K    !  64 K    !
 !=====================!==========!==========!==========!==========!==========!
 !    CCP      ( cb )  !  3400H   !  4400H   !  6400H   !  A400H   !  E400H   !
 !    BDOS     ( fb )  !  3C00H   !  4C00H   !  6C00H   !  AC00H   !  EC00H   !
 !    BIOS     ( bb )  !  4A00H   !  5A00H   !  7A00H   !  BA00H   !  FA00H   !
 ! Górne ograniczenie  !          !          !          !          !          !
 ! pamięci     ( tb )  !  4FFFH   !  5FFFH   !  7FFFH   !  BFFFH   !  FFFFH   !
 ==============================================================================


                                                                          * 3 *
     
1.3  Pamięć dyskowa
---------------------

     Pamięcią masową w systemie CP/M 2.2 jest pamięć dyskowa. System umożliwia
na dyskach od nr 1 do 16  ( w systemie oznaczanych od A do P), z których każdy
może mieć pojemność 8 MB. Dyskietki są sformatowane zgodnie ze standardem IBM,
a fizycznie najmniejszym blokiem informacji jest rekord o pojemności 128 B.
Utworzony pod systemem plik może zajmować pełny obszar jednostki pamięci dysko-
wej (czyli 8 MB). Liczba pozycji plików jest dowolna, a każdy plik może być do-
datkowo wyposażony w atrybut określający go jako tzw. systemowy lub R/O, z któ-
rego możliwy  jest  tylko  odczyt (zapis jest niedozwolony). CP/M 2.2 umożliwia
fizyczne  wydzielenie  części  pamięci użytkowej do wyłącznego dostępu do niej 
przez jednego użytkownika (liczba rozróżnionych w ten sposób użytkowników sys-
temu wynosi 0 do 15 ). Rownocześnie istnieje specjalne zlecenie pozwalające na
kopiowanie plików z obszaru jednego użytkownika do drugiego.
     Wszystkie  informacje  o  rodzaju pamięci dyskowej używanych przez system
umieszczone są  w  rezydującym w Bios bloku parametrów dysku. Blok ten zawiera 
dane o maksymalnej  liczbie aktywnych pamięci dyskowych, numerach sektorów, po-
czątkowego i  końcowego,  wielkości  przydzielonej pamięci danych, maksymalnej 
liczbie  rozszerzeń  logicznych  ilości pamięci dyskowych, objętości biblioteki
i numerach ^cieżek zarezerwowanych. Blok ten jest wypełniany ręcznie bądź jest
tworzony przez makrozlecenie definiujące dysk, w które wyposażony jest CP/M 2.2
Makrozlecenia używają tej informacji dla utworzenia odpowiednich tablic i odwo-
łań do tablic potrzebnych podczas zarządzania plikami przez system CP/M 2.2.
System tablic umożliwia takie operowanie sektorami o większej objętości będącej
wielokrotnością podstawowej jednostki bloku danych jaka jest 128  bajtow.
     System CP/m 2.2 pozwala na rozszerzenie wcześniej utworzonych plikow.
Maksymalna liczba logicznych rozszerzeń wynosi 512, a każde rozszerzenie logi-
czne zawiera 16 MB danych.
Rozszerzenie fizyczne adresuje do 128 KB danych, o odpowiada pojedynczej pozyc-
ji w bibliotece plików.
W systemie CP/M 2.2 ^cieżka składa się z 18  128 B sektorów ponumerowanych od
0 do 17 dla pojedynczej gęstości zapisu przy modulacji FM (125 KHz) i 36 ponu-
merowanych od 0 do 37 dla MFM (250 KHz). System narzuca następującą 
organizację dyskietki systemowej:
 - ^cieżki 0,1,2    - przeznaczone są na zapamiętywanie systemu CP/M 2.2,
 - ^cieżki 3 do n  - przeznaczone są na bibliotekę i pliki.
Dotyczy to minidyskietki 5,1/4", gdzie n=39 dla pojedynczej gęstości ^cieżek
i jednostronnych, i 159 dla podwójnej i dwustronnych.
W systemie CP/M 2.2 pliki są identifikowane poprzez nazwę. Pełna nazwa jest
dwuczłonowa i składa sią z:
 - maksymalnie ośmioznakowej nazwy pliku,
 - maksymalnie trzyznakowego typu pliku,
zapisanych w następującym formacie:
     nnnnnnnn.ttt
Znaki alfanumeryczne użyte w nazwie muszą być różne od znaków:
     < > , . ; = [ ] * ? :

Przykłady:

     ALA.COM
     OLA.ASM
     O.HEX
     TEST
     LOLA.111


                                                                          * 4 *




W niektórych zleceniach, np.:przy przeszukiwaniu biblioteki, można tworzyć naz-
wy z użyciem znaków "?" i "*". Umożliwia to dostęp do grupy plików, gdyż znak
"?" powoduje zamaskowanie znaku w nazwie, a "*" zamaskowanie nazwy lub typu
pliku.

Przykład:

     ???.com   - odczytuje się : wszystkie pliki o nazwie od 1 do 3 znaków
     *.*       - odczytuje się : wszystkie pliki 

     Typ pliku może być dowolnie wybrany przez programistę, natomiast programy
narzędziowe wykorzystują lub tworzą pliki następujących typów:
 .COM - plik ładowany i wykonywany przez moduł CCP,
        tworzony przez np.: L80 - linkier,
 .PRN - plik tworzony przez assembler - tekst programu,
 .HEX - plik wynikowy tworzony przez assembler, może być ładowany i wykonywany
        tylko pod nadzorem debagiera np.: DDT, ZSID,
 .ASM - plik tworzony przez ASSEMBLER,
 .MAC - plik tworzony przez MACROASSEMBLER,
 .LIB - plik makrorozkazów przeznaczony do dla makroassemblera,
 .BAK - plik tworzony przez program edytora, jest to kopia pliku pierwotnego
        i może być użyteczny w przypadku awarii podczas poprawiania programu, 
 .SUB - plik poleceń używany przez program SUBMIT
 .$$$ - przejściowy program tworzony przez niektóre programy narzędziowe 
        i niszczony po zakończeniu działania,
 .TBL - 
 .DBF - 
 .BAS - 
 .REL -
 .OVL -
 .OVR -
 .HLP -
 .FIL -
 .SYS - plik systemowy, którego nazwa przy wyprowadzaniu plikow z biblioteki
        jest pomijana,  
 .CMD -
 .DOK -
 .TXT -
 .SUB - 
 .PAS -


1.4  Polecenia rezydentne:
-------------------------------


Moduł CCP rozpoznaje sześć poleceń rezydentnych:

* DIR - umożliwia uzyskanie opisów plików dyskowych,
* ERA - kasuje pliki dyskowe,
* REN - zmienia nazwę i typ pliku,


                                                                          * 5 *



* SAVE - umożliwia ochronę obszarów pamięci; począwszy od adresu 100H, przez
         przechowanie kopii w zadanym pliku, który może być typu .COM, ponie-
         waż jest dokładnym obszarem pamięci; polecenie jest użyteczne do za-
         bezpieczenia programu zmodyfikowanego - jego składnia ma postać:
               SAVE xx (nazwa pliku) - gdzie xx oznacza liczbę stron pamięci
                                       256 Bajtowych, 
* TYPE - umożliwia wyświetlenie lub wydrukowanie zawartości pliku w kodzie
         ASCII na urządzeniu operatora,
* USER - powoduje przydzielenie dysku użytkownikom oznaczonym numerami(0 do 15)

1.5  Polecenia nierezydentne
------------------------------

STAT, ED, PIP, ASM, LOAD, DDT, SUBMIT, MOVCPM, SYSGEN
 
PIP - służy do przesyłania plików z dysku na dysk lub na inne urządzenie 
      peryferyjne,

przykład:
     PIP (odbiorca)=(nadawca)

SUBMIT - umożliwia wykonanie ciągu poleceń zawartych w jednym pliku typu .SUB
XSUB   - rozszerza możliwości programu SUBMIT,
         umożliwia on wprowadzanie danych z klawiatury zarówno do programów
         usługowych jak i do zleceń systemowych;
         po umieszczeniu programu XSUB jako pierwszego w zestawie zleceń pro-
         gramu SUBMIT , wszystkie zlecenia wykonywane przez ten program mogą
         mieć dane wprowadzane z klawiatury, gdyż XSUB kontroluje wtedy prze-
         bieg zlecenia SUBMIT.

przykład:

     Program ROUL.SUB
               XSUB
               ZSID
               I$1.COM
               R
               G0
               SAVE 1 $2.COM      

     Wywołanie programu:       
                         SUBMIT ROUL.SUB QV

     spowoduje podstawienie nazwy Q pod parametr $1 , a V pod parametr $2

          
