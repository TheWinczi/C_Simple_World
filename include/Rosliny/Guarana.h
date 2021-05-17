#pragma once
#include "Roslina.h"

#define SILA_GUARANY 0
#define INICJATYWA_GUARANY 0
#define SYMBOL_GUARANY '$'


class Guarana
    : public Roslina
{
 public:
    Guarana( Swiat &swiat, const int &sila, const int &wspX, const int &wspY );
    Guarana( Swiat &swiat, const int &x, const int &y);

    std::string getNazwa() override;
    virtual void kolizja( Organizm * atakujacy ) override;
    Organizm * getKopia() override;
    virtual void rysowanie() override;

    virtual ~Guarana();

};
