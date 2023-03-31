#ifndef URZEDNIK_H
#define URZEDNIK_H
#include <iostream>
#include <string>
#include <stdio.h>
#include <Komisariat.h>
#include <Sad.h>
#include <Wiezienie.h>
#include <Sprzatacz.h>
#include <Dom.h>
using namespace std;

class Urzednik;
void wynagrodzenie_pol(Komisariat *b_kom, Urzednik *urz);

class Urzednik
{
    friend void wynagrodzenie_pol(Komisariat *b_kom, Urzednik *urz);
    friend void wynagrodzenie_sprz(Dom *sprz, Urzednik *urz);
    friend void wynagrodzenie_sed(Sad *b_sad, Urzednik *urz);

    private:
        void wyplata_pol(Policjant *pol);       //metody, ktore wyplacaja postaciom ich wynagrodzenie
        void wyplata_sed(Sedzia *sed);
        void wyplata_sprz(Sprzatacz *sprz);



    public:
        string imie;
        string nazwisko;
        string stanowisko;
        int liczba_wyplat;


        void ustawienie_osoba();
        void info_osoba();  //wypisanie inforacji o urzedniku
        Urzednik();
        ~Urzednik();
};
#endif // URZEDNIK_H
