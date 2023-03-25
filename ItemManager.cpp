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
std::unique_ptr<Item>
ItemManager::createItem(int category, const std::string &name, float pricePerUnit, float quantity) {
    switch(category) {
        case 1:
            if(!name.empty() && pricePerUnit > 0 && quantity > 0)
                return std::unique_ptr<Item>(new MeatAndChickenItem(name, pricePerUnit, quantity));
        case 2:
            if(!name.empty() && pricePerUnit > 0 && quantity > 0)
                return std::unique_ptr<Item>(new VegetableAndFruitItem(name, pricePerUnit, quantity));
        default:
            return std::unique_ptr<Item>(new NullItem());
    }
}
//TODO sistema stampa per dipendere da oggetto creato in costruttore
void ItemManager::printCategories() {
    std::cout << "1 - Meat and Chicken" << std::endl;
    std::cout << "2 - Vegetable and Fruits" << std::endl;
}

const std::map<int, std::string> &ItemManager::getCategories() {
    return categories;
}

