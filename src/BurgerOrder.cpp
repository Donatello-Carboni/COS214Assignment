#include "BurgerOrder.h"

BurgerOrder* BurgerOrder::base = nullptr;                      //First instance of BurgerOrder object
BurgerOrder* BurgerOrder::head = nullptr;                      //Head of the linked list

BurgerOrder::BurgerOrder()
{
    if (base == nullptr)
    {
        base = this;
        head = head;
        next = nullptr;
    }
}

BurgerOrder::~BurgerOrder()
{
    
}

bool BurgerOrder::add(BurgerOrder* topping)
{
    BurgerOrder* curr = head;
    if (curr == nullptr)
    {
        head = topping;
        head->next = nullptr;
        return true;
    }
    else
    {
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = topping;
    }

    return true;
}

void BurgerOrder::printList()
{
    BurgerOrder* curr = head;
    std::cout << "\n=====LIST=====" <<std::endl;
    std::cout << "" << std::endl;
    std::string out = "";

    while (curr != nullptr)
    {
        out += "[" + curr->toString() + "]";
        if (curr->next != nullptr)
            out += "->";
        curr = curr->next;
    }

    std::cout << out << std::endl;
    std::cout << "\n=====DONE=====" <<std::endl;
}

BurgerOrder* BurgerOrder::getNext() 
{
    return next;
}