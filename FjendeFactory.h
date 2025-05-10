#ifndef FJENDEFACTORY_H
#define FJENDEFACTORY_H
#include "Fjende.h"
#include <vector>

class FjendeFactory
{
public:
    static Fjende createFjende(int heroLevel);
};

#endif