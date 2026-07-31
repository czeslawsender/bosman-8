****************************************************************
****************  TURBO   PASCAL *******************************
****************************************************************


1.WSTEP
=======


   Opis niniejszy dotyczy systemu TURBO PASCAL, implementowanego
na komputerze AMSTRAD PCW8256.
   System operacyjny CP/M PLUS.
   W stosunku do raportu jezyka /K.Jensen & N.Wirth "Pascal User
Manual and Report"/ zawiera on nastepujace rozszerzenia:

	- zmienne absolutne
	- operacje na bitach i bajtach
	- bezposredni dostep do pamieci jednostki centralnej
						    i portow
	- lancuchy dynamiczne
	- swobodne deklaracje sekcji
	- pelne wykorzystanie mechanizmow systemu operacyjnego
	- mozliwosci generacji kodu maszynowego
	- zbiory typu INCLUDE
	- logiczne operacje na obiektach typu INTEGER
	- lancuchowanie programow ze wspolnymi zmiennymi
	- obsluga zbiorow o dostepie bezposrednim
	- stale strukturalne
	- funkcje konwersji typu
	- dodatkowe procedury i funkcje, zwiazane z systemem
						 operacyjnym.

System obejmuje: edytor, kompilator i pakiet obslugi zbiorow dyskowych.

2.ZBIORY SYSTEMOWE
==================

Dyskietka dystrybucyjna zawiera nastepujace zbiory:

 - TURBO.COM   - kompilator jezyka TURBO PASCAL
 - TURBO.OVR   - zbior z nakladkami kompilatora, niezbedny jedynie
		 podczas wykonywania zbiorow .COM
 - TURBO.MSG   - zbior tekstowy zawierajacy komunikaty bledow kom-
		 pilacji. Niezbedny jedynie w przypadku korzystania
		 z opisow bledow, zamiast ich numerow. Rezygnacja
		 z opisow tekstowych /odpowiedz "N" na pytanie
		 "include error messages (Y/N)?"/ powoduje zwiekszenie
		 o 1,5k bajtow pamieci dostepnej dla programu.
 - LISTER.PAS  - postac zrodlowa programu listujacego dla programow
		 napisanych w jezyku TURBO PASCAL. Zbior opcjonalny.
 - OPIS.TXT    - niniejszy opis

3.URUCHAMIANIE KOMPILATORA
==========================

   Po wprowadzeniu systemu operacyjnego CP/M nalezy wprowadzic
z klawiatury komende TURBO. Powoduje ona zaladowanie kompilatora
do pamieci i wyswietlenie komunikatu wprowadzajacego, za-
wierajacego nastepujace pytanie:

	Include error message (Y/N)?

Odpowiedz Y (tak) powoduje zaladowanie zbioru TURBO.MSG zawierajacego
komunikaty bledow kompilacji.
Odpowiedz N (nie) powoduje , ze bledy kompilacji beda sygnalizowane
wylacznie numerami.
Po wprowadzeniu odpowiedzi na ekranie pojawia sie "Menu glowne",
ktore zawiera zbior dostepnych komend (litery wyswietlane inwersyjnie)
Aktywowanie komendy wymaga wcisniecia odpowiedniego klawisza (bez wci-
sniecia klawisza "RETURN")
UWAGA: po wykonaniu komendy ze zbioru MENU ponowne jego wyswietlenie
uzyskac mozna przez wcisniecie klawisza "RETURN".


4.OPIS KOMEND SYSTEMU
=====================


4.1 Komenda L (LOGGED DRIVE)
----------------------------
    Komenda to sluzy do wyboru stacji dyskow. Format odpowiedzi
    operatora:
                     A:     B:    lub    M:


4.2 Komenda W (WORK FILE)
-------------------------
    Komenda W sluzy do wyboru zbioru roboczego. Format odpowiedzi
    operatora:
		FILE NAME
	lub	FILE NAME.TYP

      gdzie     FILE NAME - nazwa zbioru
		TYP       - typ zbioru (domniemany typ: .PAS)

    Wprowadzenie komendy W powoduje wczytanie zbioru z dysku, lub
    jesli taki nie istnieje - utworzenie go w pamieci. Jesli w pamieci
    istnial juz zbior (np. poddawany edycji) system wyprowadza pytanie
    dotyczace jego skladowania . Odpowiedz twierdzaca (Y) powoduje jego
    skladowanie, zas przeczaca zniszczenie poprzez otworzenie nowego.


