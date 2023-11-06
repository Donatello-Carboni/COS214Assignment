#ifndef CHEESEORDER_H
#define CHEESEORDER_H
#include "BurgerToppingOrder.h"

class BurgerToppingOrder;
class CheeseOrder : public BurgerToppingOrder {
    public:
        CheeseOrder();
        ~CheeseOrder();
        double getPrice();
        std::string toString();
    private:
        double price;
};

#endif