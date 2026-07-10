#pragma once

#include "Constants.h"
#include "InstanceStructs.h"
#include "WindowManager.h"
#include "AssetHelper.h"

#include <algorithm>
#include <stdexcept>

/// <summary>
/// TODO:
/// Create Image Views
/// Finish deconstructor
/// </summary>
class SwapChainManager
{
public:
	SwapChainManager(VkDevice* device, VkPhysicalDevice* physicalDevice, VkSurfaceKHR* surface, WindowManager* windowManager);
	~SwapChainManager();

	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice inPhysicalDevice);

	void createSwapChain(QueueFamilyIndices queueFamilyIndices);
	void createSwapChainImageViews();

private:
	VkSurfaceFormatKHR chooseSwapChainSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

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

