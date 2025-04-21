#include "Soft_1.h"

Karakter::Karakter() {};

Karakter::Karakter(string n, int h, int s) {
    navn = n;
    hp = h;
    styrke = s;
}

int Karakter::angreb() {
    int nyHP = hp - styrke;
    return nyHP;
}

int Karakter::mistHP() {

}

Karakter::~Karakter() {}