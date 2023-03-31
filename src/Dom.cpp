#include "Dom.h"
#include <obywatel.h>
#include <vector>
#include <stdio.h>

/*int Dom::liczba_mieszkancow()       //obliczanie liczby mieszkancow/obywateli
{
    return spis_obywateli.size();   //zrocenie ile elementow znajduje sie w wektorze
}*/
int Dom::liczba_osob()              //obliczanie liczby mieszkancow/obywateli
{
    return spis_obywateli.size();   //zrocenie ile elementow znajduje sie w wektorze
}

void *Dom::dodaj_osobe()                   //dodawanie obywatela
{
    Obywatel *ob = new Obywatel(0.8,0);    //utworzenie nowej osoby
    ob->ustawienie_osoba();                //mozliwosc ustawienia osobie jego personaliów
    spis_obywateli.push_back(ob);          //umieszczanie wskaznika na obywatela na ostatnia pozycje w wektorze
    cout<<"\nObywatel dodany"<<endl;
    return NULL;
}

/*void Dom::dodaj_obywatela(Obywatel *obywatel)   //dodawanie obywatela
{
    spis_obywateli.push_back(obywatel);         //umieszczanie wskaznika na obywatela na ostatnia pozycje w wektorze
    cout<<"\nObywatel dodany"<<endl;
}*/

void Dom::dodaj_sprzatacza(Sprzatacz *sprzatacz)    //dodawanie sprzatacza
{
    spis_sprzataczy.push_back(sprzatacz);           //umieszczanie wskaznika na sprzatacz na ostatnia pozycje w wektorze
    cout<<"\nSprzatacz dodany"<<endl;
}

void Dom::dodaj_obywatela(Obywatel *ob)        //pobranie 3 obywateli zapisanych w pliku
{
  spis_obywateli.push_back(ob);
}

void Dom::dodaj_obywatela(char *nazwa_pliku)        //pobranie 3 obywateli zapisanych w pliku
{
 char imie[20];         //deklaracja zmiennych
 char nazwisko[20];
 char stanowisko[20];

    FILE* plik=fopen(nazwa_pliku,"r");          //otworzenie pliku w trybie do czytania
    if(NULL==plik)          //funcka sprawdzajaca istnienie danego pliu
    {
        cout<< "brak pliku " <<nazwa_pliku <<endl;
        return;
    }

    while(fscanf(plik,"%s %s %s",imie,nazwisko,stanowisko)!=EOF)    //czytanie i zapisywanie danych obywateli z pliku az siê ten plik nie skonczy
    {
        Obywatel *obl = new Obywatel(0.8,false);
        obl->imie = imie;
        obl->nazwisko = nazwisko;
        obl->stanowisko = stanowisko;
        spis_obywateli.push_back(obl);      //umieszczanie wskaznika na konkretnego obywatela na koncu wektora spis_obywateli
    }
    fclose(plik);                           //zamkniecie pliku
    cout<<"dodano "<<liczba_osob()<< " obywateli\n"<<endl;   //wypisanie ilu dodano obywateli
}


void Dom::usun_obywatela(Obywatel *obywatel)            //usuwanie obywatela z wektora
{
    try
    {
    for (unsigned i=0; i<spis_obywateli.size(); i++)
        if(spis_obywateli[i]==obywatel)                 //znalezienie obywatela o zadanym indeksie
        {
            spis_obywateli.erase(spis_obywateli.begin()+i);
            delete obywatel;        //usuniecie obiektu obywatel
            break;
        }
    }
    catch(...){}
}

Obywatel * Dom::wez_osobe(int indeks)
{
    return spis_obywateli[indeks];      //zwrocenie wskaznika na obywatela o zadanym indeksie
}

int Dom::liczba_sprzataczy()
{
    return spis_sprzataczy.size();      //obliczenie ilczby sprzataczy
}

Sprzatacz * Dom::wez_sprzatacza(int indeks)
{
    return spis_sprzataczy[indeks];     //zwrocenie wskaznika na sprzatcza o zadanym indeksie
}

Dom::~Dom()
{
    Obywatel *obl;
    while(!spis_obywateli.empty())      //petla sprawdzajaca czy wektor nie jest pusty
    {
        obl = (Obywatel *)spis_obywateli[spis_obywateli.size()-1];  //usuwanie kolejnych obywateli z wektora
        delete obl;                     //znisczenie obiektu wskazywanego przez wskazink
        spis_obywateli.pop_back();
    }

    Sprzatacz *sprz;
    while(!spis_sprzataczy.empty())      //petla sprawdzajaca czy wektor nie jest pusty
    {
        sprz = (Sprzatacz *)spis_sprzataczy[spis_sprzataczy.size()-1];  //usuwanie kolejnych sprzataczy z wektora
        delete sprz;                     //znisczenie obiektu wskazywanego przez wskazink
        spis_sprzataczy.pop_back();
    }
    cout<<"Dom zniszczony"<<endl;
}

Dom::Dom()
{
    //dtor
}
