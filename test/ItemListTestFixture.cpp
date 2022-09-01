//
// Created by ubuntuwsl on 30/08/22.
//
#include "gtest/gtest.h"

#include "../headers/MeatAndChickenItem.h"
#include "../headers/VegetableAndFruitItem.h"
#include "../headers/ItemList.h"


class ItemListSuite : public ::testing::Test {
protected:
    void SetUp() override {
        c.addItem(item1);
        c.addItem(item2);
        c.addItem(item3);
    }
    ItemList c = ItemList();
    std::shared_ptr<Item> item1 = std::make_shared<MeatAndChickenItem>();
    std::shared_ptr<Item> item2 = std::make_shared<MeatAndChickenItem>("Turkey", 2, 3);
    std::shared_ptr<Item> item3 = std::make_shared<VegetableAndFruitItem>();
};

TEST_F(ItemListSuite, DefaultConstructor) {
    ASSERT_EQ("List", c.getListName());
    ASSERT_EQ(1, c.getListId());
}
TEST_F(ItemListSuite, RemoveLast) {
    ASSERT_EQ(3, c.getListSize());
    ASSERT_EQ(item3, c.getItem(c.getListSize()));
    c.removeItem();
    ASSERT_EQ(2, c.getListSize());
    ASSERT_EQ(item2, c.getItem(c.getListSize()));
}
TEST_F(ItemListSuite, RemoveFirst) {
    ASSERT_EQ(3, c.getListSize());
    ASSERT_EQ(item1, c.getItem(1));
    c.removeItem(1);
    ASSERT_EQ(2, c.getListSize());
    ASSERT_EQ(item2, c.getItem(1));
}
