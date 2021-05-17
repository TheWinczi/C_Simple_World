#pragma once
#include <iostream>
#include "Zwierze.h"

#define SILA_ANTYLOPY 4
#define INICJATYWA_ANTYLOPY 4

#define PRAWDOPODOBIENSTWO_UNIKU 50
#define SYMBOL_ANTYLOPY 'A'

class Antylopa
    : public Zwierze
{

public:
    Antylopa( Swiat &swiat, const int &sila, const int &inicjatywa, const int &x, const int &y);
    Antylopa( Swiat &swiat, const int &x, const int &y);

    void akcja() override;
    void kolizja( Organizm* organizm ) override;
    virtual void rysowanie() override;
    virtual Organizm * getKopia() override;
    virtual std::string getNazwa() override;

    virtual ~Antylopa();

};
