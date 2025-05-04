#include "Fjende.h"

Fjende::Fjende() {}

Fjende::Fjende(string n, int h, int s, int xp) : Karakter(n, h, s), xp(xp) {};

bool Fjende::iLive() {
    if (hp == 0) {
        return false;
    }
    return true;
}

int Fjende::givXp() {
    return xp;
}

Fjende::~Fjende() {}