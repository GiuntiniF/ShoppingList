//
// Created by ubuntuwsl on 15/08/22.
//

#include "headers/ItemMeatAndChicken.h"

void ItemMeatAndChicken::getItemInfo() {

}

ItemMeatAndChicken::ItemMeatAndChicken(const std::string& name, float pricePerUnit, float quantity) : Item(name, pricePerUnit, quantity) {
    itemList = {"Chicken", "Ham", "Sausage", "Turkey"};
    categoryName = "Meat and Chicken";
    isItemInList();
}
