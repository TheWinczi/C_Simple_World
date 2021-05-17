#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>

#include "Swiat.h"
#include "Zwierzeta/Antylopa.h"
#include "Zwierzeta/Lis.h"
#include "Zwierzeta/Owca.h"
#include "Zwierzeta/Wilk.h"
#include "Zwierzeta/Zolw.h"
#include "Zwierzeta/Czlowiek.h"

#include "Rosliny/BarszczSosnowskiego.h"
#include "Rosliny/Guarana.h"
#include "Rosliny/Mlecz.h"
#include "Rosliny/Trawa.h"
#include "Rosliny/WilczeJagody.h"

#define PLIK_ZE_STANEM_GRY "stangry.txt"
using namespace std;


//
//  KONSTRUKTOR
//
Swiat::Swiat( int wymiarX, int wymiarY )
{
    this->wymiarX = wymiarX;
    this->wymiarY = wymiarY;
    this->listaZwierzat = new ListaOrganizmow();
    this->listaRoslin = new ListaOrganizmow();

    char ** array = new char * [wymiarY+2];
    for( int i=0; i<wymiarY+2; i++)
        array[i] = new char[wymiarX+2];

    this->swiat = array;
    this->interfejs = new Interfejs();
    this->czyDobry = true;
}



//
//  GRA
//
void Swiat::rysujSwiat()
{
    this->interfejs->wyswietlInterface( this->swiat, this->wymiarY, this->wymiarX );
}


void Swiat::umiescOrganizmy()
{
    Wezel * wezel = listaRoslin->getGlowa();
    while( wezel != NULL )
    {
        wezel->organizm->rysowanie();
        wezel = wezel->nastepny;
    }

    wezel = listaZwierzat->getGlowa();
    while( wezel != NULL )
    {
        wezel->organizm->rysowanie();
        wezel = wezel->nastepny;
    }

    if( this->czlowiek != NULL )
        this->czlowiek->rysowanie();
}


void Swiat::wykonajTure()
{
    Organizm * tmp;
    this->czlowiek->akcja();

    Wezel * wezel = this->listaZwierzat->getGlowa();
    while( wezel != NULL && this->getCzyOK() )
    {
        bool czyKolizja = false;

        tmp = this->czyNastapilaKolizjaZeZwierzeciem(wezel->organizm);
        if( tmp != NULL )
            czyKolizja = true;

        if( wezel->organizm->getCzyAktywny() && !czyKolizja )
            wezel->organizm->akcja();
        else
            wezel->organizm->setCzyAktywny(true);

        if( czyKolizja )
        {
            Organizm * temp = wezel->organizm;
            wezel = wezel->nastepny;
            tmp->kolizja( temp );
        }
        else
            wezel = wezel->nastepny;
    }

    wezel = listaRoslin->getGlowa();
    while( wezel != NULL && this->getCzyOK() )
    {
        bool czyKolizja = false;

        tmp = this->czyNastapilaKolizjaZeZwierzeciem(wezel->organizm);
        if( tmp != NULL )
            czyKolizja = true;

        if( wezel->organizm->getCzyAktywny() && !czyKolizja )
            wezel->organizm->akcja();
        else
            wezel->organizm->setCzyAktywny(true);

        if( czyKolizja )
        {
            Organizm * temp = wezel->organizm;
            wezel = wezel->nastepny;
            tmp->kolizja( temp );
        }
        else
            wezel = wezel->nastepny;
    }

    if( this->getCzyOK() )
    {
        if( this->listaZwierzat->getJakDuzoElementow() <= 0 )
            this->wygrana();
        else
        {
            this->resetujSwiat();
            this->umiescOrganizmy();
        }
    }
    else
        this->koniecGry();
}


void Swiat::resetujSwiat()
{
    for( int i=0; i<wymiarY+2; i++ )
    {
        for( int j=0; j<wymiarX+2; j++ )
        {
            if( i == 0 || i == wymiarY+1 )
                swiat[i][j] = '#';
            else
            {
                if( j == 0 || j == wymiarX+1 )
                    swiat[i][j] = '#';
                else
                    swiat[i][j] = ' ';
            }
        }
    }
}

void Swiat::rozpocznijNowaGre( const int &ileZwierzat, const int &ileRoslin, const bool &czyDodacLosowe )
{
    this->resetujSwiat();

    if( czyDodacLosowe )
    {
        this->wyprodukujOrganizmy( ileZwierzat, ileRoslin );
        this->zaludnijSwiat();

        // Sprawdz czy zwierze nie koliduje z jakas roslina
        Wezel * wezel = listaRoslin->getGlowa();
        while( wezel != NULL )
        {
            Organizm * tmp = this->czyNastapilaKolizjaZeZwierzeciem( wezel->organizm );
            if( tmp != NULL )
                wezel->organizm->kolizja( tmp );

            wezel->organizm->akcja();
            wezel = wezel->nastepny;
        }
        this->umiescOrganizmy();
    }
}

