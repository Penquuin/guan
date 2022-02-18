#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <string.h>

#include "application.hpp"

void application::BaseApplication::createTextureImage() {
    int texWidth, texHeight, texChannels;
    char* base = (char*)malloc(128);
    strcpy(base, TEX_PATH);
    strcat(base, "/texture.jpg");
    stbi_uc* pixels = stbi_load(base, &texWidth, &texHeight, &texChannels, STBI_rgb_alpha);
    free(base);
    VkDeviceSize imageSize = texWidth * texHeight * 4;

    if (!pixels) {
        throw std::runtime_error("failed to load texture image!");
    }
    createBuffer(imageSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
                 VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer,
                 stagingBufferMemory);
    void* data;
    vkMapMemory(device, stagingBufferMemory, 0, imageSize, 0, &data);
    memcpy(data, pixels, static_cast<size_t>(imageSize));
    vkUnmapMemory(device, stagingBufferMemory);
    stbi_image_free(pixels);

    VkImageCreateInfo imageInfo{};
    imageInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    imageInfo.imageType = VK_IMAGE_TYPE_2D;
    imageInfo.extent.width = static_cast<uint32_t>(texWidth);
    imageInfo.extent.height = static_cast<uint32_t>(texHeight);
    imageInfo.extent.depth = 1;
    imageInfo.mipLevels = 1;
    imageInfo.arrayLayers = 1;
    imageInfo.format = VK_FORMAT_R8G8B8A8_SRGB;
    imageInfo.tiling = VK_IMAGE_TILING_OPTIMAL;
    imageInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    imageInfo.usage = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT;
}