#include "FjendeFactory.h"
#include <random>
using namespace std;

Fjende FjendeFactory::createFjende(int heroLevel) {

    vector<string> navne;
    int styrke, xp, hp;

    // Fjender baseret på Hero level
    if (heroLevel <= 2) {
        navne = {"Hest", "Weak Goblin", "Strong Goblin"};
    }
    else if (heroLevel <= 4) {
        navne = {"Stronger Goblin", "Den stærkeste Goblin", "Abe Kongen"};
    }
    else if (heroLevel <= 6) {
        navne = {"Enhjørning", "Drage"};
    }


    // Vælg navn tilfældigt fra vector/liste ovenover
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> navnDist(0, navne.size() - 1); // Vælger navn fra vector
    string navn = navne[navnDist(gen)];

    // Fjenders stats baseret på Hero level
    hp = 5 * heroLevel + (rand() % 5);
    styrke = 5 * heroLevel + (rand() % 5);
    xp = heroLevel * 100 + (rand() % 100);

    return Fjende(navn, hp, styrke, xp);
}

vector<Fjende> FjendeFactory::createFjender(int heroLevel, int antal) {
    vector<Fjende> fjender;
    for (int i = 0; i < antal; ++i) {
        fjender.push_back(createFjende(heroLevel));
    }
    return fjender;
}