void Swiat::narysujOrganizm( const int &wspX, const int &wspY, const char &znak )
{
    swiat[wspY][wspX] = znak;
}

void Swiat::zaludnijSwiat()
{
    int wspX = rand()%this->wymiarX + 1;
    int wspY = rand()%this->wymiarY + 1;

    while( !czyMoznaDodacZwierze(wspX, wspY) )
    {
        wspX = rand()%this->wymiarX + 1;
        wspY = rand()%this->wymiarY + 1;
    }

    Czlowiek * czlowiek = new Czlowiek( *this, wspX, wspY);
    this->czlowiek = czlowiek;
}

void Swiat::aktuwujUmiejetnoscCzlowieka()
{
    this->interfejs->dodajWiadomoscDoWyswietlenia("Proba aktywacji specjalnej umiejetnosci");
    this->czlowiek->sprobujAktywowacUmiejetnosc();

    this->interfejs->odswiez();
}

void Swiat::koniecGry()
{
    this->czyDobry = false;

    this->interfejs->wyczyscEkran();
    this->interfejs->koniecGry();
}

void Swiat::wygrana()
{
    this->czyDobry = false;

    this->interfejs->wyczyscEkran();
    this->interfejs->wygrana();
}


//
//  DODATKOWE MECHANIKI
//
bool Swiat::poruszCzlowiekiem( const int &wKtoraStrone )
{
    return ( this->czlowiek->poruszSie(wKtoraStrone) );
}

void Swiat::wylosujNowaPozycje( int &x, int &y, int skok )
{
    int newX = x;
    int newY = y;
    int strona;

    while( true )
    {
        strona = rand()%2;
        switch( strona )
        {
        case 0: // w gore
            if( newY >= 1 + skok )
                newY = newY - skok;
            break;

        case 1: // w dol
            if( newY <= this->wymiarY - skok )
                newY = newY + skok;
            break;
        }
        if( newY != y ) // czy nastapila zmiana
            break;
    }

    while( true )
    {
        strona = rand()%2;
        switch( strona )
        {
        case 0: // w prawo
            if( newX <= this->wymiarX - skok )
                newX = newX + skok;
            break;

        case 1: // w lewo
            if( newX >= 1 + skok )
                newX = newX - skok;
            break;
        }
        if( newX != x ) // czy nastapila zmiana
            break;
    }

    x = newX;
    y = newY;
}

void Swiat::wylosujNowaPozycje( Organizm * organizm )
{
    int newX = organizm->getWspX();
    int newY = organizm->getWspY();
    this->wylosujNowaPozycje( newX, newY, 1 );

    Organizm * tmp = this->czyNastapilaKolizjaZeZwierzeciem( newX, newY );
    bool czyZmienic = true;
    if( tmp != NULL )
    {
        if( tmp->czyOdbilAtak(organizm) || organizm->getNazwa() == tmp->getNazwa() )
            czyZmienic = false;

        organizm->kolizja( tmp );
    }

    if( czyZmienic == true )
        organizm->przeniesSieNa( newX, newY );
}


//
//  POMOCNICZE
//

