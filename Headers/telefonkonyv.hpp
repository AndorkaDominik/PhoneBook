#ifndef TELEFONKONYV_HPP_INCLUDED
#define TELEFONKONYV_HPP_INCLUDED

#include "memtrace.h" // Memóriafelügyelõ fájl betöltése

class Szemely; // Személy osztály elődeklarációja

class Telefonkonyv {
public:
    struct Node { // Belsõ Node struktúra definíciója
        Szemely* data; // Személy adatokra mutató pointer
        Node* next; // Következõ Node-ra mutató pointer
    };
private:
    Node* head; // Lista elejére mutató pointer
    Node* tail; // Lista végére mutató pointer
    int count; // Lista elemeinek száma

public:
    Telefonkonyv(); // Konstruktor deklarációja

    ~Telefonkonyv(); // Destruktor deklarációja

    Node* getHead() const { // Lista elejét visszaadó getter függvény
        return head;
    }

    void adatok_felvetel(const char* vnev, const char* knev, const char* becnev, const char* cim, const char* mhsz, const char* psz); // Adatok felvétele függvény deklarációja
    void adatok_torlese(const char* vezeteknev, const char* keresztnev); // Adatok törlése függvény deklarációja
    void listaz(); // Lista kiíratása függvény deklarációja
    void adatok_keresese(const char* vezeteknev, const char* keresztnev); // Adatok keresése függvény deklarációja

    static void adatok_beolvasasa(Telefonkonyv& tk); // Adatok beolvasása statikus függvény deklarációja
    static void adatok_mentese(const Telefonkonyv& tk); // Adatok mentése statikus függvény deklarációja

    void menu(); // Menü függvény deklarációja

};

#endif // TELEFONKONYV_HPP_INCLUDED
