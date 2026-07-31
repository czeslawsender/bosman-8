         **********************************************
         *    Z80 - Reassembler v3.0                  *
         *    On-line Handbook                        *
         *    written by     h.d.frey,                *
         *                   Microbyte & Bitresearch  *
         *                   12-sep-85                *
         **********************************************

1.Einleitung

     Willkommen  bei der Arbeit mit dem Z80-Reassembler RAZ80 von 
mb&br.  Diese Beschreibung soll in kurzer Form die Bedienung  von 
RAZ80  erlaeutern.  Folgende Files gehoeren zum Lieferumfang  von 
RAZ80:
          RAZ80.COM      -    das Reassemblerprogramm
          RAZ80.MAC      -    der MACRO80-Quellcode
          RAZ80.DOK      -    diese Beschreibung
          TEST.INP       -    Testprogramm
          TEST.RDF       -    Beschreibungsfile dazu
          TEST.SYM       -    Symbolfile dazu
          HEXDUMP.COM    -    Dumpprogramm
          HEXDUMP.MAC    -    der MACRO80-Quellcode dazu

     RAZ80 wurde fuer Z80-Programme unter CP/M 2 geschrieben, die 
mit  dem MacroAssembler MACRO80 von  MicroSoft  weiterverarbeitet 
werden sollen.  RAZ80 ist ein Zwei-Pass-Disassembler, der im Pass 
1 Marken generiert und im Pass 2 Quellcode erzeugt und diesen auf 
Console,  Printer oder Diskfile ausgibt.  Das zu reassemblierende 
Programm  (Inputfile) kann mit Optionen in verschiedene  Segmente 
aufgeteilt  werden,  um Code von Text,  Konstanten (Bytes,Words), 
Datenbereichen und Markentabellen zu unterscheiden.

