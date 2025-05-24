#ifndef DATABSE_H
#define DATABSE_H
#include <sqlite3.h>
#include <vector>
#include <string>
#include "Hero.h"
#include <string>
#include <sqlite3.h>
using namespace std;

class Database {
public:
    Database(const std::string& filnavn);
    ~Database();

    void tilføjHero(Hero& hero);
    void regKamp(int heroId, int våbenId, int monsterId);
    vector<Hero> hentHeroes();
    void visHeroesAlfabetisk();
    void visHeroMedFlestDrab();
    void monsterDrabPrVåben();
    void heroFlestDrabPrVåben();

private:
    sqlite3* db;
};


#endif