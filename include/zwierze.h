#ifndef ZWIERZE_H
#define ZWIERZE_H
#include <Istota.h>

class zwierze : public  Istota
{
    public:

        int liczba_nog;
        string kolor;
        zwierze(string imie);
        virtual ~zwierze();
        virtual void odglos() = 0;
        virtual void info() = 0;
        virtual void dodaj_zwierze()= 0;

        virtual int podaj_wiek();
        virtual string podaj_ojca();
        virtual string podaj_matke();
        virtual string ulubione_danie();

    protected:

    private:
};

#endif // ZWIERZE_H
