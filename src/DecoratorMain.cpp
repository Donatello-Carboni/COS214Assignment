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
#include <iostream>
#include <unistd.h>

using namespace std;

int decoratorMain()
{
    cout << "YUM :)" << endl;
    BurgerOrder* regBun = new RegularBunOrder();
    BurgerOrder* patty = new PattyOrder();
    BurgerOrder* cheese = new CheeseOrder();
    BurgerOrder* tomatoSauce = new TomatoSauceOrder();
    BurgerOrder* lettuce = new LettuceOrder();

    //Print works from any component
    tomatoSauce->printList();
    return 0;
}
