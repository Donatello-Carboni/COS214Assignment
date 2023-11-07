#ifndef CHEESEORDER_H
#define CHEESEORDER_H

#include "BurgerToppingOrder.h"

/**
 * @brief Class to handle a cheese order, inheriting from BurgerToppingOrder.
 */
class CheeseOrder : public BurgerToppingOrder {
public:
    /**
     * @brief Constructor for CheeseOrder class.
     */
    CheeseOrder();

    /**
     * @brief Destructor for CheeseOrder class.
     */
    ~CheeseOrder();

    /**
     * @brief Calculate the price for the cheese order.
     * @return The price of the cheese order.
     */
    double getPrice();

    /**
     * @brief Represent the cheese order as a string.
     * @return String representation of the cheese order.
     */
    std::string toString();

private:
    double price; /**< Price of the cheese order. */
    std::string white = "\033[37m";
    std::string yellow = "\033[31m";
    std::string bold = "\033[1m";
    std::string reset = "\033[0m";
};

#endif