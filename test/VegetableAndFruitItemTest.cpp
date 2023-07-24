//
// Created by ubuntuwsl on 23/08/22.
//
#include "gtest/gtest.h"

#include "../headers/VegetableAndFruitItem.h"
/*REMOVED
TEST(VegetableAndFruitItem, DefaultConstructor) {
    VegetableAndFruitItem c;
    ASSERT_EQ("Apple", c.getName());
    ASSERT_NE("chicken", c.getName());
    ASSERT_EQ(2, c.getBasePrice());
    ASSERT_EQ(4, c.getQuantity());
}*/

TEST(VegetableAndFruitItem, DiscountedPrice) {
    VegetableAndFruitItem c("Salad", 2, 4, 0);
    c.setBasePrice(6.5);
    ASSERT_EQ(6.5, c.getBasePrice());
    ASSERT_EQ(26, c.calculatePrice());
    c.setQuantity(10);
    ASSERT_EQ(65*0.6, c.calculatePrice());
    c.toggleDiscount();
    ASSERT_EQ(65*0.8*0.6, c.calculatePrice());
}
