#include "Zwierze.h"
#include <iostream>

using namespace std;

Zwierze::Zwierze( Swiat &swiat, int sila, int inicjatywa, int x, int y )
    : Organizm( swiat, sila, inicjatywa, x, y ) {};


//
//  NADPISANE
//
void Zwierze::akcja()
{
    this->swiat.wylosujNowaPozycje( this );
    this->czasIstnienia++;
}


void Zwierze::kolizja( Organizm * atakujacy )
{
    this->swiat.getInterfejs()->dodajWiadomoscDoWyswietlenia("Kolizja " + this->getNazwa() + " z " + atakujacy->getNazwa() );

    if( this->getNazwa() == atakujacy->getNazwa() )
        this->sprobujSieRozmnozyc(this, atakujacy);
    else
    {

        if( !this->czyOdbilAtak(atakujacy) )
        {
            if(  this->getSila() > atakujacy->getSila() )
            {
                this->getSwiat().usunOrganizm( atakujacy );
            }
            else if( this->getSila() < atakujacy->getSila() )
            {
                this->getSwiat().usunOrganizm( this );
            }
            else if( this->getSila() == atakujacy->getSila() )
            {
                this->getSwiat().usunOrganizm(this);
            }

        }
    }
}


std::string Zwierze::getGatunek()
{
    return "zwierze";
}


void Zwierze::przeniesSieNa( const int &x, const int &y )
{
    this->x = x;
    this->y = y;
}


bool Zwierze::czyOdbilAtak( Organizm * atakujacy )
{
    return false;
}

void Zwierze::sprobujSieRozmnozyc( Organizm * pierwszyOrganizm, Organizm * drugiOrganizm )
{
    if( pierwszyOrganizm->getCzyAktywny() && drugiOrganizm->getCzyAktywny() && pierwszyOrganizm->getCzasIstnienia() > WIEK_PELNOLETNIOSCI && drugiOrganizm->getCzasIstnienia() > WIEK_PELNOLETNIOSCI )
    {
        Organizm * dziecko = pierwszyOrganizm->getKopia();
        pierwszyOrganizm->getSwiat().wylosujNowaPozycje( dziecko );

        dziecko->setCzyAktywny( false );
        pierwszyOrganizm->setCzyAktywny(false);
        drugiOrganizm->setCzyAktywny(false);

        pierwszyOrganizm->getSwiat().dodajOrganizm( dziecko );
        pierwszyOrganizm->getSwiat().getInterfejs()->dodajWiadomoscDoWyswietlenia("Nastapilo rozmnazanie. Dodano dziecko " + pierwszyOrganizm->getNazwa());
    }
}

void Zwierze::rysowanie()
{
    this->swiat.narysujOrganizm( this->x, this->y, DOMYSLNY_SYMBOL_ZWIERZECIA );
}

std::string Zwierze::toString()
{
    //std::string ciag = this->getNazwa() + " " + this->getInicjatywa() + " " + this->getSila() + " " + this->getWspX() + " " + this->getWspY();
    //return ciag;
}
