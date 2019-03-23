cmake_minimum_required(VERSION 3.13)
project(Dijk)

set(CMAKE_CXX_STANDARD 14)

add_executable(Dijk main.cpp Graph.h shortest_path.h PriorityQueue.h Graph.cpp shortest_path.cpp PriorityQueue.cpp)