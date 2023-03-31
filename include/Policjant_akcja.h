#ifndef POLICJANT_AKCJA_H
#define POLICJANT_AKCJA_H
//#include <iostream>
#include <Policjant.h>
#include <Wiezien.h>
#include <Wiezienie.h>

//using namespace std;

class Policjant_akcja : public Policjant
{
    public:

    void eskorta(Wiezienie *wiezienie, Wiezien *wiez);  //eskorta skazanego obywatela, czyli wieznia z sadu do wiezienia


        Policjant_akcja();
        ~Policjant_akcja();

    //protected:

    //private:
};

#endif // POLICJANT_AKCJA_H
