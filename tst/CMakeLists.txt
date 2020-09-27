cmake_minimum_required(VERSION 2.6)
project(tst)
set(CMAKE_BUILD_TYPE Debug)
set(SOURCE_FILES ./lib/tst.c ./lib/tst.h main.c)
add_executable(tst ${SOURCE_FILES})

