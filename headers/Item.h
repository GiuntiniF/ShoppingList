//
// Created by ubuntuwsl on 14/08/22.
//

#ifndef SHOPPINGLIST_ITEM_H
#define SHOPPINGLIST_ITEM_H


#include <string>

class Item {
public:
    Item(std::string name, float basePrice, float quantity);

    const std::string &getName() const;

    void setName(const std::string &name);

    virtual float calculatePrice() = 0;

    virtual void getItemInfo() = 0;

    virtual ~Item() = default;

private:
    std::string name;
    float basePrice;
    float quantity;
};


#endif //SHOPPINGLIST_ITEM_H
