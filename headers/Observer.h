//
// Created by francesco on 2/24/23.
//

#ifndef SHOPPINGLIST_OBSERVER_H
#define SHOPPINGLIST_OBSERVER_H

#endif //SHOPPINGLIST_OBSERVER_H

class Subject;

class Observer {
public:
    virtual ~Observer() {};

    virtual void update() = 0;
    virtual void attach(std::shared_ptr<Subject> subject) = 0;
    virtual void detach(std::shared_ptr<Subject> subject) = 0;
};