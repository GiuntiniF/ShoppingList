//
// Created by ubuntuwsl on 18/08/22.
//

#include "headers/VegetableAndFruitItem.h"

VegetableAndFruitItem::VegetableAndFruitItem(std::string name, float pricePerUnit, float quantity, bool hasDiscount) :
        Item(
            std::move(name),
            pricePerUnit,
            quantity,
            "Vegetable and Fruit",
            {"Lettuce", "Cabbage", "Potato", "Onion", "Apple", "Banana", "Blueberry"}), hasDiscount(hasDiscount) {

}

double VegetableAndFruitItem::calculatePrice() const {
    return hasDiscount ? (Item::calculatePrice() * 0.6) : Item::calculatePrice();
}

bool VegetableAndFruitItem::isDiscounted() const {
    return hasDiscount;
}

void VegetableAndFruitItem::setIsDiscounted(bool isDiscounted) {
    VegetableAndFruitItem::hasDiscount = isDiscounted;
}
