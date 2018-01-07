#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string>
#include<fstream>
#include"program4.h"

using namespace std;


Program4::Program4()                    // konstruktor klasy
    : menu4("1)Wczytaj slowo.\n\
2)Sprawdz czy jest palindromem.\n\
0)Cofnij.\n")   { }

    //#######################################################################
    //###           GLOWNA FUNKCJA PROGRAMU          ########################
    //#######################################################################

int Program4::program4main(){
    do{
        system("clear");
        if(!(slowo.empty())){
            cout << "\e[30m\e[42mWczytane slowo to: \e[30m\e[47m" << slowo;
            if(Program4::jestPal(slowo)==true){
                cout << "\t\e[30m\e[42mJest palindromem!\n\e[30m\e[47m";
            }else{
                cout << "\t\e[30m\e[41mNie jest palindromem.\n\e[30m\e[47m";
            }
        }
        cout << menu4;
        while(!(cin >> opcja4) | (opcja4>2) | (opcja4<0)){
            cout << "\e[30m\e[41m\tWpisz poprawna cyfre!\n\e[30m\e[47m";
            cin.clear();
            cin.ignore();
        }
        switch(opcja4){
        case 1:
            system("clear");
            cout << "\t\e[30m\e[42mZapisz slowo w pamieci programu: \n\e[30m\e[47m";
            cin >> slowo;
            cout << "\t\e[30m\e[42mPomyslnie zapisano slowo!\n\tKliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
            getchar();getchar();
            break;
        case 2:
            if(!(slowo.empty())){
                if(Program4::jestPal(slowo)==true) cout << "\n\t\e[30m\e[42mTak, Twoje slowo jest palindromem!\n\tKliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
                else cout << "\n\t\e[30m\e[41mNie, Twoje slowo nie jest palindromem.\n\tKliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
            }

            else cout << "\t\e[30m\e[41mNie wczytales slowa!\n\tKliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
            getchar();getchar();
            break;
        default:
            break;
        }
    }while(opcja4!=0);
    return 0;
}

//#######################################################################
//###           FUNKCJA SPRAWDZAJACA PALINDROM          #################
//#######################################################################


bool Program4::jestPal(string slowo){
    dlugosc=slowo.size()-1;             // dlugosc slowa -1, poniewaz ostatni znak tablicy string to /0
    for(int i=0; i<dlugosc; i++){       // petla zwracajaca falsz gdy choc jeden znak palindromu sie nie zgadza
        if(slowo[i]!=slowo[dlugosc]){
            return false;
        }
        dlugosc-=1;                     // dekrementuje wartosc zmiennej dlugosc, aby rekurencyjnie pasowala do integera i
    }
    return true;
}
