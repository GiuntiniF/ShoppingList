//
// Created by ubuntuwsl on 28/08/22.
//

#ifndef SHOPPINGLIST_ITEMLIST_H
#define SHOPPINGLIST_ITEMLIST_H


#include <string>
#include <memory>
#include <map>
#include <vector>
#include "Item.h"
#include "Subject.h"

class ItemList : public Subject {
public:
    explicit ItemList(std::string listName = "List");

    int getListId() const;
    void setListId(int listId);
    const std::string &getListName() const;
    void setListName(const std::string &listName);
    int getListSize() const;
    void addItem(std::shared_ptr<Item> item);
    void printList() const;
    void removeItem(int index);
    std::weak_ptr<Item> getItem(int index) const;
    const std::vector<std::shared_ptr<Item>> & getItems() const;

    static int getListIdCounter();

    void subscribe(std::weak_ptr<Observer> o) override;
    void unsubscribe(std::weak_ptr<Observer> o) override;
    void notify() override;

private:
    int listId;
    std::string listName;
    std::vector<std::shared_ptr<Item>> items;
    std::list<std::weak_ptr<Observer>> userList;

    static int listIdCounter;
};


#endif //SHOPPINGLIST_ITEMLIST_H
