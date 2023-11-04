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
int decoratorMain();

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
    cout << "REG_BUN NEXT: " << regBun->getNext()->toString() << endl;
    cout << "PATTY NEXT: " << patty->getNext()->toString() << endl;
    cout << "CHEESE NEXT: " << cheese->getNext()->toString() << endl;
    cout << "TOMATO_SAUCE NEXT: " << tomatoSauce->getNext()->toString() << endl;
    //cout << "LETTUCE NEXT: " << lettuce->getNext()->toString() << endl;     //Causes segfault even with nullptr check to toString(). Will fix later

    return 0;
}
