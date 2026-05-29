#pragma once

#include "vulkan/vulkan.h"
#include "GLFW/glfw3.h"

#include <string>
#include <stdexcept>

class WindowManager
{
public:
	WindowManager(int width, int height, std::string windowTitle);
	~WindowManager();

	void setFrameBufferResized(bool isResized);
	void createWindowSurface(VkInstance instance, VkSurfaceKHR surface);

	GLFWwindow* getWindowPointer();

private:
	GLFWwindow* window;

	bool frameBufferResized;

	int width;
	int height;

	std::string windowTitle;
};

