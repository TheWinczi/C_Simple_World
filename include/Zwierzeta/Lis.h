#pragma once
#include <iostream>
#include "Zwierze.h"

#define SILA_LISA 3
#define INICJATYWA_LISA 7
#define SYMBOL_LISA 'L'

class Lis
    : public Zwierze
{

public:
    Lis( Swiat &swiat, const int &sila, const int &inicjatywa, const int &x, const int &y);
    Lis( Swiat &swiat, const int &x, const int &y);

    void akcja() override;
    virtual Organizm * getKopia() override;
    virtual void rysowanie() override;
    std::string getNazwa() override;
    virtual ~Lis();

};
