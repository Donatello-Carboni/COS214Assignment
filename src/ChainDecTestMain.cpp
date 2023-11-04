#include "CheeseChef.h"
#include "PattyChef.h"
#include "SauceChef.h"
#include "vector"
#include "BurgerOrder.h"
#include "BurgerBunOrder.h"
#include "BurgerToppingOrder.h"
#include "CheeseOrder.h"
#include "GherkinOrder.h"
#include "GlutenFreeBunOrder.h"
#include "LettuceOrder.h"
#include "MushroomOrder.h"
#include "MustardSauceOrder.h"
#include "OnionSliceOrder.h"
#include "PattyOrder.h"
#include "RegularBunOrder.h"
#include "TomatoSauceOrder.h"
#include "ExtrasChef.h"
#include "BunChef.h"
#include <iostream>
#include <unistd.h>
int ChainDecTestMain()
{
    
    BurgerOrder* regBun = new RegularBunOrder();
    BurgerOrder* patty = new PattyOrder();
    BurgerOrder* cheese = new CheeseOrder();
    BurgerOrder* tomatoSauce = new TomatoSauceOrder();
    BurgerOrder* lettuce = new LettuceOrder();
    BurgerOrder* mushroom = new MushroomOrder();

    CheeseChef *cheeseChef = new CheeseChef();
    SauceChef *sauceChef = new SauceChef();
    PattyChef *pattyChef = new PattyChef();
    ExtrasChef *extrasChef = new ExtrasChef();
    BunChef * bunChef = new BunChef();


    cheeseChef->add(sauceChef);
    sauceChef->add(pattyChef);
    pattyChef->add(extrasChef);
    extrasChef->add(bunChef);
    

    
    Plate *plate = new Plate();
    cheeseChef->addToPlate(regBun, plate);

    std::cout << plate->toString();
    delete cheeseChef;
    delete sauceChef;
    delete pattyChef;
    delete plate;
    delete bunChef;
    return 0;
}