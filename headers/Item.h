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
    virtual void setName(const std::string &name);
    float getBasePrice() const;
    virtual void setBasePrice(float basePrice);
    float getQuantity() const;
    virtual void setQuantity(float quantity);
    const std::string &getCategoryName() const;

    virtual double calculatePrice() const;

    virtual std::string getItemInfo() const;

    virtual ~Item() = default;

protected:
    Item(std::string name, float pricePerUnit, float quantity, std::string categoryName,
         std::list<std::string> itemList, bool discounted = false);

    void isItemInList();

    std::string name;
    const std::string categoryName;
    float pricePerUnit;
    float quantity;
    std::list<std::string> itemList;
    bool discounted;
};


#endif //SHOPPINGLIST_ITEM_H
