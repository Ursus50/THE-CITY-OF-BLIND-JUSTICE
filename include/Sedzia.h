#ifndef SEDZIA_H
#define SEDZIA_H
#include <iostream>
#include <postac.h>
#include <obywatel.h>
#include <wiezien.h>
#include <Sad.h>
#include "Ministerstwo.h"
using namespace std;

class Sad;
class Obywatel;

class Sedzia: public Postac, public Ministerstwo
{
    friend class Sprzatacz;
    friend void swieto_sprawiedliwosci(Sad *b_sad);
    private:
       float zadowolenie;

    public:
       //float zadowolenie;
        int liczba_spraw;
        int zarobek;
        void info_osoba();     //wypisanie danych osobowych sedziego
        bool wyrok(Obywatel *obywatel, Wiezien **wiezien); //metoda wydajaca wyrok na wylosowanego obywatela
        bool operator<(Sedzia const &se);
        Sedzia();
        ~Sedzia();
};

#endif // SEDZIA_H
