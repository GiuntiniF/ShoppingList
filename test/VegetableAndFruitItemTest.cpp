//
// Created by ubuntuwsl on 23/08/22.
//
#include "gtest/gtest.h"

#include "../headers/VegetableAndFruitItem.h"
#include "Item.h"

TEST(VegetableAndFruitItem, DefaultConstructor) {
    VegetableAndFruitItem c;
    ASSERT_EQ("Apple", c.getName());
    ASSERT_NE("chicken", c.getName());
    ASSERT_EQ(2, c.getBasePrice());
    ASSERT_EQ(4, c.getQuantity());
    ASSERT_EQ(true, c.isDiscounted());
    ASSERT_EQ("Vegetable and Fruit", c.getCategoryName());
}

TEST(VegetableAndFruitItem, DiscountedPrice) {
    VegetableAndFruitItem c;
    c.setBasePrice(6.5);
    ASSERT_EQ(6.5, c.getBasePrice());
    ASSERT_EQ(15.6, c.calculatePrice());
    c.setDiscounted(false);
    ASSERT_EQ(false, c.isDiscounted());
    ASSERT_EQ(26, c.calculatePrice());
}
