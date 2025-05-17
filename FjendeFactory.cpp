#include "FjendeFactory.h"
#include <random>
using namespace std;

Fjende FjendeFactory::createFjende(int heroLevel) {
    vector<string> navne;

    if (heroLevel <= 2) {
        navne = {"Hest", "Weak Goblin", "Strong Goblin"};
    }
    else if (heroLevel <= 4) {
        navne = {"Stronger Goblin", "Den stærkeste Goblin", "Abe Kongen"};
    }
    else if (heroLevel <= 6) {
        navne = {"Enhjørning", "Drage"};
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> navnDist(0, navne.size() - 1);
    string navn = navne[navnDist(gen)];

    int baseHp = 0;
    int baseStyrke = 0;

    if (navn == "Hest") {
        baseHp = 2; baseStyrke = 1;
    } else if (navn == "Weak Goblin") {
        baseHp = 3; baseStyrke = 2;
    } else if (navn == "Strong Goblin") {
        baseHp = 4; baseStyrke = 3;
    } else if (navn == "Stronger Goblin") {
        baseHp = 5; baseStyrke = 4;
    } else if (navn == "Den stærkeste Goblin") {
        baseHp = 6; baseStyrke = 5;
    } else if (navn == "Abe Kongen") {
        baseHp = 7; baseStyrke = 6;
    } else if (navn == "Enhjørning") {
        baseHp = 8; baseStyrke = 7;
    } else if (navn == "Drage") {
        baseHp = 9; baseStyrke = 8;
    }

    int hp = baseHp + heroLevel + (rand() % 3);
    int styrke = baseStyrke + heroLevel + (rand() % 2);
    int xp = heroLevel * 80 + (rand() % 40);

    return Fjende(navn, hp, styrke, xp);
}


vector<Fjende> FjendeFactory::createFjender(int heroLevel, int antal) {
    vector<Fjende> fjender;
    for (int i = 0; i < antal; ++i) {
        fjender.push_back(createFjende(heroLevel));
    }
    return fjender;
}