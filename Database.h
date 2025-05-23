#ifndef DATABSE_H
#define DATABSE_H
#include <sqlite3.h>
#include <vector>
#include <string>
#include "Hero.h"
#include <string>
#include <sqlite3.h>

class Database {
public:
    Database(const std::string& filnavn);
    ~Database();

    void tilføjHero(const std::string& navn, int hp, int styrke, int level);
    void tilføjHeroIgen(const Hero& hero);
    void visHeroesAlfabetisk();
    void visHeroMedFlestDrab();
    void monsterDrabPrVåben();
    void heroFlestDrabPrVåben();

private:
    sqlite3* db;
};


#endif