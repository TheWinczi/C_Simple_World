#pragma once
#include "Organizm.h"

#define DOMYSLNA_INICJATYWA_ROSLIN 0
#define DOMYSLNY_SYMBOL_ROSLINY 'R'

#define PRAWDOPODOBIENSTWO_ROZMNOZENIA_SIE 5

class Roslina
    : public Organizm
{

public:

    Roslina( Swiat &swiat, int sila, int x, int y );
    void sprobujSieRozmnozyc();

    //
    //  NADPISANE
    //
    virtual void akcja() override;
    virtual void rysowanie() override;
    virtual void kolizja( Organizm * atakujacy ) override;
    virtual void przeniesSieNa( const int &a, const int &y ) override;
    virtual bool czyOdbilAtak( Organizm * atakujacy ) override;
    virtual std::string getGatunek() override;
    virtual std::string toString() override;


    //
    //  WIRTUALNE
    //
    virtual Organizm * getKopia() = 0;
    virtual ~Roslina();
};
