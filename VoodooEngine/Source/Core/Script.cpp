/*
	file: Script.cpp
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

#include "Core/Script.hpp"

namespace voodoo
{
	Script::Script(const std::string& id) : id(id), active(false)
	{
	}

	Script::~Script()
	{
	}

	std::string Script::getId() const
	{
		return id;
	}

	void Script::setId(const std::string& id)
	{
		this->id = id;
	}

	bool Script::isActive() const
	{
		return active;
	}

	void Script::setActive(bool active)
	{
		this->active = active;
	}
}