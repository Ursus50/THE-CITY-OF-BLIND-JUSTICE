#ifndef PIES_H
#define PIES_H
#include "zwierze.h"

class Pies : public zwierze
{
    public:

        virtual void dodaj_zwierze();
        virtual void info();
        virtual void odglos();
        string rasa;
        Pies(string imie, string kolor, string rasa, int liczba_nog);
        Pies();
        ~Pies();

    protected:

    private:
};

#endif // PIES_H
