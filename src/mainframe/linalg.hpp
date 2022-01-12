#ifndef LINALG_HPP
#define LINALG_HPP

#include <array>
#include <glm/glm.hpp>

#include "shared.hpp"
struct Vertex {
    glm::vec2 pos;
    glm::vec3 color;
    static VkVertexInputBindingDescription getBindingDescription();
    static std::array<VkVertexInputAttributeDescription, 2> getAttributeDescriptions();
};
extern const std::vector<Vertex> vertices;

#endif