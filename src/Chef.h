#ifndef CHEF_H
#define CHEF_H

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
#include "Colleague.h"
#include "string"
#include "vector"
#include "Plate.h"  
#include <iostream>
/**
 * @brief Abstract class representing a chef, inheriting from Colleague.
 */
class Chef : public Colleague {
public:
    /**
     * @brief Adds the prepared burger order to the plate.
     * @param order - Pointer to the BurgerOrder object.
     * @param plate - Pointer to the Plate object.
     */
    virtual void addToPlate(BurgerOrder* order, Plate* plate) = 0;
};

#endif
