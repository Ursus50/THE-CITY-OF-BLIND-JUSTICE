
#include <iostream>
#include <Policjant.h>

using namespace std;


Policjant::Policjant() : Postac()
{
    liczba_akcji=0;
    zadowolenie=0.8;
    zarobek=0;
}

void Policjant::info_osoba()        //wypisanie danych policjanta
{
    Postac::odczyt_osoba();
    cout<<"Zadowolenie: "<<zadowolenie<<endl;
    cout<<"Liczba przeprowadzonych akcji: "<<liczba_akcji<<endl;
    cout<<"Zarobil do tej pory: "<<zarobek<<endl;
}

/*void Policjant::eskorta(Wiezienie *wiezienie, Wiezien *wiezien)     //eskorta wieznia z sadu do wiezienia
{
    if(NULL==wiezien) return;           //sprawdzenie czy zostal utworzony obiekt wiezien
    ++liczba_akcji;                     //iteracja liczby akcji policjanta
    wiezienie->dodaj_osobe(wiezien);  //wywolanie metody wiezienia, przekazanie wieznia wiezieniu
}*/

bool Policjant::operator>(Policjant const &pol)
{
   return this->liczba_akcji >= pol.liczba_akcji;
}


Policjant::~Policjant()
{
    //dtor
}
