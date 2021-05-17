#pragma once
#include <iostream>
#include "Zwierze.h"

#define SILA_CZLOWIEKA 5
#define INICJATYWA_CZLOWIEKA 4

#define COOLDOWN_UMIEJETNOSCI 5
#define CZAS_TRWANIA_UMIEJETNOSCI 5
#define SILA_PO_UZYCIU_UMIEJETNOSCI 10

#define SYMBOL_CZLOWIEKA 'C'

class Czlowiek
    : public Zwierze
{
public:
    Czlowiek( Swiat &swiat, const int &sila, const int &inicjatywa, const int &x, const int &y);
    Czlowiek( Swiat &swiat, const int &x, const int &y);


    void akcja() override;
    void rysowanie() override;
    bool poruszSie( int wKtoraStrone );
    void sprobujAktywowacUmiejetnosc();
    virtual Organizm * getKopia() override;
    std::string getGatunek() override;
    std::string getNazwa() override;
    virtual ~Czlowiek();

private:
    int cooldownUmiejetnosci;
    int czasTrwaniaUmiejetnosci;
    bool czyUmiejetnoscAktywna;
};
