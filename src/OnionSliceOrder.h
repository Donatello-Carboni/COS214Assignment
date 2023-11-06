#ifndef ONIONSLICEORDER_H
#define ONIONSLICEORDER_H

#include "BurgerToppingOrder.h"

/**
 * @brief Class representing an order for onion slices as a burger topping, inheriting from BurgerToppingOrder.
 */
class OnionSliceOrder : public BurgerToppingOrder {
public:
    /**
     * @brief Constructor for OnionSliceOrder class.
     */
    OnionSliceOrder();

    /**
     * @brief Destructor for OnionSliceOrder class.
     */
    ~OnionSliceOrder();

    /**
     * @brief Get the price of the onion slice order.
     * @return The price of the onion slices topping.
     */
    double getPrice();

    /**
     * @brief Get a string representation of the onion slice order.
     * @return A string describing the onion slice order.
     */
    std::string toString();

private:
    double price; /**< The price of the onion slice order. */
};

#endif
