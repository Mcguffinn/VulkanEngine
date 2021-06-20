#pragma once

#include <string>
#include <vector>

namespace lve {
	class LvePipeLine {
	public:
		LvePipeLine(const std::string& vertFilePath, const std::string& fragFilepath);

	private:
		static std::vector<char> readFile(const std::string& filepath);

		void createGraphicsPipline(const std::string& vertFilePath, const std::string& fragFilepath);
	};
}