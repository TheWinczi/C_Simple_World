#include <iostream>

class Interfejs
{

public:
    Interfejs();

    void dodajWiadomoscDoWyswietlenia( const std::string &wiadomosc );
    void dodajInformacjeDoWyswietlenia( const std::string &wiadomosc );
    void wyswietlSwiat( char * swiat[], const int &wiersze, const int &kolumny );
    void wyswietlWiadomosc();
    void wyswietlAutora();
    void wyswietlInformacje();
    void wyswietlInterface( char * swiat[], const int &wiersze, const int &kolumny );
    void odswiez();

    //
    //  STATYCZNE
    //
    static void wyczyscEkran();
    static void koniecGry();
    static void wygrana();

    //
    //  GETTERY
    //
    Interfejs * getInterfejs();

private:
    std::string wiadomosc;
    std::string autor;
    std::string informacje;

    char ** poprzedniaTablica;
    int poprzedniaIloscWierszy, poprzedniaIloscKolumn;

    void wyzerujWiadomosci();
};
