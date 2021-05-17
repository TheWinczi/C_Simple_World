#include "Zwierzeta/Zolw.h"
#include <time.h>
#include <cstdlib>

#include <iostream>
using namespace std;

Zolw::Zolw( Swiat &swiat, const int &sila, const int &inicjatywa, const int &x, const int &y )
    : Zwierze( swiat, sila, inicjatywa, x, y ) {};

Zolw::Zolw( Swiat &swiat, const int &x, const int &y )
    : Zwierze( swiat, SILA_ZOLWIA, INICJATYWA_ZOLWIA, x, y ) {};


void Zolw::akcja()
{
    if( rand()%100 >= 75 )
        this->swiat.wylosujNowaPozycje( this );

    this->czasIstnienia++;
}

Organizm * Zolw::getKopia()
{
    return ( new Zolw(this->swiat, this->sila, this->inicjatywa, this->x, this->y) );
}

bool Zolw::czyOdbilAtak( Organizm * atakujacy )
{
    if( atakujacy->getSila() < 5 )
    {
        this->swiat.getInterfejs()->dodajWiadomoscDoWyswietlenia("Zolw odpil atak " + atakujacy->getNazwa());
        return true;
    }
    return false;
}

void Zolw::rysowanie()
{
    swiat.narysujOrganizm( this->x, this->y, SYMBOL_ZOLWIA );
}

std::string Zolw::getNazwa()
{
    return "zolw";
}


Zolw::~Zolw()
{
    ;
}
