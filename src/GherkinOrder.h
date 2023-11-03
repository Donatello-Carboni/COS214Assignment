#ifndef GHERKINORDER_H
#define GHERKINORDER_H
#include "BurgerToppingOrder.h"

class BurgerToppingOrder;
class GherkinOrder : public BurgerToppingOrder {
    public:
        GherkinOrder();
        ~GherkinOrder();
        double getPrice();
        std::string toString();

    private:
        double price;
};

#endif