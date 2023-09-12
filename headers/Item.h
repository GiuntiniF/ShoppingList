//
// Created by ubuntuwsl on 14/08/22.
//

#ifndef SHOPPINGLIST_ITEM_H
#define SHOPPINGLIST_ITEM_H


#include <string>
#include <list>

class Item {
public:
    Item(const std::string &name, float pricePerUnit, int quantity, bool discounted = false);
    int getItemId() const;
    const std::string& getName() const;
    virtual void setName(const std::string &name);
    float getBasePrice() const;
    virtual void setBasePrice(float basePrice);
    int getQuantity() const;
    virtual void setQuantity(int quantity);
    bool toggleDiscount();
    virtual double calculatePrice() const;

    virtual std::string getItemInfo() const;

    virtual ~Item() = default;

private:
    int itemId;
    std::string name;
    float pricePerUnit;
    int quantity;
    bool discounted;
    static int itemCount;
};


#endif //SHOPPINGLIST_ITEM_H
