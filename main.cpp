#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>

#include "Swiat.h"
#include "Zwierzeta/Antylopa.h"
#include "Zwierzeta/Wilk.h"
#include "Zwierzeta/Zolw.h"
#include "Zwierzeta/Owca.h"
#include "Zwierzeta/Lis.h"

#define ILE_ORGANIZMOW 7

using namespace std;

int main()
{
    srand( time(NULL) );
    Swiat firstWorld(20,20);
    firstWorld.rozpocznijNowaGre( 5, 10, true );
    firstWorld.rysujSwiat();

    char znak;
    while( firstWorld.getCzyOK() )
    {
        znak = getch();
        if( znak == 't' || znak == 'T' )
        {
            system( "cls" );
            firstWorld.wykonajTure();
            if( firstWorld.getCzyOK() )
                firstWorld.rysujSwiat();
        }
        else if( znak == 'q' )
            break;
        else if( znak == 72 || znak == 75 || znak == 77 || znak == 80 )
        {
            if( firstWorld.poruszCzlowiekiem(znak) )
            {
                system( "cls" );
                firstWorld.wykonajTure();
                if( firstWorld.getCzyOK() )
                    firstWorld.rysujSwiat();
            }
        }
        else if ( znak == '1' )
        {
            firstWorld.aktuwujUmiejetnoscCzlowieka();
        }
        else if( znak == 's' )
            firstWorld.zapiszDoPliku();
        else if( znak == 'l' )
        {
            system( "cls" );
            firstWorld = firstWorld.wczytajZPliku();
            firstWorld.wykonajTure();
            firstWorld.rysujSwiat();
        }
    }

    return 0;
}
