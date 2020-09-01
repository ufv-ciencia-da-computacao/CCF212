cmake_minimum_required(VERSION 2.6)
project(pratica_1)
set(CMAKE_BUILD_TYPE Debug)
set(SOURCE_FILES ./lib/item.c ./lib/item.h ./lib/bs-tree.c ./lib/bs-tree.h main.c)
add_executable(pratica_1 ${SOURCE_FILES})

