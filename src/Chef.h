#ifndef CHEF_H
#define CHEF_H

#include <iostream>

#include "Plate.h"
#include "string"
#include "vector"
class Chef {
 public:
  virtual void addToPlate(std::vector<std::string> order, Plate* plate)=0;
};

#endif