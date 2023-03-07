cmake_minimum_required(VERSION 3.5)
project(ShoppingList)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES main.cpp Item.cpp headers/Item.h MeatAndChickenItem.cpp headers/MeatAndChickenItem.h VegetableAndFruitItem.cpp headers/VegetableAndFruitItem.h NullItem.cpp headers/NullItem.h ItemList.cpp headers/ItemList.h ItemManager.cpp headers/ItemManager.h User.cpp headers/User.h headers/Observer.h headers/Subject.h)
add_executable(ShoppingList main.cpp)
add_library(ShoppingListCore ${SOURCE_FILES})
target_link_libraries(ShoppingList ShoppingListCore)