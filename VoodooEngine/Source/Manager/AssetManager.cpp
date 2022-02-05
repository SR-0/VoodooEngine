/*
	file: AssetManager.cpp
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

#include "Manager/AssetManager.hpp"

namespace voodoo
{
	std::vector<Asset*> AssetManager::assets = std::vector<Asset*>();

	bool AssetManager::initialize()
	{
		return true;
	}

	void AssetManager::update()
	{
	}

	void AssetManager::terminate()
	{
	}
}