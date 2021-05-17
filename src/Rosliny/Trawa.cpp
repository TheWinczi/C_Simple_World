#include "Rosliny/Trawa.h"

Trawa::Trawa( Swiat &swiat, const int &sila, const int &x, const int &y )
    : Roslina( swiat, sila, x, y ) {};

Trawa::Trawa( Swiat &swiat, const int &x, const int &y )
    : Roslina( swiat, SILA_TRAWY, x, y ) {};

std::string Trawa::getNazwa()
{
    return "trawa";
}

Organizm * Trawa::getKopia()
{
    return (new Trawa(this->swiat, this->sila, this->x, this->y));
}

void Trawa::rysowanie()
{
    swiat.narysujOrganizm( this->x, this->y, SYMBOL_TRAWY );
}

Trawa::~Trawa()
{
    ;
}
