#ifndef KOT_H
#define KOT_H
#include "zwierze.h"

class Kot : public zwierze
{
    public:
        //void dodaj_zwierze();
        virtual void odglos();
        virtual void info();
        virtual void dodaj_zwierze();
        string rasa;
        Kot(string imie, string kolor, string rasa, int liczba_nog);
        Kot();
        ~Kot();

    protected:

    private:
};

#endif // KOT_H
