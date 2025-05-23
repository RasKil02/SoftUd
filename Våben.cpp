#include "Våben.h"

Våben::Våben() {}

Våben::Våben(int s, int h, string n) {
    skade = s;
    holdbarhed = h;
    navn = n;
}

int Våben::getSkade() const {
    return skade;
}

int Våben::getHoldbarhed() const {
    return holdbarhed;
}

string Våben::getNavn() const {
    return navn;
}

void Våben::våbenBrugt() {
    if (holdbarhed > 0) {
        holdbarhed--;
    }
}

bool Våben::erØdelagt() {
    if (holdbarhed > 0) {
        return false;
    }
    return true;
}