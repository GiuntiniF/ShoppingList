#include <map>
#include <iostream>
#include "headers/Item.h"
#include "headers/ItemList.h"
#include "headers/User.h"

#include "CliLogic.cpp"
int main() {
    std::string cmd;
    ShoppingLists listMap;
    UserList userMap;
    std::weak_ptr<User> currentUser;
    std::weak_ptr<ItemList> currentList;
    int currentItemPosition;
    std::pair<int, std::weak_ptr<Item>> currentItem;

    std::cout << "SHOPPING LIST MANAGER" << std::endl;
    std::cout << "if you need to, you can use the help command to see a list of all the possible action" << std::endl;
    do {
        if(!currentUser.expired()) {
            std::cout << std::endl << "-Logged User: " << currentUser.lock()->getName()
                        << ", number of lists: " << currentUser.lock()->getNumberOfLists()
                        << ", total items: " << currentUser.lock()->getNumOfItemsUsingQuantity()
                        << ", items left to buy: " << currentUser.lock()->getNumberOfItemsLeftToBuy() << std::endl;
        }
        if(!currentList.expired()) {
            std::cout << "-Selected List: " << currentList.lock()->getListName()
                        << ", Id:" << currentList.lock()->getListId()
                        << ", items left to buy:" << currentList.lock()->getListSizeToBuyOnly()
                        << ", total items:" << currentList.lock()->getListSize() << std::endl;

        }
        if(!currentItem.second.expired()) {
            std::cout << "-Selected Item: " << currentItem.second.lock()->getItemInfo() << std::endl;
        }
        std::cout << "Insert a command >> ";
        getline(std::cin, cmd);
        if(cmd == "help") {
            help();
        } else
        if(cmd == "addUser") {
            addUser(userMap);
        } else
        if(cmd == "printUsers") {
            printUsers(userMap);
        } else
        if(cmd == "login") {
            login(userMap, currentUser);
        } else
        if(cmd == "logout") {
            logout(currentUser, currentList, currentItem);
        } else
        if(cmd == "deleteUser") {
            deleteUser(userMap,listMap,currentUser, currentList, currentItem);
        } else
        if(cmd == "addNewList"){
            addNewList(listMap, currentUser);
        } else
        if(cmd == "addExistingList") {
            addExistingList(listMap, currentUser);
        } else
        if(cmd == "printAllLists") {
            printAllLists(currentUser);
        } else
        if(cmd == "selectList") {
            selectList(listMap, currentUser, currentList, currentItem);
        } else
        if(cmd == "removeList") {
            removeList(listMap, currentUser, currentList, currentItem);
        } else
        if(cmd == "printList") {
            printList(currentList);
        } else
        if(cmd == "addItem") {
            addItem(currentList);
        } else
        if(cmd == "selectItem") {
            selectItem(currentList, currentItem);
        } else
        if(cmd == "removeItem") {
            removeItem(currentList, currentItem);
        } else
        if(cmd == "renameItem") {
            renameItem(currentItem);
        } else
        if(cmd == "changePrice") {
            changePrice(currentItem);
        } else
        if(cmd == "changeQuantity") {
            changeQuantity(currentItem);
        } else
        if(cmd == "checkItem") {
            checkItem(currentList, currentItem);
        } else
        if(cmd == "uncheckItem") {
            uncheckItem(currentList, currentItem);
        } else
        if(cmd != "exit") {
            std::cout << "No command found with the given name, try using the help command" << std::endl;
        }
    } while(cmd != "exit");
    std::cout << "Closing Shopping List Manager..." << std::endl;
    return 0;
}
