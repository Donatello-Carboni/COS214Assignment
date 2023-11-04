#ifndef BURGERORDER_H
#define BURGERORDER_H
#include <iostream>
#include <string>
#include <vector>

class BurgerOrder {
    public:
        BurgerOrder();
        virtual ~BurgerOrder();
        virtual double getPrice() =0;
        virtual std::string toString() =0;
        bool add(BurgerOrder*);
        void printList();
        BurgerOrder* getNext();

    private:
        static BurgerOrder* base;
        static BurgerOrder* head;
        BurgerOrder* next;
        double price;
};

#endif