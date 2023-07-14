//
// Created by ubuntuwsl on 14/08/22.
//

#include "headers/Item.h"
#include "headers/ItemManager.h"

#include <utility>
#include <algorithm>
#include <stdexcept>

int Item::itemCount = 0;

Item::Item(std::string name, float pricePerUnit, int quantity, int type, bool discounted)
    : name(std::move(name)), pricePerUnit(pricePerUnit), quantity(quantity), type(type), discounted(discounted) {
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
    this->name = name;
}

float Item::getBasePrice() const {
    return pricePerUnit;
}

void Item::setBasePrice(float basePrice) {
    this->pricePerUnit = basePrice;
}

int Item::getQuantity() const {
    return quantity;
}

void Item::setQuantity(int quantity) {
    this->quantity = quantity;
}

double Item::calculatePrice() const {
    return pricePerUnit * quantity;
}
std::string Item::getItemInfo() const {
    ItemManager itemManager;
    auto categories = itemManager.getCategories();
    return name + ": id:" + std::to_string(itemId) + " - type:" + categories[type] + " - quantity:" + std::to_string(quantity) + " - price:" + std::to_string(calculatePrice()) + "\n";
}

int Item::getType() const {
    return type;
}


