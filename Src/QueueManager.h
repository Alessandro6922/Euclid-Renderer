#pragma once

#include "Constants.h"
#include "InstanceStructs.h"


/// <summary>
/// Finish implementation
/// possibly rework constructors
/// </summary>
class QueueManager
{
public:
	QueueManager(VkDevice* device, VkPhysicalDevice* physicalDevice, VkSurfaceKHR* surface);
	~QueueManager();

	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

	QueueFamilyIndices* getQueueFamilyIndices();

private:
	VkDevice* device;
	VkPhysicalDevice* physicalDevice;
	VkSurfaceKHR* surface;

	QueueFamilyIndices queueFamilyIndices;
};

