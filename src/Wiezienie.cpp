#include "Wiezienie.h"
#include <iostream>
#include <Budynek.h>
#include <Wiezien.h>
using namespace std;

void Wiezienie::info_budynek()      //wypisanie atrybutow wiezienia
{
    cout<<"\nWiezienie:"<<endl;
    liczba_uzytkownikow=liczba_uzytkownikow+liczba_osob();
    wypisanie_ust_budynku();
    cout<<"Aktualna liczba wiezniow: "<<liczba_osob()<<"."<<endl;
}

Wiezien *Wiezienie::wez_osobe(int indeks)
{
    return spis_wiezniow[indeks];       //zwrocenie wieznia o zadanym indeksie
}


void Wiezienie::osadz_wieznia(Wiezien *wiezien)
{
    spis_wiezniow.push_back(wiezien);   //umiesczenie wskaznika na otrzymanego wieznia na koncu listy wiezniow
}

int Wiezienie::liczba_osob()
{
    return spis_wiezniow.size();        //obliczenie liczby wiezniow
}

Wiezienie::~Wiezienie()
{
   while(!spis_wiezniow.empty())        //usuwanie wiezniow z wektora spis_wiezniow dopoki wektor nie bedzie pusty
    {
        Wiezien *b_wiez = (Wiezien *)spis_wiezniow[spis_wiezniow.size()-1];
        spis_wiezniow.pop_back();       //usuniecie wskaznika wieznia z wektora
        delete b_wiez;                  //znisczenie obiektu wiezien
    }
    cout<< "Wiezienie zniszczone, wiezniowie uciekli"<<endl;
}

Wiezienie::Wiezienie()
{
    typ_budynku=typ_wiezienie;      //nadanie typu budynku
}
