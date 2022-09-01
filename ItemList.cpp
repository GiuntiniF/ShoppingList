//
// Created by ubuntuwsl on 28/08/22.
//

#include "headers/ItemList.h"

#include <utility>
#include <algorithm>
#include <iostream>

int ItemList::listIdCounter = 1;

ItemList::ItemList(std::string listName) : listId(listIdCounter++), listName(std::move(listName)) {}

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
}

void ItemList::printList() const {
    std::string listOutput;
    if(!items.empty())
    {
        int index = 1;
        for(const auto& item : items) {
            listOutput += std::to_string(index) + ") " + item->getItemInfo();
            index++;
        }
    } else
    {
        listOutput += "There are no items in the list yet";
    }
    std::cout << listOutput << std::endl;
}

void ItemList::removeItem() {
    items.pop_back();
}

void ItemList::removeItem(int index) {
    auto itr = items.begin();
    advance(itr, index - 1);
    items.erase(itr);
}

int ItemList::getListIdCounter() {
    return listIdCounter;
}

int ItemList::getListSize() const {
    return (int)items.size();
}
