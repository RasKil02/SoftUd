#include "Karakter.h"
#include <iostream>
using namespace std;

Karakter::Karakter() {}

Karakter::Karakter(string n, int h, int s) {
    navn = n;
    hp = h;
    styrke = s;
}

int Karakter::angreb() {
    return styrke;
}

int Karakter::mistHP(int skade) {
    hp -= skade;
    if (hp <= 0)
    {
        hp = 0;
        cout << navn << " er død" << endl;
        return 0;
    }
    return hp;

}

string Karakter::getNavn() const {
    return navn;
}

int Karakter::getHP() const {
    return hp;
}

int Karakter::getStyrke() const {
    return styrke;
}

void Karakter::setHp(int nyHp) {
    hp = nyHp;
}

