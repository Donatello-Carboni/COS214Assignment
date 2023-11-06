#ifndef DEFAULT_H
#define DEFAULT_H

#include "State.h"

/**
 * @brief Class representing the default state for a customer, inheriting from State.
 */
class Default : public State {
public:
    /**
     * @brief Constructor for the Default class.
     */
    Default();

    /**
     * @brief Destructor for the Default class.
     */
    ~Default();

    /**
     * @brief Implementing State's abstract method to choose items.
     * @param customer - Pointer to the Customer object.
     */
    void chooseItems(Customer*);

    /**
     * @brief Implementing State's abstract method to handle a call to order.
     * @param customer - Pointer to the Customer object.
     */
    void callToOrder(Customer*);

    /**
     * @brief Implementing State's abstract method for the idle state.
     * @param customer - Pointer to the Customer object.
     */
    void idle(Customer*);

    /**
     * @brief Implementing State's abstract method to call for the bill.
     * @param customer - Pointer to the Customer object.
     */
    void callForBill(Customer*);

    /**
     * @brief Implementing State's abstract method to pay the bill.
     * @param customer - Pointer to the Customer object.
     */
    void payBill(Customer*);

    /**
     * @brief Implementing State's abstract method for the review state.
     * @param customer - Pointer to the Customer object.
     */
    void review(Customer*);

    /**
     * @brief Implementing State's abstract method to change the customer's happiness.
     * @param customer - Pointer to the Customer object.
     */
    void changeHappiness(Customer*);

    /**
     * @brief Implementing State's abstract method to get a string representation of the state.
     * @return A string describing the state.
     */
    string toString();
};

#endif
