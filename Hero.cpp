#include "Hero.h"
#include <string>
#include <iostream>
#include <vector>

Hero::Hero(std::string navn, int hp, int styrke)
    : Karakter(navn, hp, styrke),
      xp(0),
      level(1),
      maxHp(hp),
      gold(0),
      id(-1),
      våbenId(-1) {}

Hero::Hero(std::string navn, int hp, int styrke, int lvl, int id)
    : Karakter(navn, hp, styrke),
      xp(0),
      level(lvl),
      maxHp(hp),
      gold(0),
      id(id),
      våbenId(-1) {}

int Hero::levelUp() {
    if (xp >= (level * 1000)) {
        level += 1;
        maxHp += 2;
        styrke += 1;
        hp = maxHp;
        xp = 0;
        cout << "----------------- LEVEL UP -----------------" << endl;
        cout << navn << " er steget i level og er nu i level " << level << endl;
        cout << navn << " Har nu: " << hp << " hp og " << styrke << " styrke" << endl;
    }
    return level;
}

int Hero::getXp() const {
    return xp;
}

void Hero::setXp(int nyXp) {
    xp = nyXp;
}

int Hero::modtagXp(int modtagXp) {
    xp += modtagXp;
    cout <<"Du har modtaget " << modtagXp << " XP!\n";
    cout << "Du har nu: " << xp << " xp" << endl;
    while (xp >= (level * 1000)) 
    {  
        levelUp(); 
    }
    return xp;
}

string Hero::getNavn() const {
    return navn;
}

int Hero::getHP() const {
    return hp;
}

int Hero::getStyrke() const {
    return styrke;
}

int Hero::getLevel() const {
    return level;
}

int Hero::getMaxHp() const {
    return maxHp;
}

int Hero::getGold() const {
    return gold;
}

int Hero::addGold(int mængde) {
    gold += mængde;
    return gold;
}

void Hero::setGold(int nyGold) {
    gold = nyGold;
}

int Hero::getId() const {
    return id;
}

void Hero::setId(int nyId) {
    id = nyId;
}

int Hero::getVåbenId() const {
    return våbenId;
}

void Hero::setVåbenId(int nyVåbenId) {
    våbenId = nyVåbenId;
}

void Hero::setVåben(const Våben& v) {
    aktivtVaaben = v;
    harVaaben = true;
    våbenId = v.getId();
}

const Våben* Hero::getVåben() const {
    return harVaaben ? &aktivtVaaben : nullptr;
}


Hero::~Hero() {}