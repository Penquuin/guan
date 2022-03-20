#pragma once

#include <memory>
#include <vector>

#include "device.hpp"
#include "pipeline.hpp"
#include "swapchain.hpp"
#include "window.hpp"

namespace reb
{
class Application
{
  private:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 800;

    void createPipelineLayout();
    void createPipeline();
    void createCommandBuffers();
    void drawFrame();

    Window window{WIDTH, HEIGHT, "Hello Vulkan"};
    Device device{window};
    SwapChain swapchain{device, window.getExtent()};

    std::unique_ptr<Pipeline> pipeline;
    VkPipelineLayout pipelineLayout;
    std::vector<VkCommandBuffer> commandBuffers;

  public:
    void run();
    Application();
    ~Application();

    Application(const Application &) = delete;
    Application &operator=(const Application &) = delete;
};

} // namespace reb
