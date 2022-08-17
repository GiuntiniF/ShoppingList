//
// Created by ubuntuwsl on 14/08/22.
//

#ifndef SHOPPINGLIST_ITEM_H
#define SHOPPINGLIST_ITEM_H


#include <string>
#include <list>

class Item {
public:
    const std::string& getName() const;
    void setName(const std::string &name);
    float getBasePrice() const;
    void setBasePrice(float basePrice);
    float getQuantity() const;
    void setQuantity(float quantity);
    const std::string &getCategoryName() const;

    float calculatePrice() const;

    virtual std::string getItemInfo() const;

    virtual ~Item() = default;

protected:
    Item(std::string name, float pricePerUnit, float quantity, std::string  categoryName);

    void isItemInList();

    std::string name;
    const std::string categoryName;
    float pricePerUnit;
    float quantity;
    std::list<std::string> itemList;
};


#endif //SHOPPINGLIST_ITEM_H
