//
// Created by USER on 16/04/2023.
//
#include <iostream>             // Kiíratáshoz
#include <cstring>              // Stringműveletekhez

#include "memtrace.h"           // a standard headerek után kell lennie
#include "class.h"

using std::cin;
using std::ios_base;

String::String(char ch) {
    // Meghatározzuk a hosszát
    len = 1;
    // Lefoglalunk a helyet a hossznak + a lezaró nullának
    pData = new char[len+1];
    // Betesszük a karaktert
    pData[0] = ch;
    pData[1] = '\0';
}

// Konstruktor: egy nullával lezárt char sorozatból (createStringFromCharStr)
String::String(const char *p) {
    // Meghatározzuk a hosszát
    len = strlen(p);
    // Helyet foglalunk
    pData = new char[len+1];
    // Bemásoljuk a stringet, ami le van zárva 0-val így használható az strcpy is
    strcpy(pData, p);
}

// Másoló konstruktor
String::String(const String& s1) {
    // Meghatározzuk a hosszát
    len = s1.len;
    // Helyet foglalunk
    pData = new char[len+1];
    // Bemásoljuk a stringet, ami le van zárva 0-val így használható az strcpy is
    strcpy(pData, s1.pData);
}

// operator=
String& String::operator=(const String& rhs_s) {
    if (this != &rhs_s) {
        delete[] pData;
        len = rhs_s.len;
        // Helyet foglalunk
        pData = new char[len+1];
        // Bemásoljuk a stringet, ami le van zárva 0-val így használható az strcpy is
        strcpy(pData, rhs_s.pData);
    }
    return *this;
}


bool String::operator!=(const String &s) {//egyenlőtlenség operátor
    if(this->len != s.len)//hosszokat vizsgál
        return true;
    for(int i =0;i< this->len; i++){//ha megegyeznek, akkor a betűket egyenként
       if( this->pData[i] != s.pData[i])
           return true;
    }
    return false;
}


// << operator, ami kiír az ostream-re
std::ostream& operator<<(std::ostream& os, const String& s0) {
    os << s0.c_str();
    return os;
}




