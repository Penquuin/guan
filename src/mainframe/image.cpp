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
}