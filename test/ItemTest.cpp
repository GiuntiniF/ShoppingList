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
    ASSERT_EQ(false, c.isBought());
    // EXPECT_THROW(c.setName(""), std::invalid_argument);
    c.setName("test2");
    ASSERT_EQ("test2", c.getName());

    // EXPECT_THROW(c.setBasePrice(0), std::invalid_argument);
    // EXPECT_THROW(c.setBasePrice(-1), std::invalid_argument);
    c.setBasePrice(2);
    ASSERT_EQ(2, c.getBasePrice());

    // EXPECT_THROW(c.setQuantity(0), std::invalid_argument);
    // EXPECT_THROW(c.setQuantity(-1), std::invalid_argument);
    c.setQuantity(2);
    ASSERT_EQ(2, c.getQuantity());
    // EXPECT_THROW(Item("", 10, 10), std::invalid_argument);

    c.setIsBought(true);
    ASSERT_TRUE(c.isBought());
}
