//
// Created by ubuntuwsl on 18/08/22.
//

#ifndef SHOPPINGLIST_VEGETABLEANDFRUITITEM_H
#define SHOPPINGLIST_VEGETABLEANDFRUITITEM_H


#include "Item.h"

class VegetableAndFruitItem : public Item {
public:
    explicit VegetableAndFruitItem(std::string name, float pricePerUnit, int quantity, int type);

    double calculatePrice() const override;

    ~VegetableAndFruitItem() override = default;
};


#endif //SHOPPINGLIST_VEGETABLEANDFRUITITEM_H
