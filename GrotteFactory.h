#ifndef GROTTEFACTORY_H
#define GROTTEFACTORY_H
#include "Grotte.h"
#include "FjendeFactory.h"
#include "Hero.h"
#include <vector>

class GrotteFactory {
public:
    static vector<Grotte> createGrotte(int antal, int fjendeAntal, int heroLevel);
};


#endif