//
// Created by ubuntuwsl on 05/09/22.
//

#ifndef SHOPPINGLIST_ITEMMANAGER_H
#define SHOPPINGLIST_ITEMMANAGER_H

//FIXME sostituire enum con mappa per fare controlli in main su categoria inserita
#include <list>
#include <map>
#include "Item.h"

class ItemManager {
public:
    ItemManager();
    std::unique_ptr<Item> createItem(int category, const std::string &name, float pricePerUnit = 1, float quantity = 1);
    void printCategories();
    const std::map<int, std::string> &getCategories();
private:
    std::map<int, std::string> categories;
};


#endif //SHOPPINGLIST_ITEMMANAGER_H
