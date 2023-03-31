#ifndef LOSOWANIE_H
#define LOSOWANIE_H

#include <stdlib.h>

template<typename T> class losowanie        //klasa generyczna oblugujaca losowanie danych postaci
{
private:
    T losujacy;
    public:
        losowanie(T losujacy)
        {
            this->losujacy = losujacy;
        }
        ~losowanie(){};
        int losuj()                         //losowanie osob
        {
            int pom = losujacy->liczba_osob();                //inicjalizacja zmiennej pomocniczej
            if(pom>0) pom = rand()%losujacy->liczba_osob();   //zabezpieczenie przed dzieleniem przez zerp
                 else pom = 0;
            return pom;     //zwrocenie wylosowanej wartosci (indeksu)
        }


    protected:

    private:
};

#endif // LOSOWANIE_H
