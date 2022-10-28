cmake_minimum_required(VERSION 3.2)

project(Matrix)

include(cmake/function.cmake)

add_subdirectory(include)
add_subdirectory(samples)

option(BTEST "build test?" OFF)

if(BTEST)
    add_subdirectory(gtest)
    add_subdirectory(test)
endif()
