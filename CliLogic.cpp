//
// Created by francesco on 3/27/23.
//
#include <map>
#include <iostream>
#include "headers/Item.h"
#include "headers/ItemList.h"
#include "headers/ItemManager.h"
#include "headers/User.h"

typedef std::map<int, std::shared_ptr<User>> UserList;
typedef std::map<int, std::weak_ptr<ItemList>> ShoppingLists;

void help() {
    std::cout << "---USER RELATED COMMANDS---" << std::endl;
    std::cout << "addUser: create a new User by adding the Username" << std::endl;
    std::cout << "printUsers: prints a list of all the users " << std::endl;
    std::cout << "login: select the user you want to login with using the user Id" << std::endl;
    std::cout << "logout: logout from the logged user" << std::endl;
    std::cout << "deleteUser: delete a User from the application (must be logged as said user)" << std::endl;
    std::cout << "addNewList: create a new Shopping List and assign it to the current user (must be logged as said user)" << std::endl;
    std::cout << "addExistingList: add an existing Shopping List to this user using the Id of the list (must be logged as said user)" << std::endl;
    std::cout << "printAllLists: prints all the user's Shopping Lists and their contents (must be logged as said user)" << std::endl;
    std::cout << "removeList: removes a list from the user using the Id of the list, deleting it if it isn't assigned to any user (must be logged as a user having said list)" << std::endl;
    std::cout << "selectList: select a list to work on using the Id of the list (must be logged as a user having said list)" << std::endl;
    std::cout << std::endl;
    std::cout << "---LIST RELATED COMMANDS---" << std::endl;
    std::cout << "addItem: adds a new item to the selected list (said list must be selected first using the selectList command)" << std::endl;
    std::cout << "selectItem: selects one of the items of the list to work with (said list must be selected first using the selectList command)" << std::endl;
    std::cout << std::endl;
    std::cout << "---ITEM RELATED COMMANDS---" << std::endl;
    std::cout << "renameItem: changes the name of an item (said item must be selected using the selectItem command)" << std::endl;
    std::cout << "changePrice: changes the price per unit of an item (said item must be selected using the selectItem command)" << std::endl;
    std::cout << "changeQuantity: changes the quantity per unit of an item (said item must be selected using the selectItem command)" << std::endl;
    std::cout << "removeItem: removes an item from the selected list (said list must be selected first using the selectList command)" << std::endl;
    std::cout << std::endl;
    std::cout << "---GENERAL COMMANDS---" << std::endl;
    std::cout << "help: print this very helpful guide again" << std::endl;
    std::cout << "exit: close the application" << std::endl;
}

void notLoggedError() {
    std::cout << "You are not logged as an user" << std::endl;
}

void noListSelectedError() {
    std::cout << "No List has been selected" << std::endl;
}

void noItemSelectedError() {
    std::cout << "No Item has been selected" << std::endl;
}

void clearListMap(ShoppingLists& listMap) {
    auto it = listMap.begin();
    while (it != listMap.end()) {
        if (it->second.expired()) {
            it = listMap.erase(it);
        } else {
            it++;
        }
    }
}

void clearListMap(ShoppingLists& listMap, int key) {
    auto it = listMap.find(key);
    if (it != listMap.end()) {
        if (it->second.expired()) {
            listMap.erase(it);
        }
    }
}

void addUser(UserList& userMap) {
    std::cout << "Insert the username >>" << std::endl;
    std::string newUsername;
    getline(std::cin, newUsername);
    std::unique_ptr<User> newUser = std::make_unique<User>(newUsername);
    int myId = newUser->getUserId();
    userMap.insert(std::make_pair<int, std::unique_ptr<User>>(newUser->getUserId(), std::move(newUser)));
    std::cout << "User " << newUsername << " (userId: " << myId << ") was successfully added" << std::endl;
}

void printUsers(UserList& userMap) {
    if(!userMap.empty()) {
        for (const auto& [userId, User]: userMap) {
            std::cout << userId << ": " << User->getName() << std::endl;
        }
    } else {
        std::cout << "No user has been inserted" << std::endl;
    }
}

