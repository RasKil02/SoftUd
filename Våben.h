#ifndef VÅBEN_H
#define VÅBEN_H
#include <string>
#include <vector>
using namespace std;

class Våben {
public:
    Våben();
    Våben(int, int, string, int, int);
    int getSkade() const;
    int getHoldbarhed() const;
    string getNavn() const;
    void våbenBrugt();
    bool erØdelagt();
    int getId() const;
    void setId(int);
    int getStyrkeMod();
    void setStyrkeMod(int);
    ~Våben();

private:
    int skade;
    int holdbarhed;
    int id;
    int styrkeMod = 0;
    string navn;

};


#endif