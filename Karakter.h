#include <string>
using namespace std;

class Karakter {
    public:
        Karakter();
        Karakter(string, int, int);
        int angreb();
        int mistHP(int skade);
        string getNavn() const;
        int getHP() const;
        int getStyrke() const;
        void setHp(int);
        virtual ~Karakter();
    
    protected:
        string navn;
        int hp;
        int styrke;
    
    };
