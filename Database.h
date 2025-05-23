#ifndef DATABSE_H
#define DATABSE_H
#include <sqlite3.h>
#include <vector>
#include <string>
#include "Hero.h"

#pragma once
#include <string>
#include <sqlite3.h>

class Database {
public:
    Database(const std::string& filnavn);
    ~Database();

    void tilføjHero(const std::string& navn);
    void visHeroesAlfabetisk();

private:
    sqlite3* db;
};



#endif