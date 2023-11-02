#ifndef COMPOSITE_TABLE_H
#define COMPOSITE_TABLE_H

#include "Table.h"

class CompositeTable : public Table {
    private:
    Table* childTable;
    std::vector<Table*> tables;
    
    public:
    virtual bool AddTable(Table* table);
    virtual bool RemoveTable(Table* table);
    virtual bool AddCustomer(Customer* customer);
    virtual bool RemoveCustomer(Customer* customer);
};

#endif // COMPOSITE_TABLE_H