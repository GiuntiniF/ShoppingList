//
// Created by francesco on 2/24/23.
//

#include <memory>
#include "Observer.h"

#ifndef SHOPPINGLIST_SUBJECT_H
#define SHOPPINGLIST_SUBJECT_H

#endif //SHOPPINGLIST_SUBJECT_H

class Subject {
public:
    virtual void subscribe(std::weak_ptr<Observer> o) = 0;
    virtual void unsubscribe(std::weak_ptr<Observer> o) = 0;
    virtual void notify() = 0;

    virtual ~Subject() {}
};