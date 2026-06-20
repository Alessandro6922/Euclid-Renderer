#pragma once

#include "Constants.h"
#include "InstanceStructs.h"
#include "WindowManager.h"

#include <algorithm>
#include <stdexcept>

/// <summary>
/// Finish implementation
/// possibly rework constructors
/// </summary>
class SwapChainManager
{
private:
	SwapChainManager(VkDevice* device, VkPhysicalDevice* physicalDevice, VkSurfaceKHR* surface, WindowManager* windowManager);
	~SwapChainManager();

public:
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice inPhysicalDevice);

private:
	VkSurfaceFormatKHR chooseSwapChainSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

	void createSwapChain();

private:
	VkDevice* device;
	VkPhysicalDevice* physicalDevice;
	VkSurfaceKHR* surface;
	
	WindowManager* windowManager;

	VkSwapchainKHR swapChain;
	std::vector<VkImage> swapChainImages;
	std::vector<VkImageView> swapChainImageViews;

	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;

	VkPresentModeKHR presentMode;

	uint32_t imageCount;
};

