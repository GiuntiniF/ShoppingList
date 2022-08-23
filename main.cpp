#include <iostream>
#include "headers/Item.h"
#include "headers/MeatAndChickenItem.h"

int main() {
    Item* turkey = new MeatAndChickenItem("Turkey", 5, 2);
    Item* chickenError = nullptr;
    try {
        chickenError = new MeatAndChickenItem("chicken", 5, 2);
    }  catch(std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    if(chickenError)
    {
        std::cout << chickenError->getName() << std::endl;
    }
    std::cout << turkey->getBasePrice() << std::endl;
    return 0;
}
