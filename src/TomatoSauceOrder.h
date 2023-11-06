#ifndef TOMATOSAUCEORDER_H
#define TOMATOSAUCEORDER_H
#include "BurgerToppingOrder.h"

class BurgerToppingOrder;

/**
 * @brief Class representing an order for tomato sauce as a burger topping.
 */
class TomatoSauceOrder : public BurgerToppingOrder {
public:
    /**
     * @brief Constructor for TomatoSauceOrder class.
     */
    TomatoSauceOrder();

    /**
     * @brief Destructor for TomatoSauceOrder class.
     */
    ~TomatoSauceOrder();

    /**
     * @brief Get the price of the tomato sauce order.
     * @return The price of the tomato sauce.
     */
    double getPrice();

    /**
     * @brief Get a string representation of the tomato sauce order.
     * @return A string describing the tomato sauce order.
     */
    std::string toString();

private:
    double price; /**< The price of the tomato sauce order. */
};

#endif
