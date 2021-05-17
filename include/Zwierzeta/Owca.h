#pragma once
#include <iostream>
#include "Zwierze.h"

#define SILA_OWCY 4
#define INICJATYWA_OWCY 4
#define SYMBOL_OWCY 'O'

class Owca
    : public Zwierze
{

public:
    Owca( Swiat &swiat, const int &sila, const int &inicjatywa, const int &x, const int &y);
    Owca( Swiat &swiat, const int &x, const int &y);

    virtual Organizm * getKopia() override;
    virtual void rysowanie() override;
    std::string getNazwa() override;
    virtual ~Owca();

};
