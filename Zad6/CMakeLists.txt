cmake_minimum_required(VERSION 3.13)
project(Zad5)

set(CMAKE_CXX_STANDARD 17)

add_executable(Zad5 main.cpp Task.cpp Task.hh FileReader.cpp FileReader.hh Schrage.cpp Schrage.hh Heap.cpp Heap.hh Carlier.cpp Carlier.hh)

target_link_libraries(Zad5 pthread)
