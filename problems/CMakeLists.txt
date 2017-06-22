cmake_minimum_required(VERSION 2.8)

project(PROBLEMS)

file(GLOB sources *.cpp)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11")

link_directories(${CMAKE_BINARY_DIR})

foreach(source ${sources})
    get_filename_component(BINARY_NAME ${source} NAME_WE)
    add_executable(${BINARY_NAME} ${source})
    target_link_libraries(${BINARY_NAME} -lutils)
    add_dependencies(${BINARY_NAME} utils)
endforeach()
