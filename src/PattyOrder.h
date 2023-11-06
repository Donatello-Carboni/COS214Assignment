#ifndef PATTYORDER_H
#define PATTYORDER_H

#include "BurgerToppingOrder.h"

/**
 * @brief Class representing an order for a patty as a burger topping, inheriting from BurgerToppingOrder.
 */
class PattyOrder : public BurgerToppingOrder {
public:
    /**
     * @brief Constructor for PattyOrder class.
     */
    PattyOrder();

    /**
     * @brief Destructor for PattyOrder class.
     */
    ~PattyOrder();

    /**
     * @brief Get the price of the patty order.
     * @return The price of the patty topping.
     */
    double getPrice();

    /**
     * @brief Get a string representation of the patty order.
     * @return A string describing the patty order.
     */
    std::string toString();

private:
    double price; /**< The price of the patty order. */
};

#endif
