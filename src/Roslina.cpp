#include "Roslina.h"
#include "Organizm.h"

#include <time.h>
#include <cstdlib>

#include <iostream>
using namespace std;

Roslina::Roslina( Swiat &swiat, int sila, int x, int y )
    : Organizm( swiat, sila, DOMYSLNA_INICJATYWA_ROSLIN, x, y ) {};


//
//  NADPISANE
//
void Roslina::akcja()
{
    if( this->czyAktywny && rand()%100 + 1 <= PRAWDOPODOBIENSTWO_ROZMNOZENIA_SIE )
        this->sprobujSieRozmnozyc();

    this->czasIstnienia++;
}

void Roslina::rysowanie()
{
    swiat.narysujOrganizm( this->x, this->y, DOMYSLNY_SYMBOL_ROSLINY );
}

void Roslina::kolizja( Organizm * atakujacy )
{
    this->getSwiat().getInterfejs()->dodajWiadomoscDoWyswietlenia("Kolizja " + this->getNazwa() + " z " + atakujacy->getNazwa());

    if( !this->czyOdbilAtak(atakujacy) )
        this->getSwiat().usunOrganizm( this );
}

bool Roslina::czyOdbilAtak( Organizm * atakujacy )
{
    return false;
}

std::string Roslina::getGatunek()
{
    return "roslina";
}

void Roslina::przeniesSieNa( const int &x, const int &y )
{
    this->x = x;
    this->y = y;
}

//
//  POZOSTALE
//
void Roslina::sprobujSieRozmnozyc()
{
    if( this->getCzasIstnienia() > 3 )
    {
        int newX = this->x;
        int newY = this->y;

        swiat.wylosujNowaPozycje( newX, newY, 1 );
        if( !swiat.czyNastapilaKolizjaZRoslina(this) )
        {
            Organizm * dziecko = this->getKopia();
            dziecko->setWspX( newX );
            dziecko->setWspY( newY );

            this->swiat.dodajOrganizm( dziecko );
        }

        this->getSwiat().getInterfejs()->dodajWiadomoscDoWyswietlenia( this->getNazwa() + " rozprzestrzenil sie");
    }
}

std::string Roslina::toString()
{
    //std::string ciag = this->getNazwa() + " " + this->getInicjatywa() + " " + this->getSila() + " " + this->getWspX() + " " + this->getWspY();
    //return ciag;
}

Roslina::~Roslina()
{
    ;
}

