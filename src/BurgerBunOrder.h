#ifndef BURGERBUNORDER_H
#define BURGERBUNORDER_H
#include "BurgerOrder.h"

class BurgerOrder;
/**
 * @brief Class to manage a burger bun order, inheriting from BurgerOrder.
 */
class BurgerBunOrder : public BurgerOrder {
public:
    /**
     * @brief Constructor for BurgerBunOrder.
     */
    BurgerBunOrder();

    /**
     * @brief Virtual destructor for BurgerBunOrder.
     */
    virtual ~BurgerBunOrder();

    /**
     * @brief Get the price of the burger bun order.
     * @return The price of the burger bun order.
     */
    virtual double getPrice() = 0;

    /**
     * @brief Represent the burger bun order as a string.
     * @return String representation of the burger bun order.
     */
    virtual std::string toString() = 0;
};

#endif
