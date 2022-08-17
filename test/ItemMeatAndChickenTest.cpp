//
// Created by ubuntuwsl on 16/08/22.
//
#include "gtest/gtest.h"

#include "../headers/ItemMeatAndChicken.h"

TEST(ItemMeatAndChicken, DefaultConstructor) {
ItemMeatAndChicken c;
ASSERT_EQ("Chicken", c.getName());
ASSERT_NE("chicken", c.getName());
ASSERT_EQ(5, c.getBasePrice());
ASSERT_EQ(1, c.getQuantity());
ASSERT_EQ("Meat and Chicken", c.getCategoryName());
}

TEST(ItemMeatAndChicken, QuantityDiscount) {
    ItemMeatAndChicken c;
    c.setQuantity(6);
    ASSERT_EQ(6, c.getQuantity());
    ASSERT_EQ(24, c.calculatePrice());
}
