#include "firstApp.hpp"

namespace littleEngine
{
    void FirstApp::run()
    {
        while (!window.shouldClose())
        {
            glfwPollEvents();
        }
    }
}