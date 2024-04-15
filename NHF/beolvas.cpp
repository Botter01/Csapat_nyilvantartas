//
// Created by USER on 04/05/2023.
//
#include <cstring>
#include <iostream>
#include "beolvas.h"

char* din_beolvas() { //dinamikusan beolvasó függvény ---> Stringé alakításhoz kell
    int hossz = 0;
    char aktual;
    char *vegeredm = nullptr;


    while ((aktual = getchar()) != '\n') {//enterig olvasunk be betűket
        char *temp = new char[hossz + 2];

        if (vegeredm != nullptr) {
            strcpy(temp, vegeredm);
            delete[] vegeredm;

        }
        temp[hossz] = aktual;
        temp[hossz + 1] = '\0'; //ideiglenesben eltároljuk az eddig beírt betűket
        vegeredm = new char[hossz + 2];
        strcpy(vegeredm, temp);//átírjuk a végeredménybe
        delete[] temp;//töröljük az ideiglenest

        hossz++;
    }


    return vegeredm;
}