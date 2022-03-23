#pragma once

#include "device.hpp"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

#include <vector>

namespace reb
{

class Model
{
  public:
    struct Vertex
    {
        glm::vec2 position;
        glm::vec3 color;
        static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
        static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
    };
    Model(Device *device, std::vector<Vertex> *vertices);
    ~Model();
    Model(const Model &) = delete;
    Model &operator=(const Model &) = delete;

    void bind(VkCommandBuffer commandBuffer);
    void draw(VkCommandBuffer commandBuffer);

  private:
    Device *device;
    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    uint32_t vertexCount;

    void createVertexBuffers(std::vector<Vertex> *vertices);
};

} // namespace reb
