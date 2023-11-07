#ifndef WAITINGTOORDER_H
#define WAITINGTOORDER_H

#include "State.h"

class State;
class Customer;

/**
 * @brief Class representing the state when the customer is waiting to order.
 */
class WaitingToOrder : public State {
public:
    /**
     * @brief Constructor for the WaitingToOrder class.
     */
    WaitingToOrder();

    /**
     * @brief Destructor for the WaitingToOrder class.
     */
    ~WaitingToOrder();

    /**
     * @brief Allows the customer to choose items to order.
     * @param customer - Pointer to the Customer object
     */
    void chooseItems(Customer*);

    /**
     * @brief Notifies that the customer is waiting to place an order.
     * @param customer - Pointer to the Customer object
     */
    void callToOrder(Customer*);

    /**
     * @brief Indicates the idle state for the customer waiting to order.
     * @param customer - Pointer to the Customer object
     */
    void idle(Customer*);

    /**
     * @brief Initiates the process of getting the bill for the customer.
     * @param customer - Pointer to the Customer object
     */
    void callForBill(Customer*);

    /**
     * @brief Handles the process of paying the bill for the customer.
     * @param customer - Pointer to the Customer object
     */
    void payBill(Customer*);

    /**
     * @brief Handles the customer's review process.
     * @param customer - Pointer to the Customer object
     */
    void review(Customer*);

    /**
     * @brief Randomly changes the customer's happiness.
     * @param customer - Pointer to the Customer object
     */
    void changeHappiness(Customer*);

    /**
     * @brief Returns the string representation of the state.
     * @return A string indicating the state.
     */
    std::string toString();

private:
    std::string magenta = "\033[35m";
    std::string reset = "\033[0m";
    std::string bold = "\033[1m";

};

#endif
