//
// Created by ubuntuwsl on 14/08/22.
//

#ifndef SHOPPINGLIST_ITEM_H
#define SHOPPINGLIST_ITEM_H


#include <string>
#include <list>

class Item {
public:
    int getItemId() const;
    const std::string& getName() const;
    virtual void setName(const std::string &name);
    float getBasePrice() const;
    virtual void setBasePrice(float basePrice);
    float getQuantity() const;
    virtual void setQuantity(float quantity);
    const std::string &getCategoryName() const;
    bool isItemInList() const;
    void setItemInList(bool isItemInList);

    virtual double calculatePrice() const;

    virtual std::string getItemInfo() const;

    virtual ~Item() = default;

    bool isDiscounted() const;

    void setDiscounted(bool isDiscounted);

protected:
    Item(std::string name, float pricePerUnit, float quantity, bool discounted = false);

    //void isItemInCategoryList(std::string &name, const std::list<std::string> &itemCategories);
    int itemId;
    std::string name;
    //std::string categoryName;
    float pricePerUnit;
    float quantity;
    //std::list<std::string> itemCategories;
    bool discounted;
    bool itemInList;
    static int itemCount;
};


#endif //SHOPPINGLIST_ITEM_H
