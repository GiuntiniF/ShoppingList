//
// Created by ubuntuwsl on 28/08/22.
//

#include "headers/ItemList.h"
#include <utility>
#include <algorithm>
#include <iostream>

int ItemList::listIdCounter = 0;

ItemList::ItemList(std::string listName) : listName(std::move(listName)) {
    if (this->listName.empty()) {
        throw std::invalid_argument("List Name cannot be empty.");
    }
    ItemList::listIdCounter++;
    listId = ItemList::listIdCounter;
}

int ItemList::getListId() const {
    return listId;
}

const std::string &ItemList::getListName() const {
    return listName;
}

void ItemList::addItem(std::shared_ptr<Item> item) {
    try {
        items.push_back( std::move(item));
        this->notify();
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void ItemList::printList() const {
    std::string listOutput;
    float totalPrice = 0;
    if(!items.empty()) {
        int pos = 1;
        for(const auto& item : items) {
            listOutput += "(" + std::to_string(pos) + ") " + item->getItemInfo();
            totalPrice += (float)item->calculatePrice();
            pos++;
        }
    } else {
        listOutput = "Empty List";
    }
    std::cout << "List Name: " << getListName() << ", serial: " << getListId()
        << ", number of items: " << getListSize()
        << ", items left to buy: " << getListSizeToBuyOnly()
        << ", total price: " << totalPrice
        << ", to be paid: " << getPriceToStillBePaid() << std::endl;
    std::cout << listOutput << std::endl;
}

void ItemList::removeItem(int index) {
    if(!items.empty()) {
        if(index <= 0 || index > items.size()) {
            std::cout << "Insert a valid position" << std::endl;
            return;
        }
        items.erase(items.begin() + (index - 1));
        this->notify();
    } else {
        std::cout << listName << " is already empty" << std::endl;
    }
}
std::weak_ptr<Item> ItemList::getItem(int index) const {
    if(!items.empty()) {
        if(index <= 0 || index > items.size()) {
            std::cout << "Insert a valid position " << std::endl;
            return std::shared_ptr<Item>(nullptr);
        }
        std::cout << index << std::endl;
        auto my = items[(index-1)];
        return my;
    } else {
        std::cout << listName << " is empty" << std::endl;
    }
    return std::shared_ptr<Item>(nullptr);
}
int ItemList::getListIdCounter() {
    return listIdCounter;
}

int ItemList::getListSize() const {
    return (int)items.size();
}

int ItemList::getListSizeToBuyOnly() const {
    int size = 0;
    for(const auto &item : items) {
        if(!item->isBought()) size++;
    }
    return size;
}

double ItemList::getPriceToStillBePaid() const {
    double price = 0;
    for(const auto &item : items) {
        if(!item->isBought()) price+= item->calculatePrice();
    }
    return price;
}

void ItemList::subscribe(Observer &o) {
    userList.emplace_back(o);
}

void ItemList::unsubscribe(Observer &o) {
    auto isTargetObserver = [&o](const std::reference_wrapper<Observer>& ref) {
        return &ref.get() == &o;
    };
    userList.remove_if(isTargetObserver);
}

void ItemList::notify() {
    for (const auto &user: userList) {
        user.get().update();
    }
}

const std::vector<std::shared_ptr<Item>> & ItemList::getItems() const {
    return items;
}

bool ItemList::checkItem(int index) {
    auto my_item = getItem(index);
    if(my_item.lock() == nullptr) return false;
    my_item.lock()->setIsBought(true);
    notify();
    return true;
}
bool ItemList::uncheckItem(int index) {
    auto my_item = getItem(index);
    if(my_item.lock() == nullptr) return false;
    my_item.lock()->setIsBought(false);
    notify();
    return true;
}

bool ItemList::changeItemPrice(int index, float basePrice) {
    auto my_item = getItem(index);
    if(my_item.lock() == nullptr) return false;
    my_item.lock()->setBasePrice(basePrice);
    notify();
    return true;
}

bool ItemList::changeItemQuantity(int index, int quantity) {
    auto my_item = getItem(index);
    if(my_item.lock() == nullptr) return false;
    my_item.lock()->setQuantity(quantity);
    notify();
    return true;
}
