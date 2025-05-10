#ifndef FJENDEFACTORY_H
#define FJENDEFACTORY_H
#include "Fjende.h"
#include <vector>

class FjendeFactory
{
public:
    static Fjende createFjende(int heroLevel);
    static vector<Fjende> createFjender(int heroLevel, int antal);
};

#endif