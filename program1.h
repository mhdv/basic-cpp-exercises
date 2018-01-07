#ifndef PROGRAM1_H
#define PROGRAM1_H

#endif // PROGRAM1_H

#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string>


using namespace std;


class Program1{
public:
    string menu1;
    int **tab;
    int x, y, min, max, ilemax, ilemin, opcja1, rozmiar;

    int program1main();
    void stworz();
    void wyswietl();
    void wypelnij();
    void usun();
    void maxtab();
    void mintab();
    void ileminmax();

    Program1();

};
