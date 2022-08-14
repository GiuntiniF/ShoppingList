cmake_minimum_required(VERSION 3.22)
project(ShoppingList)

set(CMAKE_CXX_STANDARD 14)

add_executable(ShoppingList main.cpp User.cpp headers/User.h Item.cpp headers/Item.h)
