#include <iostream>
#include <fstream>
#include <cstring>
#include "szemely.hpp"
#include "telefonkonyv.hpp"

Telefonkonyv::Telefonkonyv() {
    head = nullptr; // Fejmutató inicializálása nullpointerre
    tail = nullptr; // Utolsó elem mutatójának inicializálása nullpointerre
    count = 0; // Elemek számának inicializálása 0-ra
}

Telefonkonyv::~Telefonkonyv() {
    while (head != nullptr) { // Amíg van még elem a listában
        Node* temp = head; // Ideiglenes pointer a fejmutatóra
        head = head->next; // A fejmutatót az első elem utánira állítjuk
        delete temp->data; // Az adatot felszabadítjuk
        delete temp; // A node-ot felszabadítjuk
    }
}

void Telefonkonyv::adatok_felvetel(const char* vnev, const char* knev, const char* becnev, const char* cim, const char* mhsz, const char* psz) {
    Szemely* uj_szemely = new Szemely(vnev, knev, becnev, cim, mhsz, psz); // Új személy létrehozása
    Node* uj_node = new Node; // Új node létrehozása
    uj_node->data = uj_szemely; // Node-hoz tartozó adat beállítása
    uj_node->next = nullptr; // Node következő mutatójának beállítása nullpointerre

    if (head == nullptr) { // Ha a lista üres
        head = uj_node; // Az új node lesz a lista eleje
        tail = uj_node; // Az új node lesz a lista vége
    } else { // Ha a lista nem üres
        tail->next = uj_node; // A lista utolsó elemének mutatóját az új node-ra állítjuk
        tail = uj_node; // Az új node lesz a lista vége
    }
    count++; // Elemek számának növelése
}

void Telefonkonyv::adatok_torlese(const char* vezeteknev, const char* keresztnev) {
    try {
        if (head == nullptr) { // Ha a lista üres
            std::cout << "A telefonkonyv ures." << std::endl; // Hibaüzenet
            return;
        }

        Node* current = head; // Aktuális node pointer inicializálása a lista elejére
        Node* prev = nullptr; // Előző node pointer inicializálása nullpointerre
        while (current != nullptr) { // Amíg van még elem a listában
            if (strcmp(current->data->getVezeteknev(), vezeteknev) == 0 && strcmp(current->data->getKeresztnev(), keresztnev) == 0) { // Megkeressük a megadott névvel rendelkező személyt
                if (prev == nullptr) { // Ha a törlendő elem a lista elején van
                    head = current->next; // A fejmutatót a következő elemre állítjuk
                } else { // Ha a törlendő elem nem a lista elején van
                    prev->next = current->next; // Az előző elem mutatóját az aktuális következőjére állítjuk
                }
                delete current->data; // Az adatot felszabadítjuk
                delete current; // A node-ot felszabadítjuk
                count--; // Elemek számának csökkentése
                std::cout << "Szemely sikeresen torolve." << std::endl; // Sikeres törlés üzenet
                return;
            }
            prev = current; // Az előző node pointerének beállítása az aktuális node-ra
            current = current->next; // Az aktuális node pointerének beállítása a következő elemre
        }
        throw std::runtime_error("Nem talalhato szemely ezzel a nevvel."); // Ha nem található a megadott névvel rendelkező személy, hibát dobunk
    } catch (const std::exception& e) {
        std::cerr << "Hiba a szemely torlese soran: " << e.what() << std::endl; // Hibaüzenet kiírása
    }
}

