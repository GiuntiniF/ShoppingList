cmake_minimum_required(VERSION 3.5)
project(ShoppingList)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

#set(SOURCE_FILES main.cpp User.cpp headers/User.h Item.cpp headers/Item.h MeatAndChickenItem.cpp headers/MeatAndChickenItem.h)
set(SOURCE_FILES main.cpp Item.cpp headers/Item.h MeatAndChickenItem.cpp headers/MeatAndChickenItem.h VegetableAndFruitItem.cpp headers/VegetableAndFruitItem.h)
add_executable(ShoppingList main.cpp)
add_library(ShoppingListCore ${SOURCE_FILES})
target_link_libraries(ShoppingList ShoppingListCore)