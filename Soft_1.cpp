#include "Soft_1.h"
#include <iostream>
#include <fstream>
#include <sstream>

Karakter::Karakter() {}

Karakter::Karakter(string n, int h, int s) {
    navn = n;
    hp = h;
    styrke = s;
}

int Karakter::angreb() {
    return styrke;
}

int Karakter::mistHP() {
    hp -= styrke;
    if (hp <= 0)
    {
        cout << navn << " er død" << endl;
        return 0;
    }
    return hp;

}

Karakter::~Karakter() {}





GameMaster::GameMaster() {}

void GameMaster::nyHero() {
    string navn;
    cout << "Indtast navn på Hero: ";
    cin >> navn;
    Hero hero(navn, 10, 2);
    heroes.push_back(hero);
}

void GameMaster::loadHero() {
    ifstream file("Heroes.txt");
    string navn;
    int hp, styrke, level;

    while (file >> navn >> hp >> styrke >> level) 
    {
        Hero hero(navn, hp, styrke);
        heroes.push_back(hero);
    }

    file.close();
}

void GameMaster::gemHero() {
    ofstream file("Heroes.txt");

    for(Hero& h : heroes)
    {
        file << h.getNavn() << " " << h.getHP() << " " << h.getStyrke() << " " << h.getLevel() << endl;
    }
    file.close();
}

GameMaster::~GameMaster() {}






Hero::Hero() {}

Hero::Hero(string n, int h, int s) : Karakter(n, h, s) {
    xp = 0;
    level = 1;
}

int Hero::levelUp() {
    if (xp >= (level * 1000))
        level += 1;
    return level;

}

string Hero::getNavn() {
    return navn;
}

int Hero::getHP() {
    return hp;
}

int Hero::getStyrke() {
    return styrke;
}

int Hero::getLevel() {
    return level;
}
Hero::~Hero() {}




Fjende::Fjende() {}

Fjende::~Fjende() {}