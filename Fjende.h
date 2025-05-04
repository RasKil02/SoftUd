#ifndef FJENDE_H
#define FJENDE_H
#include "Karakter.h"
using namespace std;

class Fjende : public Karakter {
    public:
        Fjende();
        Fjende(string, int, int, int);
        bool iLive() const;
        int givXp();
        virtual ~Fjende();
    protected:
        int xp;
    };

#endif