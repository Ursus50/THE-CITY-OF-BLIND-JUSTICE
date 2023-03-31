#include "Policjant_akcja.h"


void Policjant_akcja::eskorta(Wiezienie *wiezienie, Wiezien *wiezien)     //eskorta wieznia z sadu do wiezienia
{
    if(NULL==wiezien) return;           //sprawdzenie czy zostal utworzony obiekt wiezien
    ++liczba_akcji;                     //aktualizacuja liczby akcji policjanta
    wiezienie->osadz_wieznia(wiezien);  //wywolanie metody wiezienia, przekazanie wieznia wiezieniu
}


Policjant_akcja::Policjant_akcja() : Policjant()
{
    typ_postaci = typ_policjant_akcja;
}

Policjant_akcja::~Policjant_akcja()
{

    //dtor
}
