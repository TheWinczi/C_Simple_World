#pragma once
#include <iostream>
#include "Zwierze.h"

#define SILA_WILKA 9
#define INICJATYWA_WILKA 5
#define SYMBOL_WILKA 'W'

class Wilk
    : public Zwierze
{

public:
    Wilk( Swiat &swiat, const int &sila, const int &inicjatywa, const int &x, const int &y );
    Wilk( Swiat &swiat, const int &x, const int &y );

    virtual Organizm * getKopia() override;
    virtual void rysowanie() override;
    std::string getNazwa() override;

    virtual ~Wilk();
};
