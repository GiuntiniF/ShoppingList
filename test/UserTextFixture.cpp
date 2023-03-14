//
// Created by francesco on 12/26/22.
//
#include "gtest/gtest.h"
#include "../headers/MeatAndChickenItem.h"
#include "../headers/VegetableAndFruitItem.h"
#include "../headers/ItemList.h"
#include "../headers/ItemManager.h"
#include "../headers/User.h"

class UserSuite : public ::testing::Test {
protected:
    void SetUp() override {
        list1->addItem(std::move(item1));
        list1->addItem(std::move(item2));
        list1->addItem(std::move(item3));
        list2->addItem(std::move(item5));
        list2->addItem(std::move(item6));
    }
    std::shared_ptr<ItemList> list1 = std::make_shared<ItemList>();
    std::unique_ptr<Item> item1 = ItemManager::createItem(0, "Steak", 12, 1);
    std::unique_ptr<Item> item2 = ItemManager::createItem(1, "Turkey", 2, 3);
    std::unique_ptr<Item> item3 = ItemManager::createItem(1,"Salad", 3, 3);

    std::shared_ptr<ItemList> list2 = std::make_shared<ItemList>();
    std::unique_ptr<Item> item5 = ItemManager::createItem(0, "Chicken", 5, 10);
    std::unique_ptr<Item> item6 = ItemManager::createItem(0, "Meat", 1, 1);
};

TEST_F(UserSuite, DefaultConstructor) {
    ASSERT_EQ(0, User::getUsersCount());
    User myuser = User("Test");
    ASSERT_EQ("Test", myuser.getName());
    ASSERT_EQ(1, myuser.getUserId());
    ASSERT_EQ(1, User::getUsersCount());
}

TEST_F(UserSuite, AddListToUser) {
    User myuser = User("Test");
    ASSERT_EQ(0, myuser.getListCount());
    myuser.addList(list1);
    ASSERT_EQ(1, myuser.getListCount());
}

TEST_F(UserSuite, getListInfo) {
    User myuser = User("Test");
    ASSERT_FALSE(myuser.getListInfo(-1));
    int my_id = list1->getListId();
    int my_id2 = list2->getListId();
    myuser.addList(list1);
    ASSERT_FALSE(myuser.getListInfo(my_id2));
    ASSERT_TRUE(myuser.getListInfo(my_id));
}

TEST_F(UserSuite, testObserverPattern) {
    std::shared_ptr<User> myuser = std::make_shared<User>("Test");
    ASSERT_FALSE(myuser->getListInfo(-1));
    ASSERT_EQ(0, myuser->getNumberOfLists());
    ASSERT_EQ(0, myuser->getNumberOfItemsAdded());
    ASSERT_EQ(0, myuser->getNumOfItemsUsingQuantity());
    int mylistid = list1->getListId();
    myuser->addList(list1);
    ASSERT_EQ(1, myuser->getNumberOfLists());
    ASSERT_EQ(3, myuser->getNumberOfItemsAdded());
    ASSERT_EQ(7, myuser->getNumOfItemsUsingQuantity());
    myuser->getLists().find(mylistid)->second->addItem(ItemManager::createItem(1, "Turkey", 2, 3));
    ASSERT_EQ(1, myuser->getNumberOfLists());
    ASSERT_EQ(4, myuser->getNumberOfItemsAdded());
    ASSERT_EQ(10, myuser->getNumOfItemsUsingQuantity());
    myuser->addList(list2);
    ASSERT_EQ(2, myuser->getNumberOfLists());
    ASSERT_EQ(6, myuser->getNumberOfItemsAdded());
    ASSERT_EQ(21, myuser->getNumOfItemsUsingQuantity());
    myuser->removeList(mylistid);
    ASSERT_EQ(1, myuser->getNumberOfLists());
    ASSERT_EQ(2, myuser->getNumberOfItemsAdded());
    ASSERT_EQ(11, myuser->getNumOfItemsUsingQuantity());
}
