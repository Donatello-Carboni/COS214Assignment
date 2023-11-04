#ifndef GLUTENFREEBUNORDER_H
#define GLUTENFREEBUNORDER_H
#include "BurgerBunOrder.h"

class BurgerBunOrder;
class GlutenFreeBunOrder : public BurgerBunOrder {
    public:
        GlutenFreeBunOrder();
        ~GlutenFreeBunOrder();
        double getPrice();
        std::string toString();

    private:
        double price;
};

#endif