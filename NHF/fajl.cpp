//
// Created by USER on 22/04/2023.
//
#include "fajl.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "class.h"


int sor_szamlalo(const char* fajlnev) {//megszámolja mennyi sor van az adoot .txt-ben
    std::ifstream fajl(fajlnev);//megnyitjuk a fájlt
    int szam = 0;

    if(!fajl.is_open()){//megvizsgálja, hogy nyitva van-e a fájl
        std::cerr<<"A fájlt nem sikerült megnyitni\n";
        return 0;
    }
    while (!fajl.eof())//addig megy amíg tart a fájl
    {
        char c = fajl.get();
        if (c == '\n')//ha entert lát növeli a sor számot eggyel
        {
            szam++;
        }
    }
    fajl.close();
    return ++szam;
}








