cmake_minimum_required(VERSION 3.10)
project(ProcessScheduling)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(ProcessScheduling
    src/main.cpp
    src/scheduling_algorithms/RoundRobin.cpp
    src/utils/Parser.cpp
)
