#ifndef MUSHROOMORDER_H
#define MUSHROOMORDER_H
#include "BurgerToppingOrder.h"

class BurgerToppingOrder;
class MushroomOrder : public BurgerToppingOrder {
    public:
        MushroomOrder();
        ~MushroomOrder();
        double getPrice();
        std::string toString();

    private:    
        double price;
};

#endif