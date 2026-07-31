                    **************************
                    * ZSID - wybrane komendy *
                    **************************
                             
    D adresp,adresk -przegladanie pamieci (wydruk w postaci
                     HEX i ASCII).
    D               -przegladanie pamieci od 0100(H).
    DW              -przegl. po slowie (2 bajty).
    L               -listing programu w mnemoniku Z80 od
                     0100(H).
    L adresp,adresk -listing.
    F adresp,adresk,wartosc  -wypelnianie wskazanego obszaru
                              pamieci podana wartoscia.
    M adresp,adresk,nowyp    -przeniesienie wskazanego obszaru
                              pod nowy poczatek (obszary nie 
                              moga zachodzic na siebie).
    I nazwa         -przygotowanie zbioru do wczytania
                     (dla zbiorow o typie innym nió COM podac 
                      rozszerzenie).
    R               -wczytanie zbioru.
    GO              -start programu od adresu 0100(H).
    GO adres,adres pulapki   -adres zakonczenia (pulapki) musi
                              byc adresem istniejacej instru-
                              kcji.
    T ilosc krokow  -sledzenie wykonania programu po kroku.
    U               -jak wyóej z ograniczeniem informacji do
                     ostatniej instrukcji ciagu.
    X               -wyswietlenie zawartosci rejestrow.
    Xnazwa          -wyswietlenie zaw. oreslonego, nazwa rej.
    S adres         -ustawienie (HEX) ciagu bajtow (lub tylko 
                     przegladanie), CR wywoluje kolejne bajty
                     wyjscie kropka(.)
    A adres         -pisanie w assemblerze od wskazanego adresu.
