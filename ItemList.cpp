//
// Created by ubuntuwsl on 28/08/22.
//

#include "headers/ItemList.h"

#include <utility>
#include <algorithm>
#include <iostream>

int ItemList::listIdCounter = 0;

ItemList::ItemList(std::string listName) : listName(std::move(listName)) {
    ItemList::listIdCounter++;
    listId = ItemList::listIdCounter;
}

int ItemList::getListId() const {
    return listId;
}

void ItemList::setListId(int listId) {
    ItemList::listId = listId;
}

const std::string &ItemList::getListName() const {
    return listName;
}

void ItemList::setListName(const std::string &listName) {
    ItemList::listName = listName;
}

void ItemList::addItem(std::shared_ptr<Item> item) {
    items.push_back(std::move(item));
    items.back()->setItemInList(true);
    this->notify();
}

std::string ItemList::printList() const {
    std::string listOutput;
    if(!items.empty())
    {
        int index = 1;
        for(const auto& item : items) {
            listOutput += item->getItemInfo();
            index++;
        }
    } else
    {
        listOutput += "Empty List";
    }
    return listOutput;
}

void ItemList::removeItem() {
    if(!items.empty()) {
        items.pop_back();
        this->notify();
    } else {
        std::cout << listName << " is already empty" << std::endl;
    }
}

void ItemList::removeItem(int index) {
    if(!items.empty()) {
        auto itr = items.begin();
        advance(itr, index - 1);
        items.erase(itr);
        this->notify();
    } else {
        std::cout << listName << " is already empty" << std::endl;
    }
}

std::shared_ptr<Item> ItemList::getItem(int index) const {
    auto itr = items.begin();
    advance(itr, index - 1);
    return *itr;
}
int ItemList::getListIdCounter() {
    return listIdCounter;
}

int ItemList::getListSize() const {
    return (int)items.size();
}

void ItemList::subscribe(std::weak_ptr<Observer> o) {
    userList.push_back(o);
}

void ItemList::unsubscribe(std::weak_ptr<Observer> o) {
    std::shared_ptr<Observer> mydelete = o.lock();
    auto it = userList.begin();
    while (it != userList.end()) {
        if (it->expired()) {
            it = userList.erase(it);
        } else {
            std::shared_ptr<Observer> tmpptr = it->lock();
            if (tmpptr) {
                if (tmpptr == mydelete) {
                    it = userList.erase(it);
                    continue;
                }
            }
            ++it;
        }
    }
}

void ItemList::notify() {
    for (const auto &user: userList) {
        user.lock()->update();
    }
}