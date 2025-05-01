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
        string getNavn() const;
        int getHP() const;
        int getStyrke() const;
        int getLevel() const;
        int getMaxHp() const;
        virtual ~Hero();
    private:
        int xp = 0;
        int level = 1;
        int maxHp;
    };

#endif