#ifndef GROTTEFACTORY_H
#define GROTTEFACTORY_H
#include "Grotte.h"
#include "FjendeFactory.h"
#include "Hero.h"

class GrotteFactory {
public:
    static vector<Grotte> createGrotte(int antal);
};


#endif