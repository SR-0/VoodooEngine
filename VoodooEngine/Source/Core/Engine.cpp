/*
	file: Engine.cpp
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

#include "Core/Engine.hpp"

// core includes
#include "Core/Global.hpp"

// manager includes
#include "Manager/AssetManager.hpp"
#include "Manager/EventManager.hpp"
#include "Manager/FileManager.hpp"
#include "Manager/InputManager.hpp"
#include "Manager/ScriptManager.hpp"

namespace voodoo
{
	bool Engine::initialize()
	{
		// core initialization
		Global::initialize();

		// manager initialization
		if (!am::initialize()) { throw std::runtime_error("error - failed to initialize AssetManager");		}
		if (!em::initialize()) { throw std::runtime_error("error - failed to initialize EventManager");		}
		if (!fm::initialize()) { throw std::runtime_error("error - failed to initialize FileManager");		}
		if (!im::initialize()) { throw std::runtime_error("error - failed to initialize InputManager");		}
		if (!sm::initialize()) { throw std::runtime_error("error - failed to initialize ScriptManager");	}

		return true;
	}

	bool Engine::isRunning()
	{
		return Global::getPrimaryWindow().isOpen(); // @TODO (specify soon)
	}

	void Engine::update()
	{
		am::update();
		em::update();
		fm::update();
		im::update();
		sm::update();
	}

	void Engine::render()
	{
		Global::getPrimaryRenderer().clear();
		Global::getPrimaryRenderer().render();
		Global::getPrimaryRenderer().display();
	}

	void Engine::terminate()
	{
		am::terminate();
		em::terminate();
		fm::terminate();
		im::terminate();
		sm::terminate();

		Global::terminate();
	}
}