#pragma once
#include "Roslina.h"

#define SILA_TRAWY 0
#define INICJATYWA_TRAWY 0
#define SYMBOL_TRAWY '^'

class Trawa
    : public Roslina
{
 public:
    Trawa( Swiat &swiat, const int &sila, const int &wspX, const int &wspY );
    Trawa( Swiat &swiat, const int &x, const int &y);

    std::string getNazwa() override;
    Organizm * getKopia() override;
    virtual void rysowanie() override;

    virtual ~Trawa();

};
