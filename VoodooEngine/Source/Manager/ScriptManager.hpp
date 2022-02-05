/*
	file: ScriptManager.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo, std
	declared class(es): ScriptManager
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_SCRIPT_MANAGER_HPP
#define VOODOO_SCRIPT_MANAGER_HPP

// core includes
#include "Core/Script.hpp"

namespace voodoo
{
	class ScriptManager
	{
	private:

		ScriptManager() = default;
		ScriptManager(const ScriptManager&) = delete;
		ScriptManager(ScriptManager&&) = delete;
		~ScriptManager() = default;

	private:

		ScriptManager& operator = (const ScriptManager&) = delete;
		ScriptManager& operator = (ScriptManager&&) = delete;

	public:

		static bool initialize();
		static void update();
		static void terminate();

	private:

		static std::vector<Script*> scripts;

	};

	using sm = ScriptManager;
}

#endif // VOODOO_SCRIPT_MANAGER_HPP