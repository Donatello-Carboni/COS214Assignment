#ifndef LETTUCEORDER_H
#define LETTUCEORDER_H
#include "BurgerToppingOrder.h"

class BurgerToppingOrder;
class LettuceOrder : public BurgerToppingOrder {
    public:
        LettuceOrder();
        ~LettuceOrder();
        double getPrice();
        std::string toString();

    private:
        double price;
};

#endif