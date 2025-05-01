#pragma once
#include "Fjende.h"

Fjende::Fjende() {}

Fjende::Fjende(string n, int h, int s, int xp) : Karakter(n, h, s), xp(xp) {};

int Fjende::givXp() {
    return xp;
}

Fjende::~Fjende() {}