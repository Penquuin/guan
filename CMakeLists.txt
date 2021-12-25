cmake_minimum_required(VERSION 3.10)

project(guan)

set(VENDOR  ${CMAKE_SOURCE_DIR}/vendor)
set(SRC     ${CMAKE_SOURCE_DIR}/src)



add_subdirectory(${VENDOR}/glfw)
add_subdirectory(${VENDOR}/glm)
add_subdirectory(${SRC})
