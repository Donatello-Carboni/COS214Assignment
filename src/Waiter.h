#ifndef WAITER_H
#define WAITER_H
#include <vector>
#include <unordered_map>
#include <string>
#include "Observer.h"
#include "Table.h"
#include "Plate.h"
#include "Colleague.h"
#include "CompositeTable.h"
#include "RestaurantTable.h"
#include "Customer.h"
#include "BurgerOrder.h"
#include "Tab.h"
#include "Caretaker.h"
class ConcreteMediator;

/**
 * @brief Class representing a Waiter that serves customers in a restaurant.
 */
class Waiter : public Colleague, public Observer {
private:
 Caretaker* caretaker; /**< Pointer to the Caretaker object. */

  // Iterator
  int currTable; /**< Current table number being handled by the waiter. */
  int currInternalTable; /**< Current internal table number being managed. */
  int currCustomer; /**< Current customer being attended by the waiter. */

  // Mediator 
  std::unordered_map<int, Plate*> plateMap; /**< Map containing plate IDs and their respective Plate objects. */ 
  std::unordered_map<int, BurgerOrder*> BurgerMap; /**< Map containing burger order IDs and their respective BurgerOrder objects. */  
  ConcreteMediator* mediator; /**< Pointer to the ConcreteMediator object. */
 
  // Observing Tables
  std::vector<Table*> FreeTables; /**< Vector containing free tables available in the restaurant. */ 
  std::vector<Table*> OccupiedTables; /**< Vector containing tables currently occupied by customers. */

    
  // Tabs
  std::unordered_map<int, Tab*> TabMap; /**< Map containing tab IDs and their respective Tab objects. */

    
  // Happiness
  std::vector<int> HappyVec; /**< Vector containing recorded happiness values. */

public:
    /**
     * @brief Constructor for the Waiter class.
     * @param mediator - A pointer to the ConcreteMediator object.
     * @param FreeTables - A vector of available tables.
     * @param caretaker - A pointer to the Caretaker object.
     */
    Waiter(ConcreteMediator* mediator, std::vector<Table*> FreeTables);
    Waiter(ConcreteMediator *mediator,std::vector<Table*> FreeTables,Caretaker* caretaker );

    /**
     * @brief Destructor for the Waiter class.
     */
    ~Waiter();

    /**
     * @brief Update method called when a table's state changes.
     * @param changedTable - The table that changed.
     */
    void update(Table* changedTable);

    /**
     * @brief Get the count of available (free) tables.
     * @return The count of free tables.
     */
    int getFreeTablesCount() const;

    /**
     * @brief Get the count of occupied tables.
     * @return The count of occupied tables.
     */
    int getOccupiedTablesCount() const;

    /**
     * @brief Seat a group of customers at a table.
     * @param customers - A vector of Customer objects to be seated.
     */
    void seatCustomer(std::vector<Customer*> customers);

    /**
     * @brief Move to the next table.
     */
    void nextTable();

    /**
     * @brief Get the next customer at the current table.
     * @return A pointer to the next Customer object.
     */
    Customer* nextCustomer();

    /**
     * @brief Complete a circuit, serving tables.
     */
    void CompleteCircuit();

    /**
     * @brief Store a Plate object in the plateMap.
     * @param plateID - The ID of the plate.
     * @param plate - A pointer to the Plate object.
     */
    void storePlate(int plateID, Plate* plate);

    /**
     * @brief Get a Plate object from the plateMap.
     * @param plateID - The ID of the plate to retrieve.
     * @return A pointer to the Plate object.
     */
    Plate* getPlate(int plateID);

    /**
     * @brief Remove a Plate from the plateMap.
     * @param plateID - The ID of the plate to remove.
     */
    void removePlate(int plateID);

    /**
     * @brief Print the plateMap for debugging purposes.
     */
    void printPlateMap();

    /**
     * @brief Print the BurgerMap for debugging purposes.
     */
    void printBurgerMap();

    /**
     * @brief Get a BurgerOrder object from the BurgerMap.
     * @param orderID - The ID of the BurgerOrder to retrieve.
     * @return A pointer to the BurgerOrder object.
     */
    BurgerOrder* getBurgerOrder(int orderID);

    /**
     * @brief Remove a BurgerOrder from the BurgerMap.
     * @param orderID - The ID of the BurgerOrder to remove.
     */
    void removeBurgerOrder(int orderID);

    /**
     * @brief Store a Tab object in the TabMap.
     * @param tabID - The ID of the tab.
     * @param tab - A pointer to the Tab object.
     */
    void storeTab(int tabID, Tab* tab);

    /**
     * @brief Get a Tab object from the TabMap.
     * @param tabID - The ID of the tab to retrieve.
     * @return A pointer to the Tab object.
     */
    Tab* getTab(int tabID);

    /**
     * @brief Remove a Tab from the TabMap.
     * @param tabID - The ID of the tab to remove.
     */
    void removeTab(int tabID);

    /**
     * @brief Store a happiness value in the HappyVec.
     * @param happy - The happiness value to store.
     */
    void storeHappy(int happy);

    /**
     * @brief Get the last stored happiness value from HappyVec.
     * @return The last stored happiness value.
     */
    int getHappy();


        /**
     * @brief Write down an order for the kitchen to process.
     * @param order - A vector of strings representing the ordered items.
     */
    void WriteDownOrder(std::vector<std::string> order);

    /**
     * @brief Cancel a specific item from an order.
     * @param order - The item to be removed from the order.
     */
    void CancelItem(std::string order);

    /**
     * @brief Notify the kitchen that an order is complete.
     */
    void DoneOrder();

    /**
     * @brief Store a BurgerOrder in the BurgerMap.
     * @param orderID - The ID of the BurgerOrder.
     * @param order - A pointer to the BurgerOrder object.
     */
    void storeBurgerOrder(int orderID, BurgerOrder* order);

    /**
     * @brief Print the TabMap for debugging purposes.
     */
    void printTabMap();
};

#endif