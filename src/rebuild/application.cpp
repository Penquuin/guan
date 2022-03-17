#include "application.hpp"

namespace reb {

Application::~Application() {}
Application::Application() {}

void Application::run() {
    while (!window.shouldClose()) {
        glfwPollEvents();
    }
}

}  // namespace reb
