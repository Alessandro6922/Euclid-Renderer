#pragma once

#include "vulkan/vulkan.h"
#include <vector>
#include <optional>

struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamilyIndex;
	std::optional<uint32_t> computeFamilyIndex;
	std::optional<uint32_t> presentationFamilyIndex;

	bool IsComplete() {
		return graphicsFamilyIndex.has_value() && computeFamilyIndex.has_value() && presentationFamilyIndex.has_value();
	}

	void Clear() {
		graphicsFamilyIndex.reset();
		computeFamilyIndex.reset();
		presentationFamilyIndex.reset();
	}

	uint32_t* GetQueueFamilyIndices() {
		uint32_t queueFamilyIndices[] = { graphicsFamilyIndex.value(), computeFamilyIndex.value(), presentationFamilyIndex.value() };

		return queueFamilyIndices;
	}
};

struct SwapChainSupportDetails {
	VkSurfaceCapabilitiesKHR surfaceCapabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};