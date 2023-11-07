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
private:
    std::string white = "\033[37m";
    std::string green = "\033[32m";
    std::string red = "\033[31m";
    std::string yellow = "\033[33m";
    std::string bold = "\033[1m";
    std::string reset = "\033[0m";
};

#endif
