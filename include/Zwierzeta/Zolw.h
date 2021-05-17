#pragma once
#include "Zwierze.h"
#include <iostream>

#define SILA_ZOLWIA 2
#define INICJATYWA_ZOLWIA 1
#define SYMBOL_ZOLWIA 'Z'

class Zolw
    : public Zwierze
{

public:
    Zolw( Swiat &swiat, const int &sila, const int &inicjatywa, const int &x, const int &y);
    Zolw( Swiat &swiat, const int &x, const int &y);

    virtual void akcja() override;
    virtual Organizm * getKopia() override;
    virtual void rysowanie() override;
    std::string getNazwa() override;

    bool czyOdbilAtak( Organizm * atakujacy ) override;
    virtual ~Zolw();

};
