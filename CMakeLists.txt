cmake_minimum_required(VERSION 3.5)
project(ShoppingList)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

#set(SOURCE_FILES main.cpp User.cpp headers/User.h Item.cpp headers/Item.h ItemMeatAndChicken.cpp headers/ItemMeatAndChicken.h)
set(SOURCE_FILES main.cpp Item.cpp headers/Item.h ItemMeatAndChicken.cpp headers/ItemMeatAndChicken.h)
add_executable(ShoppingList main.cpp)
add_library(ShoppingListCore ${SOURCE_FILES})
target_link_libraries(ShoppingList ShoppingListCore)