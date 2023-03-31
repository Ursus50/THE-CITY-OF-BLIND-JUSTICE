#include "Sprzatacz.h"
#include <postac.h>
#include <Komisariat.h>
#include <Policjant.h>
#include <Sad.h>
#include <Wiezienie.h>

void Sprzatacz::sprzatanie_kom(Komisariat *b_kom)
{
    for(int i=0; i<b_kom->liczba_osob(); i++)
        {
            cout<<"\n"<<endl;
            b_kom->wez_osobe(i)->zadowolenie+=0.1;
            cout<<"Komisariat posprzatany"<<endl;
        }
    //return l_sprzatniec+1;  //iteracja liczby sprzatniec
}

void Sprzatacz::sprzatanie_sad(Sad *b_sad)
{
    for(int i=0; i<b_sad->liczba_osob(); i++)
        {
            cout<<"\n"<<endl;
            b_sad->wez_osobe(i)->zadowolenie+=0.1;
            cout<<"Sad posprzatany"<<endl;
        }
    //return l_sprzatniec+1;  //iteracja liczby sprzatniec
}

void Sprzatacz::sprzatanie_wiez(Wiezienie *b_wiez)
{
    for(int i=0; i<b_wiez->liczba_osob(); i++)
        {
            cout<<"\n"<<endl;
            b_wiez->wez_osobe(i)->zadowolenie+=0.1;
            cout<<"Wiezienie posprzatane"<<endl;

        }
    //return l_sprzatniec+1;  //iteracja liczby sprzatniec
}

void Sprzatacz::info_osoba()    //wypisanie personaliow sprzatacza
{
    cout<<imie<<" "<<nazwisko<<endl;
    cout<<stanowisko<<endl;
    cout<<"Liczba sprzatan: "<<l_sprzatniec<<endl;
    cout<<"Zarobil do tej pory: "<<zarobek<<endl;
}

void Sprzatacz::ustawienie_osoba()     //zapisanie danych personalnych postaci
{
        cout<<"Podaj imie: "<<endl;
        cin>>imie;
        cout<<"Podaj nazwisko: "<<endl;
        cin>>nazwisko;
}

/*void Sprzatacz::odczyt_osoba()         //wypisanie danych personalnych postaci
{
    cout<<imie<<" "<<nazwisko<<endl;
    cout<<stanowisko<<endl;

}*/
Sprzatacz::Sprzatacz(string imie, string nazwisko, string stanowisko, int l_sprzatniec)
{
    this->imie=imie;                //ustawienie wartosci poczatkowych
    this->nazwisko=nazwisko;
    this->stanowisko=stanowisko;
    this->l_sprzatniec=l_sprzatniec; //nadanie wartosci poczatkowych
    zarobek=0;
}

Sprzatacz::~Sprzatacz()
{
    //dtor
}
