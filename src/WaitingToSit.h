#ifndef WAITINGTOSIT_H
#define WAITINGTOSIT_H

#include "State.h"

class State;

/**
 * @brief The WaitingToSit class represents the state where a customer is waiting to be seated in a restaurant.
 * 
 * This class inherits from the base class 'State' and defines methods related to different actions a customer can perform in this state.
 */
class WaitingToSit : public State {
public:
    /**
     * @brief Constructor for the WaitingToSit class.
     */
    WaitingToSit();

    /**
     * @brief Destructor for the WaitingToSit class.
     */
    ~WaitingToSit();

    /**
     * @brief Allows the customer to choose items from the menu.
     * 
     * @param customer A pointer to the Customer object.
     */
    void chooseItems(Customer*);

    /**
     * @brief Makes a call to place an order for the customer.
     * 
     * @param customer A pointer to the Customer object.
     */
    void callToOrder(Customer*);

    /**
     * @brief Represents an idle state for the customer.
     * 
     * @param customer A pointer to the Customer object.
     */
    void idle(Customer*);

    /**
     * @brief Notifies the staff for the bill request.
     * 
     * @param customer A pointer to the Customer object.
     */
    void callForBill(Customer*);

    /**
     * @brief Allows the customer to pay the bill.
     * 
     * @param customer A pointer to the Customer object.
     */
    void payBill(Customer*);

    /**
     * @brief Enables the customer to give a review after the meal.
     * 
     * @param customer A pointer to the Customer object.
     */
    void review(Customer*);

    /**
     * @brief Changes the customer's happiness level based on the situation.
     * 
     * @param customer A pointer to the Customer object.
     */
    void changeHappiness(Customer*);

    /**
     * @brief Provides a string representation of the current state.
     * 
     * @return A string representing the state.
     */
    string toString();
    private:
    std::string cyan = "\033[36m";
    std::string bold = "\033[1m";
    std::string reset = "\033[0m";
};

#endif
