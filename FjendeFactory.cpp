#include "FjendeFactory.h"
using namespace std;

Fjende FjendeFactory::createFjende(int heroLevel) {

    vector<string> navne;
    int styrke, xp, hp;

    if (heroLevel <= 2) {
        navne = {"Hest", "Weak Goblin", "Strong Goblin"};
    }
    else if (heroLevel <= 4) {
        navne = {"Stronger Goblin", "Den stærkeste Goblin", "Abe Kongen"}
    }
}