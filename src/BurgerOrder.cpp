
#include "BurgerOrder.h"

BurgerOrder* BurgerOrder::base = NULL;                      //First instance of BurgerOrder object
BurgerOrder* BurgerOrder::head = NULL;                      //Head of the linked list

BurgerOrder::BurgerOrder()
{
    if (base == NULL)
    {
        base = this;
        head = head;
        next = NULL;
    }
}

BurgerOrder::~BurgerOrder()
{
    
}

bool BurgerOrder::add(BurgerOrder* topping)
{
    BurgerOrder* curr = head;
    if (curr == NULL)
    {
        head = topping;
        head->next = NULL;
        return true;
    }
    else
    {
        while (curr->next != NULL)
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

    while (curr != NULL)
    {
        out += "[" + curr->toString() + "]";
        if (curr->next != NULL)
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