#include "WindowManager.h"

static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
	auto app = reinterpret_cast<WindowManager*>(glfwGetWindowUserPointer(window));
	app->setFrameBufferResized(true);
}

WindowManager::WindowManager(int inWidth, int inHeight, std::string inWindowTitle) : width(inWidth), height(inHeight), frameBufferResized(false), windowTitle(inWindowTitle)
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	window = glfwCreateWindow(width, height, windowTitle.c_str(), nullptr, nullptr);

	glfwSetWindowUserPointer(window, this);

	glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	//glfwSetCursorPosCallback(window, mouseMoveCallback);
	//glfwSetKeyCallback(window, keyCallback);
}

WindowManager::~WindowManager()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void WindowManager::setFrameBufferResized(bool isResized)
{
	frameBufferResized = isResized;
}

void WindowManager::createWindowSurface(VkInstance instance, VkSurfaceKHR surface)
{
	if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS) {
		throw std::runtime_error("Failed to create window surface!");
	}
}

GLFWwindow* WindowManager::getWindowPointer()
{
	return window;
}