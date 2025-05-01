#pragma once
#include "Karakter.h"
using namespace std;

class Fjende : public Karakter {
    public:
        Fjende();
        Fjende(string, int, int, int);
        int givXp();
        ~Fjende();
    protected:
        int xp;
    };
    