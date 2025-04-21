#include "Soft_1.h"

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

int GameMaster::newHero() {

}

int GameMaster::loadHero() {

}

GameMaster::~GameMaster() {}
