#pragma once

#include "window.hpp"
#include "pipeline.hpp"
#include "my_engine_device.hpp"
namespace littleEngine
{
    class FirstApp
    {
    public:
        const int WIDTH = 800;
        const int HEIGHT = 600;

        void run();

    private:
        WindowWrapper window{WIDTH, HEIGHT, "hello vulkan"};
        MyEngineDevice device{window};
        Pipeline pipeline{device, "shaders/simpleShader.vert.spv", "shaders/simpleShader.frag.spv", Pipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
    };
}