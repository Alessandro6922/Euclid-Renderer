#include "QueueManager.h"

QueueManager::QueueManager(VkDevice* inDevice = nullptr, VkPhysicalDevice* inPhysicalDevice = nullptr, VkSurfaceKHR* inSurface = nullptr) : device(inDevice), physicalDevice(inPhysicalDevice), surface(inSurface)
{
}

QueueManager::~QueueManager()
{
}

QueueFamilyIndices QueueManager::findQueueFamilies(VkPhysicalDevice inPhysicalDevice)
{
	QueueFamilyIndices indices;
	uint32_t queueFamilyCount = 0;

	vkGetPhysicalDeviceQueueFamilyProperties(inPhysicalDevice, &queueFamilyCount, nullptr);
	std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(inPhysicalDevice, &queueFamilyCount, queueFamilies.data());

	int i = 0;
	for (const auto& queuefamily : queueFamilies) {
		if (queuefamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
			indices.graphicsFamilyIndex = i;
		}
		if (queuefamily.queueFlags & VK_QUEUE_COMPUTE_BIT) {
			indices.computeFamilyIndex = i;
		}

		VkBool32 presentSupport = false;
		vkGetPhysicalDeviceSurfaceSupportKHR(inPhysicalDevice, i, *surface, &presentSupport);

		if (presentSupport) {
			indices.presentationFamilyIndex = i;
		}

		if (indices.IsComplete()) {
			break;
		}

		i++;
	}

	return indices;
}

QueueFamilyIndices* QueueManager::getQueueFamilyIndices()
{
	return &queueFamilyIndices;
}
