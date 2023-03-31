#ifndef WIEZIEN_H
#define WIEZIEN_H
#include <iostream>
#include <postac.h>
#include <Wiezienie.h>
using namespace std;

class Wiezienie;

class Wiezien : public Postac
{
        friend class Sprzatacz;
        friend void widzenie(Wiezienie *b_wiez);
        private:
        string wyrok;
        int odsiadka;
        float zadowolenie;

        public:

        void info_osoba();  //wypisanie danych wieznia
        Wiezien(string, int);
        ~Wiezien();
    };

#endif // WIEZIEN_H
