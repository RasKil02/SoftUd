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
        int mistHP(int skade);
        string getNavn() const;
        int getHP() const;
        int getStyrke() const;
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
    int modtagXp(int);
    string getNavn() const;
    int getHP() const;
    int getStyrke() const;
    int getLevel() const;
    ~Hero();
private:
    int xp = 0;
    int level = 1;
};

class Fjende : public Karakter {
    public:
        Fjende();
        Fjende(string, int, int, int);
        int givXp();
        ~Fjende();
    protected:
        int xp;
    };
    

class GameMaster { 
    public: 
        GameMaster();
        void nyHero();
        void loadHero();
        void gemHero();
        void opretFjender();
        const vector<Fjende>& getFjender() const;
        vector<Hero>& getHeroes();
        void startKamp();
        ~GameMaster();
    
    protected:
        vector<Fjende> fjender;
        vector<Hero> heroes;
    };


#endif