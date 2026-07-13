#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include <string.h>
#include <stdexcept>
#include <fstream>

static class AssetHelper
{
public:
	// TODO fill out this function bruh
	static VkImageView createImageView(VkDevice device, VkImage image, VkFormat format, VkImageAspectFlags aspectFlag, uint32_t mipLevels);

	static std::vector<char> readFile(const std::string& filename);
};

