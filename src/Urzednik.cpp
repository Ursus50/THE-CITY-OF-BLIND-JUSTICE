#include "Urzednik.h"
#include <Komisariat.h>
#include <Sad.h>
#include <Wiezienie.h>
#include <iostream>
#include <Sprzatacz.h>
using namespace std;
void Urzednik::wyplata_pol(Policjant *pol)
{
   pol->zarobek+=(2100+pol->liczba_akcji*300);
}

void Urzednik::wyplata_sed(Sedzia *sed)
{
    sed->zarobek+=(3100+sed->liczba_spraw*300);
}

void Urzednik::wyplata_sprz(Sprzatacz *sprz)
{
    sprz->zarobek+=(1800+(sprz->l_sprzatniec)*50);
}

Urzednik::Urzednik()
{
    imie="Jan";
    nazwisko="Kowalski";
    liczba_wyplat=0;
}

Urzednik::~Urzednik()
{
    //dtor
}

