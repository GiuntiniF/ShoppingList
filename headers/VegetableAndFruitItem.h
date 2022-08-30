//
// Created by ubuntuwsl on 18/08/22.
//

#ifndef SHOPPINGLIST_VEGETABLEANDFRUITITEM_H
#define SHOPPINGLIST_VEGETABLEANDFRUITITEM_H


#include "Item.h"

class VegetableAndFruitItem : public Item {
public:
    explicit VegetableAndFruitItem(std::string name = "Apple", float basePrice = 2, float quantity = 4, bool isDiscounted = true);

    bool isDiscounted() const;

    void setDiscounted(bool isDiscounted);

    double calculatePrice() const override;

    ~VegetableAndFruitItem() override = default;
};


#endif //SHOPPINGLIST_VEGETABLEANDFRUITITEM_H
