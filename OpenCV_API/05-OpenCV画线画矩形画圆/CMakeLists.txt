cmake_minimum_required(VERSION 3.10)
project(opencv)
project(opencv2)
find_package(OpenCV)
include_directories(${Opencv_INCLUDE_DIR})
add_executable(opencv main.cpp)
add_executable(opencv2 main2.cpp)
target_link_libraries(opencv ${OpenCV_LIBS})
target_link_libraries(opencv2 ${OpenCV_LIBS})
