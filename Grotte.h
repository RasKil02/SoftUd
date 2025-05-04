#ifndef GROTTE_H
#define GROTTE_H
#include "Fjende.h"
#include <string>
#include <vector>
using namespace std;

class Grotte {
    public:
        Grotte();
        Grotte(string, int);
        string getNavn() const;
        int getGold() const;
        vector<Fjende>& getFjender();
        bool alleFjenderDraebt();
        ~Grotte();

    private:
        string navn;
        int gold;
        vector<Fjende> fjender;
};

#endif