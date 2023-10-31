#ifndef BURGERORDER_H
#define BURGERORDER_H
#include <iostream>
#include <string>
#include <vector>

class BurgerOrder {
    public:
        BurgerOrder();
        ~BurgerOrder();
        bool add(BurgerOrder*);
        double total();

    private:
        
};

#endif