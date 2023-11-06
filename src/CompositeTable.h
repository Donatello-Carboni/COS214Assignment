#ifndef COMPOSITE_TABLE_H
#define COMPOSITE_TABLE_H

#include "Table.h"

/**
 * @brief Class representing a composite table, inheriting from Table.
 * This class can contain multiple tables or sub-tables.
 */
class CompositeTable : public Table {
private:
    Table* childTable; /**< Pointer to a child table. */
    std::vector<Table*> tables; /**< Vector containing multiple tables. */

public:
    /**
     * @brief Adds a table to the composite table.
     * @param table - Pointer to the table to add.
     * @return Boolean indicating the success of the operation.
     */
    virtual bool AddTable(Table* table);

    /**
     * @brief Removes a table from the composite table.
     * @param table - Pointer to the table to remove.
     * @return Boolean indicating the success of the operation.
     */
    virtual bool RemoveTable(Table* table);

    /**
     * @brief Adds a customer to the composite table.
     * @param customer - Pointer to the customer to add.
     * @return Boolean indicating the success of the operation.
     */
    virtual bool AddCustomer(Customer* customer);

    /**
     * @brief Removes a customer from the composite table.
     * @param customer - Pointer to the customer to remove.
     * @return Boolean indicating the success of the operation.
     */
    virtual bool RemoveCustomer(Customer* customer);

    /**
     * @brief Gets the vector of tables contained within the composite table.
     * @return A vector of Table pointers.
     */
    virtual std::vector<Table*> getTables();
};

#endif // COMPOSITE_TABLE_H
