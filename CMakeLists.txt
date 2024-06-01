cmake_minimum_required(VERSION 3.28)
project(Discrete_Structure_for_Computer_Science___CO1007)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Discrete_Structure_for_Computer_Science___CO1007
        bellman.cpp
        main.cpp
        tsp.h
        tsp.cpp
        bellman.h
        tsp.cpp)
