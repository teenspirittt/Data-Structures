cmake_minimum_required(VERSION 3.0) # version can be different

project(1_lab) #name of your project

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(CycListTests tests/CycListTests.cpp) # add this executable

target_link_libraries(CycListTests PRIVATE gtest) # link google test to this executable
