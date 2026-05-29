
#define GLFW_INCLUE_VULKAN

#include "WindowManager.h"
#include "VulkanInterface.h"

int main() {
	WindowManager winManager(1600, 1200, "Euclid Renderer");
	VulkanInterface vkInterface(&winManager);

	while (!glfwWindowShouldClose(winManager.getWindowPointer())) {
		//vkDeviceWaitIdle();
	}

	return 0;
}