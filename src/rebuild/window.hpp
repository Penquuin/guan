#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace reb
{
class Window
{
  private:
    void initWindow();
    static void framebufferResizeCallback(GLFWwindow *window, int width, int height);
    int width;
    int height;
    bool framebufferResized = false;
    std::string windowName;

    GLFWwindow *pWindow;

  public:
    Window(const int width, const int height, std::string name);
    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;
    ~Window();
    bool shouldClose()
    {
        return glfwWindowShouldClose(pWindow);
    }
    bool wasWindowResized()
    {
        return framebufferResized;
    }
    void resetWindowResizedFlag()
    {
        framebufferResized = false;
    }
    VkExtent2D getExtent()
    {
        return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)};
    }

    void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
};
} // namespace reb
