#ifndef GLUTENFREEBUNORDER_H
#define GLUTENFREEBUNORDER_H

#include "BurgerBunOrder.h"

/**
 * @brief Class representing an order for a gluten-free bun, inheriting from BurgerBunOrder.
 */
class GlutenFreeBunOrder : public BurgerBunOrder {
public:
    /**
     * @brief Constructor for GlutenFreeBunOrder class.
     */
    GlutenFreeBunOrder();

    /**
     * @brief Destructor for GlutenFreeBunOrder class.
     */
    ~GlutenFreeBunOrder();

    /**
     * @brief Get the price of the gluten-free bun order.
     * @return The price of the gluten-free bun.
     */
    double getPrice();

    /**
     * @brief Get a string representation of the gluten-free bun order.
     * @return A string describing the gluten-free bun order.
     */
    std::string toString();

private:
    double price; /**< The price of the gluten-free bun order. */
};

#endif
