#ifndef SAD_H
#define SAD_H
#include <iostream>
#include <Budynek.h>
#include <vector>
#include<Sedzia.h>

class Sedzia;
class Sad : public Budynek
{
    friend void remont_sad(Sad *b_sad);
    public:

        int sale_rozpraw;
        int liczba_spraw;
        int liczba_osob();
        vector<Sedzia*>spis_sedziow;        //wektor ze wskaznikami na obiekty sedziow

        virtual void ustawienia_budynku();             //zapisanie ustawien sadu
        virtual void *dodaj_osobe();//dodawanie wskaznika na sedziego do wektora spis_sedziow
        void info_budynek();          //wypisanie ustawien sadu
        Sedzia *wez_osobe(int indeks);

        Sad(int sale_rozpraw=1, int liczba_spraw=0,int liczba_sedziow=0);   //ustawienie wartosci poczatkowych dla sadu
        virtual ~Sad();

};

#endif // SAD_H
