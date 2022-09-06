//
// Created by ubuntuwsl on 28/08/22.
//
#include "gtest/gtest.h"

#include "../headers/NullItem.h"

TEST(NullItem, DefaultConstructor) {
    NullItem c;
    ASSERT_NE("Chicken", c.getName());
    ASSERT_EQ("NULL", c.getName());
    ASSERT_EQ(0, c.getBasePrice());
    ASSERT_EQ(0, c.getQuantity());
    //ASSERT_EQ("", c.getCategoryName());
}