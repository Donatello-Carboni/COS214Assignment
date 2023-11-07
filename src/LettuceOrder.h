#ifndef LETTUCEORDER_H
#define LETTUCEORDER_H

#include "BurgerToppingOrder.h"

/**
 * @brief Class representing an order for lettuce as a burger topping, inheriting from BurgerToppingOrder.
 */
class LettuceOrder : public BurgerToppingOrder {
public:
    /**
     * @brief Constructor for LettuceOrder class.
     */
    LettuceOrder();

    /**
     * @brief Destructor for LettuceOrder class.
     */
    ~LettuceOrder();

    /**
     * @brief Get the price of the lettuce order.
     * @return The price of the lettuce topping.
     */
    double getPrice();

    /**
     * @brief Get a string representation of the lettuce order.
     * @return A string describing the lettuce order.
     */
    std::string toString();

private:
    double price; /**< The price of the lettuce order. */
    std::string white = "\033[37m";
    std::string yellow = "\033[31m";
    std::string bold = "\033[1m";
    std::string reset = "\033[0m";
};

#endif
