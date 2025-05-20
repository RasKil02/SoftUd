#ifndef GROTTE_H
#define GROTTE_H
#include "Fjende.h"
#include <string>
#include <vector>
#pragma message "Denne version af Grotte.h er inkluderet"
using namespace std;

class Grotte {
public:
        Grotte(const string& navn, const vector<Fjende>& fjender, int gold);
        void visFjender() const;
        std::vector<Fjende>& getFjender();
        string getNavn() const;
        int getGold() const;
        bool alleFjenderDraebt() const;

private:
    string navn;
    vector<Fjende> fjender;
    int gold;

};

#endif