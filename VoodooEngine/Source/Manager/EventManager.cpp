/*
	file: EventManager.cpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo
	declared class(es): N/A
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#include "Manager/EventManager.hpp"

namespace voodoo
{
	bool EventManager::initialize()
	{
		return true;
	}

	void EventManager::update()
	{
		glfwPollEvents();
	}

	void EventManager::terminate()
	{
		glfwTerminate();
	}
}