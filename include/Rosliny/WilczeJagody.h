#pragma once
#include "Roslina.h"

#define SILA_WILCZYCH_JAGOD 10
#define INICJATYWA_WILCZYCH_JAGOD 0
#define SYMBOL_WILCZYCH_JAGOD '%'

class WilczeJagody
    : public Roslina
{
 public:
    WilczeJagody( Swiat &swiat, const int &sila, const int &wspX, const int &wspY );
    WilczeJagody( Swiat &swiat, const int &x, const int &y);

    std::string getNazwa() override;
    virtual void kolizja( Organizm * atakujacy ) override;
    Organizm * getKopia() override;
    virtual void rysowanie() override;

    virtual ~WilczeJagody();

};
