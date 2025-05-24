#include "GameMaster.h"
#include "Våben.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

GameMaster::GameMaster(Database* database) : db(database) {}

void GameMaster::nyHero() {
    string navn;
    cout << "--------- Oprettelse af nu Hero ----------" << endl;
    cout << "Indtast ønskede navn på Hero: ";
    cin >> navn;
    Hero hero(navn, 10, 2); 
    heroes.emplace_back(hero);

    if (db) {
        db->tilføjHero(heroes.back());
    }
}

void GameMaster::loadHero() {

    /* heroes.clear();

    Hero hero1("Frodo", 10, 2);
    Hero hero2("Gandalf", 12, 3);
    Hero hero3("Aragorn", 8, 4);
    Hero hero4("Legolas", 14, 1);

    heroes.push_back(hero1);
    heroes.push_back(hero2);
    heroes.push_back(hero3);
    heroes.push_back(hero4); */


    heroes = db->hentHeroes();

    if (heroes.empty()) {
        std::cout << "Ingen heroes fundet i databasen.\n";
        return;
    }

    std::cout << "\n-- Vælg en Hero --\n";
    for (size_t i = 0; i < heroes.size(); ++i) {
        std::cout << i + 1 << ". " << heroes[i].getNavn()
                  << " (HP: " << heroes[i].getHP()
                  << ", Level: " << heroes[i].getLevel()
                  << ", Styrke: " << heroes[i].getStyrke()
                  << ", XP: " << heroes[i].getXp()
                  << ", Gold: " << heroes[i].getGold()
                  << ")\n";
    }

    int valg;
    std::cout << "Indtast nummer på den hero du vil vælge: ";
    std::cin >> valg;

    if (valg >= 1 && static_cast<size_t>(valg) <= heroes.size()) {
        std::cout << "Hero valgt: " << heroes[valg - 1].getNavn() << std::endl;
    } else {
        std::cout << "Ugyldigt valg.\n";
    }
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

        if (db) {
            db->regKamp(helt.getId(), helt.getVåbenId(), fjende.getId());
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

vector<Våben> muligeVåben = {
    Våben(5, 20, "Kniv", 1, 0),
    Våben(0, 10, "Pind", 2, 1),
    Våben(0, 20, "Metalrør", 3, 2),
    Våben(20, 30, "Sværd", 4, 1),
    Våben(10, 40, "Morgenstjerne", 5, 3)
};


// startGrotte funktion til 2. iteration
void GameMaster::startGrotte(Hero* aktivHero) {
    while (aktivHero != nullptr) {
        vector<Grotte> grotter = GrotteFactory::createGrotte(3, 3, aktivHero -> getLevel());

        bool iGrotte = true;
        while (iGrotte) {
            cout << "---------- Vælg Grotte ----------" << endl;
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
                Fjende& aktivFjende = fjende;
                startKamp(*aktivHero, aktivFjende);
                if (aktivHero->getHP() <= 0) {
                    cout << "Din helt er besejret! Tilbage til hovedmenu.\n";
                    return;
                }
            }

            if (valgtGrotte.alleFjenderDraebt() == true) {
                cout << "---------- Godt kæmpet ----------" << endl;
                cout << "Du har besejret alle fjender i denne grotte og modtager: " << valgtGrotte.getGold() << " gold" << endl;
                aktivHero ->addGold(valgtGrotte.getGold());
                cout << "Du har: " << aktivHero->getGold() << " gold" << endl;
                // Tildel tilfældigt våben
                int index = rand() % muligeVåben.size();
                Våben v = muligeVåben[index];

                cout << "\n🎁 Du har modtaget et nyt våben: " << v.getNavn() << endl;
                cout << "  Skade: " << v.getSkade()
                    << ", Styrke-bonus: " << v.getStyrkeMod()
                    << ", Holdbarhed: " << v.getHoldbarhed() << endl;

                aktivHero->setVåbenId(v.getId()); // gem våben-id i helten
                        }
        }
    }
}

vector<Hero>& GameMaster::getHeroes() {
    return heroes;
}

GameMaster::~GameMaster() {}