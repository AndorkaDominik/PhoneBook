#ifndef SZEMELY_HPP_INCLUDED
#define SZEMELY_HPP_INCLUDED

#include "telefonkonyv.hpp"

class Szemely {
private:
    char* vezeteknev; // Vezetéknév
    char* keresztnev; // Keresztnév
    char* becenev; // Becenév
    char* cim; // Cím
    char* munkahelyi_szam; // Munkahelyi szám
    char* privat_szam; // Privát szám
public:
    Szemely(const char* vnev, const char* knev, const char* becnev, const char* cim, const char* mhsz, const char* psz); // Konstruktor deklaráció
    ~Szemely(); // Destruktor deklaráció
    const char* getVezeteknev() const { // Vezetéknév lekérdezése
        return vezeteknev;
    }
    const char* getKeresztnev() const { // Keresztnév lekérdezése
            return keresztnev;
    }
    const char* getBecenev() const { // Becenév lekérdezése
            return becenev;
    }
    const char* getCim() const { // Cím lekérdezése
            return cim;
    }
    const char* getMunkahelyiSzam() const { // Munkahelyi szám lekérdezése
            return munkahelyi_szam;
    }
    const char* getPrivatSzam() const { // Privát szám lekérdezése
            return privat_szam;
    }
};

#endif // SZEMELY_HPP_INCLUDED
