#ifndef RESTAURANTTABLE_H
#define RESTAURANTTABLE_H

#include "Table.h"
#include "CompositeTable.h"

/**
 * @brief Class representing a table in a restaurant establishment, inheriting from the Table class.
 */
class RestaurantTable : public Table {
private:
    std::vector<Customer*> customers; /**< Vector storing the customers at the table. */
    int customerCapacity; /**< Maximum capacity of the table for customers. */
    int customerCount; /**< Current count of customers at the table. */

public:
    /**
     * @brief Constructor for the RestaurantTable class.
     * @param capacity - Maximum capacity of the table for customers.
     */
    RestaurantTable(int capacity);

    /**
     * @brief Adds a customer to the table.
     * @param customer - Pointer to the Customer object to add.
     * @return True if the addition was successful, false otherwise.
     */
    virtual bool AddCustomer(Customer* customer);

    /**
     * @brief Removes a customer from the table.
     * @param customer - Pointer to the Customer object to remove.
     * @return True if the removal was successful, false otherwise.
     */
    virtual bool RemoveCustomer(Customer* customer);

    /**
     * @brief Get the maximum capacity of the table for customers.
     * @return The maximum capacity of the table.
     */
    int getCapacity() { return this->customerCapacity; }

    /**
     * @brief Get the count of customers currently at the table.
     * @return The count of customers at the table.
     */
    int getCustomerCount() { return this->customerCount; }

    /**
     * @brief Get the vector of customers at the table.
     * @return A vector containing Customer objects at the table.
     */
    std::vector<Customer*> getCustomers() { return this->customers; }
};

#endif // RESTAURANTTABLE_H