4.3 Komenda M (MAIN FILE)
-------------------------

    Komena M pozwala na zdefiniowanie zbioru glownego (MAIN FILE).
    Jest to niezbedne w przypadku programow, zawierajacych dyrektywe
    $I (INCLUDE FILE). Zbior glowny musi zawierac wtedy dyrektywe
    INCLUDE. W przypadku, gdy zbior roboczy rozni sie od zbioru glow
    nego, rozpoczecie kompilacji powoduje automatyczne skladowanie
    zbioru roboczego i wczytanie do pamieci zbioru glownego.
    Format odpowiedzi operatora jak w 4.2.


4.4 Komenda E (EDIT)
---------------------

    Sluzy ona do wywolania wbudowanego edytora w celu edycji zbioru
    roboczego. Opis komend edytora podano w punkcie 5.


4.5 Komenda C (COMPILE)
-----------------------

    Sluzy ona do aktywowania kompilacji. Jesli nie wyspecyfikowano
    zbioru glownego, kompilowany bedzie zbior roboczy. W przypadku
    przeciwnym kompilacji poddany zostanie zbior glowny. Jesli przed
    wprowadzeniem komendy C zbior roboczy poddawany byl edycji, sys-
    tem wyprowadza pytanie, dotyczace skladowania tego zbioru.
    Kompilacje w kazdej chwili mozna przerwac przez wcisniecie do-
    wolnego klawisza.
    Wynikiem kompilacji moze byc program wynikowy umoemieszczony w pa-
    mieci, w zbiorze .COM lub w zbiorze .CHN. Do wyboru wyjscia kompi-
    latora sluzy komenda O (patrz 4.11).


4.6 Komenda R (RUN)
-------------------

    Sluzy ona do aktywowania programu wynikowego znajdujacego sie
    w pamieci, lub w przypadku opcji C komendy O - programu ze zbioru
    .COM. Jesli program nie zostal uprzednio skompilowany, przed akty-
    wacja programu nastepuje automatycznie jego kompilacja.


4.7 Komenda S (SAVE)
--------------------

    Sluzy do skladowania zbioru roboczego na dysku. Jesli istnieje
    poprzednia wersja zbioru o tej samej nazwie, zostanie ona prze-
    mianowana na .BAK.


4.8 Komenda X (EXECUTE)
-----------------------

    Umozliwia ona wykonanie dowolnego programu spoza systemu TURBO
    PASCAL (programy kopiujace,listujace,procesor tekstowy itp).
    Po zakonczeniu dzialania wywolanego programu nastepuje powrot
    do systemu TURBO PASCAL.
    Format odpowiedzi operatora: komenda systemu CP/M....


4.9 Komenda D (DIRECTORY)
-------------------------

    Powoduje ona wyswietlenie zawartosci katalogu dysku (jak DIR sys-
    temu CP/M)
    Format odpowiedzi operatora: maska (jak parametr dyrektywy DIR
    systemu CP/M...)


4.10 Komenda Q (QUIT)
---------------------
     Wyjscie z systemu TURBO PASCAL. Jesli po zaladowaniu zbior ro-
     boczy poddawany byl edycji, system wyprowadza pytanie dotyczace
     jego skladowania.


4.11 Komenda O (COMPILER OPTIONS)
---------------------------------

     Powoduje przejscie do MENU sterujacego praca kompilatora. W punk-
     tach 4.11.1 do 4.11.4 podano komendy tego poziomu

4.11.1 Komendy M,C,H (MEMORY,COM FILE,CHN FILE)
       Steruja one wyjsciem kompilatora (program wynikowy w pamieci
       (M), w zbiorze .COM (C) lub w zbiorze .CHN (H)).Przez domnie-
       manie kompilator umieszcza program wynikowy w pamieci.
       UWAGA: zbior .CHN zawiera program wynikowy bez biblioteki
       PASCALA i musi byc aktywowany przez inny program (procedura
       CHAIN).

