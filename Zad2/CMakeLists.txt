cmake_minimum_required(VERSION 3.13)
project(SPD3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SPD3
        Controller.cpp
        Controller.hh
        Machine.cpp
        Machine.hh
        main.cpp
        Task.cpp
        Task.hh Scheduler.cpp Scheduler.hh Node.cpp Node.hh FlowshopGraph.cpp FlowshopGraph.hh)
