//
// Created by francesco on 12/23/22.
//

#ifndef SHOPPINGLIST_USER_H
#define SHOPPINGLIST_USER_H


#include <string>
#include <map>
#include <memory>
#include <utility>
#include <iostream>
#include <algorithm>
#include "ItemList.h"

class User : public Observer {
public:
    int getNumberOfItemsAdded() const;
    int getNumOfItemsUsingQuantity() const;
    int getNumberOfLists() const;
    explicit User(std::string name);

    int getUserId() const;
    const std::string &getName() const;
    void setName(const std::string &name);
    bool addList(std::shared_ptr<ItemList> &list);
    bool removeList(int key);
    int getListCount() const;
    void printAllLists() const;
    bool getListInfo(int listId) const;
    static int getUsersCount();

    const std::map<int, std::shared_ptr<ItemList>> & getLists() const;

    void update() override;

    void attach(std::shared_ptr<Subject> list) override;

    void detach(std::shared_ptr<Subject> list) override;

    int getNumberOfItemsLeftToBuy() const;

private:
    std::map<int, std::shared_ptr<ItemList>> lists;
    int userId;
    static int usersCount;
    std::string name;
    int numberOfItemsAdded = 0;
    int numberOfLists = 0;
    int numOfItemsUsingQuantity = 0;
    int numberOfItemsLeftToBuy = 0;
};


#endif //SHOPPINGLIST_USER_H
