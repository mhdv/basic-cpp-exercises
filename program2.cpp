#include"program2.h"
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string>
#include<fstream>


using namespace std;

Program2::Program2()                            // konstruktor klasy
    : menu2("1)Wczytaj tablice jednowymiarowa z pliku BIN.\n\
2)Zapisz tablice jednowymiarowa do pliku BIN.\n\
3)Wczytaj tablice jednowymiarowa z pliku TXT.\n\
4)Zapisz tablice jednowymiarowa do pliku TXT.\n\
5)Wyswietl aktualnie wczytana tablice.\n\
6)Usun zapisana tablice.\n\
0)Cofnij.\n")
    , sciezka("/home/mehow/Projekty/pamsi1console1/")       { }

//#######################################################################
//###           GLOWNA FUNKCJA PROGRAMU          ########################
//#######################################################################

int Program2::program2main(){
    if(rozmiar==0)
    tab = new string[0];
    do{
        system("clear");
        if(rozmiar!=0){
            cout << "\e[30m\e[42m\tMasz zapisana tablice w pamieci.\n\e[30m\e[47m";
        }else{
            cout << "\e[30m\e[41m\tBrak tablicy w pamieci!\n\e[30m\e[47m";
        }
        cout << menu2;
        while(!(cin >> opcja2) | (opcja2>6) | (opcja2<0)){
            cout << "\e[30m\e[41m\tWpisz poprawna cyfre!\n\e[30m\e[47m";
            cin.clear();
            cin.ignore();
        }
        switch (opcja2) {
        case 1:
            Program2::wczytajBIN();
            break;
        case 2:
            Program2::zapiszBIN();
            break;
        case 3:
            Program2::wczytajTXT();
            break;
        case 4:
            Program2::zapiszTXT();
            break;
        case 5:
            if(rozmiar>0){
                cout << "\e[42m\tOto Twoja aktualnie zapisana tablica:\n\e[30m\e[47m";
                for(int i=0; i<rozmiar; i++){
                    cout << tab[i] << endl;
                }
                cout << "\tKliknij ENTER aby kontynuowac.\e[30m\e[47m";
                getchar();getchar();
            }else{
                cout << "\e[42m\tBrak zapisanej w pamieci tablicy.\n\tKliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
                getchar();getchar();
            }
            break;
        case 6:
            Program2::usuntab();
            break;
        default:
            break;
        }
    }while(opcja2!=0);
    return 0;
}

//#######################################################################
//###           WCZYTANIE PLIKU BIN          ############################
//#######################################################################


