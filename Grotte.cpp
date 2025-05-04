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

}

Grotte::~Grotte() {}