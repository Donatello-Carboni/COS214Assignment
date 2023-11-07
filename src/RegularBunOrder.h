#ifndef REGULARBUNORDER_H
#define REGULARBUNORDER_H

#include "BurgerBunOrder.h"

/**
 * @brief Class representing an order for a regular bun, inheriting from BurgerBunOrder.
 */
class RegularBunOrder : public BurgerBunOrder {
public:
    /**
     * @brief Constructor for RegularBunOrder class.
     */
    RegularBunOrder();

    /**
     * @brief Destructor for RegularBunOrder class.
     */
    ~RegularBunOrder();

    /**
     * @brief Get the price of the regular bun order.
     * @return The price of the regular bun.
     */
    double getPrice();

    /**
     * @brief Get a string representation of the regular bun order.
     * @return A string describing the regular bun order.
     */
    std::string toString();

private:
    double price; /**< The price of the regular bun order. */
    std::string white = "\033[37m";
    std::string yellow = "\033[31m";
    std::string bold = "\033[1m";
    std::string reset = "\033[0m";
};

#endif
