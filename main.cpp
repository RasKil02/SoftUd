#include "Soft_1.h"
#include <iostream>
using namespace std;

int main() {

    GameMaster gm;

    int valg;
    bool kører = true;

    while (kører) {
        cout << "\n--- Hovedmenu ---" << endl;
        cout << "1. Opret ny helt" << endl;
        cout << "2. Gem helte" << endl;
        cout << "3. Indlæs helte" << endl;
        cout << "4. Afslut" << endl;
        cout << "Vælg: ";
        cin >> valg;

        switch (valg) {
            case 1:
                gm.nyHero();
                break;
            case 2:
                gm.gemHero();
                break;
            case 3:
                gm.loadHero();
                break;
            case 4:
                cout << "Farvel!" << endl;
                kører = false;
                break;
            default:
                cout << "Ugyldigt valg." << endl;
        }
    }

    return 0;


}