void Telefonkonyv::listaz() {
    Node* current = head; // Aktuális node pointer inicializálása a lista elejére
    while (current != nullptr) { // Amíg van még elem a listában
        std::cout << "\nNev: " << current->data->getVezeteknev() << " " << current->data->getKeresztnev() << std::endl; // Személy nevének kiírása
        std::cout << "Becenev: " << current->data->getBecenev() << std::endl; // Személy becenevének kiírása
        std::cout << "Cim: " << current->data->getCim() << std::endl; // Személy címének kiírása
        std::cout << "Munkahelyi szam: " << current->data->getMunkahelyiSzam() << std::endl; // Személy munkahelyi számának kiírása
        std::cout << "Privat szam: " << current->data->getPrivatSzam() << std::endl << std::endl; // Személy privát számának kiírása
        current = current->next; // Az aktuális node pointerének beállítása a következő elemre
    }
}
void Telefonkonyv::adatok_keresese(const char* vezeteknev, const char* keresztnev) {
    try {
        Node* current = head; // Aktuális elemre mutató pointer inicializálása a lista elejére
        while (current != nullptr) { // Amíg van még elem a listában
            if (strcmp(current->data->getVezeteknev(), vezeteknev) == 0 && strcmp(current->data->getKeresztnev(), keresztnev) == 0) { // Ellenőrzi, hogy a jelenlegi elem vezeték- és keresztnév egyezik-e a keresettel
                std::cout << "\nNev: " << current->data->getVezeteknev() << " " << current->data->getKeresztnev() << std::endl; // Kiírja a talált személy nevét
                std::cout << "Becenev: " << current->data->getBecenev() << std::endl; // Kiírja a talált személy becenevét
                std::cout << "Cim: " << current->data->getCim() << std::endl; // Kiírja a talált személy címét
                std::cout << "Munkahelyi szam: " << current->data->getMunkahelyiSzam() << std::endl; // Kiírja a talált személy munkahelyi számát
                std::cout << "Privat szam: " << current->data->getPrivatSzam() << std::endl; // Kiírja a talált személy privát számát
                return; // Kilép a függvényből, ha megtalált egyezést
            }
            current = current->next; // Lépés a következő elemre a listában
        }
        throw std::runtime_error("Nem talalhato szemely ezzel a nevvel."); // Kivétel dobása, ha nem talált megfelelő személyt
    } catch (const std::exception& e) { // Kivételkezelés, ha hiba történik a keresés során
        std::cerr << "Hiba a szemely keresese soran: " << e.what() << std::endl; // Hibaüzenet kiírása
    }
}


void Telefonkonyv::adatok_beolvasasa(Telefonkonyv& tk) {
    std::ifstream file("telefonkonyv.txt"); // Fájl megnyitása olvasásra
    try {
        if (!file.is_open()) { // Ha nem sikerült megnyitni a fájlt
            throw std::runtime_error("Nem sikerult megnyitni a fajlt."); // Kivétel dobása
        }

        std::string line; // Változó az aktuális sor tárolására
        while (std::getline(file, line)) { // Amíg van még sor a fájlban
            const char* delim = ";"; // Elválasztó karakter beállítása
            char* vezeteknev = strtok(const_cast<char*>(line.c_str()), delim); // Vezetéknév kinyerése a sorból
            char* keresztnev = strtok(nullptr, delim); // Keresztnév kinyerése a sorból
            char* becenev = strtok(nullptr, delim); // Becenév kinyerése a sorból
            char* cim = strtok(nullptr, delim); // Cím kinyerése a sorból
            char* munkahelyi_szam = strtok(nullptr, delim); // Munkahelyi szám kinyerése a sorból
            char* privat_szam = strtok(nullptr, delim); // Privát szám kinyerése a sorból

            tk.adatok_felvetel(vezeteknev, keresztnev, becenev, cim, munkahelyi_szam, privat_szam); // Felvétel a telefonkönyvbe az adott adatokkal
        }

        file.close(); // Fájl bezárása
    } catch (const std::exception& e) { // Kivételkezelés, ha hiba történik a beolvasás során
        std::cerr << "Hiba a fajl beolvasasa soran: " << e.what() << std::endl; // Hibaüzenet kiírása
        file.close(); // Biztonsági okokból bezárjuk a fájlt, ha hiba történt a try blokkban
    }
}

void Telefonkonyv::adatok_mentese(const Telefonkonyv& tk) {
    std::ofstream file("telefonkonyv.txt"); // Fájl megnyitása írásra
    try {
        if (!file.is_open()) { // Ha nem sikerült megnyitni a fájlt
            throw std::runtime_error("Nem sikerult megnyitni a fajlt."); // Kivétel dobása
        }

        Telefonkonyv::Node* current = tk.getHead(); // Aktuális elem mutatója a lista elejére állítása
        while (current != nullptr) { // Amíg van még elem a listában
            file << current->data->getVezeteknev() << ";" // Vezetéknév kiírása a fájlba
                 << current->data->getKeresztnev() << ";" // Keresztnév kiírása a fájlba
                 << current->data->getBecenev() << ";" // Becenév kiírása a fájlba
                 << current->data->getCim() << ";" // Cím kiírása a fájlba
                 << current->data->getMunkahelyiSzam() << ";" // Munkahelyi szám kiírása a fájlba
                 << current->data->getPrivatSzam() << std::endl; // Privát szám kiírása a fájlba
            current = current->next; // Lépés a következő elemre a telefonkönyvben
        }

        file.close(); // Fájl bezárása
    } catch (const std::exception& e) { // Kivételkezelés, ha hiba történik a mentés során
        std::cerr << "Hiba a fajl mentese soran: " << e.what() << std::endl; // Hibaüzenet kiírása
        file.close(); // Biztonsági okokból bezárjuk a fájlt, ha hiba történt a try blokkban
    }
}


