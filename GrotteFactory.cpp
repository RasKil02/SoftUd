#include "GrotteFactory.h"
#include <random>

Grotte GrotteFactory::createGrotte(const Hero& hero) {
    vector <string> navne = {
        "The Burning Crusade Mine", "The Mines Of Wrath Of Lich King", "Cataclysm Mines"
    };

    // Random antal fjender og hvor meget gold 
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> navnDist(0, navne.size() - 1);
    uniform_int_distribution<> goldDist(50, 200); 
    uniform_int_distribution<> antalFjenderDist(2, 5);

    string navn = navne[navnDist(gen)];
    int gold = goldDist(gen);
    int antalFjender = antalFjenderDist(gen);

    Grotte grotte(navn, gold);

    for (int i = 0; i < antalFjender; ++i) {
        Fjende f = FjendeFactory::createFjende(hero.getLevel());
        grotte.getFjender().push_back(f);
    }

    return grotte;
}