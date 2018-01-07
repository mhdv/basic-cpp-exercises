#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string>
#include<fstream>
#include"program3.h"


using namespace std;


Program3::Program3()                // konstruktor klasy
    : menu3("1)Potegowanie.\n\
2)Silnia.\n\
0)Cofnij.\n")
    , x(0)
    , p(0)  { }

//#######################################################################
//###           GLOWNA FUNKCJA PROGRAMU          ########################
//#######################################################################


int Program3::program3main(){
    do{
        system("clear");
        cout << menu3;
        while(!(cin >> opcja3) | (opcja3>2) | (opcja3<0)){
            cout << "\e[30m\e[41m\tWpisz poprawna cyfre!\n\e[30m\e[47m";
            cin.clear();
            cin.ignore();
        }
        switch(opcja3){
        case 1:
            system("clear");
            cout << "\e[30m\e[42m\tPrototyp rekurencyjny funkcji potegowania.\n";
            cout << "\tPodaj podstawe potegi (liczbe potegowana).\n\e[30m\e[47m";
            cin >> x;
            cout << "\e[30m\e[42m\n\tPodaj wykladnik potegi.\n\e[30m\e[47m";
            cin >> p;
            cout << "\e[30m\e[42m\n\tOto wynik potegowania: \n\e[30m\e[47m";
            cout << Program3::potega(x, p);
            cout << "\e[30m\e[42m\n\tKliknij ENTER aby kontynuowac. \n\e[30m\e[47m";
            getchar();getchar();
            break;
        case 2:
            system("clear");
            cout << "\e[30m\e[42m\tPrototyp rekurencyjny silni.\n";
            cout << "\tPodaj liczbe, ktorej silnie chcesz policzyc.\n\e[30m\e[47m";
            cin >> x;
            cout << "\e[30m\e[42m\n\tOto wynik silni: \n\e[30m\e[47m";
            cout << Program3::silnia(x);
            cout << "\e[30m\e[42m\n\tKliknij ENTER aby kontynuowac. \n\e[30m\e[47m";
            getchar();getchar();
            break;
        default:
            break;
        }
    }while(opcja3!=0);
    return 0;
}

//#######################################################################
//###           FUNKCJE POTEGI I SILNI          #########################
//#######################################################################



int Program3::potega(int x, int p){
    if(p>0){
        return x=x*potega(x, --p);         // rekurencyjnie wykonuje sie tak dlugo, az dojdzie do 1
    }else if(p==0){
        return 1;
    }else{
        return x=(x*(1/potega(x, (-p-1))));
    }
}

int Program3::silnia(int x){
    if(x==0) return 1;
    else return x*silnia(x-1);
}
