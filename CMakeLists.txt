cmake_minimum_required(VERSION 3.10)

project(DoubleLinkedList)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(code src/main.cpp)

# Set output directory for the executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
