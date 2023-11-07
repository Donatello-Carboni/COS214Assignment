#ifndef BCHEF_H
#define BCHEF_H


#include"BurgerOrder.h"
#include"BurgerBunOrder.h"
#include"RegularBunOrder.h"
#include"GlutenFreeBunOrder.h"
#include"BurgerToppingOrder.h"
#include"CheeseOrder.h"
#include"PattyOrder.h"
#include"TomatoSauceOrder.h"
#include"MustardSauceOrder.h"
#include"LettuceOrder.h"
#include"OnionSliceOrder.h"
#include"MushroomOrder.h"
#include"GherkinOrder.h"
#include "Chef.h"

/**
 * @brief Class representing a base chef, inheriting from Chef.
 */
class BaseChef : public Chef {
private:
    // BurgerOrder *order; // order to be added to plate
    Plate *plate; // Plate for adding the order
    std::string white = "\033[37m";
    std::string green = "\033[32m";
    std::string yellow = "\033[31m";
    std::string bold = "\033[1m";
    std::string reset = "\033[0m";

protected:
    BaseChef *nextChef; // Pointer to the next chef in the chain

public:
    /**
     * @brief Default constructor for BaseChef.
     */
    BaseChef();

    /**
     * @brief Method to set the next chef in the chain.
     * @param chef - Pointer to the next BaseChef.
     * @return Pointer to the next BaseChef.
     */
    BaseChef* add(BaseChef *chef); // setNext

    /**
     * @brief Handle method to add a BurgerOrder to the plate.
     * @param order - Pointer to the BurgerOrder object.
     * @param plate - Pointer to the Plate object.
     */
    void addToPlate(BurgerOrder* order, Plate *plate); // Handle method
    bool inspected = false;
};

#endif
