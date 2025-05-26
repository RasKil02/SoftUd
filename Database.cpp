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

void Database::tilføjHero(Hero& hero) {
    std::string sql = "INSERT INTO Hero (navn, hp, level, styrke, gold) VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, hero.getNavn().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, hero.getHP());
        sqlite3_bind_int(stmt, 3, hero.getLevel());
        sqlite3_bind_int(stmt, 4, hero.getStyrke());
        sqlite3_bind_int(stmt, 5, hero.getGold());

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            int lastId = sqlite3_last_insert_rowid(db);
            hero.setId(lastId);  // Sæt ID'et på Hero-objektet
            std::cout << "Hero tilføjet med ID: " << lastId << "\n";
        } else {
            std::cerr << "Fejl ved indsættelse af hero: " << sqlite3_errmsg(db) << "\n";
        }
    } else {
        std::cerr << "Fejl ved forberedelse af INSERT: " << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
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

std::vector<Hero> Database::hentHeroes() {
    std::vector<Hero> heroes;

    std::string sql = "SELECT id, navn, hp, styrke, level, xp, gold FROM Hero;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            std::string navn = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            int hp = sqlite3_column_int(stmt, 2);
            int styrke = sqlite3_column_int(stmt, 3);
            int level = sqlite3_column_int(stmt, 4);
            int xp = sqlite3_column_int(stmt, 5);
            int gold = sqlite3_column_int(stmt, 6);

            Hero hero(navn, hp, styrke, level, id);
            hero.setXp(xp);
            hero.setGold(gold);
            heroes.push_back(hero);
        }
    } else {
        std::cerr << "Fejl ved hentning af heroes: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    return heroes;
}

void Database::opdaterHeroes(const Hero& hero) {
    std::string sql = "UPDATE Hero SET hp = ?, styrke = ?, level = ?, xp = ?, gold = ?, vaaben_id = ? WHERE id = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, hero.getHP());
        sqlite3_bind_int(stmt, 2, hero.getStyrke());
        sqlite3_bind_int(stmt, 3, hero.getLevel());
        sqlite3_bind_int(stmt, 4, hero.getXp());
        sqlite3_bind_int(stmt, 5, hero.getGold());
        sqlite3_bind_int(stmt, 6, hero.getVåbenId());
        sqlite3_bind_int(stmt, 7, hero.getId());

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Fejl ved opdatering af hero: " << sqlite3_errmsg(db) << "\n";
        }
    } else {
        std::cerr << "Fejl ved forberedelse af UPDATE Hero: " << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
}

int Database::getMonsterId(const string& monsterNavn) {
    std::string sql = "SELECT id FROM Monster WHERE navn = ?;";
    sqlite3_stmt* stmt;
    int monsterId = -1;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, monsterNavn.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            monsterId = sqlite3_column_int(stmt, 0);
        }
    }

    sqlite3_finalize(stmt);
    return monsterId;
}

void Database::tilføjVaaben(const Våben& v) {
    std::string sql = "INSERT INTO Vaaben (navn) VALUES (?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, v.getNavn().c_str(), -1, SQLITE_STATIC);
        if (sqlite3_step(stmt) == SQLITE_DONE) {
            int id = sqlite3_last_insert_rowid(db);
            const_cast<Våben&>(v).setId(id);  // kun acceptabelt fordi vi lige har lavet objektet
        } else {
            std::cerr << "Fejl ved indsættelse af våben: " << sqlite3_errmsg(db) << "\n";
        }
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