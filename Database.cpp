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

void Database::tilføjHero(const std::string& navn, int hp, int styrke, int level) {
    std::string sql = "INSERT INTO Hero (navn, hp, styrke, level) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, navn.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, hp);
        sqlite3_bind_int(stmt, 3, styrke);
        sqlite3_bind_int(stmt, 4, level);
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Fejl ved indsættelse af hero\n";
        }
    }   
    sqlite3_finalize(stmt);
}

void Database::tilføjHeroIgen(const Hero& hero) {
    tilføjHero(hero.getNavn(), hero.getHP(), hero.getStyrke(), hero.getLevel()); // bruger den anden funktion
}

void Database::regKamp(int heroId, int våbenId, int monsterId) {
    std::string sql = "INSERT INTO Kamp (hero_id, vaaben_id, monster_id) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, heroId);
        sqlite3_bind_int(stmt, 2, våbenId);
        sqlite3_bind_int(stmt, 3, monsterId);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Fejl ved indsættelse af kamp: " << sqlite3_errmsg(db) << "\n";
        }
    } else {
        std::cerr << "Fejl ved forberedelse af INSERT Kamp: " << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
}

void Database::visHeroesAlfabetisk() {
    std::string sql = "SELECT navn, hp, styrke, level FROM Hero ORDER BY navn ASC;";
    sqlite3_stmt* stmt;

    std::cout << "Heroes i alfabetisk rækkefølge" << std::endl;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        std::cout << "Navn\t\tHP\tStyrke\tLevel" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string navn = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            int hp = sqlite3_column_int(stmt, 1);
            int level = sqlite3_column_int(stmt, 2);
            int styrke = sqlite3_column_int(stmt, 3);
            std::cout << navn << "\t\t" << hp << "\t" << styrke << "\t" << level << std::endl;
        }
    }
    sqlite3_finalize(stmt);
}

void Database::visHeroMedFlestDrab() {
        std::string sql = R"(
        SELECT Hero.navn, COUNT(*) AS drab
        FROM Kamp
        JOIN Hero ON Hero.id = Kamp.hero_id
        GROUP BY Hero.id
        ORDER BY drab DESC;
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string navn = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            int drab = sqlite3_column_int(stmt, 1);
            std::cout << "Heroes med flest drab: " << navn << " (" << drab << " monstre)\n";
        } else {
            std::cout << "Ingen data fundet.\n";
        }
    }
    sqlite3_finalize(stmt);
}

void Database::monsterDrabPrVåben() {
    std::string heroNavn;
    std::cout << "Indtast navn på hero: ";
    std::cin >> heroNavn;

    std::string sql = R"(
        SELECT Vaaben.navn, COUNT(*) AS drab
        FROM Kamp
        JOIN Hero ON Hero.id = Kamp.hero_id
        JOIN Vaaben ON Vaaben.id = Kamp.vaaben_id
        WHERE Hero.navn = ?
        GROUP BY Vaaben.id
        ORDER BY drab DESC;
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, heroNavn.c_str(), -1, SQLITE_STATIC);

        std::cout << "Drab fordelt på våben for " << heroNavn << ":\n";
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string vaabenNavn = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            int drab = sqlite3_column_int(stmt, 1);
            std::cout << vaabenNavn << ": " << drab << " monstre\n";
        }
    } else {
        std::cerr << "Fejl i query\n";
    }
    sqlite3_finalize(stmt);
}

void Database::heroFlestDrabPrVåben() {
    std::string sql = R"(
        SELECT Vaaben.navn, Hero.navn, COUNT(*) AS drab
        FROM Kamp
        JOIN Hero ON Hero.id = Kamp.hero_id
        JOIN Vaaben ON Vaaben.id = Kamp.vaaben_id
        GROUP BY Kamp.vaaben_id, Kamp.hero_id
        HAVING COUNT(*) = (
            SELECT MAX(cnt) FROM (
                SELECT COUNT(*) AS cnt
                FROM Kamp
                WHERE Kamp.vaaben_id = Vaaben.id
                GROUP BY Kamp.hero_id
            )
        )
            ORDER BY Vaaben.navn;
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        std::cout << "Mest effektiv hero pr. våben:\n";
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string vaabenNavn = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            std::string heroNavn = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            int drab = sqlite3_column_int(stmt, 2);

            std::cout << vaabenNavn << ": " << heroNavn << " (" << drab << " drab)\n";
        }
    }
    sqlite3_finalize(stmt);
}