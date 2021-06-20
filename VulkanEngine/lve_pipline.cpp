#include "lve_pipeline.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>

namespace lve {
	LvePipeLine::LvePipeLine(const std::string& vertFilePath, const std::string& fragFilePath)
	{
		createGraphicsPipline(vertFilePath, fragFilePath);
	}
	
	std::vector<char> LvePipeLine::readFile(const std::string& filepath) {

		std::ifstream file(filepath, std::ios::ate | std::ios::binary);

		if (!file.is_open()) {
			throw std::runtime_error("Failed to open file: " + filepath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();
		return buffer;
	}

	 void LvePipeLine::createGraphicsPipline(const std::string& vertFilePath, const std::string& fragFilePath)
	{
		auto vertCode = readFile(vertFilePath);
		auto fragCode = readFile(fragFilePath);

		std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
		std::cout << " Fragment Shader Code Size: " << fragCode.size() << '\n';

	}
}