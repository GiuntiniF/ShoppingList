//
// Created by francesco on 12/23/22.
//

#include "headers/User.h"

int User::usersCount = 0;

User::User(std::string name): name(std::move(name)) {
    if (this->name.empty()) {
        throw std::invalid_argument("User Name cannot be empty.");
    }
    User::usersCount++;
    userId = User::usersCount;
}

const std::string &User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    if (this->name.empty()) {
        std::cerr << "User Name cannot be empty." << std::endl;
        return;
    }
    User::name = name;
}

bool User::addList(std::shared_ptr<ItemList> &list) {
    if(list == nullptr) return false;
    std::shared_ptr<ItemList> list2 = list;
    lists.insert(std::make_pair<int, std::shared_ptr<ItemList>>(list->getListId(), std::move(list)));
    attach(std::move(list2));
    return true;
}

bool User::removeList(int key) {
    auto itr = lists.find(key);
    std::shared_ptr<ItemList> myList = itr->second;
    if(itr == lists.end()) {
        std::cout << "No list with given listId" << std::endl;
        return false;
    }
    lists.erase(key);
    detach(std::move(myList));
    return true;
}

void User::printAllLists() const {
    std::string r;
    if(!lists.empty())
    {
        std::cout << "-------------------------------------------------" << std::endl;
        for(const auto& itr : lists) {
            auto list = itr.second;
            list->printList();
            std::cout << "-------------------------------------------------";
        }
    } else
    {
        std::cout << getName() << " has no lists";
    }
    std::cout << std::endl << std::endl;
}

bool User::getListInfo(int listId) const {
    if(listId < 0)
    {
        return false;
    }
    else {
        auto myList = lists.find(listId);
        if(myList == lists.end()) {
            std::cout << "No list with given listId" << std::endl;
            return false;
        } else {
            myList->second->printList();
        }
    }
    return true;
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

void User::update() {
    numOfItemsUsingQuantity = 0;
    numberOfItemsAdded = 0;
    numberOfLists = 0;
    for(auto &list : lists) {
        numberOfItemsAdded += list.second->getListSize();
        for(auto &item : list.second->getItems()) {
            numOfItemsUsingQuantity += item->getQuantity();
        }
        numberOfLists++;
    }
}

void User::attach(std::shared_ptr<Subject> list) {
    if(list) {
        list->subscribe(this->weak_from_this());
        update();
    }
}

void User::detach(std::shared_ptr<Subject> list) {
    if(list) {
        list->unsubscribe(this->weak_from_this());
        update();
    }
}

const std::map<int, std::shared_ptr<ItemList>> & User::getLists() const {
    return lists;
}

int User::getNumberOfLists() const {
    return numberOfLists;
}

int User::getNumberOfItemsAdded() const {
    return numberOfItemsAdded;
}

int User::getNumOfItemsUsingQuantity() const {
    return numOfItemsUsingQuantity;
}

