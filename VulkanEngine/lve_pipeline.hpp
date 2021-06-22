#pragma once

#include "lve_device.hpp"

#include <string>
#include <vector>

namespace lve {

	struct PiplineConfigInfo {
		VkPipelineInputAssemblyStateCreateInfo inputAssemplyInfo;
	};

	class LvePipeLine {
	public:
		LvePipeLine(
			LveDevice &device, 
			const std::string& vertFilePath, 
			const std::string& fragFilePath,
			const PiplineConfigInfo& configInfo);
		~LvePipeLine() {};

		LvePipeLine(const LvePipeLine&) = delete;
		void operator=(const LvePipeLine&) = delete;

		static PiplineConfigInfo defaultPiplineConfigInfo(uint32_t width, uint32_t height);
	private:
		static std::vector<char> readFile(const std::string& filepath);

		void createGraphicsPipline(
			const std::string& vertFilePath, 
			const std::string& fragFilePath,
			const PiplineConfigInfo& configInfo);


		void createShaderModule( const std::vector<char>& code, VkShaderModule* shaderModule);

		LveDevice& lveDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
}