//
// Created by ubuntuwsl on 18/08/22.
//

#include "headers/VegetableAndFruitItem.h"
#include "Item.h"

VegetableAndFruitItem::VegetableAndFruitItem(std::string name, float pricePerUnit, float quantity, bool discounted) :
        Item(
                std::move(name),
                pricePerUnit,
                quantity,
                "Vegetable and Fruit",
                {"LETTUCE", "CABBAGE", "POTATO", "ONION", "APPLE", "BANANA", "BLUEBERRY"}, discounted) {

}

double VegetableAndFruitItem::calculatePrice() const {
    return discounted ? (Item::calculatePrice() * 0.6) : Item::calculatePrice();
}

