#include "GameMaster.h"
#include <iostream>
#include <vector>

GameMaster::GameMaster() {}

void GameMaster::nyHero() {
    string navn;
    cout << "Indtast navn på Hero: ";
    cin >> navn;
    Hero hero(navn, 10, 2);
    heroes.push_back(hero);
}

void GameMaster::loadHero() {

    heroes.clear();

    Hero hero1("Frodo", 10, 2);
    Hero hero2("Gandalf", 12, 3);
    Hero hero3("Aragorn", 8, 4);
    Hero hero4("Legolas", 14, 1);

    heroes.push_back(hero1);
    heroes.push_back(hero2);
    heroes.push_back(hero3);
    heroes.push_back(hero4);
}

void GameMaster::startKamp(Hero& helt, Fjende& fjende) {
    if (heroes.empty()) {
        cout << "Ingen heroes tilgængelige. Opret en først!\n";
        return;
    }

    cout << "\n-- Vælg en Hero --\n";
    for (size_t i = 0; i < heroes.size(); ++i) {
        cout << i + 1 << ". " << heroes[i].getNavn()
             << " (HP: " << heroes[i].getHP() << ", Styrke: " << heroes[i].getStyrke() << ")\n";
    }

    int heroValg;
    cout << "Indtast nummeret på din Hero: ";
    cin >> heroValg;

    if (heroValg < 1 || heroValg > (int)heroes.size()) {
        cout << "Ugyldigt valg.\n";
        return;
    }

    Hero& valgtHero = heroes[heroValg - 1];

    cout << "\nDu møder en fjende: " << fjende.getNavn()
         << " (HP: " << fjende.getHP()
         << ", Styrke: " << fjende.getStyrke() << ")\n";
    cout << "\nKAMP STARTER! " << valgtHero.getNavn() << " VS " << fjende.getNavn() << "!\n";

    while (valgtHero.getHP() > 0 && fjende.getHP() > 0) {
        // Helt angriber fjenden
        int skadeTilFjende = valgtHero.angreb();
        cout << valgtHero.getNavn() << " angriber " << fjende.getNavn()
             << " med " << skadeTilFjende << " skade." << endl;
        if (fjende.mistHP(skadeTilFjende) == 0) {
            valgtHero.modtagXp(fjende.givXp());
            valgtHero.setHp(valgtHero.getMaxHp());
            cout << valgtHero.getNavn() << " vandt kampen!\n";
            break;
        }

        // Fjende angriber helten
        int skadeTilHero = fjende.angreb();
        cout << fjende.getNavn() << " angriber " << valgtHero.getNavn()
             << " med " << skadeTilHero << " skade." << endl;
        if (valgtHero.mistHP(skadeTilHero) == 0) {
            cout << fjende.getNavn() << " vandt kampen!\n";
            break;
        }
    }
}

// startGrotte funktion til 2. iteration
void GameMaster::startGrotte(Hero* aktivHero) {
    while (aktivHero != nullptr) {
        vector<Grotte> grotter = GrotteFactory::createGrotte(3, 3, aktivHero -> getLevel());

        bool iGrotte = true;
        while (iGrotte) {
            cout << "Du kan gå ind i følgende grotter: ";
            for (size_t i = 0; i < grotter.size(); i++) {
                cout << i + 1 << ". " << grotter[i].getNavn() << endl;
                // grotter[i].visFjender() << endl;      !!!kan ikke udskrive en vector!!!
            }
            cout << "0. Gå til Hovedmenu " << endl;
            
            int valg;
            cout << "Vælg grotte: " << endl;
            cin >> valg;

            if (valg == 0) {
                break;
            }

            if (valg < 1 || valg > static_cast<int>(grotter.size())) {
                cout << " Du har valgt en ugyldig grotte... Prøv igen" << endl;
                continue;;
            }

            Grotte& valgtGrotte = grotter[valg - 1];
            cout << "Du går nu ind i: " << valgtGrotte.getNavn() << endl;
            cout << "Grotten har følgende fjender: " << endl;
            valgtGrotte.visFjender();

            for (auto& fjende : valgtGrotte.getFjender()) {
                Fjende kopiAfFjende = fjende;
                startKamp(*aktivHero, kopiAfFjende);
                if (aktivHero->getHP() <= 0) {
                    cout << "Din helt er besejret! Tilbage til hovedmenu.\n";
                    return;
                }
            }
        }
    }
}

vector<Hero>& GameMaster::getHeroes() {
    return heroes;
}

GameMaster::~GameMaster() {}