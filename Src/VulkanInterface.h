#pragma once

#include "GLFW/glfw3.h"
#include <vulkan/vulkan.h>

#include "Constants.h"
#include "WindowManager.h"
#include "QueueFamilyIndices.h"
#include "SwapChainSupportDetails.h"

#include <vector>
#include <stdexcept>
#include <set>

#ifdef _DEBUG
#include <iostream>
#endif

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

////////////////////////////////////////////////////////////////////////////////////
// TODO:	Implement a gpu selection menu
// 			Force multiple queue families, or look into whether thats worth doing
////////////////////////////////////////////////////////////////////////////////////
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	bool checkDeviceExtensionSupprt(VkPhysicalDevice device);
	bool isDeviceSuitable(VkPhysicalDevice device);
	SwapChainSupprtDetails querySwapChainSupport(VkPhysicalDevice device);
	VkSampleCountFlagBits getMaxUsableSampleCount();
	void pickPhysicalDevice();

////////////////////////////////////////////////////////////////////////////////////
// TODO:	Refactor pNext chain creation
////////////////////////////////////////////////////////////////////////////////////
	void createLogicalDevice();

	void loadExtentionFunctions();

	WindowManager* windowManager;

	VkInstance vulkanInstance;
	VkDebugUtilsMessengerEXT debugMessenger;
	VkSurfaceKHR surface;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

	VkSampleCountFlagBits maxMSAASamples = VK_SAMPLE_COUNT_1_BIT;

	QueueFamilyIndices queueFamilyIndices;

	VkDevice device;

	VkQueue graphicsQueue;
	VkQueue presentationQueue;
	VkQueue computeQueue;

	PFN_vkCmdSetPolygonModeEXT cmdSetPolygonModeEXT = NULL;
};

