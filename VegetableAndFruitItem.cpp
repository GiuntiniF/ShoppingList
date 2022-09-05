//
// Created by ubuntuwsl on 18/08/22.
//

#include "headers/VegetableAndFruitItem.h"

VegetableAndFruitItem::VegetableAndFruitItem(std::string name, float pricePerUnit, float quantity, bool discounted) :
        Item(
                std::move(name),
                pricePerUnit,
                quantity,
                discounted) {}

double VegetableAndFruitItem::calculatePrice() const {
    return discounted ? (Item::calculatePrice() * 0.6) : Item::calculatePrice();
}

