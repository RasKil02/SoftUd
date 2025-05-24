#ifndef HERO_H
#define HERO_H
#include "Karakter.h"
#include <string>

class Hero : public Karakter {
    public:
        Hero(std::string navn, int hp, int styrke); 
        Hero(std::string navn, int hp, int styrke, int level, int id);
        int levelUp();
        int getXp() const;
        void setXp(int);
        int modtagXp(int);
        int getLevel() const;   
        int getMaxHp() const;
        string getNavn() const override;
        int getHP() const override;
        int getStyrke() const override;
        int getGold() const; 
        int addGold(int);
        void setGold(int);
        int getId() const;
        void setId(int nyId);
        int getVåbenId() const;
        void setVåbenId(int nyVåbenId);
        virtual ~Hero();
    private:
        int xp = 0;
        int level = 1;
        int maxHp;
        int gold = 0;
        int id;
        int våbenId;
    };

#endif