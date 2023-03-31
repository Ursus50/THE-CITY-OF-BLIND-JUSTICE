#include "Postac.h"
#include <iostream>

using namespace std;


void Postac::ustawienie_osoba()     //zapisanie danych personalnych postaci
{
        cout<<"Podaj imie: "<<endl;
        cin>>imie;
        cout<<"Podaj nazwisko: "<<endl;
        cin>>nazwisko;
        //cout<<"Podaj stanowisko: "<<endl;
        //cin>>stanowisko;
}

void Postac::odczyt_osoba()         //wypisanie danych personalnych postaci
{
    cout<<imie<<" "<<nazwisko<<endl;
    //cout<<stanowisko<<endl;

}

int Postac::podaj_wiek()
{
    cout<<"\nPodaj wiek w miesiach: ";
    cin>>wiek;
    cout<<"\nMa "<<wiek<<" ukoñczonych lat.\n";
    return wiek;
}
string Postac::podaj_ojca()
{
     cout<<"\nPodaj imie ojca: ";
     cin>>imie_o;
     return imie_o;
}

string Postac::podaj_matke()
{
    cout<<"\nPodaj imie matki: ";
    cin>>imie_m;
    return imie_m;
}
string Postac::ulubione_danie()
{
    cout<<"\nPodaj ulubione danie: ";
    cin>>danie;
    return danie;
}



Postac::Postac(string imie, string nazwisko, string stanowisko): Istota(imie)
{
    //this->
    imie=imie;                //ustawienie wartosci poczatkowych
    this->nazwisko=nazwisko;
    this->stanowisko=stanowisko;
}


Postac::~Postac()
{
    //cout<<"\nPostac nie zyje"<<endl;
}
