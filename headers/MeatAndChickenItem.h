//
// Created by ubuntuwsl on 15/08/22.
//

#ifndef SHOPPINGLIST_MEATANDCHICKENITEM_H
#define SHOPPINGLIST_MEATANDCHICKENITEM_H


#include <vector>
#include "Item.h"

class MeatAndChickenItem : public Item {
public:

    explicit MeatAndChickenItem(std::string name = "Chicken", float basePrice = 5, float quantity = 1);

    double calculatePrice() const override;

    ~MeatAndChickenItem() override = default;

};


#endif //SHOPPINGLIST_MEATANDCHICKENITEM_H
