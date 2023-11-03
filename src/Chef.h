#ifndef CHEF_H
#define CHEF_H
#include "Colleague.h"
#include "string"
#include "vector"
#include "Plate.h"  
#include <iostream>
class Chef : public Colleague
{
    
public:
    virtual void addToPlate(std::vector<std::string> order,Plate* plate)  = 0;
};

#endif 