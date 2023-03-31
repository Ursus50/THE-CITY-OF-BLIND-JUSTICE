 /*********************************
 * Michal Wójtowicz               *
 *********************************/
#include <iostream>
#include <Budynek.h>
#include <postac.h>
#include <Sad.h>
#include <obywatel.h>
#include <Sedzia.h>
#include <Wiezien.h>
#include <Wiezienie.h>
#include <Policjant.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <Komisariat.h>
#include <Dom.h>
#include <Sprzatacz.h>
#include <losowanie.h>
#include <Dane_osobowe.h>
#include <Dodanie_osoby.h>
#include <infrastruktura.h>
#include <informacja_budowlana.h>
#include <Urzednik.h>
#include <Istota.h>
#include <Policjant_akcja.h>
#include <Policjant_biuro.h>
#include "Pies.h"
#include "Kot.h"
#include "Pies_policyjny.h"
#include "Patrol.h"
using namespace std;

    vector<class Pies*>psy;
    vector<class Kot*>koty;
    vector<class Pies_policyjny*> psy_pol;

void dodaj_sprzatacza2(Dom *b_dom)          //funckja dodajaca nowego sprzatacza do listy znajdujacej sie w domu
{
    Sprzatacz *sp1 = new Sprzatacz();       //utworzenie nowego sprzatacza
    sp1->ustawienie_osoba();                //mozliwosc ustawienia sprzataczowi jego personaliów
    b_dom->dodaj_sprzatacza(sp1);           //dodanie do listy wskaznikow sprzatacza wskaznika na nowego sprzatacza
    Sleep(1000);
    system("cls");
}
void zwiekszenie_l_sprzatniec(Sprzatacz *sprz)          //funckja zliczajaca ilosc sprzatniec danego sprzatacza
{
    sprz->l_sprzatniec+=1;
}

void wynagrodzenie_pol(Komisariat *b_kom, Urzednik *urz)    //zaplata policjantom za wykonana prace
{
    int limit=0;
    limit = b_kom->liczba_osob();
    while(limit>0)
    {
        urz->wyplata_pol(b_kom->wez_osobe(limit-1));
        --limit;
    }
}

void wynagrodzenie_sprz(Dom *b_dom, Urzednik *urz)      //zaplata sprzaataczom za wykonana prace
{
    int limit=0;
    limit = b_dom->liczba_sprzataczy();
    while(limit>0)
    {
        urz->wyplata_sprz(b_dom->wez_sprzatacza(limit-1));
        --limit;
    }
}

void wynagrodzenie_sed(Sad *b_sad, Urzednik *urz)       //zaplata sedziom za wykonana prace
{
    int limit=0;
    limit = b_sad->liczba_osob();
    while(limit>0)
    {
        urz->wyplata_sed(b_sad->wez_osobe(limit-1));
        --limit;
    }
}
void swieto_policji(Komisariat *b_kom)      //funckja poprawiajaca zadowolenie policjantow znajdujacych sie na komisariacie
{
    int limit=0;
    limit = b_kom->liczba_osob();
    while(limit>0)
    {
        b_kom->wez_osobe(limit-1)->zadowolenie+=0.2;
        --limit;
    }
}

void swieto_sprawiedliwosci(Sad *b_sad)     //funckja poprawiajaca zadowolenie sedziow znajdujacych sie w sadzie
{
    int limit=0;
    limit = b_sad->liczba_osob();
    while(limit>0)
    {
        b_sad->wez_osobe(limit-1)->zadowolenie+=0.1;
        --limit;
    }
}

void swieto_narodowe(Dom *b_dom)            //funckja poprawiajaca zadowolenie obywateli znajdujacych sie w domu
{
    int limit=0;
    limit = b_dom->liczba_osob();
    while(limit>0)
    {
        b_dom->wez_osobe(limit-1)->zadowolenie+=0.1;
        --limit;
    }
}

