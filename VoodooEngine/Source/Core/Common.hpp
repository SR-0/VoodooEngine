/*
	file: Common.hpp
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

#ifndef VOODOO_COMMON_HPP
#define VOODOO_COMMON_HPP

// std/stl includes
#include <type_traits>
#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cstring>

// glfw includes
#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

// glm includes
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include "GLM/glm.hpp"

// core includes
#include "Core/Color.hpp"
#include "Core/Vector.hpp"

// pattern includes
#include "Pattern/PolymorphicFactory.hpp"
#include "Pattern/PolymorphicContainer.hpp"
#include "Pattern/PolymorphicSystem.hpp"
#include "Pattern/PolymorphicManager.hpp"

// utility includes
#include "Utility/Utilities.hpp"

// global default defines
#define	DEFAULT_WINDOW_SIZE			Vector2u{ 1280u, 720u }
#define	DEFAULT_WINDOW_TITLE		"untitled"
#define	DEFAULT_WINDOW_STYLE		0
#define	DEFAULT_ENGINE_NAME			"Templar Engine"
#define	DEFAULT_APPLICATION_NAME	"Templar Engine Application"
#define	VALIDATION_LAYERS			std::vector<const char*>{ "VK_LAYER_KHRONOS_validation" }

#ifdef NDEBUG
	#define VALIDATION_LAYERS_ENABLED false
#else
	#define VALIDATION_LAYERS_ENABLED true
#endif

namespace voodoo
{
	static bool isValidationLayerSupported()
	{
		uint32_t layerCount;
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
		std::vector<VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
	
		for (const char* layerName : VALIDATION_LAYERS)
		{
			for (const auto& layerProperties : availableLayers)
			{
				if (strcmp(layerName, layerProperties.layerName) == 0)
				{
					return true;
				}
			}
		}
	
		return false;
	}
}

#pragma region VULKAN CALLBACKS (may be moved)

// optional chapter (page 52 @ "Message Callback") // will do later... maybe

#pragma endregion

#endif // VOODOO_COMMON_H