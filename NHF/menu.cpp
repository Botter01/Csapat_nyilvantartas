//
// Created by USER on 16/04/2023.
//
#include "class.h"
#include "menu.h"
#include "fajl.h"
#include <iostream>
using namespace std;

int beolvas(int min, int max){//megvizsgálja hogy a válasznak beírt érték helyes-e(min-nek és max-nak a menüpontok értékeit adjuk meg)
    while (true) {
        int fomenu_valasztas;
        cin >> fomenu_valasztas;
        if (!cin) {//ha a megadott válasz nem szám volt
            cout <<"Amit megadtál, nem szám volt!"<<endl;
            cin.clear();//cleareljük a buffert
            cin.ignore(256,'\n');
        } else if (fomenu_valasztas > max || fomenu_valasztas < min) {
            cout <<"A megadott szám nem volt megfelelő! min:"<< min << " max:"<< max << endl;//ha az intervallumon kívül adunk meg egy számot
        } else {
            return fomenu_valasztas;
        }
    }
}


void menu_kirajzol(){
    int fomenu_valasztas,torles_almenu,felvetel_almenu, listazas_almenu;
    Lista hetero;
    darabolo_f("foci.txt", hetero);
    darabolo_k("kosar.txt", hetero);
    darabolo_ke("kezi.txt", hetero);

    do {system("cls");
        cout<<"                                                                       ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠲⣶⣶⣦⣄⡀⠀⠀⠀⠀⠀⠀\n"
                   "                                                                       ⠀⠀⠀⣠⣾⣿⣷⡄⠀⠀⣿⣿⠛⠿⢿⡇⠀⠀⠀⠀⠀\n"
                   "                                                                       ⣀⣴⣿⡿⠛⢻⣿⣿⠀⠀⣿⣿⠀⠀⠀⠀⣠⣶⣶⣶⡄\n"
                   "                                                                       ⠀⣿⣿⡇⣠⣾⣿⡿⠀⠀⣿⣿⣶⣾⠀⣾⣿⠟⠉⠛⠁\n"
                   "                                                                       ⠀⣿⣿⣿⠿⠿⣿⣿⣦⠀⣿⣿⠛⠻⠀⣿⣿⠀⠀⠀⠀\n"
                   "                                                                       ⠀⣿⣿⡇⠀⠀⣸⣿⣿⠀⣿⣿⠀⠀⠀⣿⣿⣄⠀⣀⠀\n"
                   "                                                                       ⣠⣿⣿⣿⣿⣿⣿⠿⠃⣠⣿⣿⣄⠀⠀⠙⢿⣿⣿⡿⠇\n"
                   "                                                                       ⠀⠀⠀⠀⣀⠀⣠⣤⣄⠀⣠⣤⣄⠀⣠⣤⣄⠀⠀⠀\n"
                   "                                                                       ⠀⠀⠀⠛⣿⠀⢿⣤⣿⠀⣿⠀⣿⠀⢿⣤⣿⠀⠀⠀\n"
                   "                                                                       ⠀⠀⠀⠀⣿⠀⣤⣤⠟⠀⠻⣤⠟⠀⣤⣤⠟⠀⠀⠀\n"<< endl;

        cout<<"                                             _____                  _                                   _      _    \n"
                   "                                            / ____|                | |                           (_) (_) |    | |   \n"
                   "                                           | (___  _ __   ___  _ __| |_ ___  __ _ _   _  ___  ___ _   _| | ___| |_  \n"
                   "                                            \\___ \\| '_ \\ / _ \\| '__| __/ _ \\/ _` | | | |/ _ \\/ __| | | | |/ _ \\ __| \n"
                   "                                            ____) | |_) | (_) | |  | ||  __/ (_| | |_| |  __/\\__ \\ |_| | |  __/ |_  \n"
                   "                                           |_____/| .__/ \\___/|_|   \\__\\___|\\__, |\\__, |\\___||___/\\__,_|_|\\___|\\__| \n"
                   "                                                  | |                        __/ | __/ |                            \n"
                   "                                                  |_|                       |___/ |___/                             \n\n"
                   "                                                                     By Molnar Botond Kristóf";




        //itt rajzolódik ki a főmenü, és itt láthatóak az almenüpontok
        cout<<("\n\n\n");
        cout << ("************************************************************************************************************************************************************\n");
        cout<<("                                                                               FŐMENÜ");
        cout<<("\n");
        cout<<("\n");
        cout<<("\n");
        cout<<("\n");
        cout<<("\n");
        cout<<("                                       [ 1 ]   Régi csapat törlése.                                [ 2 ]   Új csapat felvétele.");
        cout<<("\n");
        cout<<("\n");
        cout<<("                                                                    [ 3 ]   Csapatok kilistázása.");
        cout<<("\n");
        cout<<("\n");
        cout<<("\n");
        cout<<("                                                                    [ 0 ]   Kilépés a programból.");
        cout<<("\n\n\n");
        cout << ("************************************************************************************************************************************************************\n");
        cout<<("\n");


        cout<<"\n                                                                     Válasszon egy menüpontot: ";
        fomenu_valasztas =beolvas(0,3);//lekorlátozzuk a beolvas()-sal a megadható számokat és ellenőrizzük is, hogy szám-e

        switch(fomenu_valasztas){

            case 1:
                do {
                    system("cls");
                    cout<<("\n");
                    cout<<("\n");
                    cout << ("************************************************************************************************************************************************************\n");
                    cout << ("                                                                            CSAPAT TÖRLÉSE");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("                                               [ 1 ]   Foci csapat.                                [ 2 ]   Kézi csapat. ");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("                                                                         [ 3 ]   Kosár csapat.");
                    cout << ("\n\n\n");
                    cout<<("                                                                     [ 0 ]   Visszalépés a főmenübe.");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("************************************************************************************************************************************************************\n");
                    cout << "\n                                                             Válasszon milyen csapatot szeretne törölni: ";

                    torles_almenu = beolvas(0,3);//lekorlátozzuk a beolvas()-sal a megadható számokat és ellenőrizzük is, hogy szám-e
                    switch(torles_almenu){
                        case 1:
                            system("cls");
                            hetero.hetero_kiir(1);
                            hetero.torol();
                            system("pause");
                            break;

                        case 2:
                            system("cls");
                            hetero.hetero_kiir(2);
                            hetero.torol();
                            system("pause");
                            break;

                        case 3:
                            system("cls");
                            hetero.hetero_kiir(3);
                            hetero.torol();
                            system("pause");
                            break;
                        }

                    }while(torles_almenu != 0);
                    break;

            case 2:
                do {
                    system("cls");
                    cout<<("\n");
                    cout<<("\n");
                    cout << ("************************************************************************************************************************************************************\n");
                    cout << ("                                                                            CSAPAT FELVÉTELE");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("                                               [ 1 ]   Foci csapat.                                [ 2 ]   Kézi csapat. ");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("                                                                         [ 3 ]   Kosár csapat.");
                    cout << ("\n\n\n");
                    cout<<("                                                                     [ 0 ]   Visszalépés a főmenübe.");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("************************************************************************************************************************************************************\n");
                    cout << "\n                                                             Válasszon milyen csapatot szeretne felvenni: ";

                    felvetel_almenu = beolvas(0,3);//lekorlátozzuk a beolvas()-sal a megadható számokat és ellenőrizzük is, hogy szám-e
                    switch(felvetel_almenu){
                        case 1:
                            system("cls");
                            hetero.add(Foci_epit());
                            std::cout<< "Csapatot sikeresen megépítettük.\n";
                            system("pause");
                            break;

                        case 2:
                            system("cls");
                            hetero.add(Kezi_epit());
                            std::cout<< "Csapatot sikeresen megépítettük.\n";
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            hetero.add(Kosar_epit());
                            std::cout<< "Csapatot sikeresen megépítettük.\n";
                            system("pause");
                            break;
                    }

                }while(felvetel_almenu != 0);
                break;


            case 3:
                do {
                    system("cls");
                    cout<<("\n");
                    cout<<("\n");
                    cout << ("************************************************************************************************************************************************************\n");
                    cout << ("                                                                            CSAPAT KILISTÁZÁSA");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("                                               [ 1 ]   Foci csapat.                                [ 2 ]   Kézi csapat. ");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("                                                                         [ 3 ]   Kosár csapat.");
                    cout << ("\n\n\n");
                    cout<<("                                                                     [ 0 ]   Visszalépés a főmenübe.");
                    cout << ("\n");
                    cout << ("\n");
                    cout << ("************************************************************************************************************************************************************\n");
                    cout << "\n                                                             Válasszon melyik csapatokat szeretné megtekinteni: ";

                    listazas_almenu = beolvas(0,3);//lekorlátozzuk a beolvas()-sal a megadható számokat és ellenőrizzük is, hogy szám-e
                    switch(listazas_almenu){
                        case 1:
                            system("cls");
                            hetero.hetero_kiir(1);
                            system("pause");
                            break;

                        case 2:
                            system("cls");
                            hetero.hetero_kiir(2);
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            hetero.hetero_kiir(3);
                            system("pause");
                            break;
                    }

                }while(listazas_almenu != 0);
                break;


            case 0:
                cout<<("Kiléptem a programból\n");
                system("pause");
                break;

                }

    }while(fomenu_valasztas != 0);

}