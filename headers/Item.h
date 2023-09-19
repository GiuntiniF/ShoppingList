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
    void setName(const std::string &name);
    float getBasePrice() const;
    void setBasePrice(float basePrice);
    int getQuantity() const;
    void setQuantity(int quantity);
    bool isBought() const;
    void setIsBought(bool is_bought);
    double calculatePrice() const;
    std::string getItemInfo() const;
private:
    int itemId;
    std::string name;
    float pricePerUnit;
    int quantity;
    bool is_bought = false;
    static int itemCount; //Usato per generare Id univoci autoincrementati per gli Item
};


#endif //SHOPPINGLIST_ITEM_H
