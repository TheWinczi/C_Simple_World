#include "Rosliny/BarszczSosnowskiego.h"
#include "Organizm.h"

#include <iostream>
using namespace std;

BarszczSosnowskiego::BarszczSosnowskiego( Swiat &swiat, const int &sila, const int &wspX, const int &wspY )
    : Roslina( swiat, sila, wspX, wspY ) {};

BarszczSosnowskiego::BarszczSosnowskiego( Swiat &swiat, const int &wspX, const int &wspY )
    : Roslina( swiat, SILA_BARSZCZU_SOSNOWSKIEGO, wspX, wspY ) {};

void BarszczSosnowskiego::akcja()
{
    int tempX = this->x + 1;
    int tempY = this->y - 1;

    if( tempX <= this->swiat.getWymiarX() )// wymiarX - 1
    for( int i=0; i<3; i++ )
    {
        if( tempY + i  >= 1 && tempY + i <= this->swiat.getWymiarY() ) // wymiarY - 1
        {
            Organizm * tmp = swiat.czyNastapilaKolizjaZeZwierzeciem( tempX, tempY );
            if( tmp != NULL )
                swiat.usunOrganizm( tmp );
        }
    }

    tempX = this->x - 1;
    if( tempX >= 1 )
        for( int i=0; i<3; i++ )
        {
            if( tempY + i  >= 1 && tempY + i <= this->swiat.getWymiarY() - 1 ) // wymiarY - 1
            {
                Organizm * tmp = swiat.czyNastapilaKolizjaZeZwierzeciem( tempX, tempY );
                if( tmp != NULL )
                    swiat.usunOrganizm( tmp );
            }
        }

    tempX = this->x;
    tempY = this->y + 1;

    if( tempY >= 1 && tempY <= this->swiat.getWymiarY() - 1 ) // wymiarY - 1
    {
        Organizm * tmp = swiat.czyNastapilaKolizjaZeZwierzeciem( tempX, tempY );
        if( tmp != NULL )
            swiat.usunOrganizm( tmp );
    }

    tempY = this->y - 1;
    if( tempY >= 1 && tempY <= this->swiat.getWymiarX() - 1 ) // wymiarY - 1
    {
        Organizm * tmp = swiat.czyNastapilaKolizjaZeZwierzeciem( tempX, tempY );
        if( tmp != NULL )
            swiat.usunOrganizm( tmp );
    }

    tempY = this->y;
    tempX = this->x;
    if( tempY >= 1 && tempY <= this->swiat.getWymiarX() - 1 ) // wymiarY - 1
    {
        Organizm * tmp = swiat.czyNastapilaKolizjaZeZwierzeciem( tempX, tempY );
        if( tmp != NULL )
            swiat.usunOrganizm( tmp );
    }

    this->czasIstnienia++;
}

std::string BarszczSosnowskiego::getNazwa()
{
    return "barszczsosnowskiego";
}

Organizm * BarszczSosnowskiego::getKopia()
{
    return (new BarszczSosnowskiego(this->swiat, this->sila, this->x, this->y));
}

void BarszczSosnowskiego::kolizja( Organizm * atakujacy )
{
    this->swiat.usunOrganizm( atakujacy );
    this->swiat.usunOrganizm( this );
}

void BarszczSosnowskiego::rysowanie()
{
    swiat.narysujOrganizm( this->x, this->y, SYMBOL_BARSZCZU_SOSNOWSKIEGO );
}

BarszczSosnowskiego::~BarszczSosnowskiego()
{
    ;
}
