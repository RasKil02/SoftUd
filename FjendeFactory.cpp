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


    // Vælg navn tilfældigt
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> navnDist(0, navne.size() - 1);
    std::string navn = navne[navnDist(gen)];

    // Fjenders stats baseret på Hero level
    hp = 5 * heroLevel + (rand() % 5);
    styrke = 5 * heroLevel + (rand() % 5);
    xp = heroLevel * 100 + (rand() % 100);

    return Fjende(navn, hp, styrke, xp);
}