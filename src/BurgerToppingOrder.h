#ifndef BURGERTOPPINGORDER_H
#define BURGERTOPPINGORDER_H
#include "BurgerOrder.h"

class BurgerOrder;
class BurgerToppingOrder : public BurgerOrder {
    public:
        BurgerToppingOrder();
        virtual ~BurgerToppingOrder();
        virtual double getPrice() =0;
        virtual std::string toString() =0;
        BurgerOrder* getBurger();
        void setBurger(BurgerOrder*);

    private:
        BurgerOrder* burger;
};

#endif