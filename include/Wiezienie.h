#ifndef WIEZIENIE_H
#define WIEZIENIE_H
#include <iostream>
#include <vector>
#include <Budynek.h>
#include <Wiezien.h>

using namespace std;
class Wiezien;
class Wiezienie: public Budynek
{
    friend void remont_wiez(Wiezienie *b_wiez);
    private:
    vector<Wiezien *>spis_wiezniow;     //wektor zawierajacy wskazniki na wizniow
    public:

        void info_budynek();            //wypisanie atrybutow wiezienia
        void osadz_wieznia(Wiezien *wizezien);  //zakwaterowanie wieznia
        int liczba_osob();                  //obliczanie liczby wizniow
        void *dodaj_osobe(){return NULL;};

        Wiezien *wez_osobe(int indeks);
        Wiezienie();
        virtual ~Wiezienie();

    protected:

    private:
};

#endif // WIEZIENIE_H
