#ifndef KITCHENMEDIATOR_H
#define KITCHENMEDIATOR_H
#include <vector>
#include <string>
#include "Colleague.h"
#include "Command.h"
class KitchenMediator {
 private:
    //Collection of colleagues
   std::vector<Colleague*> colleagues;
   std::vector<Command*> commands;

 public:

   KitchenMediator(Colleague *colleague[], Command *command[]);
   virtual void notify(Colleague *colleague, int choice, std::vector<std::string> order)=0;
   void addColleague(Colleague *colleague);
   void addCommand(Command *command);
   void removeColleague(Colleague *colleague);
   void removeCommand(Command *command);
   std::vector<Colleague*> getColleagues();
   std::vector<Command*> getCommands();
};
#endif