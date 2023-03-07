#include <map>
#include <iostream>
#include "headers/Item.h"
#include "headers/ItemList.h"
#include "headers/User.h"

typedef std::map<int, std::shared_ptr<User>> UserList;
typedef std::map<int, std::weak_ptr<ItemList>> ShoppingLists;

//TODO addExistingList messaggio inserimento list id e se list id non presente in liste esistenti dare errore
//TODO stampare seriale e messaggio quando si aggiunge un user con successo
//TODO aggiungere funzione removeList per rimuovere una lista da uno user e cancellarla con la funzione clearListMap(key) usando overload per esaminare solo quella lista invecew di tutta la mappa se era l'ultimo user a possedere quella lista

void help() {
    std::cout << "---USER RELATED COMMANDS---" << std::endl;
    std::cout << "addUser: create a new User by adding the Username" << std::endl;
    std::cout << "printUsers: prints a list of all the users " << std::endl;
    std::cout << "login: select the user you want to login with" << std::endl;
    std::cout << "logout: logout from the logged user" << std::endl;
    std::cout << "deleteUser: delete a User from the application (must be logged as said user)" << std::endl;
    std::cout << "addNewList: create a new Shopping List and assign it to the current user (must be logged as said user)" << std::endl;
    std::cout << "addExistingList: add an existing Shopping List to this user using the Id of the list (must be logged as said user)" << std::endl;
    std::cout << "printAllLists: prints all the user's Shopping Lists and their contents (must be logged as said user)" << std::endl;
    std::cout << std::endl;
    std::cout << "---LIST RELATED COMMANDS---" << std::endl;
    std::cout << "selectList: selects one of the users list to work with (must be logged as said user)" << std::endl;
    std::cout << std::endl;
    std::cout << "---GENERAL COMMANDS---" << std::endl;
    std::cout << "exit: close the application" << std::endl;
}

void notLoggedError() {
    std::cout << "You are not logged as an user" << std::endl;
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

void addUser(UserList& userMap) {
    std::cout << "Insert the username >>" << std::endl;
    std::string newUsername;
    getline(std::cin, newUsername);
    std::unique_ptr<User> newUser = std::make_unique<User>(newUsername);
    userMap.insert(std::make_pair<int, std::unique_ptr<User>>(newUser->getUserId(), std::move(newUser)));
    std::cout << std::endl;
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

bool logout(std::weak_ptr<User>& currentUser) {
    if(currentUser.expired()) {
        notLoggedError();
        return false;
    }
    currentUser.reset();
    std::cout << "You have logged out" << std::endl;
    return true;
}

bool deleteUser(UserList& userMap, ShoppingLists& listMap, std::weak_ptr<User>& currentUser) {
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
            std::cout << "list map before clear" << std::endl;
            for(auto const& list : listMap) {
                std::cout << "Serial: " << list.second.lock()->getListId() << " use count:"<<  list.second.use_count() << std::endl;
            }
            clearListMap(listMap);
            std::cout << "list map after clear" << std::endl;
            for(auto const& list : listMap) {
                std::cout << "Serial: " << list.second.lock()->getListId() << " use count:"<<  list.second.use_count() << std::endl;
            }
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
    int tmpListId;
    std::cin >> tmpListId;
    if(!tmpListId) {
        std::cout << "Insert a valid list serial" << std::endl;
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
            std::cout << itr->second.use_count() << std::endl;
            std::shared_ptr<ItemList> tmpList = itr->second.lock();
            std::cout << tmpList.use_count() << std::endl;
            currentUser.lock()->addList(tmpList);
            std::cout << itr->second.use_count() << std::endl;
        } else {
            std::cout << "No list with the given serial was found!" << std::endl;
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

int main() {
    std::string cmd;
    ShoppingLists listMap;
    UserList userMap;
    std::weak_ptr<User> currentUser;
    std::weak_ptr<ItemList> currentList;

    std::cout << "Shopping List Manager" << std::endl;
    do {
        if(!currentUser.expired()) {
            std::cout << std::endl << "Logged User: " << currentUser.lock()->getName()
                        << ", currentLists: " << currentUser.lock()->getNumberOfLists()
                        << ", currentItems: " << currentUser.lock()->getNumberOfItemsToBuy() << std::endl;
        }
        std::cout << "Insert a command >> ";
        getline(std::cin, cmd);
        std::cout << std::endl;
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
            logout(currentUser);
        } else
        if(cmd == "deleteUser") {
            deleteUser(userMap,listMap,currentUser);
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
        if(cmd != "exit") {
            std::cout << "No command found with the given name, try using the help command" << std::endl;
        }
    } while(cmd != "exit");
    std::cout << "Closing Shopping List Manager..." << std::endl;
    return 0;
}
