cmake_minimum_required(VERSION 3.17)
project(ostasolg_semestralka)

set(CMAKE_CXX_STANDARD 14)

add_executable(ostasolg_semestralka main.cpp Graph.cpp Graph.hpp utils.cpp utils.hpp)
add_executable(compare_measurements main2.cpp Graph.cpp Graph.hpp utils.cpp utils.hpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(ostasolg_semestralka Threads::Threads)
target_link_libraries(compare_measurements Threads::Threads)