#ifndef HERO_H
#define HERO_H
#include "Karakter.h"
#include <string>

class Hero : public Karakter {
    public:
        Hero();
        Hero(string, int, int);
        int levelUp();
        int modtagXp(int);
        int getLevel() const;
        int getMaxHp() const;
        virtual string getNavn() const;
        virtual int getHP() const;
        virtual int getStyrke() const;
        virtual ~Hero();
    private:
        int xp = 0;
        int level = 1;
        int maxHp;
    };

#endif