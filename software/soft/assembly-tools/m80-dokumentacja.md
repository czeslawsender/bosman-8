                       Macro assembler M80

Uruchomienie:

>M80
*

Rozkazy:

zbiórwynikowy, zbiórdodrukowania=zbiórźródłowy

Przyjęte rozszerzenia nazw zbiorów:

REL - relokowanlny zbiór wynikowy
PRN - tekstowy zbiór do drukowania
MAC - zbiór [ródłowy makro assemblera
CRF - zbiór z tablicą "cross reference"
COM - zbiór z programem do wykonania

Urządzenia

A:, B:, ..     - napędy dyskowe
LST:           - drukarka
TTY:           - ekran

Przełączniki

O - zbiór do drukowania z wartościami oktalnymi
H - zbiór do drukowania z wartościami heksadecymalnymi (domyślnie) 
R - wymusza generację zbioru wynikowego
L - wymusza generację zbioru do drukowania
C - wymusza generacje zbioru "cross reference"
Z - tryb procesora Z80

Przykłady:

>M80 Rozkaz

Lub

>M80
*Rozkaz

*=TEST -  assemblacja  i  wytworzenie  zbioru REL  bez  zbioru  do 
          drukowania.

*,=TEST - assemblacja bez wytwarzania zbiorów. Używane przy wykry
          waniu błędów.

*TEST,TEST=TEST -   assemblacja z wytworzeniem zbioru wynikowego i 
                    zbioru do drukowania.

*A:OBJECT=TEST -    assemblacja i wytworzenie zbioru wynikowego  w 
                    zbiorze  OBJECT.REL na dysku A:  bez zbioru do 
                    drukowania.

*OBJECT,LST:=B:TEST -    assemblacja zbioru TEST.MAC z dysku B:  z 
                         wytworzeniem  zbioru wynikowego w zbiorze 
                         OBJECT.REL  i  drukowaniem  w  zbioru  na 
                         drukarce

*=TEST/L -     assemblacja  zbioru  TEST i wytworzenie  zbioru  do 
               drukowania TEST.PRN

*=TEST/L/O - zbiór do drukowania będzie miał adresy oktalne

*LAST=TEST/C  - assemblacja  zbioru TEST.MAC i wytworzenie  zbioru 
               wynikowego  w zbiorze LAST.REL i zbioru  z  tablicą 
               "cross reference" TEST.CRF

Format zbioru .MAC

Długość linii rozkazowej:  132 znaki. W tekscie dopuszczalne tylko 
duże litery.  Stałe tekstowe mogą zawierać dowolne znaki.  Dopusz
czalne są w tekście numery linii wstawiane przez niektóre  edytory 
tekstów.

Format linii

<etykieta:<:>><operator><argument><;komentarz>

Poszczególne elementy mogą być oddzielone spacjami i tabulacjami. 

Etykieta  musi być pierwszym elementem linii i musi być zakończona 
znakiem dwukropka. Jeśli występuje podwójny dwukropek, to etykieta 
jest traktowana jako etykieta globalna (PUBLIC).
Etykiety  mogą mieć dowolną długość,  lecz tylko  pierwszych  sześć 
znaków jest podstawą identyfikacji etykiet. W etykiecie mogą pojawić 
się następujące znaki:
     A-Z 0-9 $ . ? `
Etykieta nie może zaczynać się od znaku cyfry. Etykieta, po której 
występują znaki ## jest traktowana jako zewnętrzna.

Przykłady:

FOO: RET

FOO: PUBLIC FOO
     RET

Kolejnym elementem linii jest operator,  którym może być  mnemonik 
rozkazu procesora,  dyrektywa makro-assemblera, przywołanie macra, 
wyrażenie. Kolejność interpretacji operatorów jest następująca:
     przywołanie makra
     mnemonik rozkazu/dyrektywa
     wyrażenie

Stałe programowe

Numeryczne
Podstawą  stałych  numerycznych jest dziesięć.  Można  to  zmienić 
dyrektywą  .RADIX.  Jeśli podstawa jest większa niż 10,  to liczba 
musi być poprzedzona zerem. Liczby są wielkościami 16-to bitowymi. 
Bieżącą podstawę liczby określa rozszerzenie:
     nnnnB - binarna
     nnnnD - dziesiętna
     nnnnO - {semkowa
     nnnnQ - {semkowa
     nnnnH - szestnastkowa
     X'nnnn' - szestnastkowa

Nadmiar ponad dwa bajty jest ignorowany. 

Tekstowe
Ciąg znaków umieszczony w podwójnych nawiasach.
Przykład:
     DB   "It is a string"

Wyrażenia

Wyrażenia arytmetyczne
Dopuszczalne  są następujące operatory arytmetyczne.  Operatory są 
wyszczególnione w kolejności przetwarzania:
     NUL
     LOW, HIGH
     *,/,MOD,SHR,SHL
     Unary Minus
     +,-
     EQ, NE, LT, LE, GT, GE
     NOT
     AND
     OR, XOR
Dopuszczalne są również nawiasy. Operatory muszą być oddzielone od 
operandów przynajmniej jedną spacją.

Tryby relokacji dla etykiet
Etykiety  używane  w wyrażeniach mogą być deklarowane w  jednym  z 
czterech trybów relokacji:
     absolutnym (ASEG),
     relokowalnego kodu (CSEG),
     relokowalnych danych (DSEG),
     obszaru wspólnego (COMMON).
Te  same etykiety należące do różnych bloków COMMON są  traktowane 
jako etykiety różnego trybu. 
We  wszystkich operacjach operandy muszą być w  absolutnym  trybie 
relokacji.  Wyjątkiem są operacje dodawania i odejmowania. W doda
waniu obowiązują następujące reguły:
     przynajmniej jeden operand musi być w trybie absolutnym,
     tryb absolutny + dowolny tryb = dowolny tryb
Przy odejmowaniu obowiązują następujące reguły:
     dowolny tryb - tryb absolutny = dowolny tryb
     dowolny tryb - ten sam tryb   = tryb absolutny
Należy  pamiętać  o kolejności wykonywania działań  wynikającej  z 
nawiasów,  gdyż  może ona wpłynąć na interpretację trybu  etykiety 
bądź wyrażenia. Przykładowo:
     FOO + BAZ - ZAZ
jest wyrażeniem nieprawidłowym, a
eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeaeaH
pd92BrN$PITŁ$FC"L(N('OOOyPb$( _rI LINGOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOHm 
/P linkera L80.

COMMON -  /<nazwa bloku>/

Dyrektywa  COMMON  ustawia licznik lokacji na  początek  wybranego 
dyrektywą  obszaru.  Zapewnia  to  przykładowo  pełną  zgodność  z 
blokiem COMMON Fortranu. Nazwa bloku może być pominięta.
 
CSEG - tryb relokacji kodu programu

Dyrektywa CSEG ustawia licznik lokacji na relokowalny tryb umiesz
czania wyniku assemblacji w pamięci.  Wartość licznika jest  usta
wiana na początek segmentu relokacji programu i może być zmieniona 
dyrektywą  ORG.  Relokowalny tryb lokacji  jest trybem domyślnym w 
makro-assemblerze. 

DB - definicja obszaru bajtowego

     DB <wyrażenie><,wyrażenie>
     lub
     DB <tekst>
Wartości wyrażenia przechowywana jest w bajcie.  Kolejne wyrażenia 
wypełniają  kolejne  bajty.  W  wyrażeniach teksty  nie  mogą  być 
dłuższe niż dwa bajty.  W przypadku tekstów kolejne znaki znajmują 
kolejne  bajty.  Najwyższe bity wszystkich znaków są ustawione  na 
zero.

Przykłady:
0000'  41 42     DB  'AB'
0002'  42        DB  'AB' AND 0FFH
0003'  41 42 43  DB  'ABC'

DC - definicja tekstu

     DC <tekst>
Kolejne znaki tekstu zajmują kolejne bajty, z tym ,}e ostatni znak 
ma ustawiony najwyższy bit na jeden.

DS - definicja obszaru

     DS <wyrażenie>
Dyrektywa   rezerwuje   obszar  pamięci  o  wielkości   określonej 
wyrażeniem.   Niewłaściwa  konstrukcja  wyrażenia  może  powodować 
pojawienie się błędów V i U.

DSEG - tryb relokacji danych

Dyrektywa DSEG ustawia licznik lokacji na relokowalny tryb umiesz
czania  wyniku assemblacji w pamięci.  Wartość licznika jest usta
wiana  na początek segmentu relokacji danych i może być  zmieniona 
dyrektywą ORG. 

END - zakończenie programu

     END <wyrażenie>
Wystąpienie   wyrażenia  określa  adres  startu   programu.   Brak 
wyrażenia  powoduje,  }e  linkerowi  nie jest  przekazywany  adres 
startu programu.

ENTRY/PUBLIC - deklaracja etykiet lokalnych

     ENTRY <etykieta>(,<etykieta>..)
lub
     PUBLIC <etykieta>(,<etykieta>..)
Dyrektywy ENTRY i PUBLIC deklarują etykietę z listy jako lokalną w 
programie.  Etykiety te muszą być zadeklarowane w programie i brak 
ich  deklaracji  powoduje błąd U.  Użycie tych etykiet  jako  zew
nętrznych powoduje błąd M.

EQU - przypisanie wartości etykiecie

     etykieta EQU <wyrażenia>
Jeśli wyrażenie jest wyrażeniem zewnętrznym,  to pojawia się błąd. 
Jeśli etykieta ma już przypisaną wartość, to pojawia się błąd M.

EXT/EXTRN - deklaracja etykiet zewnętrznych

     EXT <etykieta>(,<etykieta>..)
lub
     EXTRN <etykieta>(,<etykieta>..)
lub 
     etykieta##
Dyrektywa deklaruje etykiety jako zewnętrzne, czyli zdefiniowane w 
innym programie. Zdefiniowanie w programie etykiety zadeklarowanej 
jako zewnętrznej spowoduje błąd M.

INCLUDE - dołączenie tekstu

     INCLUDE <nazwa zbioru>


ORG - bieżący adres w programie

     ORG <wyrażenie>
Wartość wyrażenia określa adres bieżącej lokalizacji w pamięci.

Informacje o błędach

Informacje o błędach umieszczane są w pierwszej kolumnie zbioru do 
drukowania.  Jeśli  brak  jest takiego  zbioru,  to  błędne  linie 
wyświetlane są na ekranie.

A -  błąd argumentu
C -  błąd zagnieżdżenia warunkowej assemblacji
D -  odwołanie do etykiety o podwójnej definicji wartości 
E -  użycie etykiety zewnętrznej w niewłaściwym kontekście
M -  podwójna definicja etykiety
N -  błąd numeryczny
O -  niewłaściwie użyta dyrektywa
P -  błąd fazy
Q -  ostrzeżenie
R -  błąd relokacji
U -  niezdefiniowana etykieta
V -  błąd wartości

Komunikaty o błędach

     "No end statment encountered on input file"

Makro-assembelr nie znalazł dyrektywy END w zbiorze [ródłowym  lub 
użyto  niewłaściwie  dyrektywy kończące makra i  bloki  warunkowej 
assemblacji.

     "Unterminated condotional"

Niezakończony blok warunkowej assemblacji.

     "Unterminated REP/IRP/IRPC/MACRO"

Niezakończony blok programu.

     "<XX><No> Fatal error(s) <, XX warnings>"

Komunikat  kończący  assemblację  i  wskazujący  liczbę  błędów  i 
ostrzeżeń.
