//
// Created by ubuntuwsl on 15/08/22.
//

#include "headers/MeatAndChickenItem.h"

MeatAndChickenItem::MeatAndChickenItem(std::string name, float pricePerUnit, int quantity, int type) :
        Item(
                std::move(name),
                pricePerUnit,
                quantity, type) {}

double MeatAndChickenItem::calculatePrice() const {
    return (quantity >= 5) ? (Item::calculatePrice() * 0.8) : Item::calculatePrice();
}