void Swiat::wyprodukujOrganizmy( const int &ileZwierzat, const int &ileRoslin )
{
    int wspX = rand()%this->wymiarX + 1;
    int wspY = rand()%this->wymiarY + 1;
    Organizm * nowyOrganizm;

    for( int i=0; i<ileZwierzat; i++ )
    {
        while( !czyMoznaDodacZwierze(wspX, wspY) )
        {
            wspX = rand()%this->wymiarX + 1;
            wspY = rand()%this->wymiarY + 1;
        }

        switch( i%ILOSC_GATUNKOW_ZWIERZAT )
        {
        case 0:
            nowyOrganizm = new Antylopa( *this, wspX, wspY );
            break;
        case 1:
            nowyOrganizm = new Lis( *this, wspX, wspY );
            break;
        case 2:
            nowyOrganizm = new Owca( *this, wspX, wspY );
            break;
        case 3:
            nowyOrganizm = new Wilk( *this, wspX, wspY );
            break;
        case 4:
            nowyOrganizm = new Zolw( *this, wspX, wspY );
            break;
        }

        nowyOrganizm->setCzyAktywny(true);
        this->listaZwierzat->dodajOrganizm( nowyOrganizm );
    }

    wspX = rand()%this->wymiarX + 1;
    wspY = rand()%this->wymiarY + 1;

    for( int i=0; i<ileRoslin; i++ )
    {

        while( !czyMoznaDodacRosline(wspX, wspY) )
        {
            wspX = rand()%this->wymiarX + 1;
            wspY = rand()%this->wymiarY + 1;
        }

        switch( i%ILOSC_GATUNKOW_ROSLIN )
        {
        case 0:
            nowyOrganizm = new BarszczSosnowskiego( *this, wspX, wspY );
            break;
        case 1:
            nowyOrganizm = new Guarana( *this, wspX, wspY );
            break;
        case 2:
            nowyOrganizm = new Mlecz( *this, wspX, wspY );
            break;
        case 3:
            nowyOrganizm = new Trawa( *this, wspX, wspY );
            break;
        case 4:
            nowyOrganizm = new WilczeJagody( *this, wspX, wspY );
            break;
        }

        nowyOrganizm->setCzyAktywny(true);
        this->listaRoslin->dodajOrganizm( nowyOrganizm );
    }
}


bool Swiat::czyMoznaDodacZwierze( const int &wspX, const int &wspY )
{
    Wezel * wezel = this->listaZwierzat->getGlowa();

    while( wezel )
    {
        if( wezel->organizm->getWspX() == wspX && wezel->organizm->getWspY() == wspY )
            return false;

        wezel = wezel->nastepny;
    }

    return true;
}

bool Swiat::czyMoznaDodacRosline( const int &wspX, const int &wspY )
{
    Wezel * wezel = this->listaRoslin->getGlowa();
    while( wezel )
    {
        if( wezel->organizm->getWspX() == wspX && wezel->organizm->getWspY() == wspY )
            return false;

        wezel = wezel->nastepny;
    }

    return true;
}

bool Swiat::getCzyOK()
{
    return this->czyDobry;
}

Interfejs * Swiat::getInterfejs()
{
    return this->interfejs;
}


//
//  DODAWANIE, USUWANIE ORGANIZMOW
//
void Swiat::dodajOrganizm( Organizm * nowyOrganizm )
{
    if( nowyOrganizm->getGatunek() == "roslina" )
        this->listaRoslin->dodajOrganizm( nowyOrganizm );
    else if( nowyOrganizm->getGatunek() == "zwierze" )
        this->listaZwierzat->dodajOrganizm( nowyOrganizm );
    else if( nowyOrganizm->getGatunek() == "czlowiek" )
        this->czlowiek = (Czlowiek *)nowyOrganizm;
}

void Swiat::usunOrganizm( Organizm * organizm )
{
    if( organizm->getGatunek() == "roslina" )
        this->listaRoslin->usunOrganizm(organizm);
    else if( organizm->getGatunek() == "zwierze" )
        this->listaZwierzat->usunOrganizm(organizm);
    else if( organizm->getGatunek() == "czlowiek" )
    {
        this->czlowiek = NULL;
        this->koniecGry();
    }
}



//
//  ZBADAJ KOLIZJE
//
Organizm * Swiat::czyNastapilaKolizjaZRoslina( Organizm * organizm )
{
    Wezel * wezel = this->listaZwierzat->getGlowa();

    while( wezel )
    {
        if( wezel->organizm->getWspX() == organizm->getWspX() && wezel->organizm->getWspY() == organizm->getWspY() && wezel->organizm != organizm )
            return wezel->organizm;

        wezel = wezel->nastepny;
    }

    return NULL;
}

Organizm * Swiat::czyNastapilaKolizjaZeZwierzeciem( const int &x, const int &y )
{
    Wezel * wezel = this->listaZwierzat->getGlowa();

    while( wezel )
    {
        if( wezel->organizm->getWspX() == x && wezel->organizm->getWspY() == y )
            return wezel->organizm;

        wezel = wezel->nastepny;
    }

    if( this->czlowiek != NULL && x == this->czlowiek->getWspX() && y == this->czlowiek->getWspY()  )
        return this->czlowiek;

    return NULL;
}

Organizm * Swiat::czyNastapilaKolizjaZeZwierzeciem( Organizm * organizm )
{
    Wezel * wezel = this->listaZwierzat->getGlowa();

    while( wezel )
    {
        if( wezel->organizm != organizm && wezel->organizm->getWspX() == organizm->getWspX() && wezel->organizm->getWspY() == organizm->getWspY() )
            return wezel->organizm;

        wezel = wezel->nastepny;
    }

    if( this->czlowiek != NULL && organizm != this->czlowiek && organizm->getWspX() == this->czlowiek->getWspX() && organizm->getWspY() == this->czlowiek->getWspY()  )
        return this->czlowiek;

    return NULL;
}



