#ifndef BCHEF_H
#define BCHEF_H

#include "Chef.h"
#include <algorithm>
class BaseChef : public Chef
{
private:
    
    std::vector<std::string> order; // This needs to be populated by the mediator which will convert the Json to a vector
    Plate *plate;

protected:
BaseChef *nextChef;
public:
    BaseChef();
    BaseChef* add(BaseChef *chef);                                         // setNext
    void addToPlate(std::vector<std::string> order, Plate *plate); // Handle method
};
#endif
