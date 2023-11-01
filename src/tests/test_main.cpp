// tests/test_main.cpp

#include <gtest/gtest.h>

#include "../Caretaker.h"
#include "../Tab.h"
#include "../TabMemento.h"
#include "../Plate.h"
#include "../Waiter.h"
#include "../Chef.h"
#include "../Colleague.h"
#include "../KitchenMediator.h"
#include "../ConcreteMediator.h"

TEST(TabTest, CreateMemento) {
  Tab tab;
  tab.addOrderedItem("Item1", 10.0);
  tab.addOrderedItem("Item2", 15.0);

  TabMemento memento = tab.createMemento();

  // Perform assertions to validate the memento
  ASSERT_EQ(memento.getTabID(), tab.getTabID());
  ASSERT_EQ(memento.getTotalPrice(), tab.getTotalPrice());
  ASSERT_EQ(memento.getItemCost(), tab.getItemCost());
  ASSERT_EQ(memento.getOrderedItems(), tab.getOrderedItems());
}

TEST(TabTest, SetMemento) {
  Tab tab;
  TabMemento memento;
  memento.setTabID(1);
  memento.setTotalPrice(25.0);
  memento.setItemCost({10.0, 15.0});
  memento.setOrderedItems({"Item1", "Item2"});

  tab.setMemento(memento);

  // Perform assertions to validate the tab state after setting the memento
  ASSERT_EQ(memento.getTabID(), tab.getTabID());
  ASSERT_EQ(memento.getTotalPrice(), tab.getTotalPrice());
  ASSERT_EQ(memento.getItemCost(), tab.getItemCost());
  ASSERT_EQ(memento.getOrderedItems(), tab.getOrderedItems());
}

// Add more test cases for other functions in Tab class

TEST(CaretakerTest, AddAndGetMemento) {
  Caretaker caretaker;
  Tab tab;

  // Perform some actions on the tab
  tab.addOrderedItem("Item1", 10.0);
  tab.addOrderedItem("Item2", 15.0);
  caretaker.addMemento(tab.createMemento());

  // Perform more actions on the tab
  tab.addOrderedItem("Item3", 20.0);
  caretaker.addMemento(tab.createMemento());

  // Retrieve the previous state
  TabMemento memento = caretaker.getMemento(1);

  // Perform assertions to validate the retrieved memento
  // (similar to the previous tests)
}

TEST(MediatorTest, AddColleague) {
  KitchenMediator mediator=new ConcreteMediator();
  Chef chef=new Chef();
  Waiter waiter=new Waiter();

  mediator.addColleague(&chef);
  mediator.addColleague(&waiter);

  // Perform assertions to validate the number of colleagues
  ASSERT_EQ(mediator.getColleagues().size(), 2);
  ASSERT_EQ(mediator.getColleagues().at(0), &chef);
  ASSERT_EQ(mediator.getColleagues().at(1), &waiter);
  delete mediator;
}

TEST(MediatorTest, AddCommand) {
  KitchenMediator mediator=new ConcreteMediator();
  Command command=new Command();
  Command command2=new Command();

  mediator.addCommand(&command);
  mediator.addCommand(&command2);

  // Perform assertions to validate the number of commands
  ASSERT_EQ(mediator.getCommands().size(), 2);
  ASSERT_EQ(mediator.getCommands().at(0), &command);
  ASSERT_EQ(mediator.getCommands().at(1), &command2);
  delete mediator;
}

TEST(MediatorTest,CommsToDecor ){
  KitchenMediator mediator=new ConcreteMediator();
  Chef chef=new Chef();
  Waiter waiter=new Waiter();

  mediator.addColleague(&chef);
  mediator.addColleague(&waiter);

  waiter.writeDownOrder("Burger");
  waiter.writeDownOrder("Burger");
  

  // Perform assertions to validate the number of colleagues
  ASSERT_EQ(mediator.getCommands().at(0)->Burger->test, "BurgerBurger");
  delete mediator;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