void widzenie(Wiezienie *b_wiez)            //funckja poprawiajaca zadowolenie wiezniow
{
    if(b_wiez->liczba_osob()<=0)
    {
        cout<<"Obecnie brak wiezniow"<<endl;
    }
    else
    {
        int limit=0;
        limit = b_wiez->liczba_osob();
        while(limit>0)
        {
            b_wiez->wez_osobe(limit-1)->zadowolenie+=0.1;
            --limit;
        }
    }
}

void remont_kom(Komisariat *b_kom)           //funckja zmieniajaca stan budynku komisariatu ze zlego na dobry
{
    string pom="Dobry";
    if(b_kom->stan==pom)
    {
        cout<<"Komisariat znajduje sie w dobrym stanie i nie wymaga remontu.\n"<<endl;
    }
    else
    {
        b_kom->stan="Dobry";
        cout<<"Przeprowadzono remont komisariatu\n"<<endl;
    }
}

void remont_sad(Sad *b_sad)                 //funckja zmieniajaca stan budynku sadu ze zlego na dobry
{
    string pom="Dobry";
    if(b_sad->stan==pom)
    {
        cout<<"Sad znajduje sie w dobrym stanie i nie wymaga remontu.\n"<<endl;
    }
    else
    {
        b_sad->stan="Dobry";
        cout<<"Przeprowadzono remont sadu\n"<<endl;
    }
}

void remont_wiez(Wiezienie *b_wiez)         //funckja zmieniajaca stan budynku wiezienie ze zlego na dobry
{
    string pom="Dobry";
    if(b_wiez->stan==pom)
    {
        cout<<"Wiezienie znajduje sie w dobrym stanie i nie wymaga remontu.\n"<<endl;
    }
    else
    {
        b_wiez->stan="Dobry";
        cout<<"Przeprowadzono remont wiezienia\n"<<endl;
    }
}
Pies_policyjny * dodaj_zwierze_pol()
{
    Pies_policyjny *psina_pol = new Pies_policyjny();
    psina_pol->dodaj();
    psy_pol.push_back(psina_pol);
    return psina_pol;
}

