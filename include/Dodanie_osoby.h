#ifndef DODANIE_OSOBY_H
#define DODANIE_OSOBY_H
#include <iostream>
#include <windows.h>
template <typename T> class Dodanie_osoby   //klasa generyczna obslugujaca dodawanie osob do poszczegolnych vectorow
{
    private:
        T dodanie;
    public:
        Dodanie_osoby(T dodanie)
        {
            this->dodanie=dodanie;
        }

        void dodaj_osobe()                  //dodawanie osob do list
        {
            dodanie->dodaj_osobe();
            Sleep(1000);                            //odczekanie 1 sekundy
            system("cls");
        }

        ~Dodanie_osoby(){};
};

#endif // DODANIE_OSOBY_H
