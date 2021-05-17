#include "Rosliny/WilczeJagody.h"

#include <iostream>
using namespace std;

WilczeJagody::WilczeJagody( Swiat &swiat, const int &sila, const int &x, const int &y )
    : Roslina( swiat, sila, x, y ) {};

WilczeJagody::WilczeJagody( Swiat &swiat, const int &x, const int &y )
    : Roslina( swiat, SILA_WILCZYCH_JAGOD, x, y ) {};


std::string WilczeJagody::getNazwa()
{
    return "wilczejagody";
}

Organizm * WilczeJagody::getKopia()
{
    return (new WilczeJagody(this->swiat, this->sila, this->x, this->y));
}

void WilczeJagody::kolizja( Organizm * atakujacy )
{
    this->swiat.usunOrganizm( atakujacy );
    this->swiat.usunOrganizm( this );
}

void WilczeJagody::rysowanie()
{
    swiat.narysujOrganizm( this->x, this->y, SYMBOL_WILCZYCH_JAGOD );
}

WilczeJagody::~WilczeJagody()
{
    ;
}
