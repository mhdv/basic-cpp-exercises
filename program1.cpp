#include"program1.h"
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string>
#include<math.h>

using namespace std;

Program1::Program1()                            // konstruktor klasy
    : menu1 ("1)Podaj wymiary tablicy (stworz ja).\n\
2)Wypelnij tablice losowymi wartosciami (podaj zakres).\n\
3)Wyswietl zawartosc tej tablicy.\n\
4)Znajdz maksymalna wartosc tablicy.\n\
5)Znajdz minimalna wartosc tablicy.\n\
9)Usun tablice\n\
0)Cofnij.\n")
    , x(0)
    , y(0)
    , max(0)
    , min(0)
    , rozmiar(0)
    , ilemax(0)
    , ilemin(0)     {}

    //#######################################################################
    //###           GLOWNA FUNKCJA PROGRAMU          ########################
    //#######################################################################

int Program1::program1main(){
    do{
        system("clear");
        if(x!=0 && y!=0){                   // sprawdza czy tablica istnieje
            cout << "\e[42m\tStworzona tablica ma wymiary [" << x << "][" << rozmiar << "]\e[30m\e[47m" <<endl;
        }else{
            cout << "\e[41m\tNie masz stworzonej tablicy.\n\e[30m\e[47m";
        }
        cout << menu1;                      // wyswietla menu, ktore zadeklarowane jest w konstruktorze
        while(!(cin >> opcja1) | ((opcja1>5)&&(opcja1!=9)) | (opcja1<0)){   // prosta obsluga bledow
            cout << "\e[30m\e[41m\tWpisz poprawna cyfre!\n\e[30m\e[47m";
            cin.clear();
            cin.ignore();
        }
        switch(opcja1){                     // funkcja switch sluzaca za menu programu
        case 1:
            if((x==0) | (y==0)){            // sprawdzenie czy tablica istnieje
                Program1::stworz();
            }else{
                cout << "\e[41m\tUWAGA! Stworzenie tablicy spowoduje nadpisanie obecnej.\n Czy chcesz kontynuowac?[T/N]\n\e[30m\e[47m";
                string odp;
                do{
                    cin >> odp;
                    if(odp=="T"){
                        Program1::stworz();
                        cout << "\e[42m\tPomyslnie nadpisano tablice.\n";
                        cout << "Kliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
                        getchar();
                    }else if(odp!="N"){
                        cout << "\e[30m\e[41m\tPodaj prawidlowa odpowiedz!.\n\e[30m\e[47m";
                    }else if(odp=="N"){
                        odp="T";
                        cout << "\e[42m\tZachowano obecna tablice.\n";
                        cout << "Kliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
                        getchar();getchar();
                    }
                }while(odp!="T");
            }
            break;
        case 2:
            if((x==0) | (y==0)){
                cout << "\e[30m\e[41m\tMusisz najpierw stworzyc poprawna tablice.\n";
                cout << "Kliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
                getchar();getchar();
            }else{
                Program1::wypelnij();
            }
            break;
        case 3:
            if((x==0) | (y==0)){
                cout << "\e[30m\e[41m\tMusisz najpierw stworzyc poprawna tablice.\n";
                cout << "Kliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
                getchar();getchar();
            }else{
                Program1::wyswietl();
            }
            break;
        case 4:
            if((x==0) | (y==0)){
                cout << "\e[30m\e[41m\tMusisz najpierw stworzyc poprawna tablice.\n";
                cout << "Kliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
                getchar();getchar();
            }else{
                Program1::maxtab();
            }
            break;
        case 5:
            if((x==0) | (y==0)){
                cout << "\e[30m\e[41m\tMusisz najpierw stworzyc poprawna tablice.\n";
                cout << "Kliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
                getchar();getchar();
            }else{
                Program1::mintab();
            }
            break;
        case 9:
            if((x==0) | (y==0)){
                cout << "\e[30m\e[41m\tMusisz najpierw stworzyc poprawna tablice.\n";
                cout << "Kliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
                getchar();getchar();
            }else{
                Program1::usun();
            }
        default:
            break;
        }
    }while(opcja1!=0);
    return 0;
}
//#######################################################################
//###           STWORZ TABLICE          #################################
//#######################################################################

