cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 17)
project(fpa)

add_subdirectory(lib)
include_directories(include)

add_library(fpa STATIC include/fpa/vec2.hpp src/vec2.cpp)
target_link_libraries(fpa fpm)