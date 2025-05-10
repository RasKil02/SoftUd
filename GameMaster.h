#ifndef GAMEMASTER_H
#define GAMEMASTER_H
#include <string>
#include <vector>
#include "Fjende.h"
#include "Hero.h"
#include "FjendeFactory.h"
#include "GrotteFactory.h"
using namespace std;

class GameMaster { 
    public: 
        GameMaster();
        void nyHero();
        void loadHero();
        vector<Hero>& getHeroes();
        void startKamp();
        ~GameMaster();
    
    protected:
        vector<Hero> heroes;
        FjendeFactory fjendeFactory;
    };

#endif