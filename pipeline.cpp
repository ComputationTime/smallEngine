#include "pipeline.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace littleEngine
{
    static std::vector<char> readFile(const std::string &filePath)
    {
        std::ifstream file{filePath, std::ios::ate | std::ios::binary};

        if (!file.is_open())
        {
            throw std::runtime_error("failed to open file: " + filePath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> charBuffer(fileSize);
        file.seekg(0);
        file.read(charBuffer.data(), fileSize);

        file.close();
        return charBuffer;
    }

    // Pipeline

    Pipeline::Pipeline(MyEngineDevice &device, const std::string &vertFilePath, const std::string &fragFilePath, PipelineConfigInfo configInfo)
        : device(device)
    {
        Pipeline::createGraphicsPipeline(vertFilePath, fragFilePath, configInfo);
    }

    void Pipeline::createGraphicsPipeline(const std::string &vertFilePath, const std::string &fragFilePath, const PipelineConfigInfo configInfo)
    {

        auto vertCode = readFile(vertFilePath);
        auto fragCode = readFile(fragFilePath);

        std::cout << "vertCode size: " << vertCode.size() << std::endl;
        std::cout << "fragCode size: " << fragCode.size() << std::endl;
    }

    void Pipeline::createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule)
    {
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t *>(code.data());

        if (vkCreateShaderModule(device.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create shader module");
        }
    }

    PipelineConfigInfo Pipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height)
    {
        PipelineConfigInfo configInfo{};
        return configInfo;
    }

} // namespace littleEngine