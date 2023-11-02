// tests/test_main.cpp

#include <gtest/gtest.h>

#include "../Caretaker.h"
#include "../Chef.h"
#include "../Colleague.h"
#include "../Command.h"
#include "../ConcreteMediator.h"
#include "../CreateOrder.h"
#include "../KitchenMediator.h"
#include "../Plate.h"
#include "../Tab.h"
#include "../TabMemento.h"
#include "../Waiter.h"
#include "../BaseChef.h"
#include "../Waiter.h"
#include "../RestaurantTable.h"
#include "../CompositeTable.h"
#include "../Table.h"
#include "../Customer.h"



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
  KitchenMediator *mediator = new ConcreteMediator();
  Chef *chef = new BaseChef();
  Waiter *waiter = new Waiter((ConcreteMediator *)mediator);

  mediator->addColleague((Colleague *)chef);
  mediator->addColleague((Colleague *)waiter);

  // Perform assertions to validate the number of colleagues
  ASSERT_EQ(mediator->getColleagues().size(), 2);
  ASSERT_EQ(mediator->getColleagues().at(0), (Colleague *)chef);
  ASSERT_EQ(mediator->getColleagues().at(1), (Colleague *)waiter);
  //delete mediator;
}

TEST(MediatorTest, AddCommand) {
  KitchenMediator *mediator = new ConcreteMediator();

  Command *command = new CreateOrder();
  Command *command2 = new CreateOrder();

  mediator->addCommand(command);
  mediator->addCommand(command2);

  // Perform assertions to validate the number of commands
  ASSERT_EQ(mediator->getCommands().size(), 2);
  ASSERT_EQ(mediator->getCommands().at(0), command);
  ASSERT_EQ(mediator->getCommands().at(1), command2);
  //delete mediator;
  //ASSERT_EQ(1, 1);
}

TEST(MediatorTest, CommsToDecor) {
  KitchenMediator *mediator = new ConcreteMediator();
  Chef *chef = new BaseChef();
  Waiter *waiter = new Waiter((ConcreteMediator *)mediator);

  mediator->addColleague((Colleague *)chef);
  mediator->addColleague((Colleague *)waiter);
  Command *command = new CreateOrder();
  Command *command2 = new CreateOrder();

  mediator->addCommand(command);
  mediator->addCommand(command2);

  waiter->WriteDownOrder("Burger");
  waiter->WriteDownOrder("Burger");
  Command *command3 = mediator->getCommands().at(0);
  CreateOrder *command4 = (CreateOrder *)command3;
  // Perform assertions to validate the number of colleagues
  std::string test = command4->burger->test;
  ASSERT_EQ(test, "BurgerBurger");
  //delete mediator;
}

//COMPOSITE

// Define a test fixture for RestaurantTable and CompositeTable
class TableTest : public ::testing::Test {
protected:
    RestaurantTable* restaurantTable;
    CompositeTable* compositeTable;

    void SetUp() override {
        restaurantTable = new RestaurantTable(3);
        compositeTable = new CompositeTable();
    }

    void TearDown() override {
        delete restaurantTable;
        delete compositeTable;
    }
};

TEST_F(TableTest, RestaurantTableAddCustomer) {
    Customer customer;
    EXPECT_TRUE(restaurantTable->AddCustomer(&customer));
    EXPECT_TRUE(restaurantTable->AddCustomer(&customer));
    EXPECT_TRUE(restaurantTable->AddCustomer(&customer));
    EXPECT_FALSE(restaurantTable->AddCustomer(&customer));
}

TEST_F(TableTest, RestaurantTableRemoveCustomer) {
    Customer customer;
    restaurantTable->AddCustomer(&customer);
    EXPECT_TRUE(restaurantTable->RemoveCustomer(&customer));
    EXPECT_FALSE(restaurantTable->RemoveCustomer(&customer));  // Customer not found
}

TEST_F(TableTest, CompositeTableAddRemoveTable) {
    RestaurantTable* table1 = new RestaurantTable(2);
    RestaurantTable* table2 = new RestaurantTable(3);

    EXPECT_TRUE(compositeTable->AddTable(table1));
    EXPECT_TRUE(compositeTable->AddTable(table2));
    EXPECT_EQ(compositeTable->getState(), true); // Should be available

    EXPECT_TRUE(compositeTable->RemoveTable(table1));
    EXPECT_FALSE(compositeTable->RemoveTable(table1));  // Table not found
}

TEST_F(TableTest, CompositeTableAddCustomer) {
    Customer customer1;
    Customer customer2;
    Customer customer3;

    EXPECT_TRUE(compositeTable->AddCustomer(&customer1));
    EXPECT_TRUE(compositeTable->AddCustomer(&customer2));
    EXPECT_TRUE(compositeTable->AddCustomer(&customer3));  // All tables are full

    EXPECT_TRUE(compositeTable->RemoveCustomer(&customer1));
    EXPECT_FALSE(compositeTable->RemoveCustomer(&customer1));  // Customer not found
}


//OBSERVER

TEST_F(TableTest, WaiterUpdate) {
    // Create tables
    RestaurantTable table3(3);
    RestaurantTable table4(3);
    
    Waiter waiter({ &table3, &table4 });

    table4.setState(false); // Make table4 occupied


    // Check if the tables are initially in the correct vectors
    EXPECT_EQ(waiter.getFreeTablesCount(), 1); 
    EXPECT_EQ(waiter.getOccupiedTablesCount(), 1);

    // Change the state of the tables and simulate notification
    table3.setState(false); // Make table3 occupied


    // Check if tables are moved to the correct vectors after the state change
    EXPECT_EQ(waiter.getFreeTablesCount(), 0);
    EXPECT_EQ(waiter.getOccupiedTablesCount(), 2);

    table3.setState(true);
    table4.setState(true);

  EXPECT_EQ(waiter.getFreeTablesCount(), 2);
  EXPECT_EQ(waiter.getOccupiedTablesCount(), 0);

}






int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
