/*
	file: Global.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo, std
	declared class(es): Global
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_GLOBAL_HPP
#define VOODOO_GLOBAL_HPP

// core includes
#include "Core/Window.hpp"
#include "Core/Renderer.hpp"

namespace voodoo
{
	class Global
	{
	private: // ctors/dtors

		Global() = default;
		Global(const Global&) = delete;
		Global(Global&&) = delete;
		~Global() = default;

	private: // operator overloading
	
		Global& operator = (const Global&) = delete;
		Global& operator = (Global&&) = delete;

	public: // intialization/termination

		static bool initialize();
		static void terminate();

	private: // all global initializaitons (in order of use)

		static bool initializeGLFW();
		static bool initializeVulkan();
		static bool initializeWindow();
		static bool initializeRenderer();

	public: // getters/setters

		static Window&					getPrimaryWindow();
		static Renderer&				getPrimaryRenderer();
		static std::vector<const char*>	getInstanceExtensions();
		static std::string				getAvailableExtensionsInfo();
		static std::string				getSupportedExtensionsInfo();
		static QueueFamilyIndicies		getQueueFamilies(VkPhysicalDevice vkPhysicalDevice);
	
	private: // all global terminations/clean-ups (in order of use)

		static void terminateRenderer();
		static void terminateWindow();
		static void terminateVulkan();
		static void terminateGLFW();

	private: // static members

		static VkInstance	vkInstance;
		static Window*		window;
		static Renderer*	renderer;

	};

}

#endif//VOODOO_GLOBAL_HPP