cmake_minimum_required(VERSION 3.10)
project(Circular_buffer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Circular_buffer_testing circular_buffer.h main.cpp)

add_library(Circular_buffer SHARED circular_buffer.h)
set_target_properties(Circular_buffer PROPERTIES LINKER_LANGUAGE CXX)

if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG -fsanitize=address,undefined")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17 -pedantic")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native")
    set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
endif ()
target_link_libraries(Circular_buffer_testing Circular_buffer gtest -lpthread)
