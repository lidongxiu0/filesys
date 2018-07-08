cmake_minimum_required(VERSION 3.10)
project(filesys)

set(CMAKE_CXX_STANDARD 11)

add_executable(filesys main.cpp initialize.cpp filesys.h create.cpp open.cpp allot.cpp display_memory.cpp display.cpp recycle.cpp read_write.cpp close.cpp)