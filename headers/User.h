//
// Created by francesco on 12/23/22.
//

#ifndef SHOPPINGLIST_USER_H
#define SHOPPINGLIST_USER_H


#include <string>
#include "ItemList.h"

class User {
public:
    explicit User(std::string name);

    const std::string &getName() const;
    void setName(const std::string &name);
    bool addList(std::string &name);
    bool addList(std::shared_ptr<ItemList> list);
    void printAllLists() const;
    void getListInfo(int listId) const;
private:
    int userId;
    static int usersCount;
    std::string name;
    std::list<std::shared_ptr<ItemList>> lists;
};


#endif //SHOPPINGLIST_USER_H
