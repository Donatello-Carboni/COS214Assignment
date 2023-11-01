#ifndef CHEF_H
#define CHEF_H

#include "string"
#include "vector"
#include "Plate.h"  
#include <iostream>
class Chef
{
public:
    virtual void addToPlate(std::vector<std::string> order,Plate* plate);
};

#endif 