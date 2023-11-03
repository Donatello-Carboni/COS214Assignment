#ifndef RESTAURANTTABLE_H
#define RESTAURANTTABLE_H

#include "Table.h"
#include "CompositeTable.h"

class RestaurantTable : public Table {
    private:
    std::vector<Customer*> customers;
    int customerCapacity;
    int customerCount;

    public:
    RestaurantTable(int capacity);
    virtual bool AddCustomer(Customer* customer);
    virtual bool RemoveCustomer(Customer* customer);
    int getCapacity() {return this->customerCapacity;};

};


#endif // RESTAURANTTABLE_H