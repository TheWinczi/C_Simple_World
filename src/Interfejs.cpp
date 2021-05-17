#include "Interfejs.h"

#include <stdio.h>
#include <iostream>
#include <cstdlib>

#include <iostream>
using namespace std;

Interfejs::Interfejs()
{
    this->autor = "Maciej Winczewski 183211";
    this->wiadomosc = "";
    this->informacje = "T/t -> kolejna tura \nStrzalki -> poruszanie czlowiekiem \n1 -> dodatkowa umiejetnosc czlowieka \ns -> zapisz stan gry \nl -> wczytaj zapisany stan gry \nq -> wyjdz z gry\n";

    this->poprzedniaIloscKolumn = 0;
    this->poprzedniaIloscWierszy = 0;
    this->poprzedniaTablica = NULL;
}

void Interfejs::dodajWiadomoscDoWyswietlenia( const string &nowaWiadomosc )
{
    this->wiadomosc = this->wiadomosc + nowaWiadomosc + " \n";
}

void Interfejs::wyswietlAutora()
{
    cout<<this->autor<<endl<<endl;
}

void Interfejs::wyswietlInformacje()
{
    cout<<this->informacje<<endl;
}

void Interfejs::wyswietlWiadomosc()
{
    cout<<this->wiadomosc<<endl;
}

void Interfejs::wyswietlSwiat( char * swiat[], const int &wiersze, const int &kolumny )
{
    this->poprzedniaTablica = swiat;
    this->poprzedniaIloscKolumn = kolumny;
    this->poprzedniaIloscWierszy = wiersze;

    for( int i=0; i<wiersze+2; i++)
    {
        for( int j=0; j<kolumny+2; j++)
            cout<<swiat[i][j]<<" ";

        cout<<endl;
    }

    cout<<endl;
}

void Interfejs::wyswietlInterface( char * swiat[], const int &wiersze, const int &kolumny )
{
    this->wyswietlAutora();
    this->wyswietlSwiat( swiat, wiersze, kolumny );
    this->wyswietlInformacje();
    this->wyswietlWiadomosc();

    this->wyzerujWiadomosci();
}

Interfejs * Interfejs::getInterfejs()
{
    return this;
}

void Interfejs::wyzerujWiadomosci()
{
    this->wiadomosc = "";
}

void Interfejs::odswiez()
{
    system( "cls" );
    this->wyswietlInterface( this->poprzedniaTablica, this->poprzedniaIloscWierszy, this->poprzedniaIloscKolumn );
}

void Interfejs::wyczyscEkran()
{
    system( "cls" );
}

void Interfejs::koniecGry()
{
    cout<<"*********************************"<<endl;
    cout<<"*          KONIEC GRY           *"<<endl;
    cout<<"*********************************"<<endl;
    cout<<endl;
    cout<<"Niestety gra sie zakonczyla - czlowiek nie zyje"<<endl;
}

void Interfejs::wygrana()
{
    cout<<"*********************************"<<endl;
    cout<<"*            !BRAWO!            *"<<endl;
    cout<<"*********************************"<<endl;
    cout<<endl;
    cout<<"Brawo, gra zakonczyla sie zwyciestwem czlowieka"<<endl;
}
