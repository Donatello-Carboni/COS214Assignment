
#include "BaseChef.h"

class BunChef: public BaseChef
{
public:
    BunChef();
    void addToPlate(std::vector<std::string> order, Plate *plate) ;
};