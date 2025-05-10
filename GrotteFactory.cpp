#include "GrotteFactory.h"

vector<Grotte> GrotteFactory::createGrotte(int antal) {
    vector<Grotte> grotter;
    for (int i = 1; i <= antal; ++i) {
        string navn = "Grotte " + to_string(i);
        vector<Fjende> fjender = FjendeFactory::createFjender(1,3);
        grotter.emplace_back(navn, fjender);
    }
    return grotter;
}