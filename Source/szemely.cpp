#include <iostream>
#include <fstream>
#include <cstring>
#include "szemely.hpp"
#include "telefonkonyv.hpp"
#include "memtrace.h"
Szemely::Szemely(const char* vnev, const char* knev, const char* becnev, const char* cim, const char* mhsz, const char* psz) { // Személy osztály konstruktora
        vezeteknev = new char[strlen(vnev) + 1];    // vezetéknév memóriafoglalás
        keresztnev = new char[strlen(knev) + 1];    // keresztnév memóriafoglalás
        becenev = new char[strlen(becnev) + 1];     // becenév memóriafoglalás
        this->cim = new char[strlen(cim) + 1];      // cím memóriafoglalás
        munkahelyi_szam = new char[strlen(mhsz) + 1];   // munkahelyi szám memóriafoglalás
        privat_szam = new char[strlen(psz) + 1];    // privát szám memóriafoglalás
        // változók rámásolása a memóracímre
        strcpy(vezeteknev, vnev);
        strcpy(keresztnev, knev);
        strcpy(becenev, becnev);
        strcpy(this->cim, cim);
        strcpy(munkahelyi_szam, mhsz);
        strcpy(privat_szam, psz);
}

Szemely::~Szemely() {
        // memóriacímek felszabadítása
        delete[] vezeteknev;
        delete[] keresztnev;
        delete[] becenev;
        delete[] cim;
        delete[] munkahelyi_szam;
        delete[] privat_szam;
}

