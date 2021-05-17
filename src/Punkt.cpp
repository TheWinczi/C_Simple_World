#include "Punkt.h"


//
//  KONSTRUKTOR
//
Punkt::Punkt( int x, int y )
    : x(x), y(y) {};



//
//  GETERY
//
Punkt * Punkt::getPunkt() { return this; }
int Punkt::getX() { return this->x; }
int Punkt::getY() { return this->y; }
