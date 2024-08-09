#include "gtest_lite.h"

#include <iostream>
#include <fstream>
#include <cstring>

#include "szemely.hpp" // Személy osztály fejlécének beolvasása
#include "telefonkonyv.hpp" // Telefonkönyv osztály fejlécének beolvasása
#include "memtrace.h" // Memóriafoglalás nyomkövetésének beolvasása

using namespace std;
int main() {
    /// Fõ mûködés

    /* Kikpacsolva. Bemutatásnál ezt is megmutatom.*/
    Telefonkonyv tk; // Telefonkönyv objektum létrehozása
    tk.adatok_beolvasasa(tk); // Telefonkönyv adatainak beolvasása
    tk.menu(); // Telefonkönyv menüjének megjelenítése
    tk.adatok_mentese(tk); // Telefonkönyv adatainak mentése


    /// TESZT 1 Személy KonstruktorTeszt
    TEST(SzemelyTest, KonstruktorTest) { // Személy osztály konstruktorának tesztje
        const char* vnev = "Kovacs";
        const char* knev = "Gabor";
        const char* becnev = "Gabi";
        const char* cim = "Budapest";
        const char* mhsz = "+361234567";
        const char* psz = "+362345678";

        Szemely szemely(vnev, knev, becnev, cim, mhsz, psz); // Személy objektum létrehozása

        EXPECT_STREQ(vnev, szemely.getVezeteknev()); // Ellenõrzi, hogy a vezetéknév egyezik-e
        EXPECT_STREQ(knev, szemely.getKeresztnev()); // Ellenõrzi, hogy a keresztnév egyezik-e
        EXPECT_STREQ(becnev, szemely.getBecenev()); // Ellenõrzi, hogy a becenév egyezik-e
        EXPECT_STREQ(cim, szemely.getCim()); // Ellenõrzi, hogy a cím egyezik-e
        EXPECT_STREQ(mhsz, szemely.getMunkahelyiSzam()); // Ellenõrzi, hogy a munkahelyi szám egyezik-e
        EXPECT_STREQ(psz, szemely.getPrivatSzam()); // Ellenõrzi, hogy a privát szám egyezik-e
    } ENDM

    /// TESZT 2 Telefonkönyv KonstruktorTeszt
    TEST(TelefonkonyvTest, KonstruktorTest){ // Telefonkönyv osztály konstruktorának tesztje
        Telefonkonyv tk; // Telefonkönyv objektum létrehozása
        bool siker = false; // Siker jelzõ változó inicializálása hamis értékkel
        if(tk.getHead() == 0){ // Ha a lista feje nullpointer
            siker = true; // Akkor a teszt sikerült
        }
        EXPECT_TRUE(siker); // Várt eredmény: a lista feje nullpointer
        cout << endl;
    } ENDM

    /// TESZT 3 AdatokFelvételeTeszt
    TEST(TelefonkonyvTest, AdatokFelveteleTest) { // Telefonkönyv osztály adatok felvételének tesztje
        Telefonkonyv tk; // Telefonkönyv objektum létrehozása
        tk.adatok_felvetel("Kovacs", "Gabor", "Gabi", "Budapest", "+361234567", "+362345678"); // Adatok felvétele

        Telefonkonyv::Node* current = tk.getHead(); // Aktuális elem mutatója a lista elejére állítása
        EXPECT_STREQ("Kovacs", current->data->getVezeteknev()); // Ellenõrzi, hogy a vezetéknév egyezik-e
        EXPECT_STREQ("Gabor", current->data->getKeresztnev()); // Ellenõrzi, hogy a keresztnév egyezik-e
        EXPECT_STREQ("Gabi", current->data->getBecenev()); // Ellenõrzi, hogy a becenév egyezik-e
        EXPECT_STREQ("Budapest", current->data->getCim()); // Ellenõrzi, hogy a cím egyezik-e
        EXPECT_STREQ("+361234567", current->data->getMunkahelyiSzam()); // Ellenõrzi, hogy a munkahelyi szám egyezik-e
        EXPECT_STREQ("+362345678", current->data->getPrivatSzam()); // Ellenõrzi, hogy a privát szám egyezik-e

        bool siker = false; // Siker jelzõ változó inicializálása hamis értékkel
        if(tk.getHead() != 0){ // Ha a lista feje nem nullpointer
            siker = true; // Akkor a teszt sikerült
        }
        EXPECT_TRUE(siker); // Várt eredmény: a lista feje nem nullpointer
        cout << endl;
    } ENDM

    /// TESZT 4 AdatokTörléseTeszt
    TEST(TelefonkonyvTest, AdatokTorleseTest) { // Telefonkönyv osztály adatok törlésének tesztje
        Telefonkonyv tk; // Telefonkönyv objektum létrehozása
        tk.adatok_felvetel("Kovacs", "Gabor", "Gabi", "Budapest", "+361234567", "+362345678"); // Adatok felvétele
        tk.adatok_torlese("Kovacs", "Gabor"); // Adatok törlése
        bool siker = false; // Siker jelzõ változó inicializálása hamis értékkel
        if(tk.getHead() == 0){ // Ha a lista feje nullpointer
            siker = true; // Akkor a teszt sikerült
        }
        EXPECT_TRUE(siker); // Várt eredmény: a lista feje nullpointer
        cout << endl;
    } ENDM

    /// TESZT 5 AdatokKereséseTeszt
    TEST(TelefonkonyvTest, AdatokKereseseTest){ // Telefonkönyv osztály adatok keresésének tesztje
        Telefonkonyv tk; // Telefonkönyv objektum létrehozása
        tk.adatok_felvetel("Kovacs", "Gabor", "Gabi", "Budapest", "+361234567", "+362345678"); // Adatok felvétele
        tk.adatok_keresese("Kovacs", "Gabor"); // Adatok keresése
        cout << endl;
    } ENDM

    /// TESZT 6 AdatokBeolvasásaTeszt
    TEST(Telefonkonyv, AdatokBeolvasasaTeszt) { // Telefonkönyv osztály adatok beolvasásának tesztje
        Telefonkonyv tk; // Telefonkönyv objektum létrehozása
        tk.adatok_beolvasasa(tk); // Telefonkönyv adatainak beolvasása
        bool siker = false; // Siker jelzõ változó inicializálása hamis értékkel
        if(tk.getHead() != 0){ // Ha a lista feje nem nullpointer
            siker = true; // Akkor a teszt sikerült
        }
        EXPECT_TRUE(siker); // Várt eredmény: a lista feje nem nullpointer
        tk.adatok_mentese(tk); // Telefonkönyv adatainak mentése
        cout << endl;
    } ENDM

    /// TESZT 7 AdatokMentéseTeszt
    TEST(Telefonkonyv, AdatokMenteseTeszt) { // Telefonkönyv osztály adatok mentésének tesztje
        Telefonkonyv tk, teszt; // Telefonkönyv objektumok létrehozása
        tk.adatok_beolvasasa(tk); // Telefonkönyv adatainak beolvasása
        tk.adatok_felvetel("Andras", "Janos", "Jancsi", "Budapest", "+361234562", "+362345628"); // Adatok felvétele
        bool siker = false; // Siker jelzõ változó inicializálása hamis értékkel
        if(tk.getHead() != 0){ // Ha a lista feje nem nullpointer
            siker = true; // Akkor az adat felvétel sikerült
        }
        EXPECT_TRUE(siker); // Várt eredmény: a lista feje nem nullpointer
        tk.adatok_mentese(tk); // Telefonkönyv adatainak mentése

        // Fájl újra nyitása, valamint Andras Janos megkeresése, hogy sikeres volt-e a mentés.
        teszt.adatok_beolvasasa(teszt); // Teszt telefonkönyv adatainak beolvasása
        teszt.adatok_keresese("Andras", "Janos"); // Adatok keresése a teszt telefonkönyvben
        teszt.adatok_mentese(teszt); // Teszt telefonkönyv adatainak mentése
        cout << endl;
    } ENDM
	return 0;
}

