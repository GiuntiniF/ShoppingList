cmake_minimum_required(VERSION 3.5)
project(ShoppingList)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES main.cpp Item.cpp headers/Item.h NullItem.cpp headers/NullItem.h ItemList.cpp headers/ItemList.h User.cpp headers/User.h headers/Observer.h headers/Subject.h CliLogic.cpp)
add_executable(ShoppingList main.cpp)
add_library(ShoppingListCore ${SOURCE_FILES})
target_link_libraries(ShoppingList ShoppingListCore)