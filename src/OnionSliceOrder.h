#ifndef ONIONSLICEORDER_H
#define ONIONSLICEORDER_H
#include "BurgerToppingOrder.h"

class BurgerToppingOrder;
class OnionSliceOrder : public BurgerToppingOrder {
    public:
        OnionSliceOrder();
        ~OnionSliceOrder();
        double getPrice();
        std::string toString();

    private:
        double price;
};

#endif