cmake_minimum_required(VERSION 2.8)
project(chapter1)

set(CMAKE_CXX_STANDARD 11)
find_package(Sophus REQUIRED)
include_directories(
        "/usr/include/eigen3"
        ${Sophus_INCLUDE_DIRS}
)

add_executable(chapter1 main.cpp)
target_link_libraries(chapter1 ${Sophus_LIBRARIES})