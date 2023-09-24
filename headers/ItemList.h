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

    const std::string &getListName() const;

    int getListSize() const;
    int getListSizeToBuyOnly() const;
    double getPriceToStillBePaid() const;
    void addItem(std::shared_ptr<Item> item);
    void printList() const;
    void removeItem(int index);
    bool checkItem(int index);
    bool uncheckItem(int index);
    std::weak_ptr<Item> getItem(int index) const;
    const std::vector<std::shared_ptr<Item>> & getItems() const;

    static int getListIdCounter();

    void subscribe(Observer &o) override;
    void unsubscribe(Observer &o) override;
    void notify() override;

private:
    int listId;
    std::string listName;
    std::vector<std::shared_ptr<Item>> items;
    std::list<std::reference_wrapper<Observer>> userList;

    static int listIdCounter;
};


#endif //SHOPPINGLIST_ITEMLIST_H
