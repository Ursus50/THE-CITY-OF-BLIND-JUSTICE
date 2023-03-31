#ifndef DOM_H
#define DOM_H
#include <vector>
#include <obywatel.h>
#include <Budynek.h>
#include <Sprzatacz.h>
#include <Dom.h>
#include <przyjazn.h>

class Dom;
class Obywatel;
class Sprzatacz;

void dodaj_sprzatacza2(Dom *b_dom);

class Dom : public Budynek
{

    friend void dodaj_sprzatacza2(Dom *b_dom);
    private:
        vector<Obywatel*>spis_obywateli;        //wektor przetrzymujacy wskazniki na wszystkich obywateli
        vector<Sprzatacz*>spis_sprzataczy;      //wektor przetrzymujacy wskazniki na wszystkich sprzataczy
        void dodaj_sprzatacza(Sprzatacz *sprzatacz);    //dodawanie sprzatacza
        //void dodaj_osobe();   //dodawanie obywatela
    protected:
    public:
        //int liczba_mieszkancow();
        int liczba_osob();
        virtual void *dodaj_osobe();   //dodawanie obywatela
        void usun_obywatela(Obywatel *obywatel);    //usuwanie obywatela
        void dodaj_obywatela(char *nazwa_pliku);    //dodanie obywatela z pliku, aby mozna by³o przeprowadzic szybciej testy
        void dodaj_obywatela(Obywatel *ob);    //dodanie obywatela

        //void dodaj_sprzatacza(Sprzatacz *sprzatacz);    //dodawanie sprzatacza
        int liczba_sprzataczy();
        Obywatel *wez_osobe(int indeks);    //wybieranie obywatela z wektora o podanym indeksie
        Sprzatacz *wez_sprzatacza(int indeks);  //wybieranie obywatela z wektora o podanym indeksie
        Dom();
        virtual ~Dom();

 };

#endif // DOM_H
