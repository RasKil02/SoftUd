#ifndef GROTTE_H
#define GROTTE_H
#include "Fjende.h"
#include <string>
#include <vector>
using namespace std;

class Grotte {
public:
        Grotte(const string& navn, const vector<Fjende>& fjender, int gold);
        void visFjender() const;
        const vector<Fjende>& getFjender() const;
        string getNavn() const;
        int getGold() const;
        bool alleFjenderDraebt() const;

private:
    string navn;
    int gold;
    vector<Fjende> fjender;

};

#endif