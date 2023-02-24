//
// Created by francesco on 12/26/22.
//
#include "gtest/gtest.h"
#include "../headers/MeatAndChickenItem.h"
#include "../headers/VegetableAndFruitItem.h"
#include "../headers/ItemList.h"
#include "../headers/User.h"

//TODO aggiungi test per pattern Observer
class UserSuite : public ::testing::Test {
protected:
    void SetUp() override {
        list1->addItem(std::move(item1));
        list1->addItem(std::move(item2));
        list1->addItem(std::move(item3));
        list2->addItem(std::move(item4));
        list2->addItem(std::move(item5));
        list2->addItem(std::move(item6));
    }
    std::shared_ptr<ItemList> list1 = std::make_shared<ItemList>();
    std::unique_ptr<Item> item1 = std::make_unique<MeatAndChickenItem>();
    std::unique_ptr<Item> item2 = std::make_unique<MeatAndChickenItem>("Turkey", 2, 3);
    std::unique_ptr<Item> item3 = std::make_unique<VegetableAndFruitItem>("Salad", 3, 3);

    std::shared_ptr<ItemList> list2 = std::make_shared<ItemList>();
    std::unique_ptr<Item> item4 = std::make_unique<MeatAndChickenItem>();
    std::unique_ptr<Item> item5 = std::make_unique<MeatAndChickenItem>("Chicken", 5, 10);
    std::unique_ptr<Item> item6 = std::make_unique<MeatAndChickenItem>("Meat", 1, 1);
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
    myuser.addList("Nuova Lista");
    ASSERT_EQ(2, myuser.getListCount());
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