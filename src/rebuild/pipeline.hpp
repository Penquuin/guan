#pragma once

#include <string>
#include <vector>

#include "device.hpp"

namespace reb
{

struct PipelineConfigInfo
{
    VkViewport viewport;
    VkRect2D scissor;
    VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
    VkPipelineRasterizationStateCreateInfo rasterizationInfo;
    VkPipelineMultisampleStateCreateInfo multisampleInfo;
    VkPipelineColorBlendAttachmentState colorBlendAttachment;
    VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
    VkPipelineLayout pipelineLayout = nullptr;
    VkRenderPass renderPass = nullptr;
    uint32_t subpass = 0;
};

class Pipeline
{
  private:
    static std::vector<char> readFile(const std::string *const filePath);

    void createGraphicPipeline(const std::string *vertShaderPath, const std::string *fragShaderPath, PipelineConfigInfo &configInfo);

    void createShaderModule(const std::vector<char> *code, VkShaderModule *module);

    Device *device;
    VkPipeline graphicsPipeline;
    VkShaderModule vertShader, fragShader;

  public:
    Pipeline(Device *device, std::string vertShaderPath, std::string fragShaderPath, PipelineConfigInfo configInfo);
    ~Pipeline();

    void bind(VkCommandBuffer commandBuffer);

    Pipeline(const Pipeline &) = delete;
    Pipeline &operator=(const Pipeline &) = delete;
    Pipeline() = default;

    static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);
};

} // namespace reb
