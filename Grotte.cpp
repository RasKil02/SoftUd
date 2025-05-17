#include "Grotte.h"
#include <iostream>

Grotte::Grotte(const string& navn, const vector<Fjende>& fjender, int goldBelønning)
    : navn(navn), fjender(fjender), gold(goldBelønning) {}

void Grotte::visFjender() const {
    for (const auto& f : fjender) {
        cout << f.getNavn() << " (HP: " << f.getHP() << ", Styrke: " << f.getStyrke() << ")\n";
    }
}

const vector<Fjende>& Grotte::getFjender() const {
    return fjender;
}

string Grotte::getNavn() const {
    return navn;
}

int Grotte::getGold() const {
    return gold;
}

bool Grotte::alleFjenderDraebt() const {
    
    for(const auto& fjende : fjender) {
        if (fjende.iLive() == true) {
            return false;
        }
    }
    return true;
}