#pragma once

#include "window.hpp"

namespace reb {
class Application {
   private:
    Window window{WIDTH, HEIGHT, "Hello Vulkan"};
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 800;

   public:
    void run();
    Application();
    ~Application();
};

}  // namespace reb
