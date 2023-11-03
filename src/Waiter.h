#ifndef WAITER_H
#define WAITER_H
#include <vector>
#include <string>
#include "Observer.h"
#include "Table.h"
#include "Plate.h"
#include "Colleague.h"
class ConcreteMediator;
class Waiter: public Colleague, public Observer{
    private:
     //Mediator
     Plate *plate;
     ConcreteMediator *mediator;
     //obs
     std::vector<Table*> FreeTables;
     std::vector<Table*> OccupiedTables;
    public:
        //mediator
        Waiter(ConcreteMediator *mediator);
        void WriteDownOrder(std::string order);
        void CancelItem(std::string order);
        void DoneOrder();
        //Observer
        Waiter(std::vector<Table*> FreeTables);
        ~Waiter();
        void update(Table* changedTable);
        int getFreeTablesCount() const;
        int getOccupiedTablesCount() const;
        void givePlate(Plate* plate);
        Plate* getPlate();
};

#endif
