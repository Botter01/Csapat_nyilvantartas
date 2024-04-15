
#ifndef NHF_CLASS_H
#define NHF_CLASS_H
#include <iostream>
#include "beolvas.h"
#include "menu.h"




class String {
    char *pData;    ///< pointer az adatra
    size_t len;     ///< hossz lezáró nulla nélkül
public:


    /// Hossz lekérdezése.
    /// @return Sztring hossza
    size_t size() const { return len; }

    /// C-sztringet ad vissza
    /// @return pinter egy '\0'-val lezárt (C) sztringre
    const char* c_str() const { return pData;}

    /// Konstruktor egy nullával lezárt char sorozatból
    /// Ez a deafault is!
    /// @param p - pointer egy C sztringre
    String(const char *p = "");


    /// Konstruktor egy char karakterből
    /// @param ch - karakter
    String(char ch);


    /// Másoló konstruktor
    /// @param s1 - String, amiből létrehozzuk az új String-et
    String(const String& s1);

    /// Destruktor
     ~String() { delete[] pData; }


    /// Értékadó operátor.
    /// @param rhs_s - jobboldali String
    /// @return baoldali (módosított) string (referenciája)
    String& operator=(const String& rhs_s);

    bool operator!=(const String& s);



};

/// Globális függvények:
/// kiír az ostream-re
/// @param os - ostream típusú objektum
/// @param s0 - String, amit kiírunk
/// @return os
std::ostream& operator<<(std::ostream& os, const String& s0);

/// Beolvas az istream-ről egy szót egy string-be.
/// @param is - istream típusú objektum
/// @param s0 - String, amibe beolvas
/// @return is
std::istream& operator>>(std::istream& is, String& s0);



class Csapat{
protected:
    String csapat_nev;
    int letszam;
    String edzo;
public:
    Csapat(const String& cs_nev, int lsz, const String& nev): csapat_nev(cs_nev),  letszam(lsz), edzo(nev) {}
    virtual ~Csapat() {}

    void setCsapat_nev(const String& csn){
        csapat_nev = csn;
    }

    void setLetszam(int lsz){
        letszam = lsz;
    }
    void setEdzo(const String& e){
        edzo = e;
    }

    int getLetszam() const{
        return this->letszam;
    }
    String getEdzo()const{
        return this->edzo;
    }

    String getCsapat_nev()const{
        return this->csapat_nev;
    }
    virtual void kilistaz() = 0;//virtuális kilistaz() függvény
    virtual int getTag()=0;//virtuális getTag(), mivel az ősosztálynak nincsen tag-je
};


struct Listaelem{
    Csapat* csapat;
    Listaelem* kov;
};

class Lista{//heterogén class leírása
    Listaelem* eleje;
public:
    void add(Csapat* uj){//listába fűző függvény

        if(uj == nullptr){
             return;
        }
        Listaelem* uje = new Listaelem;//új listaelem
        uje->csapat = uj;//csapat részébe belerakjuk az új csapatot
        uje->kov = nullptr;//következő pointere nullptr

        if(eleje == nullptr){//ha üres a lista
            eleje = uje;
        }
        else{//ha nem üres a végére fűzzük
            Listaelem*  mozgo = eleje;
            while(mozgo->kov != nullptr)
                mozgo = mozgo->kov;

            mozgo->kov = uje;
        }
    }

    void torol(){//listából törlő függvény
        std::cout<<"Adja meg a törlendő csapat nevét: ";//név alapján törlünk
        char* torlendo = din_beolvas();
        while(torlendo == nullptr)
            torlendo = din_beolvas();
        String torlendocs = String(torlendo);//dinamikusan beolvassuk a csapat nevét és Stringé alakítjuk
        delete torlendo;

        Listaelem* lemarado = nullptr;
        Listaelem*  mozgo = eleje;

        while (mozgo != nullptr && mozgo->csapat->getCsapat_nev() != torlendocs) {//lépünk a listában ha nem találjuk
            lemarado = mozgo;
            mozgo = mozgo->kov;
        }
        if (mozgo == nullptr) {//ha üres a lista

        } else if (lemarado == nullptr) {//ha a végéről törlünk
            Listaelem *ujeleje = mozgo->kov;
            delete mozgo;
            eleje = ujeleje;
        } else {//ha a közepéről törlünk
            lemarado->kov = mozgo->kov;
            delete mozgo;
        }


    }

