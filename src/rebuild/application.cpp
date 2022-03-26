#include "application.hpp"

#include <array>
#include <stdexcept>

namespace reb
{

Application::~Application()
{
    vkDestroyPipelineLayout(device.device(), pipelineLayout, nullptr);
}
Application::Application()
{
    loadModels();
    createPipelineLayout();
    recreateSwapchain();
    createCommandBuffers();
}

void Application::run()
{
    while (!window.shouldClose())
    {
        glfwPollEvents();
        drawFrame();
    }

    vkDeviceWaitIdle(device.device());
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
    PipelineConfigInfo config = Pipeline::defaultPipelineConfigInfo(swapchain->width(), swapchain->height());
    config.renderPass = swapchain->getRenderPass();
    config.pipelineLayout = pipelineLayout;
    pipeline = std::make_unique<Pipeline>(&device, "vert.spv", "frag.spv", config);
}

void Application::recreateSwapchain()
{
    auto extent = window.getExtent();
    while (extent.width == 0 || extent.height == 0)
    {
        extent = window.getExtent();
        glfwWaitEvents();
    }

    vkDeviceWaitIdle(device.device());
    swapchain = std::make_unique<SwapChain>(device, extent);
    createPipeline();
}

void Application::createCommandBuffers()
{
    commandBuffers.resize(swapchain->imageCount());

    VkCommandBufferAllocateInfo allocInfo{};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandPool = device.getCommandPool();
    allocInfo.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());

    if (vkAllocateCommandBuffers(device.device(), &allocInfo, commandBuffers.data()) != VK_SUCCESS)
    {
        throw std::runtime_error("Failed to allocate command buffers");
    }
}

void Application::recordCommandBuffer(int imageIndex)
{
    VkCommandBufferBeginInfo beginInfo{};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

    if (vkBeginCommandBuffer(commandBuffers.at(imageIndex), &beginInfo) != VK_SUCCESS)
    {
        throw std::runtime_error("Failed to begin command buffer");
    }

    VkRenderPassBeginInfo renderPassInfo{};
    renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    renderPassInfo.renderPass = swapchain->getRenderPass();
    renderPassInfo.framebuffer = swapchain->getFrameBuffer(imageIndex);

    renderPassInfo.renderArea.offset = {0, 0};
    renderPassInfo.renderArea.extent = swapchain->getSwapChainExtent();

    std::array<VkClearValue, 2> clearValues{};
    clearValues[0].color = {0.1f, 0.1f, 0.1f, 1.0f};
    clearValues[1].depthStencil = {1, 0};
    renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
    renderPassInfo.pClearValues = clearValues.data();

    vkCmdBeginRenderPass(commandBuffers.at(imageIndex), &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

    pipeline->bind(commandBuffers.at(imageIndex));
    model->bind(commandBuffers.at(imageIndex));
    model->draw(commandBuffers.at(imageIndex));

    vkCmdEndRenderPass(commandBuffers.at(imageIndex));
    if (vkEndCommandBuffer(commandBuffers.at(imageIndex)) != VK_SUCCESS)
    {
        throw std::runtime_error("Failed to record command buffer!");
    }
}

void Application::drawFrame()
{
    uint32_t imageIndex;
    VkResult result = swapchain->acquireNextImage(&imageIndex);

    if (result == VK_ERROR_OUT_OF_DATE_KHR)
    {
        recreateSwapchain();
        return;
    }
    if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)
    {
        throw std::runtime_error("Failed to acquire next swapchain image!");
    }

    recordCommandBuffer(imageIndex);
    result = swapchain->submitCommandBuffers(&commandBuffers.at(imageIndex), &imageIndex);
    if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR || window.wasWindowResized())
    {
        window.resetWindowResizedFlag();
        recreateSwapchain();
        return;
    }
    if (result != VK_SUCCESS)
    {
        throw std::runtime_error("Failed to present swapchain image!");
    }
}

void runTree(std::vector<Model::Vertex> *vertices, int i, glm::vec2 left, glm::vec2 right, glm::vec2 top)
{
    if (i <= 0)
    {
        vertices->push_back({top, {1.0f, 1.0f, 0.0f}});
        vertices->push_back({right, {1.0f, 1.0f, 0.0f}});
        vertices->push_back({left, {1.0f, 1.0f, 0.0f}});
    }
    else
    {
        auto leftTop = 0.5f * (left + top);
        auto rightTop = 0.5f * (right + top);
        auto leftRight = 0.5f * (left + right);
        runTree(vertices, i - 1, left, leftRight, leftTop);
        runTree(vertices, i - 1, leftRight, right, rightTop);
        runTree(vertices, i - 1, leftTop, rightTop, top);
    }
}

void Application::loadModels()
{
    std::vector<Model::Vertex> vertices;
    runTree(&vertices, 2, {-0.5f, 0.5f}, {0.5f, 0.5f}, {0.0f, -0.5f});
    model = std::make_unique<Model>(&device, &vertices);
}

} // namespace reb