void Telefonkonyv::menu() {
    int valasztas; // Változó az aktuális menüpont kiválasztására
    do {
        std::cout << "-------------------------------------\n";
        std::cout << "Telefonkonyv Menu:\n";
        std::cout << "1. Szemely hozzaadasa\n";
        std::cout << "2. Szemely torlese\n";
        std::cout << "3. Telefonkonyv adatainak listazasa\n";
        std::cout << "4. Kereses szemely alapjan\n";
        std::cout << "5. Mentes es Kilepes\n";
        std::cout << "-------------------------------------\n";
        std::cout << "Valassz: ";

        // Bemenet ellenőrzése és kezelése try-catch blokkal
        try {
            std::cin >> valasztas; // Bemenet olvasása
            if (std::cin.fail()) { // Ha a beolvasott érték hibás
                throw std::invalid_argument("Hibas bemenet, szamot varok, 1-tol, 5-ig."); // Kivétel dobása
            }

            switch (valasztas) { // Menüpontok kezelése switch-case szerkezetben
                case 1: { // Személy hozzáadása
                    // Személy adatainak bekérése
                    char vezeteknev[100], keresztnev[100], becenev[100], cim[100], munkahelyi_szam[100], privat_szam[100];
                    std::cout << "Vezeteknev: ";
                    std::cin.ignore();
                    std::cin.getline(vezeteknev, 100);
                    std::cout << "Keresztnev: ";
                    std::cin.getline(keresztnev, 100);
                    std::cout << "Becenev: ";
                    std::cin.getline(becenev, 100);
                    std::cout << "Cim: ";
                    std::cin.getline(cim, 100);
                    std::cout << "Munkahelyi szam: ";
                    std::cin.getline(munkahelyi_szam, 100);
                    std::cout << "Privat szam: ";
                    std::cin.getline(privat_szam, 100);
                    adatok_felvetel(vezeteknev, keresztnev, becenev, cim, munkahelyi_szam, privat_szam); // Adatok felvétele a telefonkönyvbe
                    break;
                }
                case 2: { // Személy törlése
                    // Törlendő személy adatainak bekérése
                    char vezetek[100], kereszt[100];
                    std::cout << "Adja meg a torlendo szemely vezeteknevet: ";
                    std::cin.ignore();
                    std::cin.getline(vezetek, 100);
                    std::cout << "Adja meg a torlendo szemely keresztnevet: ";
                    std::cin.getline(kereszt, 100);
                    adatok_torlese(vezetek, kereszt); // Adatok törlése a telefonkönyvből
                    break;
                }
                case 3: // Telefonkönyv adatainak listázása
                    listaz();
                    break;
                case 4: { // Keresés személy alapján
                    // Keresett személy adatainak bekérése
                    char vezeteknev_kereses[100], keresztnev_kereses[100];
                    std::cout << "Keresett vezeteknev: ";
                    std::cin.ignore();
                    std::cin.getline(vezeteknev_kereses, 100);
                    std::cout << "Keresett keresztnev: ";
                    std::cin.getline(keresztnev_kereses, 100);
                    adatok_keresese(vezeteknev_kereses, keresztnev_kereses); // Adatok keresése és kiíratása
                    break;
                }
                case 5: // Mentes és kilépés
                    std::cout << "Mentes es kilepes...\n";
                    break;
                default: // Érvénytelen választás esetén
                    std::cout << "Ervenytelen valasztas.\n";
            }
        } catch (const std::invalid_argument& e) { // Kivételkezelés, ha hibás a bemenet
            std::cerr << e.what() << std::endl; // Hibaüzenet kiírása
            std::cin.clear(); // Hibajelző bit törlése
            std::cin.ignore(200, '\n'); // Bemeneti puffer kiürítése
        }
    } while (valasztas != 5); // A ciklus addig fut, amíg a felhasználó kilépés mellett nem dönt
}
