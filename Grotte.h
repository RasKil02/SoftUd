#ifndef GROTTE_H
#define GROTTE_H
#include "Fjende.h"
#include <string>
#include <vector>
using namespace std;

class Grotte {
    public:
        Grotte();
        string getNavn() const;
        int getGold() const;
        bool alleFjenderDraebt();
        ~Grotte();

    private:
        string navn;
        int gold;
        vector<Fjende> fjender;
};

#endif