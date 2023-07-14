//
// Created by ubuntuwsl on 06/09/22.
//
#include "gtest/gtest.h"

#include "../headers/ItemManager.h"

TEST(ItemManager, InitItem) {
    ItemManager itemManager;
    auto meat = itemManager.createItem(1, "Turket", 3, 4);
    ASSERT_EQ(1, meat->getType());
    ASSERT_EQ(12, meat->calculatePrice()); // Meat and Chicken per essere scontata deve avere almeno 5 elementi
    meat->setQuantity(5);
    ASSERT_EQ(15*0.8, meat->calculatePrice());
    auto apple = itemManager.createItem(2, "Apple", 1, 10);
    ASSERT_EQ(2, apple->getType());
    ASSERT_EQ(apple->calculatePrice(), 10*0.6);
}

TEST(ItemManager, InitInvalid) {
    ItemManager itemManager;
    auto invalid1 = itemManager.createItem(12, "Turket", 3, 4);
    ASSERT_EQ(invalid1->calculatePrice(), 0);
    auto invalid2 = itemManager.createItem(2, "applefake", 0, 2);
    ASSERT_EQ(invalid2->calculatePrice(), 0);
}
