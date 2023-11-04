// EdibleBurger.cpp
#include "EdibleBurger.h"

Bun::Bun(std::string type) { this->type = type; }

std::string Bun::toString() { return type;}

Cheese::Cheese() {
  // constructor code here
}

std::string Cheese::toString() { return "Cheese Slice" ;}

Sauce::Sauce(std::string sauce) { sauces.push_back(sauce); }

void Sauce::addSauce(std::string sauce) { sauces.push_back(sauce); }

std::string Sauce::toString() { 
    std::string sauceString = "";
    for (int i = 0; i < sauces.size(); i++)
    {
        sauceString += sauces[i] + " ";
    }
    return sauceString;
 }

std::string Extra::toString() { 
    std::string extraString = "";
    for (int i = 0; i < extras.size(); i++)
    {
        extraString += extras[i] + " ";
    }
    return extraString;
 }

Extra::Extra(std::string extra) { extras.push_back(extra); }

void Extra::addExtra(std::string extra) { extras.push_back(extra); }

Patty::Patty() {}

std::string Patty::toString() { return "Patty"; }
