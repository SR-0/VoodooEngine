/*
	file: Renderer.cpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo, std
	declared class(es): Renderable
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#include "Core/Renderer.hpp"

// core incluedes
#include "Core/Window.hpp"

class Renderable {}; // @TODO (make base Renderable class in seperate core .cpp and .hpp files)

namespace voodoo
{
	#pragma region CONSTRUCTORS/DESTRUCTORS

	Renderer::Renderer(VkInstance& vkInstance, Window& window)
	{
		try
		{
			// make necessary attachments/references
			attachVkInstance(vkInstance);
			attachWindow(window);

			// initialize device
			initializePhysicalDevice();
			initializeLogicalDevice();
		}
		catch (const std::runtime_error& error)
		{
			std::cerr << error.what() << "\n";
		}
	}

	Renderer::~Renderer()
	{
		detachWindow();
		detachVkInstance();
	}

	#pragma endregion CONSTRUCTORS/DESTRUCTORS





	#pragma region ATTACH/DETACH

	void Renderer::attachWindow(Window& window)
	{
		this->window = &window;
	}
	
	void Renderer::detachWindow()
	{
		window = nullptr;
	}

	void Renderer::attachVkInstance(VkInstance& vkInstance)
	{
		this->vkInstance = &vkInstance;
	}

	void Renderer::detachVkInstance()
	{
		this->vkInstance = nullptr;
	}

	#pragma endregion ATTACH/DETACH





	#pragma region CORE INTERFACE

	void Renderer::clear(const Color& color)
	{
		// @TODO
	}

	void Renderer::queue(Renderable& renderable)
	{
		renderQueue.push_back(&renderable);
	}

	void Renderer::render(Renderable& renderable)
	{
		// @TODO
	}

	void Renderer::render()
	{
		for (auto renderable : renderQueue)
		{
			this->render(*renderable);
		}
	}

	void Renderer::display()
	{
		// @TODO
	}

	#pragma endregion CORE INTERFACE





	#pragma region INITIALIZATION

	void Renderer::initializePhysicalDevice()
	{
	}

	void Renderer::initializeLogicalDevice()
	{
	}
	
	#pragma endregion INITIALIZATION
}