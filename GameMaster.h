#include <string>
#include <vector>
#include "Fjende.h"
#include "Hero.h"
using namespace std;

class GameMaster { 
    public: 
        GameMaster();
        void nyHero();
        void loadHero();
        void opretFjender();
        const vector<Fjende>& getFjender() const;
        vector<Hero>& getHeroes();
        void startKamp();
        ~GameMaster();
    
    protected:
        vector<Fjende> fjender;
        vector<Hero> heroes;
    };

