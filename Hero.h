#pragma once
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
        ~Hero();
    private:
        int xp = 0;
        int level = 1;
        int maxHp;
    };