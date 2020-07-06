cmake_minimum_required(VERSION 3.15)
project(W8)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(W8
        bst-test.cc
        BST.h)
