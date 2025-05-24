#ifndef VÅBEN_H
#define VÅBEN_H
#include <string>
using namespace std;

class Våben {
public:
    Våben();
    Våben(int, int, string, int);
    int getSkade() const;
    int getHoldbarhed() const;
    string getNavn() const;
    void våbenBrugt();
    bool erØdelagt();
    int getId() const;
    void setId(int);
    ~Våben();

private:
    int skade;
    int holdbarhed;
    int id;
    string navn;

};


#endif