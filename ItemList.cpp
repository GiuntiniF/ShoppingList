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
}

void ItemList::printList() const {
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
        listOutput += "There are no items in the list yet";
    }
    std::cout << listOutput << std::endl;
}

void ItemList::removeItem() {
    if(!items.empty()) {
        items.pop_back();
    } else {
        std::cout << listName << " is already empty" << std::endl;
    }
}

void ItemList::removeItem(int index) {
    if(!items.empty()) {
        auto itr = items.begin();
        advance(itr, index - 1);
        items.erase(itr);
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

