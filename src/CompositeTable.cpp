#include "CompositeTable.h"
#include "RestaurantTable.h"

bool CompositeTable::AddTable(Table* table) {
    this->tables.push_back(table);
    return true;
}

bool CompositeTable::RemoveTable(Table* table) {
    for (int i = 0; i < this->tables.size(); i++) {
        if (this->tables[i] == table) {
            this->tables.erase(this->tables.begin() + i);
            return true;
        }
    }
    return false;
}

bool CompositeTable::AddCustomer(Customer* customer) {
    //check if there are no tables, if so create one and add the customer
    if (tables.empty()) {
        this->AddTable(new RestaurantTable(3));
        return this->tables[0]->AddCustomer(customer);
    }

    //check if there is a table with space, if so add the customer
    for (int i = 0; i < this->tables.size(); i++) {
        if (this->tables[i]->AddCustomer(customer)) {
            return true;
        }
    }

    //check if there are less than 3 tables, if so create a table and add the customer
    if (this->tables.size() < 3) {
        this->AddTable(new RestaurantTable(3));
        return this->tables[this->tables.size() - 1]->AddCustomer(customer);
    }

    return false; //couldnt add customer
}


bool CompositeTable::RemoveCustomer(Customer* customer) {
    for (int i = 0; i < this->tables.size(); i++) {
        if (this->tables[i]->RemoveCustomer(customer)) {
            return true;
        }
    }
    return false;
}
