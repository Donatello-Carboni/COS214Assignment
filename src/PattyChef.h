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
private:
    std::string white = "\033[37m";
    std::string green = "\033[32m";
    std::string yellow = "\033[33m";
    std::string red = "\033[31m";
    std::string bold = "\033[1m";
    std::string reset = "\033[0m";
};

#endif