void Program2::wczytajBIN(){
    rozmiar=0;
    system("clear");
//    string pytanie;
    cout << "\e[42m\tCzy chcesz zmienic domyslna sciezke pliku? [T/N]\n\t(domyslnie folder z projektem)\n\e[30m\e[47m";
    string odp;                 // zmienna pomocnicza, sluzaca za odpowiedz uzytkownika na pytanie
    do{
        cin >> odp;
        if(odp=="T"){
            cin >> sciezka;
            cout << "\e[42m\tPomyslnie zmieniono sciezke.\n";
            cout << "Kliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
            getchar();getchar();
        }else if(odp!="N"){
            cout << "\e[30m\e[41m\tPodaj prawidlowa odpowiedz!.\n\e[30m\e[47m";
        }else if(odp=="N"){
            odp="T";
            cout << "\e[42m\tZachowano domyslna sciezke.\n";
        }
    }while(odp!="T");
    cout << "\e[42m\tPodaj nazwe pliku:\n\e[30m\e[47m";
    cin >> nazwa;
    plik.open(sciezka+nazwa);           // sciezka+nazwa oznacza polaczenie dwoch stringow, domyslna sciezka znajduje sie w konstruktorze
    if(plik){
        plik.close();
        plik.clear();
        plik.open(sciezka+nazwa, ios::in | ios::binary);
        string temp;                    // zmienna tymczasowa potrzebna do odczytu wielkosci pliku
        if(plik.good()){
            cout << "\e[42m\tOdczyt pliku udany. Zapisuje dane z pliku do tablicy:\n\e[30m\e[47m";
            while(!plik.eof()){
            plik >> temp;
            rozmiar++;
            }
            temp.clear();
            plik.clear();
            plik.seekg(0,ios::beg);
            tab = new string[rozmiar];
            int i=0;
            while(!plik.eof()){
                plik >> tab[i];
                cout << tab[i] << "\n";
                i++;
            }
        }else{ cout << "Odczyt pliku nieudany."; }
        cout << "\e[42mKliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
        getchar();getchar();
    }else{
        cout << "\e[42m\tTaki plik nie istnieje, chcesz go stworzyc? [T/N]\n\e[30m\e[47m";
        odp.clear();
        do{
            cin >> odp;
            if(odp=="T"){
                plik.close();
                plik.clear();
                plik.open(sciezka+nazwa, ios::out);
                cout << "\e[42m\tPomyslnie stworzono plik.\n\tPlik jest oczywiscie pusty, chcac zapisac w nim tablice,\n\twybierz opcje zapisu z menu glownego\n";
                cout << "Kliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
                plik.close();
                plik.clear();
                getchar();getchar();
            }else if(odp!="N"){
                cout << "\e[30m\e[41m\tPodaj prawidlowa odpowiedz!.\n\e[30m\e[47m";
            }else if(odp=="N"){
                odp="T";
                cout << "\e[42m\tNastapi wiec powrot do glownego menu.\n\tKliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
                getchar();getchar();
            }
        }while(odp!="T");
    }
}

//#######################################################################
//###           ZAPISANIE PLIKU BIN          ############################
//#######################################################################


void Program2::zapiszBIN(){
    system("clear");
    if(rozmiar<=0){
        cout << "\e[41m\tNie masz zapisanej w pamieci tablicy!\n\tPierw wczytaj tablice z istniejacego pliku.\n\tKliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
        getchar();getchar();

    }else{
        cout << "\e[42m\tPosiadasz zapisana w pamieci tablice.\n\e[30m\e[47m";
        cout << "\e[42m\tCzy chcesz zmienic domyslna sciezke pliku? [T/N]\n\t(domyslnie folder z projektem)\n\e[30m\e[47m";
        string odp;
        do{
            cin >> odp;
            if(odp=="T"){
                cin >> sciezka;
                cout << "\e[42m\tPomyslnie zmieniono sciezke.\n";
                cout << "Kliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
                getchar();getchar();
            }else if(odp!="N"){
                cout << "\e[30m\e[41m\tPodaj prawidlowa odpowiedz!.\n\e[30m\e[47m";
            }else if(odp=="N"){
                odp="T";
                cout << "\e[42m\tZachowano domyslna sciezke.\n";
            }
        }while(odp!="T");
        cout << "\e[42m\tPodaj nazwe pliku: \n\e[30m\e[47m";
        cin >> nazwa;
        plik.open(sciezka+nazwa);
        if(plik){
            int opzapisu;
            plik.close();
            plik.clear();
            do{
                system("clear");
                cout << "1)Nadpisz istniejace juz w pliku dane.\n2)Dopisz dane do pliku\n0)Cofnij.\n";
                while(!(cin >> opzapisu) | (opzapisu>2) | (opzapisu<0)){
                    cout << "\e[30m\e[41m\tWpisz poprawna cyfre!\n\e[30m\e[47m";
                    cin.clear();
                    cin.ignore();
                }
                switch(opzapisu){
                case 1:
                    plik.open(sciezka+nazwa, ios::out | ios::binary);
                    for(int i=0; i<rozmiar; i++){
                        plik << tab[i] << " ";
                    }
                    cout << "\e[30m\e[42m\tPomyslnie nadpisano dane.\n\tKliknij ENTER aby kontynuowac.\e[30m\e[47m";
                    getchar();getchar();
                    opzapisu=0;
                    break;
                case 2:
                    plik.open(sciezka+nazwa, ios::out | ios::app | ios::binary);
                    for(int i=0; i<rozmiar; i++){
                        plik << tab[i] << " ";
                    }
                    cout << "\e[30m\e[42m\tPomyslnie dopisano dane.\n\tKliknij ENTER aby kontynuowac.\e[30m\e[47m";
                    getchar();getchar();
                    opzapisu=0;
                    break;
                default:
                    break;
                }
            }while(opzapisu!=0);
        }else{
            plik.close();
            plik.clear();
            cout << "\e[30m\e[42m\tTaki plik nie istnieje, zostanie automatycznie stworzony i zapisany.\n\tKliknij ENTER aby kontynuowac.\e[30m\e[47m";
            plik.open(sciezka+nazwa, ios::out);
            for(int i=0; i<rozmiar; i++){
                plik << tab[i] << " ";
            }
            getchar();getchar();
        }
    }
    plik.close();
    plik.clear();
}

