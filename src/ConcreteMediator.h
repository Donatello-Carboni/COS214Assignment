#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H
#include "KitchenMediator.h"  // Mediator
#include "Command.h"
#include "CreateOrder.h"
#include "CreateComplaint.h"
/**
 * @brief Concrete mediator class responsible for coordinating communication between colleagues, inheriting from KitchenMediator.
 */
class ConcreteMediator : public KitchenMediator {
private:
    // Declare any private members here (if necessary).

public:
    /**
     * @brief Default constructor for ConcreteMediator.
     */
    ConcreteMediator(){};

    /**
     * @brief Parameterized constructor for ConcreteMediator.
     * @param colleague[] - Array of colleague pointers.
     * @param command[] - Array of command pointers.
     * @param chef - Pointer to the Chef object.
     */
    ConcreteMediator(Colleague* colleague[], Command* command[], Chef* chef)
        : KitchenMediator(colleague, command, chef){};

    /**
     * @brief Notifies the mediator when an action is taken by a colleague with an order.
     * @param colleague - Pointer to the colleague.
     * @param choice - The choice made by the colleague.
     * @param order - Vector representing the order.
     */
    void notify(Colleague* colleague, int choice, std::vector<std::string> order);

    /**
     * @brief Notifies the mediator when an order is placed by a colleague.
     * @param colleague - Pointer to the colleague.
     * @param choice - The choice made by the colleague.
     * @param order - String representing the order.
     */
    void notifyOrder(Colleague* colleague, int choice, std::string order);

    /**
     * @brief Notifies the mediator when an action is done by a colleague.
     * @param colleague - Pointer to the colleague.
     */
    void notifyDone(Colleague* colleague);

    /**
     * @brief Handles the command based on the choice made.
     * @param choice - The choice made by the colleague.
     */
    void HandleCommand(int choice);
};

#endif
