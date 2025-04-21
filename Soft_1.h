#ifndef SOFT_1_H
#define SOFT_1_H
#include <string>
#include <vector>
using namespace std;

class Karakter {
    public:
        Karakter();
        Karakter(string, int, int);
        int angreb();
        int mistHP();
        virtual ~Karakter();
    
    private:
        string navn;
        int hp;
        int styrke;
    
    };

class GameMaster { 
public: 
    GameMaster();
    int newHero();
    int loadHero();
    ~GameMaster();

private:
    vector<Karakter> enemies;

};

class Hero : public Karakter {
public:
    Hero();
    int levelUp();
    ~Hero();
private:
    int xp;
};

class Fjende : public Karakter {
public:
    Fjende();
    ~Fjende();
};



#endif