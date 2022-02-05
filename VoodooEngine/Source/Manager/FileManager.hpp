/*
	file: FileManager.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo
	declared class(es): FileManager
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_FILE_MANAGER_HPP
#define VOODOO_FILE_MANAGER_HPP

// core includes
#include "Core/Common.hpp"

namespace voodoo
{
	class FileManager
	{
	private:

		FileManager() = default;
		FileManager(const FileManager&) = delete;
		FileManager(FileManager&&) = delete;
		~FileManager() = default;

	private:

		FileManager& operator = (const FileManager&) = delete;
		FileManager& operator = (FileManager&&) = delete;

	public:

		static bool initialize();
		static void update();
		static void terminate();

	};

	using fm = FileManager;
}

#endif // VOODOO_FILE_MANAGER_HPP