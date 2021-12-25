cmake_minimum_required(VERSION 3.10)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++${CMAKE_CXX_STANDARD}")

project(guan)

set(VENDOR  ${CMAKE_SOURCE_DIR}/vendor)
set(SRC     ${CMAKE_SOURCE_DIR}/src)



add_subdirectory(${VENDOR}/glfw)
add_subdirectory(${VENDOR}/glm)
add_subdirectory(${SRC})
