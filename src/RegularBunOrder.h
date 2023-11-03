#ifndef REGULARBUNORDER_H
#define REGULARBUNORDER_H
#include "BurgerBunOrder.h"

class BurgerBunOrder;
class RegularBunOrder : public BurgerBunOrder {
    public:
        RegularBunOrder();
        ~RegularBunOrder();
        double getPrice();
        std::string toString();

    private:
        double price;
};

#endif