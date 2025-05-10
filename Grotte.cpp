#include "Grotte.h"
#include <iostream>

Grotte::Grotte(const string& navn, const vector<Fjende>& fjender)
    : navn(navn), fjender(fjender) {}

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