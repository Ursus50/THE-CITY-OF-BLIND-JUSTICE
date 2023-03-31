#ifndef OBYWATEL_H
#define OBYWATEL_H
#include <iostream>
#include <Postac.h>
#include <vector>
#include <Dom.h>
using namespace std;


class Dom;

class Obywatel: public Postac
{

    friend class Sedzia;
    friend void swieto_narodowe(Dom *b_dom);
    private :
    protected:
        float zadowolenie;

    public:
       //bool status;
        void ustawienie_obywatel();     //zapisywanie danych osobowych obywatela
        void info_osoba();           //wyswietlenie danych osobowych obywatela

        Obywatel(float zadowolenie, bool status);
        virtual ~Obywatel();
        Obywatel& operator=(const Obywatel &ob);
        bool operator==(const Obywatel &ob);
        void operator!();   //czyszczenie danych osobowych
};

#endif // OBYWATEL_H
