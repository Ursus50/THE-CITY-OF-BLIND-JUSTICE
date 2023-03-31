#ifndef POSTAC_H
#define POSTAC_H
#include <iostream>
#include <Istota.h>
using namespace std;

enum typPostaci         //enumeratywna lista typow postaci
{
    typ_obywatel = 1,
    typ_wiezien,
    typ_sedzia,
    typ_policjant_akcja,
    typ_policjant_biuro
};

class Postac : public Istota
{
    protected:

    public:

        int typ_postaci;
        string nazwisko;
        string stanowisko;

        void ustawienie_osoba();        //zapisanie danych personalnych postaci
        void odczyt_osoba();            //odczyt danych personalnych postaci

        virtual int podaj_wiek();
        virtual string podaj_ojca();
        virtual string podaj_matke();
        virtual string ulubione_danie();


        Postac(string imie="Jan", string nazwisko="Kowalski", string stanowisko="bezrobotny");  //nadanie wartosci poczatkowych postaci
        ~Postac();

};

#endif // POSTAC_H
