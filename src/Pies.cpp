#include "Pies.h"
#include <iostream>
using namespace std;

void Pies::dodaj_zwierze()
{
    cout<<"Podaj imie psa: ";
    cin >>imie;
    cout<<"Podaj rase psa: ";
    cin>>rasa;
    cout<<"Podaj umaszczenie psa: ";
    cin>>kolor;
}
void Pies::info()
{
    cout<<"Imie: "<<imie;
    cout<<" Rasa: "<<rasa;
    cout<<" Umaszczenie: "<<kolor;
}


void Pies::odglos()
{
    cout<<"\nHau hau"<<endl;
}

Pies::Pies() : zwierze("")
{
    liczba_nog=4;
}

Pies::Pies(string imie, string kolor, string rasa, int liczba_nog) : zwierze(imie)
{
    this->imie=imie;
    liczba_nog=4;
}

Pies::~Pies()
{
    //dtor
}
