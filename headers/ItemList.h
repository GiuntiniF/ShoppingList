//
// Created by ubuntuwsl on 28/08/22.
//

#ifndef SHOPPINGLIST_ITEMLIST_H
#define SHOPPINGLIST_ITEMLIST_H


#include <string>
#include <memory>
#include "Item.h"

class ItemList {
public:
    explicit ItemList(std::string listName = "List");

    int getListId() const;

    void setListId(int listId);

    const std::string &getListName() const;

    void setListName(const std::string &listName);

    int getListSize() const;

    void addItem(std::shared_ptr<Item> item);

    void printList() const;
    void removeItem();
    void removeItem(int index);

    std::shared_ptr<Item> getItem(int index) const;


    static int getListIdCounter();

private:
    int listId;
    std::string listName;
    std::list<std::shared_ptr<Item>> items;

    static int listIdCounter;
};


#endif //SHOPPINGLIST_ITEMLIST_H
