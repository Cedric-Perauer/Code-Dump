cmake_minimum_required(VERSION 2.8)

project(hello)
project(cv_tutorial1)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cv_hello hello.cpp)

target_link_libraries(cv_hello ${OpenCV_LIBS})


add_executable(cv_tutorial1 cv_tutorial1.cpp)

target_link_libraries(cv_tutorial1 ${OpenCV_LIBS})
