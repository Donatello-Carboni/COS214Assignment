#ifndef PATTYORDER_H
#define PATTYORDER_H
#include "BurgerToppingOrder.h"

class BurgerToppingOrder;
class PattyOrder : public BurgerToppingOrder {
    public:
        PattyOrder();
        ~PattyOrder();
        double getPrice();
        std::string toString();

    private:
        double price;
};  

#endif