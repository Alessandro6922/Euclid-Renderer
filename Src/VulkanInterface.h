#pragma once

#include "GLFW/glfw3.h"
#include <vulkan/vulkan.h>

#include "Constants.h"
#include "WindowManager.h"

#include <vector>
#include <stdexcept>
#include <iostream>

class VulkanInterface
{
public:
	VulkanInterface(WindowManager* windowManager);
	~VulkanInterface();

private:
	bool checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions();
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

	void createInstance();

	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
	void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);

	void setupDebugMessenger();

	void createSurface();


	bool isDeviceSuitable(VkPhysicalDevice device);
	void pickPhysicalDevice();

	WindowManager* windowManager;

	VkInstance vulkanInstance;
	VkDebugUtilsMessengerEXT debugMessenger;
	VkSurfaceKHR surface;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
};

