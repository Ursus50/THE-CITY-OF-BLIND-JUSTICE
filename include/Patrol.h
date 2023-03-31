#ifndef PATROL_H
#define PATROL_H
#include "Policjant_akcja.h"
#include "Pies_policyjny.h"
#include "Komisariat.h"

class Komisariat;
class Patrol : public Policjant_akcja, public Pies_policyjny
{
    public:

        void obchod();
        void stworz_patrol();
        void patrol_info();
        Patrol(Komisariat *kom);
        ~Patrol();

    protected:

    private:
};

#endif // PATROL_H