    void hetero_kiir(int tag){//csapatokat kiíró függvény
        Listaelem*  mozgo = eleje;
        while (mozgo != nullptr){//az egész listán végig megyünk
            if(mozgo->csapat->getTag() == tag)//ha megtalálja a megfelelő típusú csapatot
                mozgo->csapat->kilistaz();//meghívja a kilistaz() függvényét

            mozgo = mozgo->kov;
        }
        delete mozgo;
    }

    Listaelem* getLista()const {return eleje;}

    Lista() {//heterogén lista konstruktora
        eleje = nullptr;
    }

    ~Lista(){//heterogén lista destruktora
        Listaelem* i = eleje;
        while(i != nullptr){
            Listaelem* tmp = i;
            delete i->csapat;
            i = i->kov;
            delete tmp;

        }

    }

};



class Foci : public Csapat{
private:
    String masodedzo;
    int tag = 1;
public:

    Foci(const String& cs_nev = "", int lsz = 0, const String& nev1 = "", const String& nev2 = ""): Csapat(cs_nev, lsz, nev1), masodedzo(nev2){}
    ~Foci() {}

    void setMasodEdzo(const String& e){this->masodedzo = e;}
    String getMasodEdzo()const{
        return this->masodedzo;
    }
    int getTag(){
        return this->tag;
    }
    void kilistaz(){
        std::cout<<"Csapat név: "<< csapat_nev<<std::endl;
        std::cout<<"Csapat létszáma: "<< letszam<<std::endl;
        std::cout<<"Edző neve: "<< edzo<<std::endl;
        std::cout<<"Másodedző neve: "<< masodedzo<<std::endl;
        std::cout<<"\n";
    }

};

class Kezi : public Csapat{
private:
    int penz;
    int tag = 2;
public:
    Kezi(const String& cs_nev = "", int lsz=0, const String& nev1="", int p =0): Csapat(cs_nev, lsz, nev1), penz(p){}
    ~Kezi() {}

    void setPenz(int p){
        this->penz=p;
    }
    int getPenz()const{
        return this->penz;
    }

    int getTag() {
        return this->tag;
    }
    void kilistaz(){
        std::cout<<"Csapat név: "<< csapat_nev<<std::endl;
        std::cout<<"Csapat létszáma: "<< letszam<<std::endl;
        std::cout<<"Edző neve: "<< edzo<<std::endl;
        std::cout<<"Csapat támogatása: "<< penz<<" Ft" <<std::endl;
        std::cout<<"\n";
    }

};

class Kosar : public Csapat{
private:
    int pompomlsz;
    String pompomnev;
    int tag = 3;
public:
    Kosar(const String& cs_nev="", int lsz=0, const String& nev1="", int pl=0,const String& pn =""): Csapat(cs_nev, lsz, nev1), pompomlsz(pl), pompomnev(pn){}
    ~Kosar() {}

    void setPompomlsz(int plsz){
        this->pompomlsz = plsz;
    }

    void setPompomnev(const String& pn){
        this->pompomnev = pn;
    }

    int getPompomlsz()const{
        return this->pompomlsz;
    }
    String getPompomnev() const {
        return this->pompomnev;
    }
    int getTag() {
        return this->tag;
    }

    void kilistaz(){
        std::cout<<"Csapat név: "<< csapat_nev<<std::endl;
        std::cout<<"Csapat létszáma: "<< letszam<<std::endl;
        std::cout<<"Edző neve: "<< edzo<<std::endl;
        std::cout<<"Pompom csapat neve: "<< pompomnev<<std::endl;
        std::cout<<"Pompom csapat létszáma: "<<pompomlsz << std::endl;
        std::cout<<"\n";
    }

};

Csapat* Foci_epit();
Csapat* Kezi_epit();
Csapat* Kosar_epit();
void darabolo_f(const char* fajlnev, Lista& hetero);
void darabolo_ke(const char* fajlnev, Lista& hetero);
void darabolo_k(const char* fajlnev, Lista& hetero);

#endif //NHF_CLASS_H
