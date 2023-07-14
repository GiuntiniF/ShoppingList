//
// Created by ubuntuwsl on 15/08/22.
//

#ifndef SHOPPINGLIST_MEATANDCHICKENITEM_H
#define SHOPPINGLIST_MEATANDCHICKENITEM_H

#include "Item.h"

class MeatAndChickenItem : public Item {
public:

    explicit MeatAndChickenItem(std::string name, float pricePerUnit, int quantity, int type);

    double calculatePrice() const override;

    ~MeatAndChickenItem() override = default;

};


#endif //SHOPPINGLIST_MEATANDCHICKENITEM_H
