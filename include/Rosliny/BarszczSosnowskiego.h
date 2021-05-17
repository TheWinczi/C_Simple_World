#pragma once
#include "Roslina.h"

#define SILA_BARSZCZU_SOSNOWSKIEGO 10
#define INICJATYWA_BARSZCZU_SOSNOWSKIEGO 0
#define SYMBOL_BARSZCZU_SOSNOWSKIEGO '&'


class BarszczSosnowskiego
    : public Roslina
{
 public:
    BarszczSosnowskiego( Swiat &swiat, const int &sila, const int &wspX, const int &wspY );
    BarszczSosnowskiego( Swiat &swiat, const int &x, const int &y);

    std::string getNazwa() override;
    void akcja() override;
    virtual void kolizja( Organizm * atakujacy ) override;
    Organizm * getKopia() override;
    virtual void rysowanie() override;

    virtual ~BarszczSosnowskiego();

};
