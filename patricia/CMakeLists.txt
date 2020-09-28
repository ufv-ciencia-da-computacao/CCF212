cmake_minimum_required(VERSION 2.6)
project(patricia)
set(CMAKE_BUILD_TYPE Debug)
set(SOURCE_FILES ./lib/patricia.c ./lib/patricia.h main.c)
add_executable(patricia ${SOURCE_FILES})

