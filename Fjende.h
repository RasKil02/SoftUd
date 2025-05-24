#ifndef FJENDE_H
#define FJENDE_H
#include "Karakter.h"
using namespace std;

class Fjende : public Karakter {
    public:
        Fjende();
        Fjende(string, int, int, int, int);
        bool iLive() const;
        int givXp() const;
        int getId() const;
        void setId(int);
        virtual ~Fjende();
    protected:
        int xp;
        int id;
    };

#endif