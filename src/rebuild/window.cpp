#include "window.hpp"

namespace reb {

Window::Window(const int w, const int h, std::string windowName)
    : width(w), height(h), windowName(windowName) {
    initWindow();
};

Window::~Window() {
    glfwDestroyWindow(pWindow);
    glfwTerminate();
}

void Window::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    pWindow = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
}

}  // namespace reb