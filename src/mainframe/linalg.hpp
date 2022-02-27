#ifndef LINALG_HPP
#define LINALG_HPP

#include <array>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include "shared.hpp"
struct Vertex {
    glm::vec2 pos;
    glm::vec3 color;
    glm::vec2 texCoord;
    static VkVertexInputBindingDescription getBindingDescription();
    static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions();
};
extern std::vector<Vertex> vertices;
extern std::vector<uint16_t> indices;

struct UniformBufferObject {
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 proj;
};

#endif