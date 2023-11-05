#include "Plate.h"

Plate::Plate()
{
    bun = NULL;
    patty = NULL;
    cheese = NULL;
    extra = NULL;
    sauce = NULL;  
}

void Plate::addPatty()
{
    patty = new Patty();
}
void Plate::addCheese()
{
    cheese = new Cheese();
}
void Plate::addExtra(std::string extra)
{
    if (this->extra == NULL)
    {
        this->extra = new Extra(extra);
    }else
    {
        this->extra->addExtra(extra);
    }
    
    
}

void Plate::addSauce(std::string sauce) {
    if (this->sauce == NULL)
    {
        this->sauce = new Sauce(sauce);
    }else
    {
        this->sauce->addSauce(sauce);
    }
}

void Plate::addBun(std::string bun) {
    this->bun = new Bun(bun);
}

std::string Plate::toString() { 
    std::string plateString = "";
    if (bun != NULL)
    {
        plateString += bun->toString() + " ";
    }
    if (patty != NULL)
    {
        plateString += patty->toString() + " ";
    }
    if (cheese != NULL)
    {
        plateString += cheese->toString() + " ";
    }
    if (extra != NULL)
    {
        plateString += extra->toString() + " ";
    }
    if (sauce != NULL)
    {
        plateString += sauce->toString() + " ";
    }
    return plateString;
 }