//#######################################################################
//###           WCZYTANIE PLIKU TXT          ############################
//#######################################################################


void Program2::wczytajTXT(){
    rozmiar=0;
    system("clear");
    string pytanie;
    cout << "\e[42m\tCzy chcesz zmienic domyslna sciezke pliku? [T/N]\n\t(domyslnie folder z projektem)\n\e[30m\e[47m";
    string odp;
    do{
        cin >> odp;
        if(odp=="T"){
            cin >> sciezka;
            cout << "\e[42m\tPomyslnie zmieniono sciezke.\n";
            cout << "Kliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
            getchar();getchar();
        }else if(odp!="N"){
            cout << "\e[30m\e[41m\tPodaj prawidlowa odpowiedz!.\n\e[30m\e[47m";
        }else if(odp=="N"){
            odp="T";
            cout << "\e[42m\tZachowano domyslna sciezke.\n";
        }
    }while(odp!="T");
    cout << "\e[42m\tPodaj nazwe pliku:\n\e[30m\e[47m";
    cin >> nazwa;
    plik.open(sciezka+nazwa);
    if(plik){

        plik.close();
        plik.clear();
        plik.open(sciezka+nazwa, ios::in | ios::binary);
        string temp;
        if(plik.good()){
            cout << "\e[42m\tOdczyt pliku udany. Zapisuje dane z pliku do tablicy:\n\e[30m\e[47m";
            while(!plik.eof()){
            plik >> temp;
            rozmiar++;
            }
            temp.clear();
            plik.clear();
            plik.seekg(0,ios::beg);
            tab = new string[rozmiar];
            int i=0;
            while(!plik.eof()){
                plik >> tab[i];
                cout << tab[i] << "\n";
                i++;
            }
        }else{ cout << "Odczyt pliku nieudany."; }
        cout << "\e[42mKliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
        getchar();getchar();
    }else{
        cout << "\e[42m\tTaki plik nie istnieje, chcesz go stworzyc? [T/N]\n\e[30m\e[47m";
        odp.clear();
        do{
            cin >> odp;
            if(odp=="T"){
                plik.close();
                plik.clear();
                plik.open(sciezka+nazwa, ios::out);
                cout << "\e[42m\tPomyslnie stworzono plik.\n\tPlik jest oczywiscie pusty, chcac zapisac w nim tablice,\n\twybierz opcje zapisu z menu glownego\n";
                cout << "Kliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
                plik.close();
                plik.clear();
                getchar();getchar();
            }else if(odp!="N"){
                cout << "\e[30m\e[41m\tPodaj prawidlowa odpowiedz!.\n\e[30m\e[47m";
            }else if(odp=="N"){
                odp="T";
                cout << "\e[42m\tNastapi wiec powrot do glownego menu.\n\tKliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
                getchar();getchar();
            }
        }while(odp!="T");
    }
    plik.close();
    plik.clear();
}

//#######################################################################
//###           ZAPIS PLIKU TXT          ################################
//#######################################################################


