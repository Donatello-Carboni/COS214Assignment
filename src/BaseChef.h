#ifndef BASECHEF_H
#define BASECHEF_H
#include "Chef.h"

class BaseChef :public Chef{
 public:
 void addToPlate(std::vector<std::string> order, Plate* plate);
};

#endif