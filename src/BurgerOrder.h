#ifndef BURGERORDER_H
#define BURGERORDER_H
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Class representing a generic BurgerOrder.
 */
class BurgerOrder {
public:
    /**
     * @brief Default constructor for BurgerOrder.
     */
    BurgerOrder();

    /**
     * @brief Virtual destructor for BurgerOrder.
     */
    virtual ~BurgerOrder();

    /**
     * @brief Get the price of the burger order.
     * @return The price of the burger order.
     */
    virtual double getPrice() = 0;

    /**
     * @brief Represent the burger order as a string.
     * @return String representation of the burger order.
     */
    virtual std::string toString() = 0;

    /**
     * @brief Add a BurgerOrder to the list.
     * @param BurgerOrder - The BurgerOrder to be added.
     * @return Boolean indicating if the addition was successful.
     */
    bool add(BurgerOrder*);

    /**
     * @brief Print the list of BurgerOrders.
     */
    void printList();

    /**
     * @brief Get the next BurgerOrder in the list.
     * @return The next BurgerOrder in the list.
     */
    BurgerOrder* getNext();

private:
    BurgerOrder* base; /**< Pointer to the base of the BurgerOrder list. */
    BurgerOrder* head; /**< Pointer to the head of the BurgerOrder list. */
    BurgerOrder* next; /**< Pointer to the next BurgerOrder. */
    double price; /**< The price of the BurgerOrder. */
};

#endif
