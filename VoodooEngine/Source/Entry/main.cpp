/*
	file: main.cpp
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

#include "Core/Engine.hpp"

using namespace voodoo;

int main(int argc, char** argv)
{
	try
	{
		if (Engine::initialize())
		{
			while (Engine::isRunning())
			{
				Engine::update();
				Engine::render();
			}

			Engine::terminate();
		}
	}
	catch (const std::exception& exception)
	{
		std::cerr << exception.what() << "\n";

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}