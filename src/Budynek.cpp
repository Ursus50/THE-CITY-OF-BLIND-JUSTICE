#include "Budynek.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;


void Budynek::ustawienia_budynku()      //metoda umozliwiajaca ustawienie budynku
{
    cout<<"\nJaki stan budynku?\n";
    cout<<"1.Dobry\n2.Zly\n";
    cout<<"Wybor: ";

    char wybor = getche();      //pobranie wyboru od uzytkownika
    switch(wybor)
    {
    case '1':
        stan="Dobry";
        break;
    case '2':
        stan="Zly";
    break;
    }
    cout<<"\nIlu uzytkowikow?\n";   //zapisanie liczby uzytkownkow
    cin>>liczba_uzytkownikow;
}

void Budynek::wypisanie_ust_budynku()       //wypisanie atrybutow budynku
{
    cout<<"Typ budynku: "<<typ<<". Stan budynku: " <<stan<<". Liczba uzytkownikow: "<<liczba_uzytkownikow;
    cout<<".\n";
    cout<<"Budynek znajduje sie w dzielnicy: "<<polozenie<<endl;
}

void Budynek::nadaj_burmistrza()
{
    cout<<"Podaj Nazwisko burmistrza: ";
    cin>>burmistrz;
}

void Budynek::wypisz_polozenie()
{
    cout<<"\nBudynek znajduje sie w "<<polozenie;
}

Budynek::Budynek(string typ, string stan, int liczba_uzytkownikow)  //konstruktor obiektu budynek
{
    this->typ = typ;        //przypisanie zmiennych to atrybutow budynku
    this->stan = stan;
    this->liczba_uzytkownikow=liczba_uzytkownikow;
}

Budynek::~Budynek()         //komunikat po zniszczeniu budynku
{
   // cout<<"\nBudynek zniszczony"<<endl;
}
