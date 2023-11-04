#ifndef PLATE_H
#define PLATE_H
#include <iostream>
#include <string>
#include "EdibleBurger.h"

class Plate {
  
private:
  Bun* bun;
  Patty* patty;
  Cheese* cheese;
  Extra* extra;
  Sauce* sauce;


 public:
  Plate();
  void addCheese();
  void addPatty();
  void addExtra(std::string extra);
  void addSauce(std::string sauce);
  void addBun(std::string bun);
  std::string toString();


};

#endif