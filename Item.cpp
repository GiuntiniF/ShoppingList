//
// Created by ubuntuwsl on 14/08/22.
//

#include "headers/Item.h"

#include <utility>
#include <algorithm>
#include <stdexcept>
#include <iostream>

int Item::itemCount = 0;

Item::Item(const std::string &name, float pricePerUnit, int quantity, bool discounted)
    : name(name), pricePerUnit(pricePerUnit), quantity(quantity), discounted(discounted) {
    if (this->name.empty()) {
        throw std::invalid_argument("Name cannot be empty.");
    }
    if (pricePerUnit < 0.0) {
        throw std::invalid_argument("Price per unit cannot be negative.");
    }
    if (quantity < 0) {
        throw std::invalid_argument("Quantity cannot be negative.");
    }
    Item::itemCount++;
    itemId = Item::itemCount;
}

int Item::getItemId() const {
    return itemId;
}
const std::string &Item::getName() const {
    return name;
}

void Item::setName(const std::string &name) {
    if (this->name.empty()) {
        std::cerr <<"Name cannot be empty." << std::endl;
        return;
    }
    this->name = name;
}

float Item::getBasePrice() const {
    return pricePerUnit;
}

void Item::setBasePrice(float basePrice) {
    if (this->name.empty()) {
        std::cerr <<"Price per unit cannot be negative." << std::endl;
        return;
    }
    this->pricePerUnit = basePrice;
}

int Item::getQuantity() const {
    return quantity;
}

void Item::setQuantity(int quantity) {
    if (this->name.empty()) {
        std::cerr <<"Quantity cannot be negative." << std::endl;
        return;
    }
    this->quantity = quantity;
}


double Item::calculatePrice() const {
    return discounted ? (pricePerUnit * quantity * 0.8) : (pricePerUnit * quantity);
}
std::string Item::getItemInfo() const {
    std::string discounted_text;
    if(discounted) {
        discounted_text = " (discounted)";
    }
    return name + ": id:" + std::to_string(itemId) + " - quantity:" + std::to_string(quantity) + " - base price:" + std::to_string(getBasePrice()) + " - price:" + std::to_string(calculatePrice()) + discounted_text + "\n";
}

bool Item::toggleDiscount() {
    discounted = !discounted;
    return discounted;
}

