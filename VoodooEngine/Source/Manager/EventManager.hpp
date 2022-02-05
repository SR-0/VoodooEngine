/*
	file: EventManager.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo
	declared class(es): EventManager
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_EVENT_MANAGER_HPP
#define VOODOO_EVENT_MANAGER_HPP

// core includes
#include "Core/Common.hpp"

namespace voodoo
{
	class EventManager
	{
	private:

		EventManager() = default;
		EventManager(const EventManager&) = delete;
		EventManager(EventManager&&) = delete;
		~EventManager() = default;

	private:

		EventManager& operator = (const EventManager&) = delete;
		EventManager& operator = (EventManager&&) = delete;

	public:

		static bool initialize();
		static void update();
		static void terminate();

	};

	using em = EventManager;
}

#endif // VOODOO_EVENT_MANAGER_HPP