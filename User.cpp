//
// Created by francesco on 12/23/22.
//

#include "headers/User.h"

#include <memory>

const std::string &User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    User::name = name;
}

bool User::addList(std::string &name) {
    lists.push_back(std::make_shared<ItemList>(name));
    return true;
}

bool User::addList(std::shared_ptr<ItemList> list) {
    if(list == nullptr) return false;
    lists.push_back(list);
    return true;
}
