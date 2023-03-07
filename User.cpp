//
// Created by francesco on 12/23/22.
//
//TODO implementare pattern Observer per tener traccia del numero totale di oggetti da acquistare (complessivo, non per singola lista)
#include "headers/User.h"

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
    if(itr == lists.end()) return false;
    lists.erase(key);
    detach(std::move(myList));
    //update();
    return true;
}

void User::printAllLists() const {
    std::string r;
    if(!lists.empty())
    {
        for(const auto& itr : lists) {
            auto list = itr.second;
            r += "\nList Name: " + list->getListName() + ", serial: " + std::to_string(list->getListId()) + ", number of items: " + std::to_string(list->getListSize()) + "\n";
            r += list->printList() + "\n-------------------------------------------------";
        }
    } else
    {
        r += getName() + " has no lists";
    }
    std::cout << r << std::endl;
}

bool User::getListInfo(int listId) const {
    if(listId < 0)
    {
        return false;
    }
    else {
        auto myList = lists.find(listId);
        if(myList == lists.end()) {
            std::cout << "No item with given listId" << std::endl;
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
    numberOfItemsToBuy = 0;
    numberOfLists = 0;
    for(auto &list : lists) {
        numberOfItemsToBuy += list.second->getListSize();
        numberOfLists++;
    }
}

void User::attach(std::shared_ptr<Subject> list) {
    if(list) {
        list->subscribe(std::make_shared<User>(*this));
        update();
    }
}

void User::detach(std::shared_ptr<Subject> list) {
    if(list) {
        list->unsubscribe(std::make_shared<User>(*this));
        update();
    }
}

int User::getNumberOfItemsToBuy() const {
    return numberOfItemsToBuy;
}

const std::map<int, std::shared_ptr<ItemList>> & User::getLists() const {
    return lists;
}

int User::getNumberOfLists() const {
    return numberOfLists;
}

