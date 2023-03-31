#include "Patrol.h"
#include <iostream>
#include <Komisariat.h>
#include "Pies_policyjny.h"
using namespace std;
Pies_policyjny * dodaj_zwierze_pol();

void Patrol::obchod()
{
    cout<<"Zostal przeprowadzony patrol\n"<<endl;
}

void Patrol::patrol_info()
{
    cout<< "Nazwisko policjanta: " << Policjant_akcja::imie << "\n" <<"Imie psa: "<< Pies_policyjny::imie << endl;

}



Patrol::Patrol(Komisariat *kom) : Policjant_akcja(), Pies_policyjny()
{
 Policjant_akcja *pol;
 Pies_policyjny * pies;

    pol = (Policjant_akcja*)kom->dodaj_osobe();
    this->zarobek = pol->zarobek;
    this->zadowolenie= pol->zadowolenie;
    this->liczba_akcji= pol->liczba_akcji;
    this->Policjant::imie = pol->imie;
    this->nazwisko = pol->nazwisko;

    pies = dodaj_zwierze_pol();
    this->Pies::imie = pies->imie;
    this->kolor = pies->kolor;
    this->rasa = pies->rasa;
    this->typ = pies->typ;
}

Patrol::~Patrol()
{
    //dtor
}


