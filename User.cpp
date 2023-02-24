//
// Created by francesco on 12/23/22.
//

#include "headers/User.h"

#include <memory>
#include <utility>
#include <iostream>
#include <algorithm>

int User::usersCount = 0;

User::User(std::string name): name(std::move(name)) {
    User::usersCount++;
    userId = User::usersCount;
}

const std::string &User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    User::name = name;
}

bool User::addList(std::string listName) {
    lists.push_back(std::make_shared<ItemList>(listName));
    return true;
}

bool User::addList(std::shared_ptr<ItemList> list) {
    if(list == nullptr) return false;
    lists.push_back(list);
    return true;
}

void User::printAllLists() const {
    std::string r;
    if(!lists.empty())
    {
        for(const auto& list : lists) {
            r += "name: " + list->getListName() + ", serial: " + std::to_string(list->getListId()) + "\n";
        }
    } else
    {
        r += getName() + " has no lists";
    }
    std::cout << r << std::endl;
}

void User::getListInfo(int listId) const {
    if(listId < 0)
    {
        std::cout << "Invalid List Id" << std::endl;
    }
    else {
        auto myList = std::find_if(lists.begin(), lists.end(), [listId](const std::shared_ptr<ItemList> list){
            return list->getListId() == listId;
        });

        if(myList == lists.end()) {
            std::cout << "No item with given listId" << std::endl;
        } else {
            myList->get()->printList();
        }
    }
}

int User::getUserId() const {
    return userId;
}

int User::getListCount() const {
    return static_cast<int>(lists.size());
}

int User::getUsersCount() {
    return User::usersCount;
}
