#include "Fjende.h"

Fjende::Fjende() {}

Fjende::Fjende(string n, int h, int s, int xp, int id = -1) : Karakter(n, h, s), xp(xp), id(id) {};

bool Fjende::iLive() const {
    if (getHP() <= 0) {
        return false;
    }
    return true;
}

int Fjende::givXp() const {
    return xp;
}

int Fjende::getId() const {
    return id;
}

void Fjende::setId(int nyId) {
    id = nyId;
}

Fjende::~Fjende() {}