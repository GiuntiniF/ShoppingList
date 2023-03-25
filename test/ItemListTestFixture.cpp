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
        c.addItem(std::move(item1));
        c.addItem(std::move(item2));
        c.addItem(std::move(item3));
    }
    ItemList c = ItemList();
    std::unique_ptr<Item> item1 = std::make_unique<MeatAndChickenItem>();
    std::unique_ptr<Item> item2 = std::make_unique<MeatAndChickenItem>("Turkey", 2, 3);
    std::unique_ptr<Item> item3 = std::make_unique<VegetableAndFruitItem>();
    int item1Id = item1->getItemId();
    int item2Id = item2->getItemId();
    int item3Id = item3->getItemId();
};

TEST_F(ItemListSuite, DefaultConstructor) {
    ASSERT_EQ("List", c.getListName());
    ASSERT_EQ(1, c.getListId());
}
TEST_F(ItemListSuite, RemoveLast) {
    ASSERT_EQ(3, c.getListSize());
    ASSERT_EQ(item3Id, c.getItem(c.getListSize()).lock()->getItemId());
    c.removeItem(c.getListSize());
    ASSERT_EQ(item2Id, c.getItem(c.getListSize()).lock()->getItemId());
}
TEST_F(ItemListSuite, RemoveFirst) {
    ASSERT_EQ(3, c.getListSize());
    std::cout << c.getListSize() << std::endl;
    ASSERT_EQ(item1Id, c.getItem(1).lock()->getItemId());
    c.removeItem(1);
    std::cout << c.getListSize() << std::endl;
    ASSERT_EQ(2, c.getListSize());
    ASSERT_EQ(item2Id, c.getItem(1).lock()->getItemId());
}