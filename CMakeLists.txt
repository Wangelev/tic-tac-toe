cmake_minimum_required(VERSION 3.10)
project(TicTacToe VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add executable
file(GLOB SOURCES "src/*.cpp")
add_executable(TicTacToe ${SOURCES})