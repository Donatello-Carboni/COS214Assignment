#ifndef SAUCECHEF_H
#define SAUCECHEF_H

#include "BaseChef.h"

class SauceChef: public BaseChef
{
public:
    SauceChef();
    void addToPlate(BurgerOrder *order, Plate *plate);
    
};

#endif