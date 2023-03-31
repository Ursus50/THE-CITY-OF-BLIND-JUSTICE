#include "Sad.h"
#include <iostream>
#include <Budynek.h>
#include <conio.h>
using namespace std;

void Sad::ustawienia_budynku()             //wybranie oraz zapisanie ustawien sadu
{
    cout<<"Tworzenie sadu:"<<endl;
    //Budynek::ustawienia_budynku();
    cout<<"\nJaki stan budynku?\n";
    cout<<"1.Dobry\n2.Zly\n";
    cout<<"Wybor: ";

    char wybor = getche();      //pobranie wyboru od uzytkownika
    switch(wybor)
    {
    case '1':
        stan="Dobry";
        break;
    case '2':
        stan="Zly";
    break;
    }
    cout<<"\nIlu uzytkowikow?\n";   //zapisanie liczby uzytkownkow
    cin>>liczba_uzytkownikow;
    cout<<"Podaj ilosc sal rozprawowych: ";
    cin>>sale_rozpraw;
    cout<<"\nPodaj liczbe spraw jaka trzeba rozpatrzec: "<<endl;
    cin>>liczba_spraw;
}

void Sad::info_budynek()          //wypisanie ustawien sadu
{
    cout<<"\nSad:"<<endl;
    liczba_uzytkownikow=liczba_uzytkownikow+liczba_osob();
    Budynek::wypisanie_ust_budynku();
    cout<<"Liczba spraw: "<<liczba_spraw;
    cout<<" Liczba sal sadu: "<<sale_rozpraw<<endl;
}

void *Sad::dodaj_osobe()    //dodawanie nowego sedziego
{
    Sedzia *se = new Sedzia();             //utworzenie nowego sedziego
    se->ustawienie_osoba();                //mozliwosc ustawienia sedziemu jego personaliów
    spis_sedziow.push_back(se);        //dodanie wskazika na nowego sedziego na koniec wektora spis_sedziow
    cout<<"\nSedzia dodany"<<endl;
    return NULL;
}

int Sad::liczba_osob()
{
    return spis_sedziow.size();         //obliczanie liczby sedziow
}
Sedzia * Sad::wez_osobe(int indeks)
{
    return spis_sedziow[indeks];        //zrocenie sedziego o podanym indeksie w wektorze
}

Sad::Sad(int sale_rozpraw, int liczba_spraw,int liczba_sedziow)
{
    this->sale_rozpraw=sale_rozpraw;        //ustawienie wartosci poczatkowych
    this->liczba_spraw=liczba_spraw;
//    this->liczba_sedziow=liczba_sedziow;
    typ_budynku=typ_sad;
}

Sad::~Sad()
{
    Sedzia *se;
    while(!spis_sedziow.empty())      //petla sprawdzajaca czy wektor nie jest pusty
    {
        se = (Sedzia *)spis_sedziow[spis_sedziow.size()-1];  //usuwanie kolejnych sedziow z wektora
        delete se;                     //znisczenie obiektu wskazywanego przez wskazink
        spis_sedziow.pop_back();
    }
    cout<<"Sad zniszczony i nie moze wydawac wyrokow"<<endl;
}
