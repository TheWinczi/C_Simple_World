#include "Zwierzeta/Antylopa.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Antylopa::Antylopa( Swiat& swiat, const int &sila, const int &inicjatywa, const int &x, const int &y )
    : Zwierze( swiat, sila, inicjatywa, x, y ) {};

Antylopa::Antylopa( Swiat& swiat, const int &x, const int &y )
    : Zwierze( swiat, SILA_ANTYLOPY, INICJATYWA_ANTYLOPY, x, y ) {};

void Antylopa::akcja()
{
    int newX = this->x;
    int newY = this->y;

    swiat.wylosujNowaPozycje( newX, newY, 2 );
    this->x = newX;
    this->y = newY;

    this->czasIstnienia++;
}

void Antylopa::kolizja( Organizm * organizm )
{
    if( rand()%100 + 1 <= PRAWDOPODOBIENSTWO_UNIKU )
    {
        this->getSwiat().getInterfejs()->dodajWiadomoscDoWyswietlenia("Antylopa uniknela kolizji i uciekla na sasiednie pole");
        this->swiat.wylosujNowaPozycje( this );
    }
    else
        Zwierze::kolizja( organizm );
}

std::string Antylopa::getNazwa()
{
    return "antylopa";
}

Organizm * Antylopa::getKopia()
{
    return ( new Antylopa(this->swiat, this->sila, this->inicjatywa, this->x, this->y) );
}

void Antylopa::rysowanie()
{
    this->getSwiat().narysujOrganizm( this->getWspX(), this->getWspY(), SYMBOL_ANTYLOPY);
}

Antylopa::~Antylopa()
{
    ;
}
