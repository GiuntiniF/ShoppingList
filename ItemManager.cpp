//
// Created by ubuntuwsl on 05/09/22.
//

#include <memory>
#include <iostream>
#include "headers/ItemManager.h"
#include "headers/MeatAndChickenItem.h"
#include "headers/VegetableAndFruitItem.h"
#include "headers/NullItem.h"

std::unique_ptr<Item> ItemManager::createItem(int category, const std::string& name, float pricePerUnit, float quantity, bool discounted) {
    switch(category) {
        case MEATANDCHICKEN:
            if(!name.empty() && pricePerUnit > 0 && quantity > 0)
                return std::unique_ptr<Item>(new MeatAndChickenItem(name, pricePerUnit, quantity, discounted));
        case VEGETABLEANDFRUITS:
            if(!name.empty() && pricePerUnit > 0 && quantity > 0)
                return std::unique_ptr<Item>(new VegetableAndFruitItem(name, pricePerUnit, quantity, discounted));
        default:
            return std::unique_ptr<Item>(new NullItem());
    }
}

void ItemManager::printCategories() {
    std::cout << "0 - Meat and Chicken" << std::endl;
    std::cout << "1 - Vegetable and Fruits" << std::endl;

}

