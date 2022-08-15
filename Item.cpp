//
// Created by ubuntuwsl on 14/08/22.
//

#include "headers/Item.h"

#include <utility>
#include <algorithm>
#include <stdexcept>

Item::Item(const std::string& name, float pricePerUnit, float quantity) : name(name), pricePerUnit(pricePerUnit), quantity(quantity) {}

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

float Item::getQuantity() const {
    return quantity;
}

void Item::setQuantity(float quantity) {
    Item::quantity = quantity;
}

float Item::calculatePrice() {
    return pricePerUnit * quantity;
}

void Item::isItemInList() {
    auto start = itemList.begin();
    auto end = itemList.end();
    bool itemPresent =  std::any_of(start, end, [pattern = getName()](const std::string& itemType) {
        return itemType.size() > 0 && itemType == pattern;
    });
    if(!itemPresent) {
        throw std::invalid_argument(name+ "is no present in " + categoryName);
    }
}

