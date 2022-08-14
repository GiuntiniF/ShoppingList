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

