#include "Ministerstwo.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


void Ministerstwo::dodaj_wyrok()  //zdziebko nie dziala
{

    FILE* plik=fopen("wyroki.txt","rt");
    if(NULL==plik)          //funcka sprawdzajaca istnienie danego pliu
    {
        cout<< "brak pliku " <<"wyroki.txt" <<endl;
        return;
    }
    char pom[30];
    string pom1;
    //while(fscanf(plik,"%s\n",pom)!=EOF)    //czytanie i zapisywanie danych obywateli z pliku az siê ten plik nie skonczy
    while(fgets(pom,30,plik)!=NULL)    //czytanie i zapisywanie danych obywateli z pliku az siê ten plik nie skonczy
    {
        pom1 = pom;
        wyroki.push_back(pom1);
    }
    fclose(plik);                           //zamkniecie pliku
    cout<<"dodano "<<wyroki.size()<< " mozliwych wyrokow\n"<<endl;   //wypisanie ilu dodano obywateli
}






Ministerstwo::Ministerstwo()
{
    //ctor
}

Ministerstwo::~Ministerstwo()
{
    //dtor
}