int main()
{


 char nazwa_pliku[] = "spis_obywateli.txt";
 char wybor='0',wybor2='0', wybor3='0';             //inicjacja zmiennych
 int pom, pom2, pom3;
 Wiezienie *b_wiez=NULL;
 Komisariat *b_kom=NULL;
 Sad *b_sad=NULL;
 Dom *b_dom=NULL;
 //Przyjazn *b_przyjazn;
 Urzednik *urz;
 //Policjant *pol_;
    urz = new Urzednik();

 //int limit=0;

    //b_przyjazn = new Przyjazn();
    srand(time(NULL));                //funckja odpowiadajaca za rozpoczecie generowania licz pseudolosowych zaleznych od czasu

    b_wiez = new Wiezienie();                           //utworzenie wskaznika na wiezienie
    b_dom = new Dom();                                  //utworzenie wskazinka na dom
    b_dom->dodaj_obywatela(nazwa_pliku);       //wprowadzenie obywateli z pliku

    b_kom = new Komisariat();                           //utworzenie wskaznika na komisariat
    b_sad = new Sad();                                  //utworzenie wskaznika na sad

    cout<<"\n";
    cout<<"Na wstepie nalezy utworzyc 3 budynki: komisariat, wiezienie oraz sad."<<endl;

    cout<<"Tworzenie komisariatu:"<<endl;       //Utworzenie komisariatu za pomoca klasy generycznej infrastruktura
    //b_kom->ustawienia_budynku();
    infrastruktura<Komisariat *> *b_kom2 = new infrastruktura<Komisariat *>(b_kom);
    b_kom2->rozbudowa();
    delete b_kom2;
                            //zniszczenie obiektu klasy generyczne
    cout<<"\nKomisariat dodany"<<endl;
    Sleep(1000);
    system("cls");

    cout<<"Tworzenie wiezienia:"<<endl;         //Utworzenie wiezienia za pomoca klasy generycznej infrastruktura
    infrastruktura<Wiezienie *> *b_wiez2 = new infrastruktura<Wiezienie *>(b_wiez);
    b_wiez2->rozbudowa();
    delete b_kom2;                              //zniszczenie obiektu klasy generyczne
    cout<<"\nWiezienie dodane"<<endl;
    Sleep(1000);
    system("cls");

    infrastruktura<Sad *> *b_sad2 = new infrastruktura<Sad *>(b_sad);   //utworzenie sadu za pomoca klasy generycznej infrastruktura
    b_sad2->rozbudowa();
    delete b_kom2;                              //zniszczenie obiektu klasy generyczne
    cout<<"\nSad dodany"<<endl;
    Sleep(1000);
    system("cls");


    int zmiana=0;
    while(zmiana==0)                            //petla zapewniajaca ciagle dzialanie programu
    {
    cout<<"Menu:\n1. Dodaj postac.\n2. Pozwol dzialac organom scigania ;)\n3. Przegladaj\n4. Sprzatanie\n5. Dzien wyplaty :D\n6. Oglos swieto\n7. Opcje wiezienia\n8. Remonty\n9. Dodaj zwierzatko\nq. Wyslij patrol\nw. Klonuj obywatela\ne. Wyczysc dane obywatela\nr. Porownaj doswiadczenie policjantow\nt. Porownaj doswiadczenie sedziow\n0. Wyjscie"<<endl;    //wyswietlenie menu
    wybor=getch();                              //pobranie wyboru uzytkownika
    switch(wybor)
    {
        case '1':
                {
                    cout<<"Kogo chcesz dodac?\n1.Obywatela\n2.Policjanta\n3.Sedziego\n4.Sprzatacza"<<endl;      //wyswitlenie menu wyboru dodania nowe postaci prócz wieznia
                    wybor2=getch();
                    switch(wybor2)
                    {
                        case '1':
                            {
                                Dodanie_osoby<Dom*> *ob_dod = new Dodanie_osoby<Dom*>(b_dom);                   //dodawanie obywatela przy pomocy klasy generycznej Dodanie_osoby
                                //b_dom->dodaj_osobe();
                                ob_dod->dodaj_osobe();
                                //b_przyjazn->dodacOsobe(*ob_dod);
                                delete ob_dod;          //zniszczenie obiektu klasy generycznej
                                break;
                            }
                        case '2':
                            {
                                Dodanie_osoby<Komisariat*> *pol_dod = new Dodanie_osoby<Komisariat*>(b_kom);    //dodawanie policjanta przy pomocy klasy generycznej Dodanie_osoby
                                //b_kom->dodaj_osobe();
                                pol_dod->dodaj_osobe();
                                delete pol_dod;         //zniszczenie obiektu klasy generycznej
                            }
                                break;
                        case '3':
                            {
                                Dodanie_osoby<Sad*> *se_dod = new Dodanie_osoby<Sad*>(b_sad);   //dodawanie sedziego przy pomocy klasy generycznej Dodanie_osoby
                                //b_sad->dodaj_osobe();
                                se_dod->dodaj_osobe();
                                delete se_dod;          //zniszczenie obiektu klasy generycznej
                            }
                                break;
                        case '4':
                            {
                                dodaj_sprzatacza2(b_dom);
                                /*Sprzatacz *sp1 = new Sprzatacz();         //utworzenie nowego sprzatacza
                                sp1->ustawienie_osoba();                    //mozliwosc ustawienia sprzataczowi jego personaliów
                                b_dom->dodaj_sprzatacza(sp1);               //dodanie do listy wskaznikow sprzatacza wskaznika na nowego sprzatacza
                                Sleep(1000);
                                system("cls");*/
                            }
                                break;
                    }
                    break;
                }

        case '2':
            {
                if(2>=b_kom->liczba_osob() && 0!=b_sad->liczba_osob())                  //sprawdzenie czy istnieje conajmniej jeden sedzia oraz policjant, ktorzy mogliby przeprowadzic akcje
                    {
                        Wiezien *wiezien = NULL;                                        //utworzenie obiektu wiezien i wyzerowanie
                        Policjant *pol_;
                        losowanie<Dom*> *dom_los = new losowanie<Dom*>(b_dom);          //losowanie obywatela za pomoca klasy generycznej-losowanie
                        pom = dom_los->losuj();
                        delete dom_los;

                        losowanie<Sad*> *sad_los = new losowanie<Sad*>(b_sad);          //losowanie sedziego za pomoca klasy generycznej-losowanie
                        pom2 = sad_los->losuj();
                        delete sad_los;

                        losowanie<Komisariat*> *kom_los = new losowanie<Komisariat*>(b_kom);     //losowanie polcjanta za pomoca klasy generycznej-losowanie
                        pom3 = kom_los->losuj();
                        delete kom_los;

                        if(b_sad->wez_osobe(pom2)->wyrok(b_dom->wez_osobe(pom),&wiezien))        //sprawdzenie czy wylosowana osoba jest winna
                        {
                            Policjant *pol = (b_kom->wez_osobe(pom3));
                            if(pol->typ_postaci==typ_policjant_biuro)
                            {
                                Policjant *pol_ = (b_kom->wez_osobe(pom3-1));
                                ((Policjant_akcja *)pol_)->eskorta(b_wiez, wiezien);
                                ((Policjant_biuro *)pol)->raport(wiezien);
                            }
                            else
                            {
                                if(pom3==0)
                                {
                                    pol_ = (b_kom->wez_osobe(pom3+1));
                                }
                                else
                                {
                                    pol_ = (b_kom->wez_osobe(pom3-1));
                                }
                                ((Policjant_akcja *)pol)->eskorta(b_wiez, wiezien);
                                ((Policjant_biuro *)pol_)->raport(wiezien);
                            }
                                //Policjant_akcja *pol_a = (Policjant_akcja *)(pol);
                                //pol_a->eskorta(b_wiez, wiezien);                     //wezwanie policjanta, który wysle wieznia do wiezienia


                          // b_kom->wez_osobe(pom3)->eskorta(b_wiez, wiezien);                     //wezwanie policjanta, który wysle wieznia do wiezienia
                           b_dom->usun_obywatela(b_dom->wez_osobe(pom));
                        }
                    }
                else cout<<"Brak wystarczajacych ilosci organow scigania. Upewnij sie czy masz przynajmniej dwoch policjantow, sedziego oraz wszystkie potrzebne budynki.\n"<<endl;    //komunikat w przypadku braku sedziego lub policjanta
                break;
            }
        case '3':
            {   system("cls");
                cout<<"Jaka kategorie chcesz przejrzec?\n1. Obywatele\n2. Sedziowie\n3. Policjanci\n4. Wiezniowie\n5. Sprzatacze\n6. Budynki\n"<<endl;    //menu przegladania postaci
                wybor2=getch();     //pobranie wyboru uzytkownika
                switch(wybor2)
                {
                    case '1':
                        {
                            if(b_dom->liczba_osob()==0) {system("cls");cout<<"Brak obywateli"<<endl;}       //wypisanie komunikatu w przypadku braku obywateli
                            else
                            {
                                Dane_osobowe<Dom*> *ob_dane = new Dane_osobowe<Dom*>(b_dom);                //informacje o osobie za pomoca klasy generycznej-Dane_osobowe
                                ob_dane->wypisz_dane();
                                delete ob_dane;
                            }
                            break;
                        }
                    case '2':
                        {
                            if(b_sad->liczba_osob()==0) {system("cls");cout<<"Brak Sedziow\n"<<endl;}       //wypisanie komunikatu w przypadku braku sedziow
                            else
                            {
                                Dane_osobowe<Sad*> *ob_dane = new Dane_osobowe<Sad*>(b_sad);                //informacje o osobie za pomoca klasy generycznej-Dane_osobowe
                                ob_dane->wypisz_dane();
                                delete ob_dane;
                            }
                            break;
                        }
                    case '3':
                        {
                            if(b_kom->liczba_osob()==0) {system("cls");cout<<"Brak policjantow\n"<<endl;}   //wypisanie komunikatu w przypadku braku policjantow
                            else
                            {
                                Dane_osobowe<Komisariat*> *ob_dane = new Dane_osobowe<Komisariat*>(b_kom);  //informacje o osobie za pomoca klasy generycznej-Dane_osobowe
                                ob_dane->wypisz_dane();
                                delete ob_dane;
                            }
                            break;
                        }
                    case '4':
                        {
                            if(b_wiez->liczba_osob()==0) {system("cls");cout<<"Brak wiezniow\n"<<endl;}     //wypisanie komunikatu w przypadku braku wizniow
                            else
                            {
                                Dane_osobowe<Wiezienie*> *ob_dane = new Dane_osobowe<Wiezienie*>(b_wiez);   //informacje o osobie za pomoca klasy generycznej-Dane_osobowe
                                ob_dane->wypisz_dane();
                                delete ob_dane;
                            }
                            break;
                        }
                    case '5':
                        {
                            if(b_dom->liczba_sprzataczy()==0) {system("cls");cout<<"Brak sprzataczy\n"<<endl;}  //wypisanie komunikatu w przypadku braku sprzataczy
                            else
                            {
                                for(int i=0; i<b_dom->liczba_sprzataczy(); i++)     //petla iterujaca kolejno wszystkie pozycje w wektorze sprzataczy
                                {
                                cout<<"\n"<<endl;
                                b_dom->wez_sprzatacza(i)->info_osoba();             //wywołanie metody wypisania informacji o sprzataczu
                                }
                            }
                            break;
                        }
                    case '6':
                        {
                            informacja_budowlana<Komisariat*> *inf_bKom = new informacja_budowlana<Komisariat*>(b_kom);     //informacje o budynku za pomoca klasy generycznej-informacja_budowlana
                            inf_bKom->tabliczka_budynku();
                            delete inf_bKom;

                            informacja_budowlana<Sad*> *inf_bSad = new informacja_budowlana<Sad*>(b_sad);                   //informacje o budynku za pomoca klasy generycznej-informacja_budowlana
                            inf_bSad->tabliczka_budynku();
                            delete inf_bSad;

                            informacja_budowlana<Wiezienie*> *inf_bWiez = new informacja_budowlana<Wiezienie*>(b_wiez);     //informacje o budynku przy pomocy klasy generycznej-informacja_budowlana
                            inf_bWiez->tabliczka_budynku();
                            delete inf_bWiez;
                            break;
                        }
                 }
            }
            break;
        case '4':
            {
                if(b_dom->liczba_sprzataczy()<=0)           //sprawdzenie czy istnieje przynajmniej jeden sprzatacz
                {
                    cout<<"\nBrak osob sprzatajcych, aby przeprowadzic sprzatanie nalezy dodac przynajmniej jedna taka osobe\n"<<endl;
                    break;
                }
                int i=rand()%b_dom->liczba_sprzataczy();    //losowanie sprzatacza, ktory wykona sprzatanie
                cout<<"Co chcesz sprzatnac?\n1. Komisariat\n2. Sad\n3. Wiezienie"<<endl;
                wybor3=getch();     //pobranie wyboru uzytkownika
                switch(wybor3)
                {
                    case '1':
                        {
                            //int i=rand()%b_dom->liczba_sprzataczy();
                            b_dom->wez_sprzatacza(i)->sprzatanie_kom(b_kom);        //sprzaranie komisariatu
                            zwiekszenie_l_sprzatniec(b_dom->wez_sprzatacza(i));
                            break;
                        }
                    case '2':
                        {
                            b_dom->wez_sprzatacza(i)->sprzatanie_sad(b_sad);        //sprzatanie sadu
                            zwiekszenie_l_sprzatniec(b_dom->wez_sprzatacza(i));
                            break;
                        }
                    case '3':
                        {
                            b_dom->wez_sprzatacza(i)->sprzatanie_wiez(b_wiez);      //sprzatanie wiezienia
                            zwiekszenie_l_sprzatniec(b_dom->wez_sprzatacza(i));
                            break;
                        }
                }
            break;
            }
        case '5':
            {
                wynagrodzenie_pol(b_kom, urz);      //wyplacenie pracownikom ich pensji zaleznych miedzy innnymi od ilosci przeprowadzonych prac

                wynagrodzenie_sprz(b_dom, urz);

                wynagrodzenie_sed(b_sad, urz);
                cout<<"Przyznano wynagrodzenia"<<endl;
                break;
            }
        case '6':                   //oglaszanie swiat w celu poprawienia zadowolenia postaci
            {
                system("cls");
                cout<<"Oglos swieto:\n1. Swieto narodowe\n2. Swieto policji.\n3. Swieto wymiaru sprawiedliwosci."<<endl;
                wybor3=getch();     //pobranie wyboru uzytkownika
                switch(wybor3)
                {
                    case '1':
                        {
                            swieto_narodowe(b_dom);
                            break;
                        }
                    case '2':
                        {
                            swieto_policji(b_kom);
                            break;
                        }
                    case '3':
                        {
                            swieto_sprawiedliwosci(b_sad);
                            break;
                        }
                }
                break;
            }
        case '7':               //menu opcji dostepnych dla wiezienia
            {
                system("cls");
                cout<<"Opcje wiezienia:\n1. Widzenie"<<endl;
                wybor3=getch();
                switch(wybor3)
                {
                    case '1':
                        {
                            widzenie(b_wiez);
                            break;
                        }
                }

                break;
            }
        case '8':           //przeprowadzenie remontow, czyli popraw stanu budynku ze zlego na dobry
            {
                system("cls");
                cout<<"Co chcesz wyremontowac?\n1. Komisariat\n2. Sad\n3. Wiezienie\n"<<endl;
                wybor3=getch();     //pobranie wyboru uzytkownika
                switch(wybor3)
                {
                    case '1':
                        {
                            remont_kom(b_kom);
                            break;
                        }
                    case '2':
                        {
                            remont_sad(b_sad);
                            break;
                        }
                    case '3':
                        {
                            remont_wiez(b_wiez);
                            break;
                        }
                }
                break;
            }
        case '9':           //przeprowadzenie remontow, czyli popraw stanu budynku ze zlego na dobry
            {
                system("cls");
                cout<<"Jakie zwierze chcesz dodac\n1. Psa\n2. Kota\n3. Psa policyjnego\n"<<endl;
                wybor3=getch();     //pobranie wyboru uzytkownika
                switch(wybor3)
                {
                    case '1':
                        {
                            Pies *psina = new Pies();
                            psina->dodaj_zwierze();
                            psy.push_back(psina);
                            break;
                        }
                    case '2':
                        {
                            Kot *kociak = new Kot();
                            kociak->dodaj_zwierze();
                            koty.push_back(kociak);
                            break;
                        }
                    case '3':
                        {
                            /*Pies_policyjny *psina_pol = new Pies_policyjny();
                            psina_pol->dodaj();
                            psy_pol.push_back(psina_pol);*/
                            dodaj_zwierze_pol();
                            break;
                        }
                }
                break;
            }
        case 'q':           //przeprowadzenie remontow, czyli popraw stanu budynku ze zlego na dobry
            {
                Patrol *pat = new Patrol(b_kom);
                system("cls");
                pat->patrol_info();
                pat->obchod();
                delete pat;
                break;
            }
        case 'w':           //przeprowadzenie remontow, czyli popraw stanu budynku ze zlego na dobry
            {
                if(b_dom->liczba_osob()>0)
                {
                    Obywatel * ob;
                    Obywatel * klon= new Obywatel(0.0, true);
                    b_dom->dodaj_obywatela(klon);
                    ob = b_dom->wez_osobe(0);
                    *klon = *ob;
                    if(*klon==*ob)
                        printf("\nSklonowano obywalela nr %d\n\n",0);
                    else
                        printf("\nKlonowanie obywatela nr %d nieudane\n\n",0);
                }
                else cout<<"\nBrak obywateli"<<endl;
                break;
            }
        case 'e':           //przeprowadzenie remontow, czyli popraw stanu budynku ze zlego na dobry
            {
                if(b_dom->liczba_osob()>0)
                {
                    Obywatel * ob;
                    ob = b_dom->wez_osobe(0);
                    !(*ob);
                    cout<<"Wyczyszczono dane dot. obywatela nr. 0"<<endl;
                }
                else cout<<"\nBrak obywateli"<<endl;

                break;
            }
        case 'r':           //przeprowadzenie remontow, czyli popraw stanu budynku ze zlego na dobry
            {
                if(b_kom->liczba_osob()>1)
                {
                    Policjant *pol;
                    Policjant *pol_pom;
                    int nr1=100,nr2=100;
                    cout<<"\nPodaj numer 1 policjanta (od 0 do "<<b_kom->liczba_osob()-1<<")"<<endl;
                    cin>>nr1;
                    cout<<"\nPodaj numer 2 policjanta (od 0 do "<<b_kom->liczba_osob()-1<<")"<<endl;
                    cin>>nr2;
                    if(nr1>=b_kom->liczba_osob() || nr2>=b_kom->liczba_osob())
                    {
                        cout<<"\nBledne numery."<<endl;
                        break;
                    }
                    pol=b_kom->wez_osobe(nr1);
                    pol_pom=b_kom->wez_osobe(nr2);
                    if((*pol)>(*pol_pom))
                        cout<<"Pierwszy podany policjant jest bardziej doswiadczony"<<endl;
                    else
                        cout<<"Drugi podany policjant jest bardziej doswiadczony"<<endl;
                }
                else cout<<"\nBrak policjantow"<<endl;

                break;
            }
        case 't':           //przeprowadzenie remontow, czyli popraw stanu budynku ze zlego na dobry
            {
                if(b_sad->liczba_osob()>0)
                {
                    Sedzia *se;
                    Sedzia *se_pom;
                    int nr1=100,nr2=100;
                    cout<<"\nPodaj numer 1 sedziego (od 0 do "<<b_sad->liczba_osob()-1<<")"<<endl;
                    cin>>nr1;
                    cout<<"\nPodaj numer 2 sedziego (od 0 do "<<b_sad->liczba_osob()-1<<")"<<endl;
                    cin>>nr2;
                    if(nr1>=b_sad->liczba_osob() || nr2>=b_sad->liczba_osob())
                    {
                        cout<<"\nBledne numery."<<endl;
                        break;
                    }
                    se=b_sad->wez_osobe(nr1);
                    se_pom=b_sad->wez_osobe(nr2);

                    if((*se)<(*se_pom))
                        cout<<"Pierwszy podany sedzia jest mniej doswiadczony"<<endl;
                    else
                        cout<<"Drugi podany sedzia jest mniej doswiadczony"<<endl;
                }
                else cout<<"\nBrak sedziow"<<endl;

                break;
            }
        case '0':           //wyjscie z programu
            {
                zmiana=1;
                break;
            }

      }
    }
    delete b_dom;       //niszczenie obiektow
    delete b_wiez;
    delete b_kom;
    delete b_sad;
    delete urz;

    return 0;
}
