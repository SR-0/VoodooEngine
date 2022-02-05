/*
	file: ScriptManager.cpp
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

#include "Manager/ScriptManager.hpp"

namespace voodoo
{
	std::vector<Script*> ScriptManager::scripts = std::vector<Script*>();

	bool ScriptManager::initialize()
	{
		return true;
	}

	void ScriptManager::update()
	{
		for (auto script : scripts)
		{
			if (script->isActive())
			{
				script->update();
			}
		}
	}

	void ScriptManager::terminate()
	{
		for (auto script : scripts)
		{
			delete script;
		}

		scripts.clear();
	}
}