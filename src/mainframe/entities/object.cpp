#include "object.hpp"

object::object(std::string modelPath, std::string texPath, std::string mtlPath)
    : texPath(texPath), mtlPath(mtlPath), modelPath(modelPath) {}

object::object(std::string modelPath, std::string mtlPath) : modelPath(modelPath), mtlPath(mtlPath){};
object::object(std::string modelPath) : modelPath(modelPath){};