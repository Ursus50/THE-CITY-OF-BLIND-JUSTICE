#ifndef INFORMACJA_BUDOWLANA_H
#define INFORMACJA_BUDOWLANA_H
#include <iostream>
#include <windows.h>
using namespace std;
template <typename T> class informacja_budowlana        //klasa generyczna obslugujaca wypisywanie informacji o danym obiekcie budowalnym
{
    private:
    T budowla;

    public:
        informacja_budowlana(T budowla)
        {
            this->budowla=budowla;
        }

        void tabliczka_budynku()        //wypisywanie informacji o poszczegolnych budynku
        {
            budowla->info_budynek();
        }

        ~informacja_budowlana(){};

    protected:


};

#endif // INFORMACJA_BUDOWLANA_H
