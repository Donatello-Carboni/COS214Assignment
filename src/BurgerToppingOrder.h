#ifndef BURGERTOPPINGORDER_H
#define BURGERTOPPINGORDER_H
#include "BurgerOrder.h"

class BurgerOrder;
/**
 * @brief Class representing a burger topping order, inheriting from BurgerOrder.
 */
class BurgerToppingOrder : public BurgerOrder {
public:
    /**
     * @brief Constructor for BurgerToppingOrder.
     */
    BurgerToppingOrder();

    /**
     * @brief Virtual destructor for BurgerToppingOrder.
     */
    virtual ~BurgerToppingOrder();

    /**
     * @brief Get the price of the burger topping order.
     * @return The price of the burger topping order.
     */
    virtual double getPrice() = 0;

    /**
     * @brief Represent the burger topping order as a string.
     * @return String representation of the burger topping order.
     */
    virtual std::string toString() = 0;

    /**
     * @brief Get the burger order.
     * @return Pointer to the BurgerOrder object.
     */
    BurgerOrder* getBurger();

    /**
     * @brief Set the burger order.
     * @param burger - Pointer to the BurgerOrder object.
     */
    void setBurger(BurgerOrder* burger);

private:
    BurgerOrder* burger; /**< Pointer to the BurgerOrder object. */
};

#endif
