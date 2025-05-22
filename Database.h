#ifndef DATABSE_H
#define DATABSE_H
#include <sqlite3.h>
#include <vector>
#include <string>
#include "Hero.h"

class Database {
public:
    Database();
    void insertHero();
    vector<Hero> loadHero();
    void heroAlphapetic(); 
    int heroKills();                    // Hvor mange kills hver hero har
    int heroWeaponKills();              // Hvor mange monstre hvert våben har dræbt
    string mostHeroWeaponKills();       // For hvert våben vis hvilken ”hero” der har besejret flest monstre med dette våben

    ~Database();

private:
    sqlite3* db;
    void createTable();

};


#endif