#ifndef SOFT_1.H
#define SOFT_1.H
#include <string>
#include <vector>
using namespace std;

class Karakter {
    public:
        Karakter();
        Karakter(string, int, int);
        int angreb();
        int mistHP();
        ~Karakter();
    
    private:
        string name;
        int hp;
        int styrke;
    
    };

class GameMaster { 
public: 
    GameMaster();
    int startGame();
    int newHero();
    int loadHero();
    ~GameMaster();

private:
    vector<Karakter> enemies;

};

class Hero : Karakter {
public:
    Hero();
    int levelUp();
    ~Hero();
private:
    int xp;
};

class Fjende : Karakter {
public:

private:
};



#endif