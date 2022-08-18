//
// Created by ubuntuwsl on 15/08/22.
//

#include <stdexcept>
#include "headers/ItemMeatAndChicken.h"

ItemMeatAndChicken::ItemMeatAndChicken(std::string name, float pricePerUnit, float quantity) :
    Item(
        std::move(name),
        pricePerUnit,
        quantity,
        "Meat and Chicken",
        {"Chicken", "Ham", "Sausage", "Turkey"}) {}

double ItemMeatAndChicken::calculatePrice() const {
    return quantity >= 5 ? (Item::calculatePrice() * 0.8) : Item::calculatePrice();
}
