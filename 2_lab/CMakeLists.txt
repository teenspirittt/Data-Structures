cmake_minimum_required(VERSION 3.0) # version can be different

project(2_lab) #name of your project

add_executable(2_lab src/BSTree.cpp src/menu.cpp menu_program.cpp) # add this executable
add_executable(SPEED_TEST speed_test.cpp src/BSTree.cpp)

