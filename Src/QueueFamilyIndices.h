#pragma once
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
};