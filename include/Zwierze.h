#pragma once
#include "Organizm.h"

#define DOMYSLNY_SYMBOL_ZWIERZECIA 'Z'
#define WIEK_PELNOLETNIOSCI 5


class Zwierze
    : public Organizm
{
public:

    Zwierze( Swiat &swiat, int sila, int inicjatywa, int x, int y );

    //
    //  NADPISANE
    //
    virtual void akcja() override;
    virtual void kolizja( Organizm * atakujacy ) override;
    virtual void rysowanie() override;
    virtual bool czyOdbilAtak( Organizm * atakujacy ) override;
    virtual void przeniesSieNa( const int &a, const int &y ) override;
    virtual std::string getGatunek() override;
    virtual std::string toString() override;

    //
    //  DODATKOWE
    //
    void przemiescSie( const int &x, const int &y );
    static void sprobujSieRozmnozyc( Organizm * pierwszyOrganizm, Organizm * drugiOrganizm );

    //
    //  WIRTUALNE
    //
    virtual Organizm * getKopia() = 0;
    virtual std::string getNazwa() = 0;


};
