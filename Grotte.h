#ifndef GROTTE_H
#define GROTTE_H
#include "Fjende.h"
#include <string>
#include <vector>
using namespace std;

class Grotte {
public:
        Grotte(const string& navn, const vector<Fjende>& fjender);
        void visFjender() const;
        const vector<Fjende>& getFjender() const;
        string getNavn() const;

private:
    string navn;
    vector<Fjende> fjender;

};

#endif