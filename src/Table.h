#ifndef TABLE_H
#define TABLE_H


#include "Observer.h"
#include "Customer.h"
#include <vector>

/**
 * @brief Abstract class representing a table in a restaurant.
 */
class Table {
private:
    Observer* myWaiter; /**< Pointer to the waiter assigned to the table. */
    bool isAvailable = true; /**< Availability status of the table. */

public:
    /**
     * @brief Constructor for the Table class.
     */
    Table();

    /**
     * @brief Virtual destructor for the Table class.
     */
    virtual ~Table();

    /**
     * @brief Adds a customer to the table.
     * @param customer - Pointer to the Customer object to add.
     * @return True if the addition was successful, false otherwise.
     */
    virtual bool AddCustomer(Customer* customer) = 0;

    /**
     * @brief Removes a customer from the table.
     * @param customer - Pointer to the Customer object to remove.
     * @return True if the removal was successful, false otherwise.
     */
    virtual bool RemoveCustomer(Customer* customer) = 0;

    /**
     * @brief Attaches a waiter as an observer to the table.
     * @param waiter - Pointer to the Observer (waiter) to attach.
     */
    void attach(Observer* waiter);

    /**
     * @brief Detaches a waiter from being an observer of the table.
     * @param waiter - Pointer to the Observer (waiter) to detach.
     */
    void detach(Observer* waiter);

    /**
     * @brief Notifies the waiter about changes in the table.
     */
    void notify();

    /**
     * @brief Get the availability status of the table.
     * @return True if the table is available, false otherwise.
     */
    bool getState();

    /**
     * @brief Set the availability status of the table.
     * @param state - The state to set (true for available, false for not available).
     */
    void setState(bool state);
};

#endif
