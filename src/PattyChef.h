#ifndef PATTYCHEF_H
#define PATTYCHEF_H

#include "BaseChef.h"

/**
 * @brief Class representing a chef specialized in preparing patties for burger orders.
 */
class PattyChef : public BaseChef {
public:
    /**
     * @brief Constructor for the PattyChef class.
     */
    PattyChef();

    /**
     * @brief Adds a prepared patty to the plate based on the burger order.
     * @param order - Pointer to the BurgerOrder object.
     * @param plate - Pointer to the Plate object.
     */
    void addToPlate(BurgerOrder* order, Plate* plate);
};

#endif
