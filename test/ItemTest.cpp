//
// Created by Utente on 19/09/2023.
//

#include "gtest/gtest.h"

#include "../headers/Item.h"

TEST(Item, Constructor) {
    EXPECT_THROW(Item("", 10, 10), std::invalid_argument);
    EXPECT_THROW(Item("test", -1, 10), std::invalid_argument);
    EXPECT_THROW(Item("test", 0, 10), std::invalid_argument);
    EXPECT_THROW(Item("test", 10, 0), std::invalid_argument);
    EXPECT_THROW(Item("test", 10, -1), std::invalid_argument);
    EXPECT_NO_THROW(Item("test", 10, 10));
}

TEST(Item, Setters) {
    Item c("test", 10, 2);

    c.setName("test2");
    ASSERT_EQ("test2", c.getName());

    c.setName("");
    ASSERT_EQ("test2", c.getName());

    c.setBasePrice(2);
    ASSERT_EQ(2, c.getBasePrice());
    c.setBasePrice(0);
    ASSERT_EQ(2, c.getBasePrice());
    c.setBasePrice(-1);
    ASSERT_EQ(2, c.getBasePrice());

    c.setQuantity(2);
    ASSERT_EQ(2, c.getQuantity());
    c.setQuantity(0);
    ASSERT_EQ(2, c.getQuantity());
    c.setQuantity(-1);
    ASSERT_EQ(2, c.getQuantity());

    ASSERT_FALSE(c.isBought());
    c.setIsBought(true);
    ASSERT_TRUE(c.isBought());
    c.setIsBought(false);
    ASSERT_FALSE(c.isBought());
}
