cmake_minimum_required(VERSION 3.9)
project(CppLang)

set(CMAKE_CXX_STANDARD 17)

add_executable(CppLang main.cpp CREATE.cpp CREATE.h WORD.cpp WORD.h)