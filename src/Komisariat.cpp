//#include <vector>
#include "Komisariat.h"

//#include <Policjant.h>
#include <Policjant_akcja.h>
#include <Policjant_biuro.h>
using namespace std;

//Policjant * Komisariat::dodaj_osobe() //dodawnie policjanta
void * Komisariat::dodaj_osobe() //dodawnie policjanta
{
 Policjant *pol_pol;
    if(liczba_osob()%2==0)
    {
        Policjant_akcja *pol = new Policjant_akcja();
        //Policjant *pol;
        pol->ustawienie_osoba();
        pol->stanowisko="Pracuje w terenie";
        spis_policji.push_back(pol);      //umieszczanie wskaznika na nowego policjanta na koniec wektora spis_policji
        pol_pol = pol;
    }
    else
    {
        Policjant_biuro *pol = new Policjant_biuro();
        //Policjant *pol;
        pol->ustawienie_osoba();
        pol->stanowisko="Pracuje w biurze";
        spis_policji.push_back(pol);      //umieszczanie wskaznika na nowego policjanta na koniec wektora spis_policji
        pol_pol = pol;
    }

    cout<<"\nPolicjant dodany"<<endl;
    return pol_pol;
}

void Komisariat::info_budynek()
{
    cout<<"Komisariat:"<<endl;
    liczba_uzytkownikow=liczba_uzytkownikow+liczba_osob();
    Budynek::wypisanie_ust_budynku();

}

Policjant *Komisariat::wez_osobe(int indeks)
{
 return spis_policji[indeks];       //zwrot wskaznika na policjanata o zadanym indeksie
}

int Komisariat::liczba_osob()
{
    return spis_policji.size();     //obliczanie liczby policjantow
}

Komisariat::Komisariat() : Budynek()
{
}

Komisariat::~Komisariat()
{
    Policjant *pol;
    while(!spis_policji.empty())      //petla sprawdzajaca czy wektor nie jest pusty
    {
        pol = (Policjant *)spis_policji[spis_policji.size()-1];  //usuwanie kolejnych policjantow z wektora
        delete pol;                     //znisczenie obiektu wskazywanego przez wskazink
        spis_policji.pop_back();
    }
    cout<<"Komisariat zniszczony!"<<endl;
}
