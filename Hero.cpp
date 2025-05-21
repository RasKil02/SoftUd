#include "Hero.h"
#include <string>
#include <iostream>
#include <vector>

Hero::Hero() {}

Hero::Hero(string n, int h, int s) : Karakter(n, h, s) {
    xp = 0;
    level = 1;
    maxHp = h;
}

int Hero::levelUp() {
    if (xp >= (level * 1000)) {
        level += 1;
        hp += 2;
        styrke += 1;
        hp = maxHp;
        xp -= level * 1000;
        cout << "----------------- LEVEL UP -----------------" << endl;
        cout << navn << " er steget i level og er nu i level " << level << endl;
        cout << navn << " Har nu: " << hp << " hp og " << styrke << " styrke" << endl;
    }
    return level;
}

int Hero::getXp() const {
    return xp;
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

Hero::~Hero() {}