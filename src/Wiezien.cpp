#include "Wiezien.h"
#include "postac.h"
#include <iostream>

using namespace std;


void Wiezien::info_osoba()      //wypisanie danych wieznia
{
    odczyt_osoba();
    cout<<"Wyrok: "<<wyrok<<". Odsiadka: "<<odsiadka<<" dni"<<endl;
    cout<<"Zadowolenie: "<<zadowolenie<<endl;
}

Wiezien::Wiezien(string wyrok, int odsiadka) : Postac()
{
    typ_postaci = typ_wiezien;      //przypisanie danych poczatkowych;
    this->wyrok=wyrok;
    this->odsiadka=odsiadka;
    zadowolenie=0.5;
}

Wiezien::~Wiezien()
{
    //dtor
}
