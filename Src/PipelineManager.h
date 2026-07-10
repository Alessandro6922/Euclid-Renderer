#pragma once

#include "Constants.h"


/// <summary>
/// TODO: Create this whole class honestly
/// It should be able to create graphics pipelines and will be used by other classes which will then store their own pipeline.
/// e.g. rasterisation pipeline class will use it to create a rasterisation pipeline, rt pipeline class will use it to create an rt pipeline
/// </summary>
class PipelineManager
{
public:
	PipelineManager();
	~PipelineManager();

	VkPipeline createGraphicsPipeline();
};

