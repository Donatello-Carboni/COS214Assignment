#ifndef MUSTARDSAUCEORDER_H
#define MUSTARDSAUCEORDER_H

#include "BurgerToppingOrder.h"

/**
 * @brief Class representing an order for mustard sauce as a burger topping, inheriting from BurgerToppingOrder.
 */
class MustardSauceOrder : public BurgerToppingOrder {
public:
    /**
     * @brief Constructor for MustardSauceOrder class.
     */
    MustardSauceOrder();

    /**
     * @brief Destructor for MustardSauceOrder class.
     */
    ~MustardSauceOrder();

    /**
     * @brief Get the price of the mustard sauce order.
     * @return The price of the mustard sauce topping.
     */
    double getPrice();

    /**
     * @brief Get a string representation of the mustard sauce order.
     * @return A string describing the mustard sauce order.
     */
    std::string toString();

private:
    double price; /**< The price of the mustard sauce order. */
};

#endif
