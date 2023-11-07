#ifndef BUNCHEF_H
#define BUNCHEF_H

#include "BaseChef.h"

/**
 * @brief Class representing a chef specialized in handling bun orders, inheriting from BaseChef.
 */
class BunChef: public BaseChef {
public:
    /**
     * @brief Default constructor for BunChef.
     */
    BunChef();

    /**
     * @brief Add the bun from the order to the plate.
     * @param order - Pointer to the BurgerOrder object.
     * @param plate - Pointer to the Plate object.
     */
    void addToPlate(BurgerOrder *order, Plate *plate);
private:
    std::string white = "\033[37m";
    std::string green = "\033[32m";
    std::string red = "\033[31m";    
    std::string yellow = "\033[33m";
    std::string bold = "\033[1m";
    std::string blue = "\033[34m";
    std::string reset = "\033[0m";
};

#endif
