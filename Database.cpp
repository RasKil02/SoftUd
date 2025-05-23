#include "Database.h"
#include <iostream>

Database::Database(const std::string& filnavn) {
    if (sqlite3_open(filnavn.c_str(), &db)) {
        std::cerr << "Kunne ikke åbne database: " << sqlite3_errmsg(db) << std::endl;
    }
}

Database::~Database() {
    sqlite3_close(db);
}

void Database::tilføjHero(const std::string& navn) {
    std::string sql = "INSERT INTO Hero (navn) VALUES (?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, navn.c_str(), -1, SQLITE_STATIC);
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Fejl ved indsættelse af hero\n";
        }
    }
    sqlite3_finalize(stmt);
}

void Database::visHeroesAlfabetisk() {
    std::string sql = "SELECT navn FROM Hero ORDER BY navn ASC;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char* navn = sqlite3_column_text(stmt, 0);
            std::cout << navn << std::endl;
        }
    }
    sqlite3_finalize(stmt);
}
