#ifndef ISTOTA_H
#define ISTOTA_H
#include <string>
using namespace std;



class Istota
{
    public:
        string imie;
        int wiek;
        string imie_o;
        string imie_m;
        string danie;
        virtual int podaj_wiek()=0;
        virtual string podaj_ojca()=0;
        virtual string podaj_matke()=0;
        virtual string ulubione_danie()=0;

        Istota(string imie);
        virtual ~Istota();

    protected:

    private:
};

#endif // ISTOTA_H
