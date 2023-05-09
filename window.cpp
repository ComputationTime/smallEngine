#include "window.hpp"
#include <stdexcept>

namespace littleEngine
{

    WindowWrapper::WindowWrapper(int w, int h, std::string name)
        : width(w), height(h), windowName(name)
    {
        initWindow();
    }

    WindowWrapper::~WindowWrapper()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void WindowWrapper::initWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // disables openGL
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }

    void WindowWrapper::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface)
    {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create window surface");
        }
    }

}
