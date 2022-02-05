/*
	file: JinxScript.cpp
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

#include "Script/JinxScript.hpp"

namespace voodoo
{
	JinxScript::JinxScript(const std::string& id) : Script(id)
	{
	}

	void JinxScript::update()
	{
		std::cout << "script id: " << this->getId() << " - update\n";
	}
}
