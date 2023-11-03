#ifndef BURGERBUNORDER_H
#define BURGERBUNORDER_H
#include "BurgerOrder.h"

class BurgerOrder;
class BurgerBunOrder : public BurgerOrder {
    public:
        BurgerBunOrder();
        virtual ~BurgerBunOrder();
        virtual double getPrice() =0;
        virtual std::string toString() =0;

};

#endif