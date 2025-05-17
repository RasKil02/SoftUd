#include "GrotteFactory.h"
#include <random>
#include <algorithm>

vector<Grotte> GrotteFactory::createGrotte(int antal, int fjendeAntal, int heroLevel) {
    vector<Grotte> grotter;

    vector<string> navne = {
        "The cave of Lich King",
        "The cave og Cataclysm",
        "Pandarias cave", 
        "Burning Crusades",
        "The Warlords of Dreanor",
        "Battle of Azeroth"
    };

    // Shuffle navnene, så der vælges tilfældige
    random_device rd;
    mt19937 g(rd());
    shuffle(navne.begin(), navne.end(), g);

    for (int i = 0; i < antal; ++i) {
        vector<Fjende> fjender = FjendeFactory::createFjender(heroLevel, fjendeAntal);
        string navn = navne[i % navne.size()];
        grotter.emplace_back(navn, fjender);
    }

    return grotter;
}