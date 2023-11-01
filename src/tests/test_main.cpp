// tests/test_main.cpp

#include <gtest/gtest.h>

#include "../Caretaker.h"
#include "../Tab.h"
#include "../TabMemento.h"

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


//COMPOSITE

#include "../RestaurantTable.h"
#include "../CompositeTable.h"
#include "../Customer.h"

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
    EXPECT_FALSE(restaurantTable->AddCustomer(&customer));  // Capacity is full
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
    EXPECT_FALSE(compositeTable->AddCustomer(&customer3));  // All tables are full

    EXPECT_TRUE(compositeTable->RemoveCustomer(&customer1));
    EXPECT_FALSE(compositeTable->RemoveCustomer(&customer1));  // Customer not found
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
