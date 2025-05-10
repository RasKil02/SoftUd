#include "GrotteFactory.h"

vector<Grotte> GrotteFactory::createGrotte(int antal, int fjendeAntal, int heroLevel) {
    vector<Grotte> grotter;
    for (int i = 1; i <= antal; ++i) {
        string navn = "Grotte " + to_string(i + 1);
        vector<Fjende> fjender = FjendeFactory::createFjender(heroLevel, fjendeAntal);

        Grotte grotte(navn, fjender);
        grotter.push_back(grotte);
    }
    return grotter;
}