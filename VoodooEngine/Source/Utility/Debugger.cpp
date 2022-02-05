/*
	file: Debugger.cpp
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

#include "Utility/Debugger.hpp"

namespace voodoo
{
	bool Debugger::active = false;

	bool Debugger::isActive()
	{
		return active;
	}

	void Debugger::setActive(bool active)
	{
		Debugger::active = active;
	}
}