void Program1::stworz(){
    cout << "Podaj ilosc wierszy tablicy: " << endl;
    while(!(cin >> x) | (x<=0)){
        cout << "\e[30m\e[41m\tWpisz poprawna cyfre!\n\e[30m\e[47m";
        cin.clear();
        cin.ignore();
    }
    cout << "Podaj ilosc kolumn tablicy: " << endl;
    while(!(cin >> rozmiar) | (rozmiar<=0)){
        cout << "\e[30m\e[41m\tWpisz poprawna cyfre!\n\e[30m\e[47m";
        cin.clear();
        cin.ignore();
    }
    y=rozmiar-1;                // rozmiar pozostaje zmienna wyswietlana jako ilosc kolumn
    tab = new int *[x];
    for(int i=0; i<x; i++){
        tab[i] = new int [y];
    }
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            tab[i][j]=0;
        }
    }
    cout << "\e[42mTablica o wymiarach [" << x << "][" << rozmiar << "] zostala wypelniona zerami." << endl;
    cout << "Kliknij ENTER aby kontynuowac.\e[30m\e[47m";
    getchar();getchar();
}

//#######################################################################
//###           WYPELNIJ TABLICE          ###############################
//#######################################################################

void Program1::wypelnij(){
    system("clear");
    int pocz;                   // zmienna deklarujaca poprzez uzytkownika poczatek zakresu 100 liczb pseudolosowych
    cout << "Podaj poczatek zakresu stu liczb: " << endl;
    while(!(cin >> pocz)){
        cout << "\e[30m\e[41m\tWpisz poprawca cyfre!\n\e[30m\e[47m";
        cin.clear();
        cin.ignore();
    }
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            tab[i][j]=((rand()%100) + pocz);    // zapisywanie liczb pseudolosowych do poszczegolnych komorek tablicy
        }
    }
    cout << "\e[42mPoprawnie wypelniono tablice." << endl;
    cout << "Kliknij ENTER aby kontynuowac.\e[30m\e[47m" << endl;
    getchar();getchar();
}

//#######################################################################
//###           USUN TABLICE          ###################################
//#######################################################################

void Program1::usun(){
    cout << "\e[41m\tUWAGA! Czy na pewno chcesz usunac tablice?[T/N]\n\e[30m\e[47m";
    string odp;
    do{
        cin >> odp;
        if(odp=="T"){
            x=0, y=0;
            for(int i=0; i<x; i++){
                delete [] tab[i];
            }
            delete [] tab;
            tab=NULL;
            cout << "\e[42m\tPomyslnie usunieto tablice.\n";
            cout << "Kliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
            getchar();getchar();
        }else if(odp!="N"){
            cout << "\e[30m\e[41m\tPodaj prawidlowa odpowiedz!.\n\e[30m\e[47m";
        }else if(odp=="N"){
            odp="T";
            cout << "\e[42m\tZachowano tablice.\n";
            cout << "Kliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
            getchar();getchar();
        }
    }while(odp!="T");
}

//#######################################################################
//###           WYSWIETL TABLICE          ###############################
//#######################################################################

void Program1::wyswietl(){
    system("clear");
    cout << "\e[42m\tOto Twoja tablica:\n\n\e[30m\e[47m";
    for(int i=0; i<x; i++){
        cout << "[\t" << tab[i][0] << "\t";
        for(int j=0; j<y; j++){
            cout << tab[i][j] << "\t";
        }
        cout << "\t]\n";
    }
    cout << "\e[42m\tKliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
    getchar();getchar();
}

//#######################################################################
//###           ZNAJDZ MAX          #####################################
//#######################################################################

void Program1::maxtab(){
    system("clear");
    cout << "\e[42m\tOto maksymalna wartosc znaleziona w Twojej tablicy:\n\n\e[30m\e[47m";
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(tab[i][j]>max){
                max=tab[i][j];      // nadpisuje kazda kolejna wieksza od poprzedniej wartosc
            }
        }
    }
    cout << "\e[31m\t" << max << endl;
    cout << "\n\n\n\e[30m\e[42m\tIlosc znalezionych wartosci maksymalnych:\n\n\e[30m\e[47m";
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(tab[i][j]==max){
                ilemax++;           // ^ tak samo jak wyzej, tylko zlicza maksima
            }
        }
    }
    cout << "\e[31m\t" << ilemax << endl;
    ilemax=0;
    cout << "\n\n\n\e[30m\e[42m\tKliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
    getchar();getchar();
}

//#######################################################################
//###           ZNAJDZ MIN          #####################################
//#######################################################################

void Program1::mintab(){
    system("clear");
    cout << "\e[42m\tOto minimalna wartosc znaleziona w Twojej tablicy:\n\n\e[30m\e[47m";
    min=tab[0][0];
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(tab[i][j]<min){
                min=tab[i][j];
            }
        }
    }
    cout << "\e[31m\t" << min << endl;
    cout << "\n\n\n\e[30m\e[42m\tIlosc znalezionych wartosci minimalnych:\n\n\e[30m\e[47m";
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(tab[i][j]==min){
                ilemin++;
            }
        }
    }
    cout << "\e[31m\t" << ilemin << endl;
    ilemin=0;
    cout << "\n\n\n\e[30m\e[42m\tKliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
    getchar();getchar();
}
