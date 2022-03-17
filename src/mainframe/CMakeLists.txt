# mainframe cmake list
set(SHADER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/shaders)
set(TEX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/images)
set(MOD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/models)


set(sourcefiles
mainframe.cpp
extdebug.cpp
application.cpp
window.cpp
pipeline.cpp
linalg.cpp
image.cpp
entities/object.cpp
)

set(headerfiles
shared.hpp
application.hpp
linalg.hpp
entities/object.hpp
)


add_executable(guan_mainframe ${sourcefiles} ${headerfiles})

set(LIB_PATH "D:/Libs")

set(VULKAN_SDK "${LIB_PATH}/VulkanSDK")
set(VULKAN_VERSION "1.2.198.1")
set(VULKAN_PATH "${VULKAN_SDK}/${VULKAN_VERSION}")
set(VULKAN_LIB_LIST "vulkan-1")

set(TINYLOADER_PATH "${LIB_PATH}/tinyobjloader")

add_definitions(-DSHADER_PATH="${SHADER_PATH}")
add_definitions(-DMOD_PATH="${MOD_PATH}")
add_definitions(-DTEX_PATH="${TEX_PATH}")
add_definitions(-DTINYLOADER_PATH="${TINYLOADER_PATH}")

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
${CMAKE_SOURCE_DIR}/vendor/stb
${VULKAN_PATH}/Include
${TINYLOADER_PATH}
)
target_link_libraries (guan_mainframe glfw ${VULKAN_LIB_LIST})