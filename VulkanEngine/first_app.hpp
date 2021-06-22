#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_window.hpp"

namespace lve {
	class FirstApp {

	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();
	private:
		LveWindow lveWindow{ WIDTH, HEIGHT, "Vulkan Window" };
		LveDevice lveDevice{ lveWindow };
		LvePipeLine lvePipeLine{
			lveDevice, 
			"Shaders/simple_shader.vert.spv", 
			"Shaders/simple_shader.frag.spv", 
			LvePipeLine::defaultPiplineConfigInfo(WIDTH, HEIGHT) };
	};
}