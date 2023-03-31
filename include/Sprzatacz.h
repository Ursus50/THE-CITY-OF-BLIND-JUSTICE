#ifndef SPRZATACZ_H
#define SPRZATACZ_H
#include <postac.h>
#include <Komisariat.h>
#include <Sad.h>
#include <Wiezienie.h>

class Sad;
class Sprzatacz
{
    //friend class Postac;
    friend void zwiekszenie_l_sprzatniec(Sprzatacz *sprz);
    friend class Urzednik;
    public:
        string imie;
        string nazwisko;
        string stanowisko;
        int zarobek;

        void ustawienie_osoba();        //zapisanie danych personalnych postaci
        //void odczyt_osoba();
        void sprzatanie_kom(Komisariat *b_kom);
        void sprzatanie_sad(Sad *b_sad);
        void sprzatanie_wiez(Wiezienie *b_wiez);

        void info_osoba();  //wypisanie inforacji o sprzataczu
        Sprzatacz(string imie="Jan", string nazwisko="Kowalski", string stanowisko="brak danych", int l_sprzatniec=0);
        ~Sprzatacz();

    protected:

    private:
        int l_sprzatniec;
};

#endif // SPRZATACZ_H
