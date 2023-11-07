
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
    std::string white = "\033[37m";
    std::string yellow = "\033[33m";
    std::string green = "\033[32m";
    std::string bold = "\033[1m";
    std::string reset = "\033[0m";

public:
    /**
     * @brief Default constructor for ConcreteMediator.
     */
    ConcreteMediator(){};
    bool inspected = false;

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
     * @brief Handles the creation of reports.
     * @param colleague - Colleague making call.
     */
      void notifyReport(Colleague *colleague);
};

#endif

