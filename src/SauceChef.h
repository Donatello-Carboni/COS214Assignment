#ifndef SAUCECHEF_H
#define SAUCECHEF_H

#include "BaseChef.h"

class SauceChef: public BaseChef
{
public:
    SauceChef();
    void addToPlate(std::vector<std::string> order, Plate *plate);
    
};

#endif