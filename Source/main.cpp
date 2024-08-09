#include "gtest_lite.h"

#include <iostream>
#include <fstream>
#include <cstring>

#include "szemely.hpp" // Szem�ly oszt�ly fejl�c�nek beolvas�sa
#include "telefonkonyv.hpp" // Telefonk�nyv oszt�ly fejl�c�nek beolvas�sa
#include "memtrace.h" // Mem�riafoglal�s nyomk�vet�s�nek beolvas�sa

using namespace std;
int main() {
    /// F� m�k�d�s

    /* Kikpacsolva. Bemutat�sn�l ezt is megmutatom.*/
    Telefonkonyv tk; // Telefonk�nyv objektum l�trehoz�sa
    tk.adatok_beolvasasa(tk); // Telefonk�nyv adatainak beolvas�sa
    tk.menu(); // Telefonk�nyv men�j�nek megjelen�t�se
    tk.adatok_mentese(tk); // Telefonk�nyv adatainak ment�se


    /// TESZT 1 Szem�ly KonstruktorTeszt
    TEST(SzemelyTest, KonstruktorTest) { // Szem�ly oszt�ly konstruktor�nak tesztje
        const char* vnev = "Kovacs";
        const char* knev = "Gabor";
        const char* becnev = "Gabi";
        const char* cim = "Budapest";
        const char* mhsz = "+361234567";
        const char* psz = "+362345678";

        Szemely szemely(vnev, knev, becnev, cim, mhsz, psz); // Szem�ly objektum l�trehoz�sa

        EXPECT_STREQ(vnev, szemely.getVezeteknev()); // Ellen�rzi, hogy a vezet�kn�v egyezik-e
        EXPECT_STREQ(knev, szemely.getKeresztnev()); // Ellen�rzi, hogy a keresztn�v egyezik-e
        EXPECT_STREQ(becnev, szemely.getBecenev()); // Ellen�rzi, hogy a becen�v egyezik-e
        EXPECT_STREQ(cim, szemely.getCim()); // Ellen�rzi, hogy a c�m egyezik-e
        EXPECT_STREQ(mhsz, szemely.getMunkahelyiSzam()); // Ellen�rzi, hogy a munkahelyi sz�m egyezik-e
        EXPECT_STREQ(psz, szemely.getPrivatSzam()); // Ellen�rzi, hogy a priv�t sz�m egyezik-e
    } ENDM

    /// TESZT 2 Telefonk�nyv KonstruktorTeszt
    TEST(TelefonkonyvTest, KonstruktorTest){ // Telefonk�nyv oszt�ly konstruktor�nak tesztje
        Telefonkonyv tk; // Telefonk�nyv objektum l�trehoz�sa
        bool siker = false; // Siker jelz� v�ltoz� inicializ�l�sa hamis �rt�kkel
        if(tk.getHead() == 0){ // Ha a lista feje nullpointer
            siker = true; // Akkor a teszt siker�lt
        }
        EXPECT_TRUE(siker); // V�rt eredm�ny: a lista feje nullpointer
        cout << endl;
    } ENDM

    /// TESZT 3 AdatokFelv�teleTeszt
    TEST(TelefonkonyvTest, AdatokFelveteleTest) { // Telefonk�nyv oszt�ly adatok felv�tel�nek tesztje
        Telefonkonyv tk; // Telefonk�nyv objektum l�trehoz�sa
        tk.adatok_felvetel("Kovacs", "Gabor", "Gabi", "Budapest", "+361234567", "+362345678"); // Adatok felv�tele

        Telefonkonyv::Node* current = tk.getHead(); // Aktu�lis elem mutat�ja a lista elej�re �ll�t�sa
        EXPECT_STREQ("Kovacs", current->data->getVezeteknev()); // Ellen�rzi, hogy a vezet�kn�v egyezik-e
        EXPECT_STREQ("Gabor", current->data->getKeresztnev()); // Ellen�rzi, hogy a keresztn�v egyezik-e
        EXPECT_STREQ("Gabi", current->data->getBecenev()); // Ellen�rzi, hogy a becen�v egyezik-e
        EXPECT_STREQ("Budapest", current->data->getCim()); // Ellen�rzi, hogy a c�m egyezik-e
        EXPECT_STREQ("+361234567", current->data->getMunkahelyiSzam()); // Ellen�rzi, hogy a munkahelyi sz�m egyezik-e
        EXPECT_STREQ("+362345678", current->data->getPrivatSzam()); // Ellen�rzi, hogy a priv�t sz�m egyezik-e

        bool siker = false; // Siker jelz� v�ltoz� inicializ�l�sa hamis �rt�kkel
        if(tk.getHead() != 0){ // Ha a lista feje nem nullpointer
            siker = true; // Akkor a teszt siker�lt
        }
        EXPECT_TRUE(siker); // V�rt eredm�ny: a lista feje nem nullpointer
        cout << endl;
    } ENDM

    /// TESZT 4 AdatokT�rl�seTeszt
    TEST(TelefonkonyvTest, AdatokTorleseTest) { // Telefonk�nyv oszt�ly adatok t�rl�s�nek tesztje
        Telefonkonyv tk; // Telefonk�nyv objektum l�trehoz�sa
        tk.adatok_felvetel("Kovacs", "Gabor", "Gabi", "Budapest", "+361234567", "+362345678"); // Adatok felv�tele
        tk.adatok_torlese("Kovacs", "Gabor"); // Adatok t�rl�se
        bool siker = false; // Siker jelz� v�ltoz� inicializ�l�sa hamis �rt�kkel
        if(tk.getHead() == 0){ // Ha a lista feje nullpointer
            siker = true; // Akkor a teszt siker�lt
        }
        EXPECT_TRUE(siker); // V�rt eredm�ny: a lista feje nullpointer
        cout << endl;
    } ENDM

    /// TESZT 5 AdatokKeres�seTeszt
    TEST(TelefonkonyvTest, AdatokKereseseTest){ // Telefonk�nyv oszt�ly adatok keres�s�nek tesztje
        Telefonkonyv tk; // Telefonk�nyv objektum l�trehoz�sa
        tk.adatok_felvetel("Kovacs", "Gabor", "Gabi", "Budapest", "+361234567", "+362345678"); // Adatok felv�tele
        tk.adatok_keresese("Kovacs", "Gabor"); // Adatok keres�se
        cout << endl;
    } ENDM

    /// TESZT 6 AdatokBeolvas�saTeszt
    TEST(Telefonkonyv, AdatokBeolvasasaTeszt) { // Telefonk�nyv oszt�ly adatok beolvas�s�nak tesztje
        Telefonkonyv tk; // Telefonk�nyv objektum l�trehoz�sa
        tk.adatok_beolvasasa(tk); // Telefonk�nyv adatainak beolvas�sa
        bool siker = false; // Siker jelz� v�ltoz� inicializ�l�sa hamis �rt�kkel
        if(tk.getHead() != 0){ // Ha a lista feje nem nullpointer
            siker = true; // Akkor a teszt siker�lt
        }
        EXPECT_TRUE(siker); // V�rt eredm�ny: a lista feje nem nullpointer
        tk.adatok_mentese(tk); // Telefonk�nyv adatainak ment�se
        cout << endl;
    } ENDM

    /// TESZT 7 AdatokMent�seTeszt
    TEST(Telefonkonyv, AdatokMenteseTeszt) { // Telefonk�nyv oszt�ly adatok ment�s�nek tesztje
        Telefonkonyv tk, teszt; // Telefonk�nyv objektumok l�trehoz�sa
        tk.adatok_beolvasasa(tk); // Telefonk�nyv adatainak beolvas�sa
        tk.adatok_felvetel("Andras", "Janos", "Jancsi", "Budapest", "+361234562", "+362345628"); // Adatok felv�tele
        bool siker = false; // Siker jelz� v�ltoz� inicializ�l�sa hamis �rt�kkel
        if(tk.getHead() != 0){ // Ha a lista feje nem nullpointer
            siker = true; // Akkor az adat felv�tel siker�lt
        }
        EXPECT_TRUE(siker); // V�rt eredm�ny: a lista feje nem nullpointer
        tk.adatok_mentese(tk); // Telefonk�nyv adatainak ment�se

        // F�jl �jra nyit�sa, valamint Andras Janos megkeres�se, hogy sikeres volt-e a ment�s.
        teszt.adatok_beolvasasa(teszt); // Teszt telefonk�nyv adatainak beolvas�sa
        teszt.adatok_keresese("Andras", "Janos"); // Adatok keres�se a teszt telefonk�nyvben
        teszt.adatok_mentese(teszt); // Teszt telefonk�nyv adatainak ment�se
        cout << endl;
    } ENDM
	return 0;
}

