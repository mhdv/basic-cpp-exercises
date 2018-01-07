#ifndef PROGRAM4_H

// plik naglowkowy dla programu 4

#define PROGRAM4_H

#endif // PROGRAM4_H

#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string>
#include<fstream>


using namespace std;


class Program4{
public:
    string slowo, menu4;
    int opcja4, dlugosc;

    int program4main();
    bool jestPal(string slowo);

    Program4();

};

