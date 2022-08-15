//
// Created by ubuntuwsl on 14/08/22.
//

#ifndef SHOPPINGLIST_ITEM_H
#define SHOPPINGLIST_ITEM_H


#include <string>
#include <list>

class Item {
public:
    const std::string &getName() const;
    void setName(const std::string &name);
    float getBasePrice() const;
    void setBasePrice(float basePrice);
    float getQuantity() const;
    void setQuantity(float quantity);
protected:
    Item(const std::string& name, float pricePerUnit, float quantity);


    void isItemInList();

    float calculatePrice();

    virtual void getItemInfo() = 0;

    virtual ~Item() = default;

    std::string name, categoryName;
    float pricePerUnit;
    float quantity;
    std::list<std::string> itemList;
};


#endif //SHOPPINGLIST_ITEM_H
