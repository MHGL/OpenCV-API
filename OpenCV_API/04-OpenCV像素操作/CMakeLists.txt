cmake_minimum_required(VERSION 3.10)
project(opencv)
find_package(OpenCV)
include_directories(${Opencv_INCLUDE_DIR})
add_executable(opencv main.cpp)
target_link_libraries(opencv ${OpenCV_LIBS})
