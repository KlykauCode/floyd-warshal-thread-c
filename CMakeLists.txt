cmake_minimum_required(VERSION 3.29)
project(semestralka_c)

set(CMAKE_CXX_STANDARD 14)

add_executable(semestralka_c main.cpp
        Menu.cpp
        Menu.hpp
        Graph.cpp
        Graph.h
        FloydWarshallSingleThread.cpp
        FloydWarshallSingleThread.h
        FloydWarshallMultiThread.cpp
        FloydWarshallMultiThread.h
        FloydWarshall.cpp
        FloydWarshall.h
        App.cpp
        App.h
)

find_package(Threads REQUIRED)

target_link_libraries(semestralka_c PRIVATE Threads::Threads)