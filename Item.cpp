//
// Created by ubuntuwsl on 14/08/22.
//

#include "headers/Item.h"
#include "headers/NullItem.h"

#include <utility>
#include <algorithm>
#include <stdexcept>
#include <iostream>

Item::Item(std::string name, float pricePerUnit, float quantity, bool discounted)
    : name(std::move(name)), pricePerUnit(pricePerUnit), quantity(quantity), discounted(discounted), itemInList(false) {}

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
/*
const std::string &Item::getCategoryName() const {
    return categoryName;
}*/

double Item::calculatePrice() const {
    return pricePerUnit * quantity;
}

std::string Item::getItemInfo() const {
    return name + ": quantity:" + std::to_string(quantity) + " - price:" + std::to_string(calculatePrice()) + "\n";
}

//DEPRECATO
/*void Item::isItemInCategoryList(std::string &name, const std::list<std::string> &itemCategories) {
    std::for_each(name.begin(), name.end(), [](char & c){
        c = ::toupper(c);
    });

    bool itemPresent =  std::any_of(itemCategories.begin(), itemCategories.end(), [=](const std::string& itemType) {
        return !itemType.empty() && itemType == name;
    });
    if(!itemPresent) {
        throw std::invalid_argument(name+ " is not present in " + categoryName);
    }
}*/

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