#ifndef BURGERTOPPINGORDER_H
#define BURGERTOPPINGORDER_H
#include "BurgerOrder.h"

class BurgerOrder;
class BurgerToppingOrder : public BurgerOrder {
    public:
        BurgerToppingOrder();
        ~BurgerToppingOrder();
        BurgerOrder* getBurger();
        void setBurger(BurgerOrder*);
    private:
        BurgerOrder* burger;
};

#endif