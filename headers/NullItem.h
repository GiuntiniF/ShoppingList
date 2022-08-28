//
// Created by ubuntuwsl on 28/08/22.
//

#ifndef SHOPPINGLIST_NULLITEM_H
#define SHOPPINGLIST_NULLITEM_H


#include "Item.h"

class NullItem : public Item {
public:
    NullItem();

    double calculatePrice() const override;

    std::string getItemInfo() const override;

    void setName(const std::string &name) override;

    void setBasePrice(float basePrice) override;

    void setQuantity(float quantity) override;

    ~NullItem() override = default;
};


#endif //SHOPPINGLIST_NULLITEM_H
