#ifndef MUSTARDSAUCEORDER_H
#define MUSTARDSAUCEORDER_H
#include "BurgerToppingOrder.h"

class BurgerToppingOrder;
class MustardSauceOrder : public BurgerToppingOrder {
    public:
        MustardSauceOrder();
        ~MustardSauceOrder();
        double getPrice();
        std::string toString();

    private:
        double price;
};

#endif