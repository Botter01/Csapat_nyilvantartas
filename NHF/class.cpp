

#include "class.h"
#include <cstring>
#include <fstream>

Csapat* Foci_epit(){ //Foci csapatot építő függvény
std::cout<<"Írja be a football csapat nevét: ";
   char* informacio = din_beolvas();
    while(informacio == nullptr)
        informacio = din_beolvas();
String csn = String(informacio);//beolvassuk dinamikusan a csapat információit és azokat Stringé alakítjuk
Foci* uj = new Foci;//létrehozunk egy új foci csapatot
uj->setCsapat_nev(csn);//beállítjuk az információt
delete[] informacio;//és töröljük


std::cout<<"\nÍrja be a football csapat létszámát: ";
int letszam = beolvas(0, 80);//lekorlátozzuk a beírható értéket
uj->setLetszam(letszam);//beállítjuk az információt



std::cout<<"\nÍrja be a football csapatnak az első számú edzőjét: ";
    informacio = din_beolvas();
while(informacio == nullptr)
 informacio = din_beolvas();
String edzo1 = String(informacio);//beolvassuk dinamikusan a csapat információit és azokat Stringé alakítjuk
uj->setEdzo(edzo1);//beállítjuk az információt
delete[] informacio;

std::cout<<"\nÍrja be a football csapatnak a második számú edzőjét: ";
    informacio = din_beolvas();
while(informacio == nullptr){
    informacio = din_beolvas();
}
String edzo2 = String(informacio);//beolvassuk dinamikusan a csapat információit és azokat Stringé alakítjuk
uj->setMasodEdzo(edzo2);//beállítjuk az információt
delete[] informacio;

return uj;
}


Csapat* Kezi_epit(){//Kézi csapatot építő függvény
    std::cout<<"Írja be a kézilabda csapat nevét: ";
    char* informacio = din_beolvas();
    while(informacio == nullptr)
        informacio = din_beolvas();
    String csn = String(informacio);//beolvassuk dinamikusan a csapat információit és azokat Stringé alakítjuk
    Kezi* uj = new Kezi;
    uj->setCsapat_nev(csn);//beállítjuk az információt
    delete[] informacio;


    std::cout<<"\nÍrja be a kézilabda csapat létszámát: ";
    int letszam = beolvas(0, 80);//lekorlátozzuk a beírható értéket
    uj->setLetszam(letszam);



    std::cout<<"\nÍrja be a kézilabda csapatnak az edzőjét: ";
    informacio = din_beolvas();
    while(informacio == nullptr)
        informacio = din_beolvas();
    String edzo1 = String(informacio);//beolvassuk dinamikusan a csapat információit és azokat Stringé alakítjuk
    uj->setEdzo(edzo1);//beállítjuk az információt
    delete[] informacio;

    std::cout<<"\nÍrja be a kézilabda csapatnak a támogatását: ";
    int osszeg = beolvas(0, 999999999);//lekorlátozzuk a beírható értéket
    uj->setPenz(osszeg);

    return uj;
}

Csapat* Kosar_epit(){//Kosár csapatot építő függvény
    std::cout<<"Írja be a kosárlabda csapat nevét: ";
    char* informacio = din_beolvas();
    while(informacio == nullptr)
        informacio = din_beolvas();
    String csn = String(informacio);//beolvassuk dinamikusan a csapat információit és azokat Stringé alakítjuk
    Kosar* uj = new Kosar;
    uj->setCsapat_nev(csn);//beállítjuk az információt
    delete[] informacio;


    std::cout<<"\nÍrja be a kosárlabda csapat létszámát: ";
    int letszam = beolvas(0, 80);//lekorlátozzuk a beírható értéket
    uj->setLetszam(letszam);//beállítjuk az információt



    std::cout<<"\nÍrja be a kosárlabda csapatnak az edzőjét: ";
    informacio = din_beolvas();
    while(informacio == nullptr)
        informacio = din_beolvas();
    String edzo1 = String(informacio);//beolvassuk dinamikusan a csapat információit és azokat Stringé alakítjuk
    uj->setEdzo(edzo1);//beállítjuk az információt
    delete[] informacio;

    std::cout<<"\nÍrja be a pompom csapat nevét: ";
    informacio = din_beolvas();
    while(informacio == nullptr){
        informacio = din_beolvas();
    }
    String pompomn = String(informacio);//beolvassuk dinamikusan a csapat információit és azokat Stringé alakítjuk
    uj->setPompomnev(pompomn);//beállítjuk az információt
    delete[] informacio;

    std::cout<<"\nÍrja be a pompom csapat létszámát: ";
    int pompomlsz = beolvas(0, 40);//lekorlátozzuk a beírható értéket
    uj->setLetszam(pompomlsz);//beállítjuk az információt

    return uj;


}
void darabolo_f(const char* fajlnev, Lista& hetero){
    std::ifstream fajl(fajlnev);//megnyitjuk a fájlt
    if (!fajl) {
        std::cerr << "Nem sikerült a fájlt megnyitni" << std::endl;
    }
    char buffer[1024];
    while (fajl.getline(buffer, 1024)) {// sorról sorra olvas
        Foci* uj = new Foci;//létrehozzuk az adott típusú csapatot
        char* token = strtok(buffer, ":"); // darabol ":" szerint
        String csn = String(token);
        uj->setCsapat_nev(csn);
        token = strtok(nullptr, ":");
        uj->setLetszam(atoi(token));
        token = strtok(nullptr, ":");//beállítjuk a megfelelő információkat
        String edzo1 = String(token);
        uj->setEdzo(edzo1);
        token = strtok(nullptr, ":");
        String edzo2 = String(token);
        uj->setMasodEdzo(edzo2);
        hetero.add(uj);//hozzáadjuk a listánkhoz


    }

    fajl.close();
}

void darabolo_k(const char* fajlnev, Lista& hetero){
    std::ifstream fajl(fajlnev);
    if (!fajl) {
        std::cerr << "Nem sikerült a fájlt megnyitni" << std::endl;
    }
    char buffer[1024];
    while (fajl.getline(buffer, 1024)) {// sorról sorra olvas
        Kosar* uj = new Kosar;
        char* token = strtok(buffer, ":"); // darabol ":" szerint
        String csn = String(token);
        uj->setCsapat_nev(csn);
        token = strtok(nullptr, ":");
        uj->setLetszam(atoi(token));
        token = strtok(nullptr, ":");
        String edzo1 = String(token);
        uj->setEdzo(edzo1);
        token = strtok(nullptr, ":");
        String pompomn = String(token);
        uj->setPompomnev(pompomn);
        token = strtok(nullptr, ":");
        uj->setPompomlsz(atoi(token));
        hetero.add(uj);


    }

    fajl.close();
}

void darabolo_ke(const char* fajlnev, Lista& hetero){
    std::ifstream fajl(fajlnev);
    if (!fajl) {
        std::cerr << "Nem sikerült a fájlt megnyitni" << std::endl;
    }
    char buffer[1024];
    while (fajl.getline(buffer, 1024)) {// sorról sorra olvas
        Kezi* uj = new Kezi;
        char* token = strtok(buffer, ":"); // darabol ":" szerint
        String csn = String(token);
        uj->setCsapat_nev(csn);
        token = strtok(nullptr, ":");
        uj->setLetszam(atoi(token));
        token = strtok(nullptr, ":");
        String edzo1 = String(token);
        uj->setEdzo(edzo1);
        token = strtok(nullptr, ":");
        uj->setPenz(atoi(token));
        hetero.add(uj);


    }

    fajl.close();
}