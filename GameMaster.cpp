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
    cout << "\nDu møder en fjende: " << fjende.getNavn()
         << " (HP: " << fjende.getHP()
         << ", Styrke: " << fjende.getStyrke() << ")\n";
    cout << "\nKAMP STARTER! " << helt.getNavn() << " VS " << fjende.getNavn() << "!\n";

    while (helt.getHP() > 0 && fjende.getHP() > 0) {
        int skadeTilFjende = helt.angreb();
        cout << helt.getNavn() << " angriber " << fjende.getNavn()
             << " med " << skadeTilFjende << " skade." << endl;
        if (fjende.mistHP(skadeTilFjende) == 0) {
            helt.modtagXp(fjende.givXp());
            helt.setHp(helt.getMaxHp());
            cout << helt.getNavn() << " vandt kampen!\n";
            break;
        }

        int skadeTilHero = fjende.angreb();
        cout << fjende.getNavn() << " angriber " << helt.getNavn()
             << " med " << skadeTilHero << " skade." << endl;
        if (helt.mistHP(skadeTilHero) == 0) {
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
            cout << "Du kan gå ind i følgende grotter: " << endl;;
            for (size_t i = 0; i < grotter.size(); i++) {
                cout << i + 1 << ". " << grotter[i].getNavn() << endl;
                // grotter[i].visFjender() << endl;      !!!kan ikke udskrive en vector!!!
            }
            cout << "0. Gå til Hovedmenu " << endl;
            
            int valg;
            cout << "Vælg grotte: " << endl;
            cin >> valg;

            if (valg == 0) {
                return;
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