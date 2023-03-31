#include "Pies_policyjny.h"
#include <iostream>
#include <conio.h>
using namespace std;


void Pies_policyjny::dodaj()
{
    int wybor;
    dodaj_zwierze();

    cout<<"Do czego szkolony?\n1. Obronny.\n2. Tropiciel"<<endl;
    wybor=getch();     //pobranie wyboru uzytkownika
    switch(wybor)
    {
    case '1':
        {
            typ="obronny";
        break;
        }
    case '2':
        {
            typ="Tropiciel";
        break;
        }
    }
}

Pies_policyjny::Pies_policyjny(): Pies()
{
    typ="Nieznane";
}

Pies_policyjny::~Pies_policyjny()
{
    //dtor
}
