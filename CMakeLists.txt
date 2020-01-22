cmake_minimum_required(VERSION 3.5)
project(bfi)

set(CMAKE_CXX_STANDARD 11)

add_executable(bfi main.cpp orders.h)
add_executable(enc bf_encryption.cpp orders.h)