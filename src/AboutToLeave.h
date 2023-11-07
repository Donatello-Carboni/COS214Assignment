#ifndef ABOUTTOLEAVE_H
#define ABOUTTOLEAVE_H
#include "State.h"


class State;
/**
 * @brief Class representing the state when a customer is about to leave, inheriting from State.
 */
class AboutToLeave : public State {
public:
    /**
     * @brief Constructor for AboutToLeave.
     */
    AboutToLeave();

    /**
     * @brief Destructor for AboutToLeave.
     */
    ~AboutToLeave();

    /**
     * @brief Implementation of choosing items for a customer in the AboutToLeave state.
     * @param customer - Pointer to the Customer object.
     */
    void chooseItems(Customer*);

    /**
     * @brief Implementation of calling to order for a customer in the AboutToLeave state.
     * @param customer - Pointer to the Customer object.
     */
    void callToOrder(Customer*);

    /**
     * @brief Implementation of the idle state for a customer in the AboutToLeave state.
     * @param customer - Pointer to the Customer object.
     */
    void idle(Customer*);

    /**
     * @brief Implementation of calling for the bill for a customer in the AboutToLeave state.
     * @param customer - Pointer to the Customer object.
     */
    void callForBill(Customer*);

    /**
     * @brief Changes the happiness of the customer.
     * @param customer - Pointer to the Customer object.
     */
    void changeHappiness(Customer*);

    /**
     * @brief Implementation of paying the bill for a customer in the AboutToLeave state.
     * @param customer - Pointer to the Customer object.
     */
    void payBill(Customer*);

    /**
     * @brief Implementation of reviewing the order for a customer in the AboutToLeave state.
     * @param customer - Pointer to the Customer object.
     */
    void review(Customer*);

    /**
     * @brief Get a string representation of the AboutToLeave state.
     * @return String representation of the state.
     */
    std::string toString();
};

#endif
