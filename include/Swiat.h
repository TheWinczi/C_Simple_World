#pragma once

#include "Organizm.h"
#include "ListaOrganizmow.h"
#include "Interfejs.h"

#define ILOSC_GATUNKOW_ZWIERZAT 5
#define ILOSC_GATUNKOW_ROSLIN 5

class Organizm;
class ListaOrganizmow;
class Czlowiek;

class Swiat
{

public:
    Swiat( int wymiarX, int wymiarY );
    void wykonajTure();
    void rysujSwiat();
    void rozpocznijNowaGre( const int &ileZwierzat, const int &ileRoslin, const bool &czyDodacLosowe );
    void zapiszDoPliku();
    Swiat wczytajZPliku();

    void aktuwujUmiejetnoscCzlowieka();
    bool poruszCzlowiekiem( const int &wKtoraStrone );

    void wylosujNowaPozycje( Organizm* organizm );
    void wylosujNowaPozycje( int &x, int &y, int skok );
    void narysujOrganizm( const int &wspX, const int &wspY, const char &znak);
    void usunOrganizm( Organizm * organizm );
    void dodajOrganizm( Organizm * nowyOrganizm );

    //
    //
    Organizm * czyNastapilaKolizjaZeZwierzeciem( Organizm * organizm );
    Organizm * czyNastapilaKolizjaZeZwierzeciem( const int &x, const int &y );
    Organizm * czyNastapilaKolizjaZRoslina( Organizm * organizm );
    //
    //

    Interfejs * getInterfejs();
    int getWymiarX();
    int getWymiarY();
    bool getCzyOK();

private:
    int wymiarX, wymiarY;
    char ** swiat;
    bool czyDobry;
    ListaOrganizmow * listaZwierzat;
    ListaOrganizmow * listaRoslin;
    Czlowiek * czlowiek;
    Interfejs * interfejs;

    void umiescOrganizmy();
    void resetujSwiat();
    void zaludnijSwiat();

    void wyprodukujOrganizmy( const int &ileZwierzat, const int &ileRoslin );
    bool czyMoznaDodacZwierze( const int &wspX, const int &wspY );
    bool czyMoznaDodacRosline( const int &wspX, const int &wspY );
    void koniecGry();
    void wygrana();
};
