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

int Karakter::mistHP(int skade) {
    hp -= skade;
    if (hp <= 0)
    {
        hp = 0;
        cout << navn << " er død" << endl;
        return 0;
    }
    return hp;

}

string Karakter::getNavn() const {
    return navn;
}

int Karakter::getHP() const {
    return hp;
}

int Karakter::getStyrke() const {
    return styrke;
}

void Karakter::setHp(int nyHp) {
    hp = nyHp;
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
    Fjende f1("Hest", 4, 1, 100);
    Fjende f2("Weak Goblin", 4, 2, 200);
    Fjende f3("Strong Goblin", 8, 3, 400);
    Fjende f4("Stronger Goblin", 10, 4, 500);
    Fjende f5("Den stærkeste Goblin", 15, 5, 800);
    Fjende f6("Abe Kongen", 30, 5, 1000);
    Fjende f7("Enhjørning", 50, 8, 1500);
    Fjende f8("Drage", 100, 10, 3000);

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

    while (valgtHero.getHP() > 0 && valgtFjende.getHP() > 0) {
        // Helt angriber fjenden
        int skadeTilFjende = valgtHero.angreb();
        cout << valgtHero.getNavn() << " angriber " << valgtFjende.getNavn()
             << " med " << skadeTilFjende << " skade." << endl;
        if (valgtFjende.mistHP(skadeTilFjende) == 0) {
            cout << valgtHero.getNavn() << " vandt kampen!\n";
            break;
        }

        // Fjende angriber helten
        int skadeTilHero = valgtFjende.angreb();
        cout << valgtFjende.getNavn() << " angriber " << valgtHero.getNavn()
             << " med " << skadeTilHero << " skade." << endl;
        if (valgtHero.mistHP(skadeTilHero) == 0) {
            cout << valgtFjende.getNavn() << " vandt kampen!\n";
            break;
        }
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
    {
        level += 1;
        hp += 2;
        styrke += 1;
    }
    return level;
}

int Hero::modtagXp(int modtagXp) {
    this->xp += modtagXp;
    cout << "Du har modtaget " << xp << " XP!\n";
    while (xp >= (level * 1000)) 
    {  
        levelUp(); 
    }
    return xp;
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

Fjende::Fjende(string n, int h, int s, int xp) : Karakter(n, h, s), xp(xp) {};

int Fjende::givXp() {
    return xp;
}

Fjende::~Fjende() {}