/*
	file: Engine.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo
	declared class(es): Engine
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_ENGINE_HPP
#define VOODOO_ENGINE_HPP

#include "Core/Common.hpp"

namespace voodoo
{
	class Engine
	{
	private: // ctors/dtors

		Engine() = default;
		Engine(const Engine&) = delete;
		Engine(Engine&&) = delete;
		~Engine() = default;

	private: // operator overloading
	
		Engine& operator = (const Engine&) = delete;
		Engine& operator = (Engine&&) = delete;
	
	public: // engine core interface

		static bool initialize();
		static bool isRunning();
		static void update();
		static void render();
		static void terminate();

	};
}

#endif//VOODOO_ENGINE_HPP