//
// Created by ubuntuwsl on 15/08/22.
//

#ifndef SHOPPINGLIST_ITEMMEATANDCHICKEN_H
#define SHOPPINGLIST_ITEMMEATANDCHICKEN_H


#include <vector>
#include "Item.h"

class ItemMeatAndChicken : public Item {
public:

    ItemMeatAndChicken(const std::string& name, float basePrice, float quantity);

    void getItemInfo() override;

    ~ItemMeatAndChicken() override = default;
};


#endif //SHOPPINGLIST_ITEMMEATANDCHICKEN_H
