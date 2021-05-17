#pragma once
#include "Roslina.h"

#define SILA_MLECZA 0
#define INICJATYWA_MLECZA 0
#define SYMBOL_MLECZA '}'

class Mlecz
    : public Roslina
{
 public:
    Mlecz( Swiat &swiat, const int &sila, const int &wspX, const int &wspY );
    Mlecz( Swiat &swiat, const int &x, const int &y);

    std::string getNazwa() override;
    void akcja() override;
    Organizm * getKopia() override;
    virtual void rysowanie() override;

    virtual ~Mlecz();

};
