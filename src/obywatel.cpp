#include "Obywatel.h"
#include <iostream>
#include <postac.h>
#include <vector>
using namespace std;


Obywatel& Obywatel::operator=(const Obywatel &ob)
{
    this->danie=ob.danie;
    this->imie=ob.imie;
    this->imie_m=ob.imie_m;
    this->imie_o=ob.imie_o;
    this->nazwisko=ob.nazwisko;
    this->wiek=ob.wiek;
    this->zadowolenie=ob.zadowolenie;

    return *this;
}

bool Obywatel::operator==(const Obywatel &ob)
{
	return this->danie==ob.danie && this->imie==ob.imie && this->zadowolenie==ob.zadowolenie;
	//return this->==q.a && this->b==q.b && this->c==q.c;
}

void Obywatel::operator!()
{
  this->nazwisko = "N";
  this->imie = "N";
  this->zadowolenie = 0,0;
}


void Obywatel::info_osoba()      //metoda wypisujaca informacje o obywatelu
{
    Postac::odczyt_osoba();         //wywolanie metody dzidziczonej po postaci
    cout<<"Zadowolenie: "<<zadowolenie;     //wypisanie zadowolenia
    if(typ_postaci==typ_obywatel) cout<<"\nPrzykladny obywatel"<<endl;  //sprawdzenie typu postaci
    else  cout<<" Podejrzany"<<endl;

}

void Obywatel::ustawienie_obywatel()
{
    ustawienie_osoba();     //metoda umo¿liwiajaca zapisac dane osobowe obywatela
}

Obywatel::Obywatel(float zadowolenie, bool status)
{
    this->zadowolenie=0.8;          //nadanie wartosci poczatkowych obiektowi
    typ_postaci = typ_obywatel;     //przypisanie typu postaci
}

Obywatel::~Obywatel()
{
    //dtor
 //   cout << "obywatel del" << endl;
}
