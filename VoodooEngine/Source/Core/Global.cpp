/*
	file: Global.cpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo, std
	declared class(es): N/A
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#include "Core/Global.hpp"

namespace voodoo
{
	#pragma region STATIC

	VkInstance	Global::vkInstance	= VkInstance{};
	Window*		Global::window		= nullptr;
	Renderer*	Global::renderer	= nullptr;

	#pragma endregion STATIC





	#pragma region INTERFACE

	bool Global::initialize()
	{
		if (!initializeGLFW())		{ throw std::runtime_error("error - failed to initialize glfw");		}
		if (!initializeVulkan())	{ throw std::runtime_error("error - failed to initialize vulkan");		}
		if (!initializeWindow())	{ throw std::runtime_error("error - failed to initialize window");		}
		if (!initializeRenderer())	{ throw std::runtime_error("error - failed to initialize renderer");	}

		return true;
	}

	void Global::terminate()
	{
		terminateRenderer();
		terminateWindow();
		terminateVulkan();
		terminateGLFW();
	}

	#pragma endregion INTERFACE





	#pragma region INITIALIZATION

	bool Global::initializeGLFW()
	{
		if (!glfwInit())
		{
			return false;
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		return true;
	}

	bool Global::initializeVulkan()
	{
		VkApplicationInfo vkApplicationInfo		= VkApplicationInfo{};
		vkApplicationInfo.sType					= VK_STRUCTURE_TYPE_APPLICATION_INFO;
		vkApplicationInfo.pNext					= nullptr;
		vkApplicationInfo.pApplicationName		= DEFAULT_APPLICATION_NAME;
		vkApplicationInfo.applicationVersion	= VK_MAKE_VERSION(1, 0, 0);
		vkApplicationInfo.pEngineName			= DEFAULT_ENGINE_NAME;
		vkApplicationInfo.engineVersion			= VK_MAKE_VERSION(1, 0, 0);
		vkApplicationInfo.apiVersion			= VK_API_VERSION_1_0;

		uint32_t		glfwExtensionCount	= 0;
		const char**	glfwExtensions		= glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		VkInstanceCreateInfo vkInstanceCreateInfo		= VkInstanceCreateInfo{};
		vkInstanceCreateInfo.sType						= VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		vkInstanceCreateInfo.pNext						= nullptr;
		vkInstanceCreateInfo.enabledExtensionCount		= glfwExtensionCount;
		vkInstanceCreateInfo.ppEnabledExtensionNames	= glfwExtensions;
		vkInstanceCreateInfo.pApplicationInfo			= &vkApplicationInfo;
		vkInstanceCreateInfo.enabledLayerCount			= 0;
		vkInstanceCreateInfo.ppEnabledLayerNames		= nullptr; // @TODO setup intance validation layers

		if (vkCreateInstance(&vkInstanceCreateInfo, nullptr, &vkInstance) != VK_SUCCESS)
		{
			return false;
		}

		return true;
	}

	bool Global::initializeWindow()
	{
		window = new Window
		{
			DEFAULT_WINDOW_SIZE,
			DEFAULT_WINDOW_TITLE,
			DEFAULT_WINDOW_STYLE
		};

		if (!window) 
		{
			return false;
		}
		
		return true;
	}

	bool Global::initializeRenderer()
	{
		renderer = new Renderer(vkInstance, *window);

		if (!renderer)
		{
			return false;
		}
		
		return true;
	}

	#pragma endregion INITIALIZATION





	#pragma region GETTERS/SETTERS

	Window& Global::getPrimaryWindow()
	{
		return *window;
	}

	Renderer& Global::getPrimaryRenderer()
	{
		return *renderer;
	}

	std::vector<const char*> Global::getInstanceExtensions()
	{
		std::vector<const char*>	instanceExtensions	= std::vector<const char*>{};
		uint32_t					glfwExtensionCount	= 0;
		const char**				glfwExtensions		= nullptr;

		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		for (size_t i = 0; i < glfwExtensionCount; i++)
		{
			instanceExtensions.push_back(glfwExtensions[i]);
		}

		return instanceExtensions;
	}

	std::string Global::getAvailableExtensionsInfo()
	{
		uint32_t extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
		std::vector<VkExtensionProperties> extensions(extensionCount);
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
		std::stringstream availableExtensionsInfo = std::stringstream{};
		availableExtensionsInfo << "available extensions:\n";

		auto instanceExtensions = getInstanceExtensions();

		for (const auto& instanceExtension : instanceExtensions)
		{
			bool hasExtension = false;

			for (const auto& extension : extensions)
			{
				if (strcmp(instanceExtension, extension.extensionName))
				{
					hasExtension = true;
					break;
				}
			}

			if (!hasExtension)
			{
				throw std::runtime_error("error - " + std::string(instanceExtension) + " not found");
			}
		}

		for (const auto& extension : extensions)
		{
			availableExtensionsInfo << "- " << extension.extensionName << "\n";
		}

		return availableExtensionsInfo.str();
	}

	std::string Global::getSupportedExtensionsInfo()
	{
		return std::string(); // @TODO
	}

	QueueFamilyIndicies Global::getQueueFamilies(VkPhysicalDevice vkPhysicalDevice)
	{
		// get all queue family property infor for the given device
		QueueFamilyIndicies queueFamilyIndicies = QueueFamilyIndicies{};
		uint32_t queueFamilyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(vkPhysicalDevice, &queueFamilyCount, nullptr);
		std::vector<VkQueueFamilyProperties> queueFamilyList = std::vector<VkQueueFamilyProperties>{ queueFamilyCount };
		vkGetPhysicalDeviceQueueFamilyProperties(vkPhysicalDevice, &queueFamilyCount, queueFamilyList.data());

		// go through each queue family and check if it has at leadst 1
		// of the required types of queue.
		//for (const auto& queueFamily : queueFamilyList)
		for (size_t i = 0; i < queueFamilyList.size(); i++)
		{
			// first check if queue family has at least one queue in the family
			// (could have no queues). Queue can be multiple types defined through bit field.
			// need bitwise AND with VK_QUEUE_*_BIT to hceck if it has required type
			if ( (queueFamilyList[i].queueCount > 0) && (queueFamilyList[i].queueFlags & VK_QUEUE_GRAPHICS_BIT))
			{
				queueFamilyIndicies.graphicsFamily = i; // if queue family is valid, then get index
			}

			// check if queue family indicies are in a valid state, stop searching
			// if so
			if (queueFamilyIndicies.isValid())
			{
				break;
			}
		}

		return queueFamilyIndicies;
	}

	#pragma endregion GETTERS/SETTERS





	#pragma region TERMINATION

	void Global::terminateRenderer()
	{
		if (renderer)
		{
			delete renderer;
			renderer = nullptr;
		}
	}

	void Global::terminateWindow()
	{
		if (window)
		{
			delete window;
			window = nullptr;
		}
	}

	void Global::terminateVulkan()
	{
		vkDestroyInstance(vkInstance, nullptr);
	}

	void Global::terminateGLFW()
	{
		glfwTerminate();
	}

	#pragma endregion TERMINATION
}