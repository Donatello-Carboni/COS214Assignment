#ifndef OBSERVER_H
#define OBSERVER_H

class Table; // Forward declaration

/**
 * @brief Abstract class for an observer observing changes in a Table.
 */
class Observer {
public:
    /**
     * @brief Method to be implemented by observers for updates on changes in a table.
     * @param changedTable - Pointer to the Table object that has changed.
     */
    virtual void update(Table* changedTable) = 0;
};

#endif
