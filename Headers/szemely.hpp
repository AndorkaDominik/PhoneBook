#ifndef SZEMELY_HPP_INCLUDED
#define SZEMELY_HPP_INCLUDED

#include "telefonkonyv.hpp"

class Szemely {
private:
    char* vezeteknev; // Vezet�kn�v
    char* keresztnev; // Keresztn�v
    char* becenev; // Becen�v
    char* cim; // C�m
    char* munkahelyi_szam; // Munkahelyi sz�m
    char* privat_szam; // Priv�t sz�m
public:
    Szemely(const char* vnev, const char* knev, const char* becnev, const char* cim, const char* mhsz, const char* psz); // Konstruktor deklar�ci�
    ~Szemely(); // Destruktor deklar�ci�
    const char* getVezeteknev() const { // Vezet�kn�v lek�rdez�se
        return vezeteknev;
    }
    const char* getKeresztnev() const { // Keresztn�v lek�rdez�se
            return keresztnev;
    }
    const char* getBecenev() const { // Becen�v lek�rdez�se
            return becenev;
    }
    const char* getCim() const { // C�m lek�rdez�se
            return cim;
    }
    const char* getMunkahelyiSzam() const { // Munkahelyi sz�m lek�rdez�se
            return munkahelyi_szam;
    }
    const char* getPrivatSzam() const { // Priv�t sz�m lek�rdez�se
            return privat_szam;
    }
};

#endif // SZEMELY_HPP_INCLUDED
