cmake_minimum_required(VERSION 3.14)
project(C_string C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS FALSE)
set(CMAKE_CXX_STANDARD 14)

add_library(C_string SHARED cstring_library.c cstring_library.h)


#zlib-shared PROPERTIES OUTPUT_NAME bzlib)add_library(bzlib STATIC ${mylib_SRCS})
##add_library(bzlib-shared SHARED ${mylib_SRCS})
##set_target_properties(b