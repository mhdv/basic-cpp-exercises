
// plik naglowkowy dla programu 2

#ifndef PROGRAM2_H
#define PROGRAM2_H

#endif // PROGRAM2_H

#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string>
#include<fstream>


using namespace std;


class Program2{
public:
    string menu2, nazwa, sciezka;
    fstream plik;
    string *tab;
    int opcja2, rozmiar;

    int program2main();
    void wczytajBIN();
    void zapiszBIN();
    void wczytajTXT();
    void zapiszTXT();
    void usuntab();

    Program2();

};
