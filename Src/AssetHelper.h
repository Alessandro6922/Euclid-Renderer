#pragma once

#include <vulkan/vulkan.h>

static class AssetHelper
{
public:
	static VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlag, uint32_t mipLevels);
};

