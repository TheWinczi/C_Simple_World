#include "Zwierzeta/Owca.h"

Owca::Owca( Swiat &swiat, const int &sila, const int &inicjatywa, const int &x, const int &y )
    : Zwierze( swiat, sila, inicjatywa, x, y ) {};

Owca::Owca( Swiat &swiat, const int &x, const int &y )
    : Zwierze( swiat, SILA_OWCY, INICJATYWA_OWCY, x, y ) {};

std::string Owca::getNazwa()
{
    return "owca";
}

Organizm * Owca::getKopia()
{
    return ( new Owca(this->swiat, this->sila, this->inicjatywa, this->x, this->y) );
}

void Owca::rysowanie()
{
    swiat.narysujOrganizm( this->x, this->y, SYMBOL_OWCY );
}

Owca::~Owca()
{
    ;
}
