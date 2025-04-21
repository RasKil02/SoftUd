#include "Soft_1.h"
#include <iostream>

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
        return ('Er død');
    return hp;

}

Karakter::~Karakter() {}



GameMaster::GameMaster() {}

void GameMaster::newHero() {
    string navn;
    cout << "Indtast navn på Hero: ";
    cin >> navn;
    Hero = Hero(navn, 10, 2);
}

void GameMaster::loadHero() {

}

GameMaster::~GameMaster() {}




Hero::Hero() {}

int Hero::levelUp() {
    int level = 1;
    if (xp >= (level * 1000))
        level += 1;
    return level;

}

Hero::~Hero() {}