#ifndef DZIELNICA_H
#define DZIELNICA_H
#include <iostream>
using namespace std;

class Dzielnica
{
    public:
        string burmistrz;
        string polozenie;
        virtual void zmien_nazwe();
        virtual void nadaj_burmistrza()= 0 ;
        virtual void wypisz_polozenie()= 0 ;
        Dzielnica();
        virtual ~Dzielnica();

    protected:

    private:
};

#endif // DZIELNICA_H
