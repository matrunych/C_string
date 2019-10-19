CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

PROJECT(examples-cstring C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS FALSE)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_LIBRARY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cstring-library/bin)

find_library(CSTRING libcstring.so REQUIRED)
add_executable(pr2_cstring-usage pr2_cstring-usage.c)
add_executable(func_examples func_examples.c)

target_link_libraries (pr2_cstring-usage ${CSTRING})
target_link_libraries (func_examples ${CSTRING})