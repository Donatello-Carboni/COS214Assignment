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
class ConcreteMediator;
class Waiter: public Colleague, public Observer{
    private:
    //Iterator 
    int currTable;
    int currInternalTable;
    int currCustomer;
    //Mediator
    std::unordered_map<int, Plate*> plateMap;
    std::unordered_map<int, BurgerOrder*> BurgerMap;
     ConcreteMediator *mediator;
    //obs
     std::vector<Table*> FreeTables;
     std::vector<Table*> OccupiedTables;
    public:
        //mediator
        void WriteDownOrder(std::vector<std::string> order);
        void CancelItem(std::string order);
        void DoneOrder();
        //Observer
        Waiter(ConcreteMediator *mediator,std::vector<Table*> FreeTables);
        ~Waiter();
        void update(Table* changedTable);
        int getFreeTablesCount() const;
        int getOccupiedTablesCount() const;
        //seating customers
        void seatCustomer(vector<Customer*> customers);
        void nextTable();
        Customer* nextCustomer();
        void CompleteCircuit();
        void storePlate(int plateID, Plate* plate);
        Plate* getPlate(int plateID);
        void removePlate(int plateID);
        void printPlateMap();
        void printBurgerMap();
        BurgerOrder* getBurgerOrder(int orderID);
        void removeBurgerOrder(int orderID);
        void storeBurgerOrder(int orderID, BurgerOrder* order);
};

#endif
