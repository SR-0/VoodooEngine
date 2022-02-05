/*
	file: Asset.cpp
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

#include "Core/Asset.hpp"

namespace voodoo
{
	std::string Asset::getId() const
	{
		return id;
	}

	void Asset::setId(const std::string& id)
	{
		this->id = id;
	}
}