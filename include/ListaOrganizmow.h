#pragma once
#include "Organizm.h"

class Organizm; // predefinicja


class Wezel
{
public:
    Wezel();

    Organizm * organizm;
    Wezel * nastepny;
    Wezel * poprzedni;
};

class ListaOrganizmow
{
public:
    ListaOrganizmow();

    void dodajOrganizm( Organizm * organizm );
    void usunOrganizm( Organizm * organizm );
    int getJakDuzoElementow();
    void wyswietl();

    //
    //  GETTERY
    //
    Wezel * getGlowa();
    Wezel * getOgon();

private:
    Wezel * glowa;
    Wezel * ogon;
    int jakDuzoElementow;

    void dodajJakoPierwszy( Wezel * wezel );
    void dodajJakoOstatni( Wezel * wezel );
    void dodajPrzed( Wezel * nowyWezel, Wezel * wezel );

    //
    //  STATYCZNE
    //
    static bool czyTenSam( const Organizm * const pierwszyOrganizm, const Organizm * const drugiOrganizm );
};
