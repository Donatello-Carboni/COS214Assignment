#ifndef SAUCECHEF_H
#define SAUCECHEF_H

#include "BaseChef.h"

/**
 * @brief Class representing a chef specializing in preparing sauces for burger orders.
 */
class SauceChef : public BaseChef {
public:
    /**
     * @brief Constructor for the SauceChef class.
     */
    SauceChef();

    /**
     * @brief Adds prepared sauce to the plate based on the burger order.
     * @param order - Pointer to the BurgerOrder object.
     * @param plate - Pointer to the Plate object.
     */
    void addToPlate(BurgerOrder* order, Plate* plate);
};

#endif
