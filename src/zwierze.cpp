#include "zwierze.h"
#include <iostream>


int zwierze::podaj_wiek()
{
    cout<<"\nPodaj wiek w miesiach: ";
    cin>>wiek;
    int pom = wiek/12;
    cout<<"\nMa "<<pom<<" ukoñczonych lat.\n";
    return wiek;
}
string zwierze::podaj_ojca()
{
     cout<<"\nPodaj imie ojca: ";
     cin>>imie_o;
     return imie_o;
}

string zwierze::podaj_matke()
{
    cout<<"\nPodaj imie matki: ";
    cin>>imie_m;
    return imie_m;
}
string zwierze::ulubione_danie()
{
    cout<<"\nPodaj ulubione danie: ";
    cin>>danie;
    return danie;
}





zwierze::zwierze(string imie):Istota(imie)
{
    this->imie=imie;
}

zwierze::~zwierze()
{
    //dtor
}
