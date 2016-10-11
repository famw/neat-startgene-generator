cmake_minimum_required(VERSION 2.8)
project(neat-startergene-generator)
list(APPEND CMAKE_CXX_FLAGS "-std=c++11 -Wall")
add_executable(generator src/main.cpp)
