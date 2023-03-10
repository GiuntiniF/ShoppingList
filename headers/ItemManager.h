//
// Created by ubuntuwsl on 05/09/22.
//

#ifndef SHOPPINGLIST_ITEMMANAGER_H
#define SHOPPINGLIST_ITEMMANAGER_H


#include <list>
#include "Item.h"

class ItemManager {
public:
    static std::unique_ptr<Item> createItem(int category, const std::string& name, float pricePerUnit, float quantity, bool discounted = false);
    static void printCategories();
private:
    enum categories {
        MEATANDCHICKEN = 0,
        VEGETABLEANDFRUITS = 1,
    };
};


#endif //SHOPPINGLIST_ITEMMANAGER_H
