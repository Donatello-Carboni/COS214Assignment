#include "RestaurantTable.h"

RestaurantTable::RestaurantTable(int capacity)
{
    customerCapacity = capacity;
    customerCount = 0;
}


bool RestaurantTable::AddCustomer(Customer* customer)
{
    if (customerCount < customerCapacity)
    {
        customers.push_back(customer);
        customerCount++;
        return this;
    }
    return false;
}

bool RestaurantTable::RemoveCustomer(Customer* customer) {
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (*it == customer) {
            customers.erase(it);  
            customerCount--;
            return true;
        }
    }
    return false;
}
