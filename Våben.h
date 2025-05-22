#ifndef VÅBEN_H
#define VÅBEN_H
#include <string>
using namespace std;

class Våben {
public:
    Våben();
    Våben(int, int, string);
    int getSkade() const;
    int getHoldbarhed() const;
    string getNavn() const;
    void våbenBrugt();
    bool erØdelagt();
    ~Våben();

private:
    int skade;
    int  holdbarhed;
    string navn;

};


#endif