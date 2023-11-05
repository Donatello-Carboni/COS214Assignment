#ifndef WAITER_H
#define WAITER_H
#include <vector>
#include <string>
#include "Observer.h"
#include "Table.h"
#include "Plate.h"
#include "Colleague.h"
#include "CompositeTable.h"
#include "RestaurantTable.h"
#include "Customer.h"
class ConcreteMediator;
class Waiter: public Colleague, public Observer{
    private:
    //Iterator 
    int currTable;
    int currInternalTable;
    int currCustomer;
    //Mediator
     Plate *plate;
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
        // orders from kicthen
        void givePlate(Plate* plate);
        Plate* getPlate();
        //seating customers
        void seatCustomer(vector<Customer*> customers);
        void nextTable();
        Customer* nextCustomer();
        void CompleteCircuit();
};

#endif
