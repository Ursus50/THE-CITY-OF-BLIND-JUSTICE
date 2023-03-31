#ifndef DANE_OSOBOWE_H
#define DANE_OSOBOWE_H
#include <iostream>
using namespace std;

template <typename T> class Dane_osobowe    //klasa generyczna obslugujaca wypisywanie danych osobowy
{
private:
    T Dane;

public:
    Dane_osobowe(T Dane)
    {
        this->Dane=Dane;
    }

    void wypisz_dane()          //wypisywanie kolejnych osob z poszczegolnych list
    {
        for(int i=0; i<Dane->liczba_osob(); i++)
        {
            cout<<"\n"<<endl;
            Dane->wez_osobe(i)->info_osoba();
        }
    }

    ~Dane_osobowe(){};
};

#endif // DANE_OSOBOWE_H