bool login(UserList& userMap, std::weak_ptr<User>& currentUser) {
    std::cout << "Insert the id of the user you want to select >>" << std::endl;
    int tmpUserId;
    std::cin >> tmpUserId;
    if(!tmpUserId) {
        std::cout << "Insert a valid userId" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    } else
    if(userMap.empty()) {
        std::cout << "No user to login as has been inserted" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    } else {
        auto itr = userMap.find(tmpUserId);
        if(itr != userMap.end()) {
            currentUser = itr->second;
        } else {
            std::cout << "No user with the given key was found!" << std::endl;
        }
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    return true;
}

bool logout(std::weak_ptr<User> &currentUser, std::weak_ptr<ItemList> &currentList, std::pair<int, std::weak_ptr<Item>> &currentItem) {
    if(currentUser.expired()) {
        notLoggedError();
        notLoggedError();
        return false;
    }
    currentUser.reset();
    currentList.reset();
    currentItem.second.reset();
    std::cout << "You have logged out" << std::endl;
    return true;
}

bool deleteUser(UserList& userMap, ShoppingLists& listMap, std::weak_ptr<User>& currentUser, std::weak_ptr<ItemList> &currentList, std::pair<int, std::weak_ptr<Item>> &currentItem) {
    if(currentUser.expired()) {
        notLoggedError();
        return false;
    }
    if(userMap.empty()) {
        return false;
    }
    auto itr = userMap.find(currentUser.lock()->getUserId());
    if(itr != userMap.end()) {
        std::cout << "The current user and all his lists that are not shared with other users will be deleted, asre you sure you want to continue? (y,N)?" << std::endl;
        std::string response;
        std::getline(std::cin, response);
        if(response=="y") {
            //per messaggio di ocnferma di cancellazione dell'user
            std::string userNameForMessage = currentUser.lock()->getName();
            userMap.erase(itr->first);
            currentUser.reset();
            currentList.reset();
            currentItem.second.reset();
            clearListMap(listMap);
            return true;
        } else return false;
    } else return false;
}

bool addNewList(ShoppingLists& listMap, const std::weak_ptr<User>& currentUser) {
    if(currentUser.expired()) {
        notLoggedError();
        return false;
    }
    std::string listName;
    std::cout << "Insert the new list name >>" << std::endl;
    std::getline(std::cin, listName);
    std::shared_ptr<ItemList> newList = std::make_shared<ItemList>(listName);
    std::weak_ptr<ItemList> newList2 = newList;
    listMap.insert(std::pair<int, std::weak_ptr<ItemList>>(newList->getListId(), std::move(newList2)));
    currentUser.lock()->addList(newList);
    return true;
}

bool addExistingList(const ShoppingLists& listMap, const std::weak_ptr<User>& currentUser) {
    if(currentUser.expired()) {
        notLoggedError();
        return false;
    }
    std::cout << "Insert the id of the list you want to add >>" << std::endl;
    int tmpListId;
    std::cin >> tmpListId;
    if(!tmpListId) {
        std::cout << "Insert a valid list id" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    } else
    if(listMap.empty()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    } else {
        auto itr = listMap.find(tmpListId);
        if(itr != listMap.end()) {
            std::shared_ptr<ItemList> tmpList = itr->second.lock();
            currentUser.lock()->addList(tmpList);
        } else {
            std::cout << "No list with the given id was found!" << std::endl;
        }
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    return true;
}
bool printAllLists( const std::weak_ptr<User>& currentUser) {
    if (currentUser.expired()) {
        notLoggedError();
        return false;
    }
    currentUser.lock()->printAllLists();
    return true;
}
void removeList(ShoppingLists& listMap, std::weak_ptr<User>& currentUser, std::weak_ptr<ItemList> &currentList, std::pair<int, std::weak_ptr<Item>> &currentItem) {
    if(currentList.expired()) {
        noListSelectedError();
        return;
    }
    if(listMap.empty()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    } else {
        int myId = currentList.lock()->getListId();
        if(currentUser.lock()->removeList(myId)) {
            auto itr = listMap.find(myId);
            currentList.reset();
            currentItem.second.reset();
            clearListMap(listMap, myId);
        }
    }
}
//FIXME sistema caso in cui non inserito id valido
bool selectList(ShoppingLists& listMap, const std::weak_ptr<User>& currentUser,std::weak_ptr<ItemList>& currentList) {
    if(currentUser.expired()) {
        notLoggedError();
        return false;
    }
    if(currentUser.lock()->getNumberOfLists() == 0) {
        std::cout << "No list to select" << std::endl;
        return false;
    }
    std::cout << "Insert the Id of the list you want to select >>" << std::endl;
    int tmpListId;
    std::cin >> tmpListId;
    if(!tmpListId) {
        std::cout << "Insert a valid list Id" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    } else
    if(listMap.empty()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    } else {
        auto mylist = currentUser.lock()->getLists();
        auto itr = mylist.find(tmpListId);
        if(itr != mylist.end()) {
            currentList = itr->second;
        } else {
            std::cout << currentUser.lock()->getName() <<" doesn't have any list with the given Id" << std::endl;
            return false;
        }
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    return true;
}

void printList(const std::weak_ptr<ItemList>& currentList) {
    if(currentList.expired()) {
        noListSelectedError();
        return;
    }
    currentList.lock()->printList();
}

bool addItem(std::weak_ptr<ItemList>& currentList, ItemManager& itemManager) {
    if(currentList.expired()) {
        noListSelectedError();
        return false;
    }
    int itemCategory = -1;
    std::string itemName, response;
    float itemPricePerUnit = 0, itemQuantity = 0;
    std::cout << "Select one of the following Item Categories by inserting their Id" << std::endl;
    itemManager.printCategories();
    std::cout << " >>"<< std::endl;
    std::cin >> itemCategory;
    auto myCategories = itemManager.getCategories();
    if(myCategories.find(itemCategory) == myCategories.end()) {
        std::cout << "insert a valid item category" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return false;
    }
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Insert the name of the item you want to add >>" << std::endl;
    std::getline(std::cin, itemName);
    if(itemName.empty()) {
        std::cout << "insert a valid item name" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return false;
    }
    std::cin.clear();
    std::cout << "Insert the price per unit of the item you want to add >>" << std::endl;
    std::cin >> itemPricePerUnit;
    if(itemPricePerUnit<=0) {
        std::cout << "insert a valid price" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return false;
    }
    std::cout << "Insert how many of said items you want to add >>" << std::endl;
    std::cin >> itemQuantity;
    if(itemQuantity<=0) {
        std::cout << "insert a valid number" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return false;
    }
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::unique_ptr<Item> newItem = itemManager.createItem(itemCategory, itemName, itemPricePerUnit, itemQuantity);
    currentList.lock()->addItem(std::move(newItem));
    return true;
}

void selectItem(std::weak_ptr<ItemList>& currentList, std::pair<int, std::weak_ptr<Item>>& currentItem) {
    if(currentList.expired()) {
        noListSelectedError();
        return;
    }
    if(currentList.lock()->getListSize() == 0) {
        std::cout << "No item to select" << std::endl;
        return;
    }
    int position = -1;
    std::cout << "Insert the position of the item in the list that you want to select >>" << std::endl;
    std::cin >> position;
    if(position && position>0) {
        if(position > currentList.lock()->getListSize()) {
            std::cout << "Insert a valid position" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            return;
        }
        currentItem.first = position;
        currentItem.second = currentList.lock()->getItem(position);
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    } else {
        std::cout << "Insert a valid position" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return;
    }
}

void removeItem(std::weak_ptr<ItemList>& currentList, std::pair<int, std::weak_ptr<Item>>& currentItem) {
    if(currentItem.second.expired()) {
        noItemSelectedError();
        return;
    }
    std::cout << "The current Item will be deleted, asre you sure you want to continue? (y,N)?" << std::endl;
    std::string response;
    std::getline(std::cin, response);
    if(response=="y") {
        currentList.lock()->removeItem(currentItem.first);
        currentItem.second.reset();
    }
}

void changePrice(std::pair<int, std::weak_ptr<Item>>& currentItem) {
    if(currentItem.second.expired()) {
        noItemSelectedError();
        return;
    }
    float newPrice = 0;
    std::cout << "Insert the new price of the item >>" << std::endl;
    std::cin >> newPrice;
    if(newPrice<=0) {
        std::cout << "Insert a valid price" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return;
    }
    currentItem.second.lock()->setBasePrice(newPrice);
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

void renameItem(std::pair<int, std::weak_ptr<Item>>& currentItem) {
    if(currentItem.second.expired()) {
        noItemSelectedError();
        return;
    }
    std::string newName;
    std::cout << "Insert the new name of the item >>" << std::endl;
    std::getline(std::cin, newName);
    if(newName.empty()) {
        std::cout << "Insert a valid name" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return;
    }
    currentItem.second.lock()->setName(newName);
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

void changeQuantity(std::pair<int, std::weak_ptr<Item>>& currentItem) {
    if(currentItem.second.expired()) {
        noItemSelectedError();
        return;
    }
    int newQuantity = 0;
    std::cout << "Insert the new quantity of the item >>" << std::endl;
    std::cin >> newQuantity;
    if(newQuantity<=0) {
        std::cout << "Insert a valid quantity" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return;
    }
    currentItem.second.lock()->setQuantity(newQuantity);
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}