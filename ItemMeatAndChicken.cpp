//
// Created by ubuntuwsl on 15/08/22.
//

#include <stdexcept>
#include "headers/ItemMeatAndChicken.h"

ItemMeatAndChicken::ItemMeatAndChicken(std::string name, float pricePerUnit, float quantity) :
    Item(std::move(name),
         pricePerUnit,
         quantity,
         "Meat and Chicken"
     ){
    itemList = {"Chicken", "Ham", "Sausage", "Turkey"};
    isItemInList();
}

double ItemMeatAndChicken::calculatePrice() const {
    double normalPrice = Item::calculatePrice();
    return quantity >= 5 ? (normalPrice * 0.8) : normalPrice;
}
