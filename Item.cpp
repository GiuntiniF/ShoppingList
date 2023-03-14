//
// Created by ubuntuwsl on 14/08/22.
//

#include "headers/Item.h"
#include "headers/NullItem.h"

#include <utility>
#include <algorithm>
#include <stdexcept>
#include <iostream>

int Item::itemCount = 0;

Item::Item(std::string name, float pricePerUnit, float quantity, bool discounted)
    : name(std::move(name)), pricePerUnit(pricePerUnit), quantity(quantity), discounted(discounted), itemInList(false) {
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
    Item::name = name;
}

float Item::getBasePrice() const {
    return pricePerUnit;
}

void Item::setBasePrice(float basePrice) {
    Item::pricePerUnit = basePrice;
}

int Item::getQuantity() const {
    return quantity;
}

void Item::setQuantity(int quantity) {
    Item::quantity = quantity;
}

double Item::calculatePrice() const {
    return pricePerUnit * quantity;
}

std::string Item::getItemInfo() const {
    return name + ": quantity:" + std::to_string(quantity) + " - price:" + std::to_string(calculatePrice()) + "\n";
}

bool Item::isItemInList() const {
    return itemInList;
}

void Item::setItemInList(bool isItemInList) {
    Item::itemInList = isItemInList;
}


bool Item::isDiscounted() const {
    return discounted;
}

void Item::setDiscounted(bool discounted) {
    this->discounted = discounted;
}