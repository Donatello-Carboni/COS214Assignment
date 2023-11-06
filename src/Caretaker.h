
#ifndef CARETAKER_H
#define CARETAKER_H
#include <vector>

#include "TabMemento.h"

/**
 * @brief Caretaker class to manage mementos of the Tab.
 */
class Caretaker {
private:
    std::vector<TabMemento> tabHistory; /**< Vector to store Tab mementos. */

public:
    /**
     * @brief Adds a memento to the caretaker's history.
     * @param memento - TabMemento to be added.
     */
    void addMemento(TabMemento memento);

    /**
     * @brief Retrieves a memento from the caretaker's history based on the number of rollbacks.
     * @param numberOfRollbacks - The number of rollbacks to perform.
     * @return The requested TabMemento.
     */
    TabMemento getMemento(int numberOfRollbacks);
};

#endif

