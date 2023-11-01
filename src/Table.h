#ifndef TABLE_H
#define TABLE_H

#include "Customer.h"

#include <vector>

class Table {
    public:
    virtual bool AddCustomer(Customer* customer) = 0;
    virtual bool RemoveCustomer(Customer* customer) = 0;

};




#endif  // TABLE_H