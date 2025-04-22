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
    
    protected:
        string navn;
        int hp;
        int styrke;
    
    };

class Hero : public Karakter {
public:
    Hero();
    Hero(string, int, int);
    int levelUp();
    string getNavn() const;
    int getHP() const;
    int getStyrke() const;
    int getLevel() const;
    ~Hero();
private:
    int xp = 0;
    int level = 1;
};


class GameMaster { 
    public: 
        GameMaster();
        void nyHero();
        void loadHero();
        void gemHero();
        void opretFjender();
        const vector<Fjende>& getFjender() const;
        void startKamp();
        ~GameMaster();
    
    protected:
        vector<Fjende> fjender;
        vector<Hero> heroes;
    };


class Fjende : public Karakter {
public:
    Fjende();
    Fjende(string, int, int);
    string getNavn() const;
    int getHP() const;
    int getStyrke() const;
    ~Fjende();
};



#endif