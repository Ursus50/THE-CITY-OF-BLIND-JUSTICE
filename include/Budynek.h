#ifndef BUDYNEK_H
#define BUDYNEK_H
#include <iostream>
#include "Dzielnica.h"
using namespace std;

enum typ_budynku            //utworzenie enumeratywnej listy typow mozliwych budynkow
    {
        typ_sad=1,
        typ_komisariat,
        typ_wiezienie
    };

class Budynek : public Dzielnica
{
    protected:
        int typ_budynku;
        string stan ;
        public:

        string typ;
        int liczba_uzytkownikow ;
        int kondygnacje ;

        //void platnosci();
        virtual void nadaj_burmistrza();
        virtual void *dodaj_osobe() = 0;
        virtual void wypisz_polozenie();
        virtual void ustawienia_budynku();
        virtual void wypisanie_ust_budynku();
         Budynek(string typ="nieznany", string stan="dobry", int liczba_uzytkownicy=0); //nadanie zmiennych startowych
        virtual ~Budynek();


};

#endif // BUDYNEK_H
