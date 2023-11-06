#ifndef STATE_H
#define STATE_H
#include "Customer.h"
#include <string>
#include <iostream>

using namespace std;

/**
 * @brief Abstract class defining the state of a customer in a restaurant.
 */
class Customer; // Forward declaration
class State {
public:
    /**
     * @brief Constructor for the State class.
     */
    State();

    /**
     * @brief Virtual destructor for the State class.
     */
    virtual ~State();

    /**
     * @brief Method to allow the customer to choose items to order.
     * @param customer - Pointer to the Customer object.
     */
    virtual void chooseItems(Customer*) = 0;

    /**
     * @brief Method to handle the scenario when a customer is called to place an order.
     * @param customer - Pointer to the Customer object.
     */
    virtual void callToOrder(Customer*) = 0;

    /**
     * @brief Method representing the idle state of a customer.
     * @param customer - Pointer to the Customer object.
     */
    virtual void idle(Customer*) = 0;

    /**
     * @brief Method for calling the bill for the customer's order.
     * @param customer - Pointer to the Customer object.
     */
    virtual void callForBill(Customer*) = 0;

    /**
     * @brief Method to handle the payment of the bill by the customer.
     * @param customer - Pointer to the Customer object.
     */
    virtual void payBill(Customer*) = 0;

    /**
     * @brief Method for the customer to review their experience.
     * @param customer - Pointer to the Customer object.
     */
    virtual void review(Customer*) = 0;

    /**
     * @brief Method to change the customer's happiness.
     * @param customer - Pointer to the Customer object.
     */
    virtual void changeHappiness(Customer*) = 0;

    /**
     * @brief Method to get a string representation of the state.
     * @return A string representing the state.
     */
    virtual std::string toString() = 0;

private:
    Customer* customer; /**< Pointer to the associated Customer object. */
};

#endif
