#ifndef POLICJANT_BIURO_H
#define POLICJANT_BIURO_H
//#include <iostream>
#include <Policjant.h>
#include <Wiezien.h>
class Policjant_biuro: public Policjant
{
    public:

        void raport(Wiezien *wiez); //tworzenie raportu w postaci pliku txts
        Policjant_biuro();
        ~Policjant_biuro();

    protected:

    private:
};

#endif // POLICJANT_BIURO_H
