#ifndef CHEESECHEF_H
#define CHEESECHEF_H

#include "BaseChef.h"

/**
 * @brief Class representing a chef specialized in handling cheese orders, inheriting from BaseChef.
 */
class CheeseChef : public BaseChef {
public:
    /**
     * @brief Default constructor for CheeseChef.
     */
    CheeseChef();

    /**
     * @brief Add the cheese from the order to the plate.
     * @param order - Pointer to the BurgerOrder object.
     * @param plate - Pointer to the Plate object.
     */
    void addToPlate(BurgerOrder* order, Plate* plate);
};

#endif
