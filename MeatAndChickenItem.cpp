//
// Created by ubuntuwsl on 15/08/22.
//

#include "headers/MeatAndChickenItem.h"

MeatAndChickenItem::MeatAndChickenItem(std::string name, float pricePerUnit, float quantity, bool discounted) :
        Item(
                std::move(name),
                pricePerUnit,
                quantity,
                "Meat and Chicken",
                {"CHICKEN", "HAM", "SAUSAGE", "TURKEY"}, false) {}

double MeatAndChickenItem::calculatePrice() const {
    return (quantity >= 5 && discounted) ? (Item::calculatePrice() * 0.8) : Item::calculatePrice();
}
