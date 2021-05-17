#include "Zwierzeta/Wilk.h"

Wilk::Wilk( Swiat &swiat, const int &sila, const int &inicjatywa, const int &x, const int &y )
    : Zwierze( swiat, sila, inicjatywa, x, y ) {};

Wilk::Wilk( Swiat &swiat, const int &x, const int &y )
    : Zwierze( swiat, SILA_WILKA, INICJATYWA_WILKA, x, y ) {};

std::string Wilk::getNazwa()
{
    return "wilk";
}

Organizm * Wilk::getKopia()
{
    return ( new Wilk(this->swiat, this->sila, this->inicjatywa, this->x, this->y) );
}

void Wilk::rysowanie()
{
    swiat.narysujOrganizm( this->x, this->y, SYMBOL_WILKA );
}

Wilk::~Wilk()
{
    ;
}
