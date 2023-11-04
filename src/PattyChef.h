#ifndef PATTYCHEF_H
#define PATTYCHEF_H

#include "BaseChef.h"

class PattyChef: public BaseChef
{
public:
    PattyChef();
    void addToPlate(BurgerOrder* order, Plate *plate);
};

#endif