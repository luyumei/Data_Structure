cmake_minimum_required(VERSION 3.17)
project(Data_Structure)

set(CMAKE_CXX_STANDARD 20)

add_executable(Data_Structure dict.h main.cpp Scanner.cpp infix2postfix.cpp)