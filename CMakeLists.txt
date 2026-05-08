cmake_minimum_required(VERSION 4.0)
project(Some_Amazing_Games)

set(CMAKE_CXX_STANDARD 20)

add_executable(Some_Amazing_Games main.cpp
        XO.cpp
        XO.h
        colors.h
        utils.h
        Connect4.cpp
        Connect4.h
        utils.cpp)
