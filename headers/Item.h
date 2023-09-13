//
// Created by ubuntuwsl on 14/08/22.
//

#ifndef SHOPPINGLIST_ITEM_H
#define SHOPPINGLIST_ITEM_H


#include <string>
#include <list>

class Item {
public:
    Item(const std::string &name, float pricePerUnit, int quantity);
    int getItemId() const;
    const std::string& getName() const;
    virtual void setName(const std::string &name);
    float getBasePrice() const;
    virtual void setBasePrice(float basePrice);
    int getQuantity() const;
    virtual void setQuantity(int quantity);

    virtual double calculatePrice() const;

    virtual std::string getItemInfo() const;

    virtual ~Item() = default;

private:
    int itemId;
    std::string name;
    float pricePerUnit;
    int quantity;
    static int itemCount;
};


#endif //SHOPPINGLIST_ITEM_H
