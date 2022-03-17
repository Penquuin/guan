#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace reb {
class Window {
   private:
    void initWindow();
    const int width;
    const int height;
    std::string windowName;

    GLFWwindow* pWindow;

   public:
    Window(const int w, const int h, std::string windowName);
    ~Window();
    bool shouldClose() { return glfwWindowShouldClose(pWindow); }
};
}  // namespace reb
