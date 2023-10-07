//
// Created by ubuntuwsl on 30/08/22.
//
#include "gtest/gtest.h"

#include "../headers/ItemList.h"


class ItemListSuite : public ::testing::Test {
protected:
    void SetUp() override {
        c.addItem(std::move(item1));
        c.addItem(std::move(item2));
        c.addItem(std::move(item3));
    }
    ItemList c = ItemList();
    std::unique_ptr<Item> item1 = std::make_unique<Item>("Pork",3,2);
    std::unique_ptr<Item> item2 = std::make_unique<Item>("Turkey", 2,3);
    std::unique_ptr<Item> item3 = std::make_unique<Item>("Salad",1,5);
    int item1Id = item1->getItemId();
    int item2Id = item2->getItemId();
    int item3Id = item3->getItemId();
};

TEST_F(ItemListSuite, DefaultConstructor) {
    EXPECT_THROW(ItemList(""), std::invalid_argument);
    EXPECT_NO_THROW(ItemList("lista"));
}
TEST_F(ItemListSuite, RemoveLast) {
    ASSERT_EQ(3, c.getListSize());
    ASSERT_EQ(item3Id, c.getItem(c.getListSize()).lock()->getItemId());
    c.removeItem(c.getListSize());
    ASSERT_EQ(item2Id, c.getItem(c.getListSize()).lock()->getItemId());
}
TEST_F(ItemListSuite, RemoveFirst) {
    ASSERT_EQ(3, c.getListSize());
    std::cout << c.getListSize() << std::endl;
    ASSERT_EQ(item1Id, c.getItem(1).lock()->getItemId());
    c.removeItem(1);
    std::cout << c.getListSize() << std::endl;
    ASSERT_EQ(2, c.getListSize());
    ASSERT_EQ(item2Id, c.getItem(1).lock()->getItemId());
}
TEST_F(ItemListSuite, AddAndBuyItem) {
    ASSERT_EQ(3, c.getListSize());
    ASSERT_EQ(item3Id, c.getItem(c.getListSize()).lock()->getItemId());
    ASSERT_EQ(c.getListSize(), c.getListSizeToBuyOnly());
    ASSERT_EQ(17, c.getPriceToStillBePaid());
    auto item4 = std::make_unique<Item>("Cheese", 5, 10);
    int item4Id = item4->getItemId();
    c.addItem(std::move(item4));
    ASSERT_EQ(4, c.getListSize());
    ASSERT_EQ(item4Id, c.getItem(c.getListSize()).lock()->getItemId());
    ASSERT_EQ(c.getListSize(), c.getListSizeToBuyOnly());
    ASSERT_EQ(67, c.getPriceToStillBePaid());

    c.checkItem(4);
    ASSERT_EQ(4, c.getListSize());
    ASSERT_EQ(3, c.getListSizeToBuyOnly());
    ASSERT_EQ(17, c.getPriceToStillBePaid());

    c.uncheckItem(4);
    ASSERT_EQ(4, c.getListSize());
    ASSERT_EQ(c.getListSize(), c.getListSizeToBuyOnly());
    ASSERT_EQ(67, c.getPriceToStillBePaid());
}

TEST_F(ItemListSuite, CheckAndUncheckItem) {
    ASSERT_EQ(3, c.getListSize());
    ASSERT_EQ(c.getListSize(), c.getListSizeToBuyOnly());
    ASSERT_EQ(17, c.getPriceToStillBePaid());

    c.checkItem(1);
    ASSERT_EQ(3, c.getListSize());
    ASSERT_EQ(2, c.getListSizeToBuyOnly());
    ASSERT_EQ(11, c.getPriceToStillBePaid());

    c.uncheckItem(1);
    ASSERT_EQ(3, c.getListSize());
    ASSERT_EQ(c.getListSize(), c.getListSizeToBuyOnly());
    ASSERT_EQ(17, c.getPriceToStillBePaid());
}

TEST_F(ItemListSuite, changeItemPriceAndQuantity) {
    ASSERT_EQ(3, c.getListSize());
    ASSERT_EQ(c.getListSize(), c.getListSizeToBuyOnly());
    ASSERT_EQ(17, c.getPriceToStillBePaid());

    c.changeItemQuantity(1, 6);
    ASSERT_EQ(29, c.getPriceToStillBePaid());

    c.changeItemPrice(1, 2);
    ASSERT_EQ(23, c.getPriceToStillBePaid());
}
// Aggiungere test