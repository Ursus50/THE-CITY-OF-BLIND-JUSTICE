#ifndef POLICJANT_H
#define POLICJANT_H

//#include <iostream>
#include <postac.h>
//#include <Wiezien.h>
//#include <Wiezienie.h>
//#include <Komisariat.h>

//class Komisariat;

class Policjant: public Postac
{
    friend class Sprzatacz;
    friend class Urzednik;
    //friend void swieto_policji(Komisariat *b_kom);
    private:

//protected:
   // float zadowolenie;

    public:
    int zarobek;
    float zadowolenie;
    int liczba_akcji;
    void info_osoba();          //wyswitlenie danych policjanta
    //void eskorta(Wiezienie *wiezienie, Wiezien *wiez);  //eskorta skazanego obywatela, czyli wieznia z sadu do wiezienia
    bool operator>(Policjant const &pol);
    Policjant();
    ~Policjant();

};

#endif // POLICJANT_H
