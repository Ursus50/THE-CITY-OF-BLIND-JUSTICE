#ifndef KOMISARIAT_H
#define KOMISARIAT_H
#include <Budynek.h>
#include <vector>
#include <Policjant.h>
//#include "Policjant_akcja.h"
//#include "Policjant_biuro.h"
//class Policjant;
#include<Patrol.h>

class Komisariat : public Budynek
{
    friend void remont_kom(Komisariat *b_kom);
    friend class Patrol;
    private:

        vector<class Policjant*>spis_policji;     //wektor przchowujacy wskaziki na wszystkich policjantow
    public:
        int liczba_osob();
        //Policjant * dodaj_osobe();    //dodawnie nowego policjanta
        void *dodaj_osobe();    //dodawnie nowego policjanta

        void info_budynek();
        Policjant *wez_osobe(int indeks);          //zwracanie wskaznika na policjanta o podanym indeksie

        Komisariat();
        virtual ~Komisariat();

    protected:


};

#endif // KOMISARIAT_H
