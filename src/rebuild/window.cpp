#include "window.hpp"

#include <stdexcept>

namespace reb
{

Window::Window(const int w, const int h, std::string windowName) : width(w), height(h), windowName(windowName)
{
    initWindow();
};

Window::~Window()
{
    glfwDestroyWindow(pWindow);
    glfwTerminate();
}

void Window::initWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    pWindow = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    glfwSetWindowUserPointer(pWindow, this);
    glfwSetFramebufferSizeCallback(pWindow, framebufferResizeCallback);
}

void Window::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface)
{
    if (glfwCreateWindowSurface(instance, pWindow, nullptr, surface) != VK_SUCCESS)
    {
        throw std::runtime_error("Failed to create window surface!");
    };
};
void Window::framebufferResizeCallback(GLFWwindow *window, int width, int height)
{
    auto pindow = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));
    pindow->framebufferResized = true;
    pindow->width = width;
    pindow->height = height;
}

} // namespace reb