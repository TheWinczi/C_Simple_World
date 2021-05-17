#include "ListaOrganizmow.h"
#include <iostream>

using namespace std;

ListaOrganizmow::ListaOrganizmow()
    : glowa(NULL), ogon(NULL), jakDuzoElementow(0) {};

Wezel::Wezel()
    : organizm(NULL), nastepny(NULL), poprzedni(NULL) {};


//
//  GETTERY
//
Wezel * ListaOrganizmow::getGlowa()
{
    return this->glowa;
}

Wezel * ListaOrganizmow::getOgon()
{
    return this->ogon;
}

int ListaOrganizmow::getJakDuzoElementow()
{
    return this->jakDuzoElementow;
}


//
//  DODAWANIE
//
void ListaOrganizmow::dodajOrganizm( Organizm * organizm )
{
    Wezel * nowyWezel = new Wezel();
    nowyWezel->organizm = organizm;

    if( this->getOgon() == NULL )
    {
        this->glowa = nowyWezel;
        this->ogon = nowyWezel;
    }
    else
    {
        Wezel * wezel = this->glowa;
        while( wezel != NULL )
        {
            if( wezel->organizm->getInicjatywa() < organizm->getInicjatywa() )
                break;

            wezel = wezel->nastepny;
        }

        if( wezel == this->glowa )
            this->dodajJakoPierwszy( nowyWezel );
        else if( wezel == NULL )
            this->dodajJakoOstatni( nowyWezel );
        else if( wezel != this->glowa && wezel != NULL )
            dodajPrzed( nowyWezel, wezel );
    }

    this->jakDuzoElementow++;
}

void ListaOrganizmow::dodajJakoOstatni( Wezel * nowyWezel )
{
    nowyWezel->poprzedni = this->ogon;
    this->ogon->nastepny = nowyWezel;
    this->ogon = nowyWezel;
}

void ListaOrganizmow::dodajJakoPierwszy( Wezel * nowyWezel )
{
    nowyWezel->nastepny = this->ogon;
    this->ogon->poprzedni = nowyWezel;
    this->glowa = nowyWezel;
}

void ListaOrganizmow::dodajPrzed( Wezel * nowyWezel, Wezel * wezel )
{
    nowyWezel->poprzedni = wezel->poprzedni;
    nowyWezel->nastepny = wezel;
    wezel->poprzedni->nastepny = nowyWezel;
    wezel->poprzedni = nowyWezel;
}



//
//  USUWANIE
//
void ListaOrganizmow::usunOrganizm( Organizm * organizm )
{
    Wezel * wezel = this->glowa;

    organizm->getSwiat().getInterfejs()->dodajWiadomoscDoWyswietlenia( "Zginela " + organizm->getNazwa() );
    while( wezel != NULL )
    {
        if( czyTenSam(wezel->organizm, organizm) )
            break;

        wezel = wezel->nastepny;
    }

    if( wezel != NULL )
    {
        if( wezel->poprzedni != NULL )
            wezel->poprzedni->nastepny = wezel->nastepny;
        else
            this->glowa = wezel->nastepny;

        if( wezel->nastepny != NULL )
            wezel->nastepny->poprzedni = wezel->poprzedni;
        else
            this->ogon = wezel->poprzedni;

        this->jakDuzoElementow--;
        delete wezel;
    }
}



//
//  POROWNYWANIE
//
bool ListaOrganizmow::czyTenSam( const Organizm * const pierwszyOrganizm, const Organizm * const drugiOrganizm )
{
    if( pierwszyOrganizm == drugiOrganizm ) // czy ten sam adres zeminnej
        return true;

    return false;
}



//
//  POZOSTALE
//
void ListaOrganizmow::wyswietl()
{
    cout<<"Lista: "<<endl;

    Wezel * wezel = this->glowa;
    while( wezel != NULL )
    {
        cout<<wezel->organizm->getNazwa()<<endl;
        wezel = wezel->nastepny;
    }
}






