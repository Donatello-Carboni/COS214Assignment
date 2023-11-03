#ifndef EXTACHEF_H
#define EXTRACHEF_H
#include "BaseChef.h"

class ExtrasChef: public BaseChef
{
public:
    ExtrasChef();
    void addToPlate(std::vector<std::string> order, Plate *plate);
};

#endif