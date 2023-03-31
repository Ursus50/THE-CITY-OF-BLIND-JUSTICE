#include "Sedzia.h"
#include <postac.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;


bool Sedzia::operator<(Sedzia const &se)
{
   return this->liczba_spraw <= se.liczba_spraw;
}


void Sedzia::info_osoba()      //wypisanie danych osobowych sedziego
{
    Postac::odczyt_osoba();
    cout<<"Zadowolenie: "<<zadowolenie<<endl;
    cout<<"Liczba przeprowadzonych spraw: "<<liczba_spraw<<endl;
    cout<<"Zarobil do tej pory: "<<zarobek<<endl;
}

bool Sedzia::wyrok(Obywatel* obywatel,Wiezien **wiezien)    //metoda wydajaca orzeczenie w sprawie winy wylosowanego obywatela
{
    system("cls");
    cout<<"Osoba:"<<endl;
    obywatel->info_osoba();      //wypisanie danych wylosowanego obywatela

    bool pom=rand()%2;              //losowanie czy obywatel jest winny czy nie (50/50)
    if (pom==0)
    {
        cout<<"Ta osoba jest niewinna\n"<<endl;     //komunikat w przypadku gdy osoba jest niewinna
        obywatel->zadowolenie=obywatel->zadowolenie+0.1;
    }
    else
    {
        cout<<"\nTa osoba jest winna\n"<<endl;                  //komunikat w przypadku gdy osoba jest winna
        (*wiezien) = new Wiezien("Przestepstwo podatkowe",150); //utworzenie nowego obiektu - wiezien
        (*wiezien)->imie=obywatel->imie;                        //przepisanie danych osobowych obywatela do obiektu wiezien
        (*wiezien)->nazwisko=obywatel->nazwisko;
        (*wiezien)->stanowisko=obywatel->stanowisko;
        (*wiezien)->info_osoba();
        //delete obywatel;        //zniszczenie obywatela

    }
    ++liczba_spraw;             //iteracja liczby przeprowadzonych spraw
    return pom;                 //zrocenie informacji czy wylosowany obywatel zostal uznany z winnego (1-winny, 0-niewinny)
}

Sedzia::Sedzia()
{
    typ_postaci = typ_sedzia;   //ustawienie wartosci poczatkowych
    liczba_spraw = 0;
    zadowolenie=0.8;
    zarobek=0;
}

Sedzia::~Sedzia()
{
    cout<<"\nSedzia zwolniony."<<endl;  //wypisanie omunikatu w przypadku znisczenia obiektu sedzia
}
