#pragma once
#include <iostream>
#include "Swiat.h"

class Swiat;


class Organizm{

public:
    Organizm( Swiat &swiat, const int &sila, const int inicjatywa, const int &x, const int &y );

    //
    //  METODY WIRTUALNE
    //
    virtual void akcja() = 0;
    virtual void kolizja( Organizm * atakujacy ) = 0;
    virtual void rysowanie() = 0;
    virtual void przeniesSieNa( const int &x, const int &y ) = 0;
    virtual bool czyOdbilAtak( Organizm * atakujacy ) = 0;
    virtual std::string getGatunek() = 0;
    virtual std::string getNazwa() = 0;
    virtual Organizm * getKopia() = 0;
    virtual std::string toString() = 0;
    virtual ~Organizm();

    //
    //  GETTERY I SETTERY PRZYDATNE DLA KAZDEGO ORGANIZMU
    //
    void setWspX( int newX );
    void setWspY( int newX );
    void setSila( int newSila );
    void setInicjatywa( int inicjatywa );
    void setCzyAktywny( bool czyAktywny );

    int getSila();
    int getInicjatywa();
    int getWspX();
    int getWspY();
    bool getCzyAktywny();
    int getCzasIstnienia();

    Swiat &getSwiat();


protected:
    int sila, inicjatywa;
    int x, y;
    int czasIstnienia;
    bool czyAktywny;
    Swiat &swiat;
};
