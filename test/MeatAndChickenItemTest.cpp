//
// Created by ubuntuwsl on 16/08/22.
//
#include "gtest/gtest.h"

#include "../headers/MeatAndChickenItem.h"
/* REMOVED
TEST(MeatAndChickenItem, DefaultConstructor) {
    MeatAndChickenItem c;
    ASSERT_EQ("Chicken", c.getName());
    ASSERT_EQ(5, c.getBasePrice());
    ASSERT_EQ(1, c.getQuantity());
}
*/
TEST(MeatAndChickenItem, QuantityDiscount) {
    MeatAndChickenItem c(std::string(), 0, 0, 0);
    c.setQuantity(4);
    c.setBasePrice(20);
    ASSERT_EQ(20, c.getBasePrice());
    ASSERT_EQ(80, c.calculatePrice());
    c.setQuantity(5);
    ASSERT_EQ(5, c.getQuantity());
    ASSERT_EQ(80, c.calculatePrice());
}
