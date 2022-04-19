cmake_minimum_required(VERSION 3.17)
project(lab11)

set(CMAKE_CXX_STANDARD 14)

add_executable(test test.cpp SinglyLinkedList.cpp SLLBasedStack.cpp)
add_executable(time time.cpp SinglyLinkedList.cpp SLLBasedStack.cpp)
