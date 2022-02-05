/*
	file: InputManager.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo
	declared class(es): InputManager
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_INPUT_MANAGER_HPP
#define VOODOO_INPUT_MANAGER_HPP

// core includes
#include "Core/Common.hpp"

namespace voodoo
{
	class InputManager
	{
	private:

		InputManager() = default;
		InputManager(const InputManager&) = delete;
		InputManager(InputManager&&) = delete;
		~InputManager() = default;

	private:

		InputManager& operator = (const InputManager&) = delete;
		InputManager& operator = (InputManager&&) = delete;

	public:

		static bool initialize();
		static void update();
		static void terminate();

	};

	using im = InputManager;
}

#endif // VOODOO_INPUT_MANAGER_HPP