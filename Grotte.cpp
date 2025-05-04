#include "Grotte.h"

Grotte::Grotte() {}

Grotte::Grotte(string n, int g) {
    navn = n;
    gold = g;
}

string Grotte::getNavn() const {
    return navn;
}

int Grotte::getGold() const {
    return gold;
}

vector <Fjende>& Grotte::getFjender() {
    return fjender;
}

bool Grotte::alleFjenderDraebt() {
    for (Fjende& f : fjender) {
        if (f.iLive()) {
            return false;
        }

    }
    return true;
}

Grotte::~Grotte() {}