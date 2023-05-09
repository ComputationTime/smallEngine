#pragma once

#include <string>
#include <vector>
#include "my_engine_device.hpp"

namespace littleEngine
{
    struct PipelineConfigInfo
    {
    };
    class Pipeline
    {
    private:
        MyEngineDevice &device; // must make sure device outlives pipeline
        VkPipeline graphicsPipeilne;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;

    public:
        Pipeline(MyEngineDevice &device, const std::string &vertFilePath, const std::string &fragFilePath, const PipelineConfigInfo configInfo);
        ~Pipeline() {}

        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

    private:
        void createGraphicsPipeline(const std::string &vertFilePath, const std::string &fragFilePath, const PipelineConfigInfo configInfo);
        void createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);
    };
    static std::vector<char> readFile(const std::string &filePath);

} // namespace littleEngine