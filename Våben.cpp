#include "Våben.h"

Våben::Våben() {}

Våben::Våben(int s, int h, string n, int id, int sMod) {
    skade = s;
    holdbarhed = h;
    navn = n;
    this->id = id;
    styrkeMod = sMod;
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

int Våben::getId() const {
    return id;
}

void Våben::setId(int nyId) {
    id = nyId;
}

int Våben::getStyrkeMod() {
    return styrkeMod;
}

void Våben::setStyrkeMod(int mod) {
    styrkeMod = mod;
}

Våben::~Våben() {}