#ifndef EXTACHEF_H
#define EXTRACHEF_H
#include "BaseChef.h"

class ExtrasChef: public BaseChef
{
public:
    ExtrasChef();
    void addToPlate(BurgerOrder *order, Plate *plate);
};

#endif