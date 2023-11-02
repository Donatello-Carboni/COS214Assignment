#include "BurgerToppingOrder.h"

BurgerToppingOrder::BurgerToppingOrder()
{
    
}

BurgerToppingOrder::~BurgerToppingOrder()
{
    
}

BurgerOrder* BurgerToppingOrder::getBurger()
{
    return burger;
}

void BurgerToppingOrder::setBurger(BurgerOrder* b)
{
    this->burger = b;
}

