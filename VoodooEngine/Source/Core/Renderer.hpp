/*
	file: Renderer.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo, std
	declared class(es): Renderer
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_RENDERER_HPP
#define VOODOO_RENDERER_HPP

#include "Core/Common.hpp"

namespace voodoo
{
	class Renderer
	{
	public:

		Renderer(VkInstance& vkInstance, class Window& window);
		~Renderer();

	private:

		void attachWindow(class Window& window);
		void attachVkInstance(VkInstance& vkInstance);

	private:

		void detachWindow();
		void detachVkInstance();

	public:

		void clear(const Color& color = Color::Black);
		void queue(class Renderable& renderable);
		void render(class Renderable& renderable);
		void render();
		void display();

	private:

		void initializePhysicalDevice();
		void initializeLogicalDevice();

	private:

		VkInstance*						vkInstance	= nullptr;
		class Window*					window		= nullptr;
		Device							device		= Device{};
		std::vector<class Renderable*>	renderQueue	= std::vector<class Renderable*>{};

	};
}

#endif//VOODOO_RENDERER_HPP

