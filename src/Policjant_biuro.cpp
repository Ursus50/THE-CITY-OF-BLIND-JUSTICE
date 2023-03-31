#include <Policjant_biuro.h>
#include <fstream>


using namespace std;

void Policjant_biuro::raport(Wiezien *wiez)
{

    ofstream plik("raport.txt", ios::app);//otwarcie pliku w trybie dopisywania

    plik << "Imie: "<<wiez->imie;
    plik << " Nazwisko: "<<wiez->nazwisko;
    plik << " Dzialanie: eskorta\n";
    plik.close();
}




Policjant_biuro::Policjant_biuro() :  Policjant()
{
    typ_postaci = typ_policjant_biuro;
}

Policjant_biuro::~Policjant_biuro()
{
    //dtor
}
