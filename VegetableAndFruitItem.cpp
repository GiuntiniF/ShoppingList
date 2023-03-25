//
// Created by ubuntuwsl on 18/08/22.
//

#include "headers/VegetableAndFruitItem.h"

VegetableAndFruitItem::VegetableAndFruitItem(std::string name, float pricePerUnit, float quantity) :
        Item(
                std::move(name),
                pricePerUnit,
                quantity) {}

double VegetableAndFruitItem::calculatePrice() const {
    return (quantity >= 10) ? (Item::calculatePrice() * 0.6) : Item::calculatePrice();
}

