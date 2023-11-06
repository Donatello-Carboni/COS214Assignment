#ifndef EXTRACHEF_H
#define EXTRACHEF_H

#include "BaseChef.h"

/**
 * @brief Class representing a chef specialized in adding extra toppings to a plate.
 */
class ExtrasChef : public BaseChef {
public:
    /**
     * @brief Constructor for ExtrasChef class.
     */
    ExtrasChef();

    /**
     * @brief Adds extra toppings to the plate based on the burger order.
     * @param order - Pointer to the BurgerOrder object.
     * @param plate - Pointer to the Plate object.
     */
    void addToPlate(BurgerOrder* order, Plate* plate);
};

#endif
