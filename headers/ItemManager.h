//
// Created by ubuntuwsl on 05/09/22.
//

#ifndef SHOPPINGLIST_ITEMMANAGER_H
#define SHOPPINGLIST_ITEMMANAGER_H

#include <list>
#include <map>
#include <memory>
#include "Item.h"

class ItemManager {
public:
    ItemManager();
    std::unique_ptr<Item> createItem(int category, const std::string &name, float pricePerUnit = 1, int quantity = 1);
    void printCategories();
    const std::map<int, std::string> &getCategories();
private:
    std::map<int, std::string> categories;
};


#endif //SHOPPINGLIST_ITEMMANAGER_H
