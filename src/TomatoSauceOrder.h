#ifndef TOMATOSAUCEORDER_H
#define TOMATOSAUCEORDER_H
#include "BurgerToppingOrder.h"

class BurgerToppingOrder;
class TomatoSauceOrder : public BurgerToppingOrder {
    public:
        TomatoSauceOrder();
        ~TomatoSauceOrder();
        double getPrice();
        std::string toString();

    private:
        double price;
};

#endif