void Program2::zapiszTXT(){
    system("clear");
    if(rozmiar<=0){
        cout << "\e[41m\tNie masz zapisanej w pamieci tablicy!\n\tPierw wczytaj tablice z istniejacego pliku.\n\tKliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
        getchar();getchar();

    }else{
        cout << "\e[42m\tPosiadasz zapisana w pamieci tablice.\n\e[30m\e[47m";
        cout << "\e[42m\tCzy chcesz zmienic domyslna sciezke pliku? [T/N]\n\t(domyslnie folder z projektem)\n\e[30m\e[47m";
        string odp;
        do{
            cin >> odp;
            if(odp=="T"){
                cin >> sciezka;
                cout << "\e[42m\tPomyslnie zmieniono sciezke.\n";
                cout << "Kliknij ENTER aby kontynuowac.\n\e[30m\e[47m";
                getchar();getchar();
            }else if(odp!="N"){
                cout << "\e[30m\e[41m\tPodaj prawidlowa odpowiedz!.\n\e[30m\e[47m";
            }else if(odp=="N"){
                odp="T";
                cout << "\e[42m\tZachowano domyslna sciezke.\n";
            }
        }while(odp!="T");
        cout << "\e[42m\tPodaj nazwe pliku: \n\e[30m\e[47m";
        cin >> nazwa;
        plik.open(sciezka+nazwa);
        if(plik){
            int opzapisu;
            plik.close();
            plik.clear();
            do{
                system("clear");
                cout << "1)Nadpisz istniejace juz w pliku dane.\n2)Dopisz dane do pliku\n0)Cofnij.\n";
                while(!(cin >> opzapisu) | (opzapisu>2) | (opzapisu<0)){
                    cout << "\e[30m\e[41m\tWpisz poprawna cyfre!\n\e[30m\e[47m";
                    cin.clear();
                    cin.ignore();
                }
                switch(opzapisu){
                case 1:
                    plik.open(sciezka+nazwa, ios::out);
                    for(int i=0; i<rozmiar; i++){
                        plik << tab[i] << " ";
                    }
                    cout << "\e[30m\e[42m\tPomyslnie nadpisano dane.\n\tKliknij ENTER aby kontynuowac.\e[30m\e[47m";
                    getchar();getchar();
                    opzapisu=0;
                    break;
                case 2:
                    plik.open(sciezka+nazwa, ios::out | ios::app);
                    for(int i=0; i<rozmiar; i++){
                        plik << tab[i] << " ";
                    }
                    cout << "\e[30m\e[42m\tPomyslnie dopisano dane.\n\tKliknij ENTER aby kontynuowac.\e[30m\e[47m";
                    getchar();getchar();
                    opzapisu=0;
                    break;
                default:
                    break;
                }
            }while(opzapisu!=0);
        }else{
            plik.close();
            plik.clear();
            cout << "\e[30m\e[42m\tTaki plik nie istnieje, zostanie automatycznie stworzony i zapisany.\n\tKliknij ENTER aby kontynuowac.\e[30m\e[47m";
            plik.open(sciezka+nazwa, ios::out);
            for(int i=0; i<rozmiar; i++){
                plik << tab[i] << " ";
            }
            getchar();getchar();
        }
    }
    plik.close();
    plik.clear();
}

//#######################################################################
//###           USUWA ZAPISANA TABLICE          #########################
//#######################################################################


void Program2::usuntab(){
    if(rozmiar>0){
        delete[] tab;
        tab = new string[0];
        rozmiar=0;
        cout << "\e[42m\tPomyslnie usunieto tablice.\n\tKliknij ENTER aby kontynuowac.\e[30m\e[47m";
        getchar();getchar();
    }else{
        cout << "\e[42m\tNie masz aktualnie zapamietanej zadnej tablicy.\n\tKliknij ENTER aby kontynuowac.\e[30m\e[47m";
        getchar();getchar();
    }
}
