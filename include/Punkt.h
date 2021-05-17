#pragma once

class Punkt
{
private:
    int x;
    int y;
public:
    Punkt( int x, int y );

    Punkt * getPunkt();
    int getX();
    int getY();
};
