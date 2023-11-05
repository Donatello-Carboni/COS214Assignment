// EdibleBurger.h
#ifndef EDIBLEBURGER_H
#define EDIBLEBURGER_H
#include <iostream>
#include <string>
#include <vector>
class Bun {
 private:
  std::string type;

 public:
  Bun(std::string type);
  std::string toString();
};

class Patty {
 public:
  Patty();
  std::string toString();
};

class Cheese {
 public:
  Cheese();
  std::string toString();
};

class Extra {
 private:
  std::vector<std::string> extras;

 public:
  std::string toString();
  Extra(std::string extra);
  void addExtra(std::string extra);
  // other methods and data members
};

class Sauce {
 private:
  std::vector<std::string> sauces;

 public:
  Sauce(std::string extra);
  void addSauce(std::string sauce);
  std::string toString();
};

#endif