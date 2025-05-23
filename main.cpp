#include "GameMaster.h"
#include "Hero.h"
#include "Fjende.h"
#include "Database.h"
#include <iostream>
#include <vector>
using namespace std;


int main() {
    Database db("spil.db"); // Opretter og åbner forbindelsen
    GameMaster gm(&db);     // Sender databasen til GameMaster

    bool kører = true;
    Hero* aktivHero = nullptr;

    while (kører) {
        cout << "\n--- HOVEDMENU ---\n";
        cout << "1. Opret ny Hero\n";
        cout << "2. Load Hero\n";
        cout << "3. Afslut\n";
        cout << "4. Se analyse\n";
        cout << "Vælg en mulighed: ";

        int valg;
        cin >> valg;

        switch (valg) {
            case 1: {
                gm.nyHero();
                aktivHero = &gm.getHeroes().back();
                cout << "Hero oprettet og valgt!\n";
                gm.startGrotte(aktivHero);
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
                    if (hvalg >= 1 && static_cast<size_t>(hvalg) <= heroes.size()) {
                        aktivHero = &gm.getHeroes()[hvalg - 1];
                        cout << "Hero valgt: " << aktivHero->getNavn() << endl;
                    } else {
                        cout << "Ugyldigt valg.\n";
                    }

                    gm.startGrotte(aktivHero);
                }
                break;
            }
            case 3: {
                kører = false;
                cout << "Farvel!\n";
                break;
            }
            
            case 4: {
                cout << "--- Analyse ---\n\n";
                cout << "1. Vis heroes i alfabetisk rækkefølge\n";
                cout << "2. Hero med flest drab\n";
                cout << "3. Monsterdrab pr. våben for en valgt hero\n";
                cout << "4. Mest effektiv hero pr. våben\n";
                cout << "Vælg en mulighed: ";

                int analyseValg;
                cin >> analyseValg;

                switch (analyseValg) {
                    case 1:
                        db.visHeroesAlfabetisk();
                        break;
                    case 2:
                        db.visHeroMedFlestDrab();
                        break;
                    case 3:
                        db.monsterDrabPrVåben();
                        break;
                    case 4:
                        db.heroFlestDrabPrVåben();;
                        break;
                    default:
                        cout << "Ugyldigt analysevalg.\n";
                    }
                break;
            }
            
            default:
                cout << "Ugyldigt valg.\n";
        }
        
    }
    
    return 0;
}