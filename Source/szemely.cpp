#include <iostream>
#include <fstream>
#include <cstring>
#include "szemely.hpp"
#include "telefonkonyv.hpp"
#include "memtrace.h"
Szemely::Szemely(const char* vnev, const char* knev, const char* becnev, const char* cim, const char* mhsz, const char* psz) { // Szem�ly oszt�ly konstruktora
        vezeteknev = new char[strlen(vnev) + 1];    // vezet�kn�v mem�riafoglal�s
        keresztnev = new char[strlen(knev) + 1];    // keresztn�v mem�riafoglal�s
        becenev = new char[strlen(becnev) + 1];     // becen�v mem�riafoglal�s
        this->cim = new char[strlen(cim) + 1];      // c�m mem�riafoglal�s
        munkahelyi_szam = new char[strlen(mhsz) + 1];   // munkahelyi sz�m mem�riafoglal�s
        privat_szam = new char[strlen(psz) + 1];    // priv�t sz�m mem�riafoglal�s
        // v�ltoz�k r�m�sol�sa a mem�rac�mre
        strcpy(vezeteknev, vnev);
        strcpy(keresztnev, knev);
        strcpy(becenev, becnev);
        strcpy(this->cim, cim);
        strcpy(munkahelyi_szam, mhsz);
        strcpy(privat_szam, psz);
}

Szemely::~Szemely() {
        // mem�riac�mek felszabad�t�sa
        delete[] vezeteknev;
        delete[] keresztnev;
        delete[] becenev;
        delete[] cim;
        delete[] munkahelyi_szam;
        delete[] privat_szam;
}

