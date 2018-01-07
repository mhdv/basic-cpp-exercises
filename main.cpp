//#######################################################################
//###           Michal Filipowicz                                     ###
//###           nr 226393                                             ###
//###           Wydzial Elektroniki W4                                ###
//###           AiR                                                   ###
//###           mail: 226393@student.pwr.wroc.pl                      ###
//#######################################################################

#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string>
#include<fstream>
#include"program1.h"
#include"program2.h"
#include"program3.h"
#include"program4.h"

using namespace std;

void wpisz(int liczba);

string menu =  "\e[31m\e[42m Witaj w programie PAMSI-1\n"
        "\e[30m\e[47m\t1)Dynamiczne tablice dwuwymiarowe.\n"
        "\t2)Tablice jednowymiarowe z zapisem.\n"
        "\t3)Prototypy funkcji.\n"
        "\t4)Palindromy.\n"
        "\t0)Wyjdz.\n";

int main(){
    int opcja;
    do{
        cout << menu;
        system("clear");
        cout << menu;
        while(!(cin >> opcja) | (opcja>4) | (opcja<0)){
            cout << "\e[30m\e[41m\tWpisz poprawca cyfre!\n\e[30m\e[47m";
            cin.clear();
            cin.ignore();
        }
        switch(opcja){
        case 1:
        {
            Program1 dwuwymiarowe;
            dwuwymiarowe.program1main();
            break;
        }
        case 2:
        {
            Program2 jednowymiarowe;
            jednowymiarowe.program2main();
            break;
        }
        case 3:
        {
            Program3 prototypy;
            prototypy.program3main();
            break;
        }
        case 4:
        {
            Program4 palindrom;
            palindrom.program4main();
            break;
        }
        default:
        {
            break;
        }
        }
    }while(opcja!=0);
    return 0;
}
