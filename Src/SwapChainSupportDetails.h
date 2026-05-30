#pragma once

#include "vulkan/vulkan.h"
#include <vector>

struct SwapChainSupprtDetails {
	VkSurfaceCapabilitiesKHR surfaceCapabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};