cmake_minimum_required(VERSION 3.23)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1  test.cpp)

include_directories(/usr/include/mysql/)

link_directories(/usr/include/mysql/)
