#include "GameMaster.h"
#include "Fjende.h"
#include "Hero.h"
#include "Karakter.h"
#include "GameMaster.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    GameMaster gm;
    gm.opretFjender(); 

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
                             << ", Styrke: " << heroes[i].getStyrke() << endl;;
                    }
                    int hvalg;
                    cout << "Indtast nummer på den hero du vil vælge: ";
                    cin >> hvalg;
                    if (hvalg >= 1 && hvalg <= heroes.size()) {
                        aktivHero = &gm.getHeroes()[hvalg - 1];
                        cout << "Hero valgt: " << aktivHero->getNavn() << endl;;
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


        while (aktivHero != nullptr) {
            aktivHero->setHp(10 + (aktivHero->getLevel() - 1) * 2);
            
            cout << "\n--- VÆLG EN FJENDE ---\n";
            const vector<Fjende>& fjender = gm.getFjender();
            for (size_t i = 0; i < fjender.size(); ++i) {
                cout << i + 1 << ". " << fjender[i].getNavn()
                     << " (HP: " << fjender[i].getHP()
                     << ", Styrke: " << fjender[i].getStyrke() << ")\n";
            }
        
            int fvalg;
            cout << "Indtast nummer på den fjende du vil kæmpe imod: ";
            cin >> fvalg;
        
            if (fvalg >= 1 && fvalg <= fjender.size()) {
                Fjende valgtFjende = fjender[fvalg - 1];
                cout << "\nKAMP STARTER! " << aktivHero->getNavn() << " VS " << valgtFjende.getNavn() << "!\n";
        
                while (aktivHero->getHP() > 0 && valgtFjende.getHP() > 0) {
                    int skadeTilFjende = aktivHero->angreb();  
                    cout << aktivHero->getNavn() << " angriber " << valgtFjende.getNavn() << " med " << skadeTilFjende << " skade!" << endl;
                    if (valgtFjende.mistHP(skadeTilFjende) == 0) {
                        cout << valgtFjende.getNavn() << " er død!" << endl;
                        aktivHero->modtagXp(valgtFjende.givXp());
                        break;
                    }
        
                    int skadeTilHero = valgtFjende.angreb();  
                    cout << valgtFjende.getNavn() << " angriber " << aktivHero->getNavn() << " med " << skadeTilHero << " skade!" << endl;
                    if (aktivHero->mistHP(skadeTilHero) == 0) {
                        cout << aktivHero->getNavn() << " er død!" << endl;
                        break;
                    }
                }
        
                if (aktivHero->getHP() > 0) {
                    cout << aktivHero->getNavn() << " vandt kampen!\n";
                } else {
                    cout << valgtFjende.getNavn() << " vandt kampen!\n";
                }
            } else {
                cout << "Ugyldigt valg af fjende.\n";
            }
        
            // Spørg om man vil fortsætte eller afslutte
            cout << "\nVil du kæmpe igen eller gå til hovedmenu?\n";
            cout << "1. Kæmp igen\n";
            cout << "2. Gå til hovedmenu\n";
            int valg;
            cin >> valg;
            if (valg == 2) {
                aktivHero = nullptr;
            }
        
        
            else {
                cout << "Ugyldigt valg af fjende.\n";
            }
        }
    }

    return 0;
}