2. Aufruf von CP/M - Systemebene:

          RAZ80 [d:]infileź.extń [optionźsńń

     Wird  nur RAZ80 eingegeben,  so erscheint eine  Liste  aller 
Optionen  als Helptext,  falls Sie eine Option nicht exakt wissen 
und dieses Papier zuweit von Ihrem PC entfernt ist.

     Wird  ein  Inputfile angegeben,  so wird ohne  Optionen  von 
diesem  Filenamen mit der Extension .RAZ ein (Output-)  Quellfile 
reassembliert.  Das Inputfile kann auf einem beliebigen  Laufwerk 
sein,   das   Outputfile   wird   auf  dem   aktuellen   Laufwerk 
abgespeichert. Erproben Sie RAZ80, indem Sie

          RAZ80 TEST.INP

eingeben. Bei kleiner Diskettekapazitaet koennen Sie sich mit

     C>A:RAZ80 B:TEST.INP

helfen.
.pa
3. Optionen

     Mit  den  Optionen  L,  P,  T und  U  wird  die  Ausgabeform 
bestimmt.  Die Option L definiert die Console als  Ausgabegeraet, 
auf  der  linken  Seite werden zusaetzlich Addressen  und  Opcode 
gelistet.  Die  Option P definiert den Drucker  als  Ausgabe,  es 
werden 65 Zeilen pro Seite gedruckt, dieser Standardwert kann mit 
P:nn  auf  nn Zeilen geaendert werden.  T bewirkt,  dass  in  der 
Ausgabedatei   die   Addressen  und  der  Opcode  als   Kommentar 
miterzeugt werden.  Mit U werden Grossbuchstaben  erzeugt,  sonst 
nur Kleinbuchstaben.

     Mit  den  Optionen  S,  E  und  O  werden  die  Grenzen  der 
Reassemblierung festgelegt.  Mit S:XXXX wird die Startadresse auf 
XXXX vereinbart,  ohne Angabe ist 100h die Startaddresse.  E:XXXX 
gibt die Endadresse, ohne Angabe wird bis zu Ende der Datei (EOF) 
reassembliert.  Mit O:XXXX wird dem ersten Byte in der Inputdatei 
eine Adresse zugeordnet,  ohne Angabe hat das erste Byte die fuer 
CP/M-Files  uebliche  Adresse 100h.  Die  Hexadezimalzahlen  XXXX 
koennen  auch  mit  weniger als vier Stellen  eingegeben  werden. 
Zwischen den einzelnen Optionen brauch kein Trennzeichen sein, es 
sei  den,  diese wird von einer Hexzahl gefolgt und danach  kommt 
eine weiter Option A bis F. Dann ist ein Leerzeichen einzufuegen, 
da die Optionen sonst fehlgedeutet werden.

     Mit  den Optionen A,  B,  C,  D,  M und N  koennen  einzelne 
Bereiche vereinbart werden. Ohne Angaben dieser Art ist ein Code-
Segment   ab   Dateianfang  eingestellt.   Die  Reihenfolge   der 
Segmentadressen  hat  in aufsteigender  Reihe  zu  erfolgen.  Mit 
folgende  Optionen sind die entsprechenden  Bereichseinstellungen 
moeglich:

     Option    Bedeutung                Bespiel

     A:xxxx    ASCII-Segment            db   'Text $',0dh,8ah
     B:xxxx    Byte-Segment             db   1,0afh,13h,7,0,0,0,0
     C:xxxx    Code-Segment             ld   hl,m03af
     D:xxxx    Daten-Segment            ds   91
     M:xxxx    Marken-Segment           dw   m0005
     N:xxxx    Word-Segment             dw   0dafh,012h,0ffffh

     Werden   in  einem  Code-Segment  acht   aufeinanderfolgende 
gleiche Bytes gefunden,  so wird kein Opcode erzeugt, sondern ein 
Datensegment  mit  soviel Bytes,  bis  der  naechste  Unterschied 
festgestellt wird. z.B.:

          DS   91,0e5h

     Wird mehr als ein NOP erkannt, so wird analog verfahren.

     Mit der Option F werden weitere Optionen aus einer Datei mit 
dem  Name  infile.RDF gelesen.  Diese Option dient dazu,  um  bei 
grossen  Inputfiles  die Bereichsaufteilung  nicht  jedesmal  mit 
einzugeben. Die .RDF-Datei kann maximal 2K Byte lang sein.
.pa
     Die  W und die Y Option dient der Verwendung von Marken  mit 
Name  aus  bis zu sieben Zeichen.  Es wird eine infile.SYM  Datei 
eingelesen  und  die  darin enthaltenen Symbole  als  Marken  des 
Reassemblers in die Markentabelle uebertragen.  Linker wie LINK80 
oder  LINKMT geben mit den Optionen Y bzw.  W  Symboltabellen  in 
file.SYM aus,  so dass mit RAZ80 effektiv Libraries von Compilern 
etc.  geknackt werden koennen. Mit dieser Option lassen sich auch 
groessere  Programme modular reassemblieren.  Die .SYM-Datei  hat 
folgenden Aufbau:

          <4Zeichen-Hexadresse><space><Name><tab or crlf>....
          ............<EOF>
     z,B. 0005 BDOS      005C FCB       0100 TPA
          0080 DEFBUF

     Waehrend  des  Programmlauf wird in Pass 1 nach  jeweils  32 
neugenerierten  Marken  ein  '+'  auf  Console  ausgegeben.   Bei 
Diskausgabe  wird im Pass 2 nach jeweils 128 geschriebenen Zeilen 
ein '+' auf Console ausgegeben.  Der Programmlauf kann mit ctrl-S 
gestoppt und mit ctrl-C abgebrochen werden.

4. Beispiellauf

     Es  soll  das Programm TEST.INP  reassembliert  werden.  Als 
erstes  wird  von  dem Programm  ein  Hexdump  gemacht,  um  eine 
Bereichsaufteilung vorzunehmen.

          HEXDUMP TEST.INP

     erzeugt dann

     .
     .
     .


     Nachsatz:  Es soll noch Leute geben,  die sich scheuen,  20K 
lange Programme zu Reassemblieren. Gebt ihnen RAZ80!
