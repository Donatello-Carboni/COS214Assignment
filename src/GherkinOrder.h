#ifndef GHERKINORDER_H
#define GHERKINORDER_H

#include "BurgerToppingOrder.h"

/**
 * @brief Class representing an order for gherkins as a burger topping, inheriting from BurgerToppingOrder.
 */
class GherkinOrder : public BurgerToppingOrder {
public:
    /**
     * @brief Constructor for GherkinOrder class.
     */
    GherkinOrder();

    /**
     * @brief Destructor for GherkinOrder class.
     */
    ~GherkinOrder();

    /**
     * @brief Get the price of the gherkin order.
     * @return The price of the gherkin topping.
     */
    double getPrice();

    /**
     * @brief Get a string representation of the gherkin order.
     * @return A string describing the gherkin order.
     */
    std::string toString();

private:
    double price; /**< The price of the gherkin order. */
    std::string white = "\033[37m";
    std::string yellow = "\033[31m";
    std::string bold = "\033[1m";
    std::string reset = "\033[0m";
};

#endif
