cmake_minimum_required(VERSION 3.14)
project(C_string C)

set(CMAKE_C_STANDARD 99)

add_library(C_string SHARED library.c library.h)