# mainframe cmake list
set(sourcefiles
mainframe.cpp
extdebug.cpp
application.cpp
window.cpp
)

set(headerfiles
application.hpp
)


add_executable(guan_mainframe ${sourcefiles} ${headerfiles})

set(VULKAN_SDK "D:/include/VulkanSDK")
set(VULKAN_VERSION "1.2.198.1")
set(VULKAN_PATH "${VULKAN_SDK}${VULKAN_VERSION}")
set(VULKAN_LIB_LIST "vulkan-1")


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