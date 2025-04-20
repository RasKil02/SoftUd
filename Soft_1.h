#ifndef SOFT_1.H
#define SOFT_1.H
#include <string>
#include <vector>
using namespace std;

class Character {
    public:
        Character();
        int attack();
        int looseHP();
        ~Character();
    
    private:
        string name;
        int hp;
        int styrke;
    
    };

class GameMaster{
public: 
    GameMaster();
    int startGame();
    int newHero();
    int loadHero();
    ~GameMaster();

private:
    vector<Character> enemies;

};


#endif