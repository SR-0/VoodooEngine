/*
	file: AssetManager.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo, std
	declared class(es): AssetManager
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_ASSET_MANAGER_HPP
#define VOODOO_ASSET_MANAGER_HPP

// core includes
#include "Core/Asset.hpp"

namespace voodoo
{
	class AssetManager
	{
	private:

		AssetManager() = default;
		AssetManager(const AssetManager&) = delete;
		AssetManager(AssetManager&&) = delete;
		~AssetManager() = default;

	private:

		AssetManager& operator = (const AssetManager&) = delete;
		AssetManager& operator = (AssetManager&&) = delete;

	public:

		static bool initialize();
		static void update();
		static void terminate();

	private:

		static std::vector<class Asset*> assets;

	};

	using am = AssetManager;
}

#endif // VOODOO_ASSET_MANAGER_HPP