#ifndef CHEESECHEF_H
#define CHEESECHEF_H
#include "BaseChef.h"

class CheeseChef: public BaseChef
{
public:
    CheeseChef();
    void addToPlate(BurgerOrder *order, Plate *plate);
};

#endif