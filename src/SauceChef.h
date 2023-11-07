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
private:
    std::string white = "\033[37m";
    std::string green = "\033[32m";
    std::string yellow = "\033[33m";
    std::string bold = "\033[1m";
    std::string reset = "\033[0m";
};

#endif
