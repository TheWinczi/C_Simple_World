#include "Zwierzeta/Lis.h"
#include <time.h>
#include <cstdlib>

#include <iostream>
using namespace std;

Lis::Lis( Swiat &swiat, const int &sila, const int &inicjatywa, const int &x, const int &y )
    : Zwierze( swiat, sila, inicjatywa, x, y ) {};

Lis::Lis( Swiat &swiat, const int &x, const int &y )
    : Zwierze( swiat, SILA_LISA, INICJATYWA_LISA, x, y ) {};

void Lis::akcja()
{
    while( true )
    {
        int kopiaX = this->x;
        int kopiaY = this->y;

        swiat.wylosujNowaPozycje( this->x, this->y, 1 );

        Organizm * tmp = swiat.czyNastapilaKolizjaZeZwierzeciem( this );

        if( tmp != NULL ) // kolizja na wylosowanym polu
        {
            if( tmp->getSila() < this->sila )
            {
                this->kolizja( tmp );
                break;
            }
            else
            {
                this->setWspX( kopiaX );
                this->setWspY( kopiaY );
            }
        }
        else
            break;
    }

    this->czasIstnienia++;
}

void Lis::rysowanie()
{
    swiat.narysujOrganizm( this->x, this->y, SYMBOL_LISA );
}

Organizm * Lis::getKopia()
{
    return ( new Lis(this->swiat, this->sila, this->inicjatywa, this->x, this->y) );
}


std::string Lis::getNazwa()
{
    return "lis";
}

Lis::~Lis()
{
    ;
}
