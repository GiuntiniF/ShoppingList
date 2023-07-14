//
// Created by ubuntuwsl on 05/09/22.
//

#include <memory>
#include <iostream>
#include "headers/ItemManager.h"
#include "headers/MeatAndChickenItem.h"
#include "headers/VegetableAndFruitItem.h"
#include "headers/NullItem.h"

ItemManager::ItemManager() {
    categories = {
        {1, "Meat and Chicken"},
        {2, "Vegetable and Fruits"}
    };
}
std::unique_ptr<Item>ItemManager::createItem(int category, const std::string &name, float pricePerUnit, int quantity) {
    switch(category) {
        case 1:
            if(!name.empty() && pricePerUnit > 0 && quantity > 0)
                return std::unique_ptr<Item>(new MeatAndChickenItem(name, pricePerUnit, quantity, category));
        case 2:
            if(!name.empty() && pricePerUnit > 0 && quantity > 0)
                return std::unique_ptr<Item>(new VegetableAndFruitItem(name, pricePerUnit, quantity, category));
        default:
            return std::unique_ptr<Item>(new NullItem());
    }
}
void ItemManager::printCategories() {
    for(auto& category : categories) {
        std::cout << category.first << " - " << category.second << std::endl;
    }
}

const std::map<int, std::string> &ItemManager::getCategories() {
    return categories;
}

