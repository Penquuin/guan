set(SHADER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/shaders)
set(TEX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/images)
set(MOD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/models)


set(sourcefiles
main.cpp
window.cpp
application.cpp
)

set(headerfiles
window.hpp
application.hpp
)


add_executable(guan_rebuild ${sourcefiles} ${headerfiles})

set(LIB_PATH "D:/Libs")

set(VULKAN_SDK "${LIB_PATH}/VulkanSDK")
set(VULKAN_VERSION "1.2.198.1")
set(VULKAN_PATH "${VULKAN_SDK}/${VULKAN_VERSION}")
set(VULKAN_LIB_LIST "vulkan-1")
# Compile
# execute_process(COMMAND ${VULKAN_PATH}/Bin/glslc.exe ${SHADER_PATH}/shader.vert -o ${SHADER_PATH}/vert.spv)
# execute_process(COMMAND ${VULKAN_PATH}/Bin/glslc.exe ${SHADER_PATH}/shader.frag -o ${SHADER_PATH}/frag.spv)


target_link_directories(guan_rebuild
PUBLIC
${VULKAN_PATH}/Bin;
${VULKAN_PATH}/Lib;
)

target_include_directories(guan_rebuild PUBLIC ${CMAKE_SOURCE_DIR}/vendor/glfw/include
${CMAKE_SOURCE_DIR}/vendor/glm
${CMAKE_SOURCE_DIR}/vendor/stb
${VULKAN_PATH}/Include
)
target_link_libraries (guan_rebuild glfw ${VULKAN_LIB_LIST})