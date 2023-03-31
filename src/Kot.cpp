#include "Kot.h"

#include <iostream>
using namespace std;

void Kot::dodaj_zwierze()
{
    cout<<"Podaj imie kota: ";
    cin >>imie;
    cout<<"Podaj rase kota: ";
    cin>>rasa;
    cout<<"Podaj umaszczenie kota: ";
    cin>>kolor;
}

void Kot::info()
{
    cout<<"Imie: "<<imie;
    cout<<" Rasa: "<<rasa;
    cout<<" Umaszczenie: "<<kolor;
}

void Kot::odglos()
{
    cout<<"\nmeow meow"<<endl;
}
Kot::Kot() : zwierze("")
{
    liczba_nog=4;
}

Kot::Kot(string imie, string kolor, string rasa, int liczba_nog) : zwierze(imie)
{
    this->imie=imie;
    liczba_nog=4;
}

Kot::~Kot()
{
    //dtor
}
