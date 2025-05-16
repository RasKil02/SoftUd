#include "GameMaster.h"
#include <iostream>
#include <vector>
using namespace std;


int main() {
    GameMaster gm;

    bool kører = true;
    Hero* aktivHero = nullptr;

    while (kører) {
        cout << "\n--- HOVEDMENU ---\n";
        cout << "1. Opret ny Hero\n";
        cout << "2. Load Hero\n";
        cout << "3. Afslut\n";
        cout << "Vælg en mulighed: ";

        int valg;
        cin >> valg;

        switch (valg) {
            case 1: {
                gm.nyHero();
                aktivHero = &gm.getHeroes().back();
                cout << "Hero oprettet og valgt!\n";
                break;
            }
            case 2: {
                gm.loadHero();
                const vector<Hero>& heroes = gm.getHeroes();
                if (heroes.empty()) {
                    cout << "Ingen heroes fundet.\n";
                } else {
                    cout << "\n-- Vælg en Hero --\n";
                    for (size_t i = 0; i < heroes.size(); ++i) {
                        cout << i + 1 << ". " << heroes[i].getNavn()
                             << " (HP: " << heroes[i].getHP()
                             << ", Styrke: " << heroes[i].getStyrke() << ")\n";
                    }
                    int hvalg;
                    cout << "Indtast nummer på den hero du vil vælge: ";
                    cin >> hvalg;
                    if (hvalg >= 1 && hvalg <= static_cast<size_t>(heroes.size())) {
                        aktivHero = &gm.getHeroes()[hvalg - 1];
                        cout << "Hero valgt: " << aktivHero->getNavn() << endl;
                    } else {
                        cout << "Ugyldigt valg.\n";
                    }
                }
                break;
            }
            case 3: {
                kører = false;
                cout << "Farvel!\n";
                break;
            }
            default:
                cout << "Ugyldigt valg.\n";
        }
    }

    // Hero valgt → gå ind i grotter og kæmp
    while (aktivHero != nullptr) {
        vector<Grotte> grotter = GrotteFactory::createGrotte(3, 3, aktivHero->getLevel());

        bool iGrotte = true;
        while (iGrotte) {
            cout << "\n-- Tilgængelige grotter --\n";
            for (size_t i = 0; i < grotter.size(); ++i) {
                cout << i + 1 << ". " << grotter[i].getNavn() << endl;
            }
            cout << "0. Gå til hovedmenu\n";

            int valg;
            cout << "Vælg en grotte: ";
            cin >> valg;

            if (valg == 0) {
                aktivHero = nullptr;
                break;
            }

            if (valg < 1 || valg > static_cast<int>(grotter.size())) {
                cout << "Ugyldigt valg.\n";
                continue;
            }

            Grotte& valgtGrotte = grotter[valg - 1];
            cout << "\n-- Du går ind i " << valgtGrotte.getNavn() << " --\n";
            valgtGrotte.visFjender();

            for (auto& fjende : valgtGrotte.getFjender()) {
                Fjende kopiAfFjende = fjende; 
                gm.startKamp(*aktivHero, kopiAfFjende);
                if (aktivHero->getHP() <= 0) {
                    cout << "Din helt er besejret! Tilbage til hovedmenu.\n";
                    aktivHero = nullptr;
                    iGrotte = false;
                    break;
                }
            }

            if (aktivHero != nullptr) {
                cout << "\nVil du udforske en anden grotte?\n1. Ja\n2. Gå til hovedmenu\nValg: ";
                cin >> valg;
                if (valg == 2) {
                    aktivHero = nullptr;
                    break;
                }
            }
        }
    }

    return 0;
}