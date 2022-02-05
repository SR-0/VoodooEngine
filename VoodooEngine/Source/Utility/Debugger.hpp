/*
	file: Debugger.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo
	declared class(es): Debugger
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_DEBUGGER_HPP
#define VOODOO_DEBUGGER_HPP

#include "Core/Common.hpp"

namespace voodoo
{
	class Debugger
	{
	private:

		Debugger() = default;
		Debugger(const Debugger&) = delete;
		Debugger(Debugger&&) = delete;
		~Debugger() = default;

	private:

		Debugger& operator = (const Debugger&) = delete;
		Debugger& operator = (Debugger&&) = delete;

	public:

		static bool isActive();
		static void setActive(bool active);

	private:

		static bool active;

	};

	using debug = Debugger;
}

#endif // VOODOO_DEBUGGER_HPP