4.11.2 Komenda S (START ADDRESS)
       Sluzy ona do podania adresu pierwszego bejtu kodu programu
       (przez domniemanie adres ten jest o 1 wiekszy od adresu kon-
       cowego biblioteki PASCALA). Po wprowadzeniu tej komendy sys-
       tem wyprowadza pytanie o adres.
       Format odpowiedzi operatora: adres w postaci HEX
       UWAGA: wprowadzenie adresu nizszego od wartosci minimalnej
       (adres koncowy biblioteki+1) powoduje zniszczenie czesci
       biblioteki.

4.11.3 Komenda E (END ADDRESS)
       Sluzy do podania najwyzszego adresu pamieci,dostepnego dla
       programu. Wartosc w nawiasach wskazuje na gorny adres obszaru
       TPA (tzn. adres poczatku systemu CP/M minus 1). Wartosc standar-
       dowa adresu koncowego dla programu jest od tej wartosci mniej-
       sza o 700 do 1000 bajtow, co pozwala na umieszczenie Loadera.
       Po wprowadzeniu tej komendy system wyprowadza pytanie o adres.
       Format odpowiedzi operatora: adres w postaci HEX.
       Komenda ta sluzy zazwyczaj do generacji programu, ktory bedzie
       wykonywany w innym otoczeniu.

4.11.4 Komenda F (FIND RUNTIME ERROR)
       Sluzy do znalezienia w programie zrodlowym miejsca, w ktorym
       wystapil blad wykonania. Komende te nalezy wprowadzac po wysta-
       pieniu bledu wykonania, zas odpowiedz operatora na wyprowadze-
       nie przez system zapytania o adres (PC) polega na wprowadzeniu
       sygnalizowanego wczesniej adresu, w ktorym wystapil blad.


5.Edytor systemu TURBO PASCAL
=============================

Ekranowy edytor systemu TURBO PASCAL przeznaczony jest do tworzenia
i poprawiania programow zrodlowych.

Edytor ten mozna w pewnym sensie uwazac za realizacje podzbioru fun-
kcji procesora tekstowego WORDSTAR.
Obsluga edytora jest identyczna jak obsluga procesora tekstowego
WORDSTAR. Odstepstwa od tej reguly podano w punkcie 5.5.
Po wprowadzeniu komendy E (MENU glownego) nastepuje wywolanie edytora.
Pierwszy wiersz ekranu zawiera status edytora:

	Line n	- numer wiersza zawierajacego kursor
	Col  n  - numer kolumny zawierajacej kursor
	
	INSERT  - znak zostaje wprowadzony na pozycje kursora,zas po-
		  zostala czesc wiersza (od kursora w prawo do konca
		  wiersza) jest przesuwana w prawo. Komenda  powo-
		  duje ustawienie trybu OVERWRITE (napis ten pojawia
		  sie w miejscu tekstu INSERT). W trybie tym znak zos
		  taje wprowadzony na miejsce znaku, wskazywanego
		  przez kursor. Patrz p.5.2
	INDENT  - automatyczna tabulacja wprowadzanego tekstu w nowym
		  wierszu. Tryb ten moze byc kasowany za pomoca komen-
		  dy ^QśI

	X:FILENAME.TYP - identyfikator aktywacji stacji dyskow, oraz
			 nazwa i typ zbioru poddawanego edycji

W punktach 5.1 do 5.4 podano - w skroconej formie - komendy edytora.
Zestaw obejmuje 45 komend. Skladaja sie one z 1 lub 2 znakow. Symbol
^ oznacza, ze przed wcisnieciem nastepujacego po nim znaku nalezy
przycisnac i przytrzymac klawisz CONTROL.

5.1 Komendy ruchu kursora
-------------------------

	^S	znak w lewo
	^D	znak w prawo
	^A	slowo w lewo
	^F	slowo w prawo
	^E	wiersz w gore
	^X	wiersz w dol
	^W	przewiniecie w gore
	^Z	przewiniecie w dol
	^R	strona w gore
	^C	strona w dol
	^QśS    w lewo do poczatku wiersza
	^QśD	w prawo do konca wiersza
	^QśE	poczatek ekranu
	^QśX	koniec ekranu
	^QśR	pierwszy znak tekstu
	^QśC	ostatni znak tekstu
	^QśB	poczatek bloku (ustawianego przez ^KśB)
	^QśK	koniec bloku (ustawianego przez ^KśK)
	^QśP	ostatnia pozycja kursora

