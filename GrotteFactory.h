#ifndef GROTTEFACTORY_H
#define GROTTEFACTORY_H
#include "Grotte.h"
#include "FjendeFactory.h"
#include "Hero.h"

class GrotteFactory {
public:
    static Grotte createGrotte(const Hero& hero);
};


#endif