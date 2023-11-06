#ifndef MUSHROOMORDER_H
#define MUSHROOMORDER_H

#include "BurgerToppingOrder.h"

/**
 * @brief Class representing an order for mushrooms as a burger topping, inheriting from BurgerToppingOrder.
 */
class MushroomOrder : public BurgerToppingOrder {
public:
    /**
     * @brief Constructor for MushroomOrder class.
     */
    MushroomOrder();

    /**
     * @brief Destructor for MushroomOrder class.
     */
    ~MushroomOrder();

    /**
     * @brief Get the price of the mushroom order.
     * @return The price of the mushroom topping.
     */
    double getPrice();

    /**
     * @brief Get a string representation of the mushroom order.
     * @return A string describing the mushroom order.
     */
    std::string toString();

private:
    double price; /**< The price of the mushroom order. */
};

#endif
