#ifndef CHEESECHEF_H
#define CHEESECHEF_H
#include "BaseChef.h"

class CheeseChef: public BaseChef
{
public:
    CheeseChef();
    void addToPlate(std::vector<std::string> order, Plate *plate);
};

#endif