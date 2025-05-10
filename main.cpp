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
                    if (hvalg >= 1 && hvalg <= heroes.size()) {
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

        // Hero valgt → gå ind i grotter og kæmp
        while (aktivHero != nullptr) {
            // Opret 2 grotter med 3 fjender hver
            vector<Grotte> grotter = GrotteFactory::createGrotte(3, 3, aktivHero->getLevel());

            for (const auto& grotte : grotter) {
                cout << "\n-- Du går ind i " << grotte.getNavn() << " --\n";
                const vector<Fjende>& fjender = grotte.getFjender();

                for (const auto& fjende : fjender) {
                    gm.startKamp(*aktivHero, fjende); 
                    if (aktivHero->getHP() <= 0) {
                        cout << "Din helt er besejret! Tilbage til hovedmenu.\n";
                        aktivHero = nullptr;
                        break;
                    }
                }

                if (aktivHero == nullptr) break;
            }

            if (aktivHero != nullptr) {
                cout << "\nVil du gå ind i flere grotter?\n";
                cout << "1. Ja\n";
                cout << "2. Gå til hovedmenu\n";
                int valg;
                cin >> valg;
                if (valg == 2) {
                    aktivHero = nullptr;
                }
            }
        }
    }

    return 0;
}