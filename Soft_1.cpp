#include "Soft_1.h"
#include <iostream>
#include <fstream>
#include <sstream>


// Karakter klasse
Karakter::Karakter() {}

Karakter::Karakter(string n, int h, int s) {
    navn = n;
    hp = h;
    styrke = s;
}

int Karakter::angreb() {
    return styrke;
}

int Karakter::mistHP() {
    hp -= styrke;
    if (hp <= 0)
    {
        cout << navn << " er død" << endl;
        return 0;
    }
    return hp;

}

string Fjende::getNavn() const {
    return navn;
}

int Fjende::getHP() const {
    return hp;
}

int Fjende::getStyrke() const {
    return styrke;
}



Karakter::~Karakter() {}




// GameMaster klasse
GameMaster::GameMaster() {}

void GameMaster::nyHero() {
    string navn;
    cout << "Indtast navn på Hero: ";
    cin >> navn;
    Hero hero(navn, 10, 2);
    heroes.push_back(hero);
}

void GameMaster::loadHero() {
    // ifstream til at finde de gemte hereos
    ifstream file("Heroes.txt");
    string navn;
    int hp, styrke, level;

    while (file >> navn >> hp >> styrke >> level) 
    {
        Hero hero(navn, hp, styrke);
        heroes.push_back(hero);
    }

    file.close();
}

void GameMaster::gemHero() {
    // ofstream til at gemme heroes 
    ofstream file("Heroes.txt");

    for(Hero& h : heroes)
    {
        file << h.getNavn() << " " << h.getHP() << " " << h.getStyrke() << " " << h.getLevel() << endl;
    }
    file.close();
}

void GameMaster::opretFjender() {
    Fjende f1("Hest", 4, 1);
    Fjende f2("Weak Goblin", 4, 2);
    Fjende f3("Strong Goblin", 8, 3);
    Fjende f4("Stronger Goblin", 10, 4);
    Fjende f5("Den stærkeste Goblin", 15, 5);
    Fjende f6("Abe Kongen", 30, 5);
    Fjende f7("Enhjørning", 50, 8);
    Fjende f8("Drage", 100, 10);

    fjender.push_back(f1);
    fjender.push_back(f2);
    fjender.push_back(f3);
    fjender.push_back(f4);
    fjender.push_back(f5);
    fjender.push_back(f6);
    fjender.push_back(f7);
    fjender.push_back(f8);
}

void GameMaster::startKamp() {
    if (heroes.empty()) {
        cout << "Ingen heroes tilgængelige. Opret en først!\n";
        return;
    }

    cout << "\n-- Vælg en Hero --\n";
    for (size_t i = 0; i < heroes.size(); ++i) {
        cout << i + 1 << ". " << heroes[i].getNavn()
             << " (HP: " << heroes[i].getHP() << ", Styrke: " << heroes[i].getStyrke() << ")\n";
    }

    int heroValg;
    cout << "Indtast nummeret på din Hero: ";
    cin >> heroValg;

    if (heroValg < 1 || heroValg > (int)heroes.size()) {
        cout << "Ugyldigt valg.\n";
        return;
    }

    Hero& valgtHero = heroes[heroValg - 1];

    if (fjender.empty()) {
        cout << "Ingen fjender oprettet.\n";
        return;
    }

    cout << "\n-- Vælg en Fjende --\n";
    for (size_t i = 0; i < fjender.size(); ++i) {
        const Fjende& f = fjender[i];
        cout << i + 1 << ". " << f.getNavn()
             << " (HP: " << f.getHP() << ", Styrke: " << f.getStyrke() << ")\n";
    }

    int fjendeValg;
    cout << "Indtast nummeret på fjenden: ";
    cin >> fjendeValg;

    if (fjendeValg < 1 || fjendeValg > (int)fjender.size()) {
        cout << "Ugyldigt valg.\n";
        return;
    }

    Fjende& valgtFjende = fjender[fjendeValg - 1];

    cout << "\nKAMP STARTER! " << valgtHero.getNavn() << " VS " << valgtFjende.getNavn() << "!\n";

    while (valgtHero.getHP() > 0 && valgtFjende.mistHP() > 0) {
        valgtFjende.mistHP();
        valgtHero.mistHP();
    }

    if (valgtHero.getHP() > 0) {
        cout << valgtHero.getNavn() << " vandt kampen!\n";
    } else {
        cout << valgtFjende.getNavn() << " vandt kampen!\n";
    }
}

vector<Hero>& GameMaster::getHeroes() {
    return heroes;
}
GameMaster::~GameMaster() {}


// Hero klasse - Arver fra karakterklassen
Hero::Hero() {}

Hero::Hero(string n, int h, int s) : Karakter(n, h, s) {
    xp = 0;
    level = 1;
}

int Hero::levelUp() {
    if (xp >= (level * 1000))
        level += 1;
    return level;

}

string Hero::getNavn() const {
    return navn;
}

int Hero::getHP() const {
    return hp;
}

int Hero::getStyrke() const {
    return styrke;
}

int Hero::getLevel() const {
    return level;
}

const vector<Fjende>& GameMaster::getFjender() const {
    return fjender;
}

Hero::~Hero() {}



// Fjende klasse - Husk den arver fra karakter-klassen
Fjende::Fjende() {}

Fjende::Fjende(string n, int h, int s) : Karakter(n, h, s) {};

Fjende::~Fjende() {}