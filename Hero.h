#ifndef HERO_H
#define HERO_H
#include "Karakter.h"
#include <string>

class Hero : public Karakter {
    public:
        Hero();
        Hero(string, int, int);
        int levelUp();
        int getXp() const;
        int modtagXp(int);
        int getLevel() const;   
        int getMaxHp() const;
        string getNavn() const override;
        int getHP() const override;
        int getStyrke() const override;
        int getGold() const; 
        int addGold(int);
        virtual ~Hero();
    private:
        int xp = 0;
        int level = 1;
        int maxHp;
        int gold = 0;
    };

#endif