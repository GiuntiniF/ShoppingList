//
// Created by ubuntuwsl on 14/08/22.
//

#include "Item.h"
#include "headers/VegetableAndFruitItem.h"
#include "headers/Item.h"

#include <utility>
#include <algorithm>
#include <stdexcept>
#include <iostream>

Item::Item(std::string name, float pricePerUnit, float quantity, std::string categoryName,
           std::list<std::string> itemList, bool discounted)
        : name(std::move(name)), pricePerUnit(pricePerUnit), quantity(quantity), categoryName(std::move(categoryName)), itemCategories(std::move(itemList)), discounted(discounted) {
    isItemInCategoryList();
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

float Item::getQuantity() const {
    return quantity;
}

void Item::setQuantity(float quantity) {
    Item::quantity = quantity;
}

const std::string &Item::getCategoryName() const {
    return categoryName;
}

double Item::calculatePrice() const {
    return pricePerUnit * quantity;
}

std::string Item::getItemInfo() const {
    return name + ": quantity:" + std::to_string(quantity) + " - price:" + std::to_string(calculatePrice()) + "\n";
}

void Item::isItemInCategoryList() {
    std::string toUpperName = name;
    std::for_each(toUpperName.begin(), toUpperName.end(), [](char & c){
        c = ::toupper(c);
    });

    bool itemPresent =  std::any_of(itemCategories.begin(), itemCategories.end(), [=](const std::string& itemType) {
        return !itemType.empty() && itemType == toUpperName;
    });
    if(!itemPresent) {
        throw std::invalid_argument(name+ " is not present in " + categoryName);
    }
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
    discounted = discounted;
}