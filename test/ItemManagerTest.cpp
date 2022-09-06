//
// Created by ubuntuwsl on 06/09/22.
//
#include "gtest/gtest.h"

#include "../headers/ItemManager.h"

class ItemManagerSuite : public ::testing::Test {
protected:
    ItemManager c;
};

TEST_F(ItemManagerSuite, InitItem) {
    auto meat = ItemManager::createItem(0, "Turket", 3, 4, false);
    ASSERT_EQ(meat->calculatePrice(), 12);
    meat->setDiscounted(true);
    ASSERT_EQ(meat->calculatePrice(), 12); // Meat and Chicken per essere scontata deve avere almeno 5 elementi
    meat->setQuantity(5);
    ASSERT_EQ(meat->calculatePrice(), 15*0.8);
    auto apple = ItemManager::createItem(1, "Apple", 1, 6, true);
    ASSERT_EQ(apple->calculatePrice(), 6*0.6);
}

TEST_F(ItemManagerSuite, InitInvalid) {
    auto invalid1 = ItemManager::createItem(12, "Turket", 3, 4, false);
    ASSERT_EQ(invalid1->calculatePrice(), 0);
    auto invalid2 = ItemManager::createItem(1, "applefake", 0, 2, true);
    ASSERT_EQ(invalid2->calculatePrice(), 0);
}
