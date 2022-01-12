# mainframe cmake list
set(SHADER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/shaders)


set(sourcefiles
mainframe.cpp
extdebug.cpp
application.cpp
window.cpp
pipeline.cpp
linalg.cpp
)

set(headerfiles
shared.hpp
application.hpp
linalg.hpp
)


add_executable(guan_mainframe ${sourcefiles} ${headerfiles})

set(VULKAN_SDK "D:/Libs/VulkanSDK")
set(VULKAN_VERSION "1.2.198.1")
set(VULKAN_PATH "${VULKAN_SDK}/${VULKAN_VERSION}")
set(VULKAN_LIB_LIST "vulkan-1")

add_definitions(-DSHADER_PATH="${SHADER_PATH}")

# Compile
execute_process(COMMAND ${VULKAN_PATH}/Bin/glslc.exe ${SHADER_PATH}/shader.vert -o ${SHADER_PATH}/vert.spv)
execute_process(COMMAND ${VULKAN_PATH}/Bin/glslc.exe ${SHADER_PATH}/shader.frag -o ${SHADER_PATH}/frag.spv)


target_link_directories(guan_mainframe
PUBLIC
${VULKAN_PATH}/Bin;
${VULKAN_PATH}/Lib;
)

target_include_directories(guan_mainframe PUBLIC ${CMAKE_SOURCE_DIR}/vendor/glfw/include
${CMAKE_SOURCE_DIR}/vendor/glm
${VULKAN_PATH}/Include
)
target_link_libraries (guan_mainframe glfw ${VULKAN_LIB_LIST})