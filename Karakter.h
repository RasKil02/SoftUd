#ifndef KARAKTER_H
#define KARAKTER_H
#include <string>
using namespace std;

class Karakter {
    public:
        Karakter();
        Karakter(string, int, int);
        virtual int angreb();
        int mistHP(int skade);
        virtual string getNavn() const;
        virtual int getHP() const;
        virtual int getStyrke() const;
        void setHp(int);
        virtual ~Karakter();
    
    protected:
        string navn;
        int hp;
        int styrke;
    
    };

#endif 
