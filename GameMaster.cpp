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

void GameMaster::startKamp(Hero& helt, Fjende fjende) {
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

    Fjende fjende = fjendeFactory.createFjende(valgtHero.getLevel());

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

vector<Hero>& GameMaster::getHeroes() {
    return heroes;
}


GameMaster::~GameMaster() {}