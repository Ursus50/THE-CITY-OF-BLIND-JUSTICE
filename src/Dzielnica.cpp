#include "Dzielnica.h"

void Dzielnica::zmien_nazwe()
{
    cout<<"Podaj nazwe dzielnicy, w ktorej znajduje sie budynek: ";
    cin>>polozenie;
}

/*void Dzielnica::nadaj_burmistrza()
{
    cout<<"Podaj Nazwisko burmistrza: ";
    cin>>burmistrz;
}*/
/*void Dzielnica::wypisz_polozenie()
{
    cout<<"\nBudynek znajduje sie w "<<polozenie;
}*/

Dzielnica::Dzielnica()
{
    polozenie="Centrum";
}

Dzielnica::~Dzielnica()
{
    //dtor
}
