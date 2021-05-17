#include "Rosliny/Mlecz.h"

Mlecz::Mlecz( Swiat &swiat, const int &sila, const int &x, const int &y )
    : Roslina( swiat, sila, x, y ) {};

Mlecz::Mlecz( Swiat &swiat, const int &x, const int &y )
    : Roslina( swiat, SILA_MLECZA, x, y ) {};

void Mlecz::akcja()
{
    for( int i = 0; i < 3; i++ )
        Roslina::akcja();

    this->czasIstnienia++;
}

std::string Mlecz::getNazwa()
{
    return "mlecz";
}

Organizm * Mlecz::getKopia()
{
    return (new Mlecz(this->swiat, this->sila, this->x, this->y));
}

void Mlecz::rysowanie()
{
    swiat.narysujOrganizm( this->x, this->y, SYMBOL_MLECZA );
}

Mlecz::~Mlecz()
{
    ;
}