//
//  ZAPIS I ODCZYT Z PLIKU
//
void Swiat::zapiszDoPliku()
{
    std::fstream plik;
    plik.open( PLIK_ZE_STANEM_GRY, std::ios::out );
    if( plik.good() )
    {
        plik << this->wymiarX << " " << this->wymiarY << endl;
        plik << this->listaZwierzat->getJakDuzoElementow() << " " << this->listaRoslin->getJakDuzoElementow() << endl;

        Wezel * wezel = this->listaZwierzat->getGlowa();
        while( wezel )
        {
            plik << wezel->organizm->getNazwa() << " " << wezel->organizm->getInicjatywa() << " " << wezel->organizm->getSila() << " " << wezel->organizm->getWspX() << " " << wezel->organizm->getWspY() << std::endl;
            wezel = wezel->nastepny;
        }

        wezel = this->listaRoslin->getGlowa();
        while( wezel )
        {
            plik << wezel->organizm->getNazwa() << " " << wezel->organizm->getInicjatywa() << " " << wezel->organizm->getSila() << " " << wezel->organizm->getWspX() << " " << wezel->organizm->getWspY() << std::endl;
            wezel = wezel->nastepny;
        }

        plik << this->czlowiek->getNazwa() << " " << this->czlowiek->getInicjatywa() << " " << this->czlowiek->getSila() << " " << this->czlowiek->getWspX() << " " << this->czlowiek->getWspY() << std::endl;

        this->interfejs->dodajWiadomoscDoWyswietlenia("Zapisano stan gry");
        this->interfejs->odswiez();
        plik.close();
    }
    else
        this->interfejs->dodajWiadomoscDoWyswietlenia("Nie udalo sie zapisac gry");
}

Swiat Swiat::wczytajZPliku()
{
    std::string nazwa;
    int sila;
    int inicjatywa;
    int wspX;
    int wspY;
    Organizm * nowyOrganizm;
    int wymiarX, wymiarY, ileZwierzat, ileRoslin;

    std::fstream plik;
    plik.open( PLIK_ZE_STANEM_GRY, std::ios::in );
    if( plik.good() )
    {
        plik >> wymiarX >> wymiarY >> ileZwierzat >> ileRoslin;
        Swiat nowySwiat( wymiarX, wymiarY );
        nowySwiat.rozpocznijNowaGre( ileZwierzat, ileRoslin, false );

        while( !plik.eof() )
        {
            plik >> nazwa >> sila >> inicjatywa >> wspX >> wspY;
            if( nazwa == "antylopa" )
                nowyOrganizm = new Antylopa( *this, sila, inicjatywa, wspX, wspY );
            else if( nazwa == "lis" )
                nowyOrganizm = new Lis( *this, wspX, wspY );
            else if( nazwa == "owca" )
                nowyOrganizm = new Owca( *this, wspX, wspY );
            else if( nazwa == "wilk" )
                nowyOrganizm = new Wilk( *this, wspX, wspY );
            else if( nazwa == "zolw" )
                nowyOrganizm = new Zolw( *this, wspX, wspY );
            else if( nazwa == "barszczsosnowskiego" )
                nowyOrganizm = new BarszczSosnowskiego( *this, wspX, wspY );
            else if( nazwa == "guarana" )
                nowyOrganizm = new Guarana( *this, wspX, wspY );
            else if( nazwa == "mlecz" )
                nowyOrganizm = new Mlecz( *this, wspX, wspY );
            else if( nazwa == "trawa" )
                nowyOrganizm = new Trawa( *this, wspX, wspY );
            else if( nazwa == "wilczejagody" )
                nowyOrganizm = new WilczeJagody( *this, wspX, wspY );
            else if( nazwa == "czlowiek" )
                nowyOrganizm = new Czlowiek( *this, sila, inicjatywa, wspX, wspY );

            nowySwiat.dodajOrganizm( nowyOrganizm );
        }


        nowySwiat.interfejs->dodajWiadomoscDoWyswietlenia("Wczytano ostatnio zapisany stan gry");
        plik.close();

        return nowySwiat;
    }
    else
        this->interfejs->dodajWiadomoscDoWyswietlenia("Nie udalo sie wczytac stanu gry");
}


int Swiat::getWymiarX()
{
    return this->wymiarX;
}

int Swiat::getWymiarY()
{
    return this->wymiarY;
}
