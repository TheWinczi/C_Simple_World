#include "Rosliny/Guarana.h"

#include <iostream>
using namespace std;

Guarana::Guarana( Swiat &swiat, const int &sila, const int &x, const int &y )
    : Roslina( swiat, sila, x, y ) {};

Guarana::Guarana( Swiat &swiat, const int &x, const int &y )
    : Roslina( swiat, SILA_GUARANY, x, y ) {};


std::string Guarana::getNazwa()
{
    return "guarana";
}

Organizm * Guarana::getKopia()
{
    return (new Guarana(this->swiat, this->sila, this->x, this->y));
}

void Guarana::kolizja( Organizm * atakujacy )
{
    this->getSwiat().getInterfejs()->dodajWiadomoscDoWyswietlenia("Sila " + atakujacy->getNazwa() + " zostala zwiekszona o 3");
    atakujacy->setSila( atakujacy->getSila() + 3 );

    this->swiat.usunOrganizm( this );
}

void Guarana::rysowanie()
{
    swiat.narysujOrganizm( this->x, this->y, SYMBOL_GUARANY );
}

Guarana::~Guarana()
{
    ;
}
