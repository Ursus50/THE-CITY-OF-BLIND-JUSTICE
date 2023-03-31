#ifndef PIES_POLICYJNY_H
#define PIES_POLICYJNY_H
#include "Pies.h"

class Pies_policyjny : public Pies
{
    public:
        string typ;
        void dodaj();
        //virtual void info();
        Pies_policyjny();
        ~Pies_policyjny();

    protected:

    private:
};

#endif // PIES_POLICYJNY_H
