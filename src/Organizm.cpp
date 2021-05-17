#include "Organizm.h"


Organizm::Organizm( Swiat &swiat, const int &sila, const int inicjatywa, const int &x, const int &y )
    : swiat(swiat), sila(sila), inicjatywa(inicjatywa), x(x), y(y), czyAktywny(false), czasIstnienia(1) {};


//
//  GETTERY
//
int Organizm::getInicjatywa()
{
    return this->inicjatywa;
}

int Organizm::getSila()
{
    return this->sila;
}

int Organizm::getWspX()
{
    return this->x;
}

int Organizm::getWspY()
{
    return this->y;
}

bool Organizm::getCzyAktywny()
{
    return this->czyAktywny;
}

int Organizm::getCzasIstnienia()
{
    return this->czasIstnienia;
}


//
//  SETTERY
//
void Organizm::setWspX( int newX )
{
    this->x = newX;
}

Swiat & Organizm::getSwiat()
{
    return this->swiat;
}

void Organizm::setWspY( int newY )
{
    this->y = newY;
}

void Organizm::setSila( int nowaSila )
{
    this->sila = nowaSila;
}

void Organizm::setInicjatywa( int inicjatywa )
{
    this->inicjatywa = inicjatywa;
}

void Organizm::setCzyAktywny( bool czyAktywny )
{
    this->czyAktywny = czyAktywny;
}


//
// INNE
//
Organizm::~Organizm()
{
    ;
}