5.2 Komendy wstawiania i usuwania
---------------------------------

	^V	tryb INSERT (wstawianie z przesunieciem reszty tekstu)
		lub OVERWRITE (wstawianie zamiast) - patrz wiersz
		statusu
	DEL	usun znak przed kursorem
	^G	usun znak na pozycji kursora
	^T	usun slowo na prawo od kursora
	^N	wstaw wiersz na pozycji kursora
	^Y	usun wiersz zawierajacy kursor
	^QśY	usun tekst od kursora do konca wiersza
	
5.3 Komendy blokowe
-------------------

UWAGA: blok jest fragmentem tekstu dowolnej dlugosci, ograniczonym
       markerami poczatku i konca. Markery sa na ekranie niewidoczne.

	^KśB	wstaw marker poczatku bloku
	^KśK	  "     "    konca     "
	^KśT	  "     "    pojedynczego slowa
	^KśH	ustaw wyswietlanie bloku
	^KśC	kopiuj blok od miejsca wskazanego przez kursor
	^KśV	przesun blok      "        "        "      "
	^KśY	usun blok
	^KśR	czytaj blok z dysku do miejsca wskazanego przez
		kursor. Nalezy wprowadzic nazwe zbioru
	^KśW	pisz na dysk. Nalezy wprowadzic nazwe zbioru

5.4 Komendy pozostale
---------------------

	^KśD	koniec edycji, powrot do MENU glownego
	^I	wykonaj tabulacje. UWAGA: edytor ustawia tabulacje
		dynamicznie, zawsze na poczatkowe znaki slow wiersza
		poprzedzajacego kursor
	^QśI	ustawianie/kasowanie automatycznej tabulacji po
		zmianie wiersza (patrz wiersz statusu)
	^QśL	ignoruj zmiany wprowadzone w wierszu biezacym.Ko-
		menda skuteczna do konca wiersza.
	^QśF	szukaj lancucha znakow. Nalezy wprowadzic lancuch
		o dlugosci do 30 znakow. Jesli lancuch zawiera znaki
		sterujace, nalezy poprzedzic je znakiem ^P

 	        Dopuszczalne opcje operacji:

	B	szukaj wstecz od kursora
	G	szukaj w calym tekscie
	n	znajdz n-te wystapienie lancucha, poczynajac od kursora
	U	ignoruj roznice pomiedzy literami malymi i duzymi
	W	szukaj jedynie calych slow

	Liste opcji nalezy konczyc przez wcisniecie klawisza RETURN


	^QśA	szukaj i zmien. Tak jak ^QśF, lecz z zamiana odnalezio-
		nego lancucha na zadany, ktory nalezy wprowadzic.

		Dopuszczalne opcje operacji:

	B	szukaj i zmien wstecz od kursora
	G	szukaj i zmien w calym tekscie
	n	znajdz i zmien n-te wystapienie lancucha
	N	zmien bez pytania o potwierdzenie
	U	ignoruj roznice pomiedzy literami malymi i duzymi
	W	szukaj i zmien jedynie cale slowa

	Liste opcji nalezy konczyc przez wcisniecie  klawisza RETURN


	^L	powtorz ostatnia operacje "szukaj" lub "szukaj i zmien"
	^P	komenda umozliwia wprowadzenie nastepujacego po niej
		znaku sterujacego jako tekstu
	^U	natychmiast zaniechaj dalszego wykonywania operacji

5.5 Roznice w stosunku do procesora tekstowego WORDSTAR
-------------------------------------------------------

5.5.1   Komendy ^S,^D,^E i ^X umozliwiaja przesuwanie kursora po calym
	ekranie bez opuszczania znakow pustych
	Komendy ^S i ^D nie pozwalaja na zmiane wiersza

5.5.2	Komendy ^KśT umozliwiaja oznaczenie pojedynczego slowa jako
							      bloku

5.5.3	Komenda ^KśD nie powoduje zapisu zbioru na dysk

5.5.4	Komenda ^QśL umozliwia zignorowanie wprowadzonych w danym
	wierszu zmian tak dlugo, dopoki kursor znajduje sie w tym
							  wierszu

5.5.5	Tabulacja ma charakter dynamiczny (poczatki slow wiersza
						 poprzedzajacego)

5.5.6	Automatyczna tabulacja przy zmianie wiersza

***********************************************************************
