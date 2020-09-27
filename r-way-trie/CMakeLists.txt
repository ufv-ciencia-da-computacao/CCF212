cmake_minimum_required(VERSION 2.6)
project(r_way)
set(CMAKE_BUILD_TYPE Debug)
set(SOURCE_FILES ./lib/trie.c ./lib/trie.h main.c)
add_executable(r_way ${SOURCE_FILES})

