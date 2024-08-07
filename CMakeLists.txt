cmake_minimum_required(VERSION 3.28)
project(untitled4)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(untitled4 main.cpp)
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
