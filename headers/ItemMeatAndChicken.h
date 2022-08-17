//
// Created by ubuntuwsl on 15/08/22.
//

#ifndef SHOPPINGLIST_ITEMMEATANDCHICKEN_H
#define SHOPPINGLIST_ITEMMEATANDCHICKEN_H


#include <vector>
#include "Item.h"

class ItemMeatAndChicken : public Item {
public:

    explicit ItemMeatAndChicken(std::string name = "Chicken", float basePrice = 5, float quantity = 1);

    double calculatePrice() const override;

    ~ItemMeatAndChicken() override = default;

};


#endif //SHOPPINGLIST_ITEMMEATANDCHICKEN_H
