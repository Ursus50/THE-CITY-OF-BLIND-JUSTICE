#ifndef INFRASTRUKTURA_H
#define INFRASTRUKTURA_H
#include <iostream>
#include <windows.h>

using namespace std;

template <typename T> class infrastruktura      //klasa generyczna umozliwiajaca utworzenie danego obiektu budowlanego
{
    private:
    T n_infrastruktura;
    public:
        infrastruktura(T n_infrastruktura)
        {
            this->n_infrastruktura=n_infrastruktura;
        }
        void rozbudowa()                        //umozliwienie nadawania wlasciwosci budynkom
        {
            n_infrastruktura->ustawienia_budynku();
            Sleep(1000);
            system("cls");
        }
        ~infrastruktura(){};

    protected:


};

#endif // INFRASTRUKTURA_H
