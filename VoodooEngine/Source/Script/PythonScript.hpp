/*
	file: PythonScript.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo, std
	declared class(es): PythonScript
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_PYTHON_SCRIPT_HPP
#define VOODOO_PYTHON_SCRIPT_HPP

#include "Core/Script.hpp"

namespace voodoo
{
	class PythonScript : public Script
	{
	public:

		PythonScript(const std::string& id);

	public:

		virtual void update() override final;

	};
}

#endif // VOODOO_PythonScript_SCRIPT_HPP