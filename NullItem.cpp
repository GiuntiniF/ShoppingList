//
// Created by ubuntuwsl on 28/08/22.
//

#include <iostream>
#include "headers/NullItem.h"

NullItem::NullItem() : Item("NULL", 0, 0, "", {"NULL"}) {}

double NullItem::calculatePrice() const {
    return 0;
}

std::string NullItem::getItemInfo() const {std::cout << "Null Item" << std::endl;}

void NullItem::setName(const std::string &name) {}

void NullItem::setBasePrice(float basePrice) {}

void NullItem::setQuantity(float quantity) {}

