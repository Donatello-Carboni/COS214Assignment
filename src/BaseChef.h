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

class BaseChef : public Chef
{
private:
    
    // BurgerOrder *order; // order to be added to plate
    Plate *plate;

protected:
BaseChef *nextChef;
public:
    BaseChef();
    BaseChef* add(BaseChef *chef);                                         // setNext
    void addToPlate(BurgerOrder* order, Plate *plate); // Handle method
};
#endif
