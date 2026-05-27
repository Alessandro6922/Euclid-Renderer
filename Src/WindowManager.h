#pragma once

#include "GLFW/glfw3.h"
#include <string>

class WindowManager
{
public:
	WindowManager(int width, int height, std::string windowTitle);
	~WindowManager();

	void setFrameBufferResized(bool isResized);

	GLFWwindow* getWindowPointer();

private:
	GLFWwindow* window;

	bool frameBufferResized;

	int width;
	int height;

	std::string windowTitle;
};

