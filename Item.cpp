//
// Created by ubuntuwsl on 14/08/22.
//

#include "headers/Item.h"

#include <utility>
#include <algorithm>
#include <stdexcept>
#include <iostream>

Item::Item(std::string name, float pricePerUnit, float quantity, std::string categoryName,
           std::list<std::string>  itemList)
        : name(std::move(name)), pricePerUnit(pricePerUnit), quantity(quantity), categoryName(std::move(categoryName)), itemList(std::move(itemList)) {
    isItemInList();
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
    return name + ": quantity:" + std::to_string(quantity) + " - price:" + std::to_string(calculatePrice());
}

void Item::isItemInList() {
    std::string toUpperName = name;
    std::cout << toUpperName << std::endl;
    std::for_each(toUpperName.begin(), toUpperName.end(), [](char & c){
        c = ::toupper(c);
    });

    bool itemPresent =  std::any_of(itemList.begin(), itemList.end(), [=](const std::string& itemType) {
        return !itemType.empty() && itemType == toUpperName;
    });
    if(!itemPresent) {
        throw std::invalid_argument(name+ " is not present in " + categoryName);
    }
}




