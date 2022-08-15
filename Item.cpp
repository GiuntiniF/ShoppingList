//
// Created by ubuntuwsl on 14/08/22.
//

#include "headers/Item.h"

#include <utility>

Item::Item(std::string name, float basePrice, float quantity) : name(std::move(name)), basePrice(basePrice), quantity(quantity) {}

const std::string &Item::getName() const {
    return name;
}

void Item::setName(const std::string &name) {
    Item::name = name;
}

float Item::getBasePrice() const {
    return basePrice;
}

void Item::setBasePrice(float basePrice) {
    Item::basePrice = basePrice;
}

float Item::getQuantity() const {
    return quantity;
}

void Item::setQuantity(float quantity) {
    Item::quantity = quantity;
}

float Item::calculatePrice() {
    return basePrice * quantity;
}

