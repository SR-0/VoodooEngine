/*
	file: LuaScript.cpp
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

#include "Script/LuaScript.hpp"

extern "C"
{
	#include <LUA/lua.h> 
	#include <LUA/lualib.h> 
	#include <LUA/lauxlib.h> 
}

namespace voodoo
{
	LuaScript::LuaScript(const std::string& id) : Script(id)
	{
	}

	void LuaScript::update()
	{
		/*
		std::cout << "script id: " << this->getId() << " - updating\n";

		std::string command = "a = 7 + 11 + math.sin(23.7)";

		lua_State* state = luaL_newstate();
		luaL_openlibs(state);

		int errorCode = luaL_dostring(state, command.c_str());

		if (errorCode != LUA_OK)
		{
			std::string errormsg = lua_tostring(state, -1);
			std::cout << errormsg << "\n";
		}
		else
		{
			lua_getglobal(state, "a");

			if (lua_isnumber(state, -1))
			{
				std::cout << lua_tonumber(state, -1) << "\n";
			}
		}

		lua_close(state);

		std::cout << "script id: " << this->getId() << " - updated\n";
		*/
	}
}