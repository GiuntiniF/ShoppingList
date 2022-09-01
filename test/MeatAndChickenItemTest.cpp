//
// Created by ubuntuwsl on 16/08/22.
//
#include "gtest/gtest.h"

#include "../headers/MeatAndChickenItem.h"

TEST(MeatAndChickenItem, DefaultConstructor) {
MeatAndChickenItem c;
ASSERT_EQ("Chicken", c.getName());
ASSERT_EQ(5, c.getBasePrice());
ASSERT_EQ(1, c.getQuantity());
ASSERT_FALSE(c.isDiscounted());
ASSERT_EQ("Meat and Chicken", c.getCategoryName());
ASSERT_NE("Snacks", c.getCategoryName());
}

TEST(MeatAndChickenItem, QuantityDiscount) {
    MeatAndChickenItem c;
    c.setQuantity(5);
    c.setBasePrice(20);
    c.setDiscounted(true);
    ASSERT_EQ(5, c.getQuantity());
    ASSERT_EQ(20, c.getBasePrice());
    ASSERT_EQ(80, c.calculatePrice());
}
