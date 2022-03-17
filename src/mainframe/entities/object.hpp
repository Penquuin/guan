#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "../shared.hpp"
class object {
   private:
   public:
    std::string modelPath;
    std::optional<std::string> texPath, mtlPath;
    uint32_t firstIndex, vertexOffset;
    VkImage* texImage;
    VkImageView* texImageView;
    static object* createFull(std::string modelPath, std::string texPath, std::string mtlPath) {
        return (new object(modelPath, texPath, mtlPath));
    };
    static object* createTex(std::string modelPath, std::string texPath) {
        object* obj = (new object(modelPath));
        obj->texPath = texPath;
        return obj;
    };
    static object* createMtl(std::string modelPath, std::string mtlPath) {
        return (new object(modelPath, mtlPath));
    };
    object(std::string modelPath, std::string texPath, std::string mtlPath);
    object(std::string modelPath, std::string mtlPath);
    object(std::string modelPath);
};

#endif