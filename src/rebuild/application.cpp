#include "application.hpp"

#include <stdexcept>

namespace reb
{

Application::~Application()
{
    vkDestroyPipelineLayout(device.device(), pipelineLayout, nullptr);
}
Application::Application()
{
    createPipelineLayout();
    createPipeline();
    createCommandBuffers();
}

void Application::run()
{
    while (!window.shouldClose())
    {
        glfwPollEvents();
    }
}

void Application::createPipelineLayout()
{
    VkPipelineLayoutCreateInfo pipelineCreateInfo{};
    pipelineCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;

    /**
     * @brief Layouts can store uniforms and textures...
     */
    pipelineCreateInfo.setLayoutCount = 0;
    pipelineCreateInfo.pSetLayouts = nullptr;

    /**
     * @brief Push Constant is a way to efficiently
     * send a small package of data to our shader program.
     */
    pipelineCreateInfo.pushConstantRangeCount = 0;
    pipelineCreateInfo.pPushConstantRanges = nullptr;
    if (vkCreatePipelineLayout(device.device(), &pipelineCreateInfo, nullptr, &pipelineLayout) != VK_SUCCESS)
    {
        throw std::runtime_error("Failed to create pipeline layout!");
    }
}

void Application::createPipeline()
{
    PipelineConfigInfo config = Pipeline::defaultPipelineConfigInfo(swapchain.width(), swapchain.height());
    config.renderPass = swapchain.getRenderPass();
    config.pipelineLayout = pipelineLayout;
    pipeline = std::make_unique<Pipeline>(&device, "vert.spv", "frag.spv", config);
}

void Application::createCommandBuffers()
{
}

void Application::drawFrame()
{
}

} // namespace reb
