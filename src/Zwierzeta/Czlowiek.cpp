#include "Zwierzeta/Czlowiek.h"

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


Czlowiek::Czlowiek( Swiat &swiat, const int &sila, const int &inicjatywa, const int &x, const int &y )
    : Zwierze( swiat, sila, inicjatywa, x, y )
{
    this->cooldownUmiejetnosci = 0;
    this->czasTrwaniaUmiejetnosci = CZAS_TRWANIA_UMIEJETNOSCI;
    this->czyUmiejetnoscAktywna = false;
}

Czlowiek::Czlowiek( Swiat &swiat, const int &x, const int &y )
    : Zwierze( swiat, SILA_CZLOWIEKA, INICJATYWA_CZLOWIEKA, x, y )
{
    this->cooldownUmiejetnosci = 0;
    this->czasTrwaniaUmiejetnosci = CZAS_TRWANIA_UMIEJETNOSCI;
    this->czyUmiejetnoscAktywna = false;
}

void Czlowiek::akcja()
{
    if( this->czyUmiejetnoscAktywna )
    {
        if( this->czasTrwaniaUmiejetnosci == CZAS_TRWANIA_UMIEJETNOSCI )// pierwsza tura z umiejetnoscia
        {
            this->czasTrwaniaUmiejetnosci = 10 - this->sila; // ustaw czas trwania umiejetnosci
            this->setSila( 10 );
        }
        else
            this->setSila( this->sila - 1 );

        this->czasTrwaniaUmiejetnosci = this->czasTrwaniaUmiejetnosci - 1;

        std::stringstream ss;
        ss << this->czasTrwaniaUmiejetnosci;
        std::string out_string = ss.str();

        string info = "Pozostalo " + out_string;
        this->swiat.getInterfejs()->dodajWiadomoscDoWyswietlenia( info + " tur do konca specjalnej umiejetnosci czlowieka" );

        if( this->czasTrwaniaUmiejetnosci <= 0 )
        {
            this->czyUmiejetnoscAktywna = false;
            this->czasTrwaniaUmiejetnosci = CZAS_TRWANIA_UMIEJETNOSCI;
            this->cooldownUmiejetnosci = COOLDOWN_UMIEJETNOSCI;
            this->setSila( SILA_CZLOWIEKA );
        }
    }

    if( this->cooldownUmiejetnosci > 0 )
        this->cooldownUmiejetnosci--;

    this->czasIstnienia++;
}

std::string Czlowiek::getNazwa()
{
    return "czlowiek";
}

void Czlowiek::rysowanie()
{
    swiat.narysujOrganizm( this->x, this->y, 'C' );
}

void Czlowiek::sprobujAktywowacUmiejetnosc()
{
    if( cooldownUmiejetnosci <= 0 )
    {
        this->czyUmiejetnoscAktywna = true;
        this->getSwiat().getInterfejs()->dodajWiadomoscDoWyswietlenia("Aktywowano umiejetnosc scpecjalna czlowieka, jego sila wzrosla do 10");
    }
}

bool Czlowiek::poruszSie( int wKtoraStrone )
{
    switch( wKtoraStrone )
    {
    case 72:
        if( this->y >= 2 )
        {
            this->przeniesSieNa( this->x, this->y-1 );
            return true;
        }
        break;
    case 80:
        if( this->y <= this->swiat.getWymiarY() - 1 )
        {
            this->przeniesSieNa( this->x, this->y+1 );
            return true;
        }
        break;
    case 75:
        if( this->x >= 2 )
        {
            this->przeniesSieNa( this->x-1, this->y );
            return true;
        }
        break;
    case 77:
        if( this->x <= this->swiat.getWymiarX() - 1 )
        {
            this->przeniesSieNa( this->x+1, this->y );
            return true;
        }
        break;
    }
    return false;
}

Organizm * Czlowiek::getKopia()
{
    return new Czlowiek( this->swiat, this->x, this->y );
}

std::string Czlowiek::getGatunek()
{
    return "czlowiek";
}

Czlowiek::~Czlowiek()
{
    ;
}
