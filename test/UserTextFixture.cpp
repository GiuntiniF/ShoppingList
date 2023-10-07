//
// Created by francesco on 12/26/22.
//
#include "gtest/gtest.h"
#include "../headers/ItemList.h"
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
    int list1id = list1->getListId();
    std::unique_ptr<Item> item1 = std::make_unique<Item>("Steak", 12, 1);
    std::unique_ptr<Item> item2 = std::make_unique<Item>( "Turkey", 2, 3);
    std::unique_ptr<Item> item3 = std::make_unique<Item>( "Salad", 3, 3);

    std::shared_ptr<ItemList> list2 = std::make_shared<ItemList>();
    int list2id = list2->getListId();
    std::unique_ptr<Item> item5 = std::make_unique<Item>("Chicken", 5, 10);
    std::unique_ptr<Item> item6 = std::make_unique<Item>("Meat", 1, 1);
};

TEST_F(UserSuite, DefaultConstructor) {
    ASSERT_EQ(0, User::getUsersCount());
    User myuser = User("Test");
    ASSERT_EQ("Test", myuser.getName());
    ASSERT_EQ(1, myuser.getUserId());
    ASSERT_EQ(1, User::getUsersCount());
    ASSERT_THROW(User(""), std::invalid_argument);
    ASSERT_NO_THROW(User("test2"));
}

TEST_F(UserSuite, Setters) {
    User myuser = User("Test");
    ASSERT_EQ("Test", myuser.getName());
    myuser.setName("");
    ASSERT_EQ("Test", myuser.getName());
    myuser.setName("test2");
    ASSERT_EQ("test2", myuser.getName());
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
    ASSERT_EQ(0, myuser->getNumberOfItemsLeftToBuy());
    int mylistid = list1->getListId();
    myuser->addList(list1);
    ASSERT_EQ(1, myuser->getNumberOfLists());
    ASSERT_EQ(3, myuser->getNumberOfItemsAdded());
    ASSERT_EQ(7, myuser->getNumOfItemsUsingQuantity());
    ASSERT_EQ(7, myuser->getNumberOfItemsLeftToBuy());
    myuser->getLists().find(mylistid)->second->addItem(std::make_unique<Item>("Turkey", 2, 3));
    ASSERT_EQ(1, myuser->getNumberOfLists());
    ASSERT_EQ(4, myuser->getNumberOfItemsAdded());
    ASSERT_EQ(10, myuser->getNumOfItemsUsingQuantity());
    ASSERT_EQ(10, myuser->getNumberOfItemsLeftToBuy());

    ASSERT_FALSE(myuser->getLists().find(mylistid)->second->getItem(1).lock()->isBought());
    myuser->getLists().find(mylistid)->second->checkItem(1);
    ASSERT_TRUE(myuser->getLists().find(mylistid)->second->getItem(1).lock()->isBought());
    ASSERT_EQ(1, myuser->getNumberOfLists());
    ASSERT_EQ(4, myuser->getNumberOfItemsAdded());
    ASSERT_EQ(10, myuser->getNumOfItemsUsingQuantity());
    ASSERT_EQ(9, myuser->getNumberOfItemsLeftToBuy());

    myuser->addList(list2);
    ASSERT_EQ(2, myuser->getNumberOfLists());
    ASSERT_EQ(6, myuser->getNumberOfItemsAdded());
    ASSERT_EQ(21, myuser->getNumOfItemsUsingQuantity());
    ASSERT_EQ(20, myuser->getNumberOfItemsLeftToBuy());
    myuser->removeList(mylistid);
    ASSERT_EQ(1, myuser->getNumberOfLists());
    ASSERT_EQ(2, myuser->getNumberOfItemsAdded());
    ASSERT_EQ(11, myuser->getNumOfItemsUsingQuantity());
    ASSERT_EQ(11, myuser->getNumberOfItemsLeftToBuy());

    myuser->getLists().find(list2id)->second->changeItemQuantity(1, 5);
    ASSERT_EQ(1, myuser->getNumberOfLists());
    ASSERT_EQ(2, myuser->getNumberOfItemsAdded());
    ASSERT_EQ(6, myuser->getNumOfItemsUsingQuantity());
    ASSERT_EQ(6, myuser->getNumberOfItemsLeftToBuy());

    myuser->getLists().find(list2id)->second->checkItem(2);
    ASSERT_EQ(1, myuser->getNumberOfLists());
    ASSERT_EQ(2, myuser->getNumberOfItemsAdded());
    ASSERT_EQ(6, myuser->getNumOfItemsUsingQuantity());
    ASSERT_EQ(5, myuser->getNumberOfItemsLeftToBuy());
}
