/*
	file: JinxScript.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo, std
	declared class(es): JinxScript
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_JINX_SCRIPT_HPP
#define VOODOO_JINX_SCRIPT_HPP

#include "Core/Script.hpp"

namespace voodoo
{
	class JinxScript : public Script
	{
	public:

		JinxScript(const std::string& id);

	public:

		virtual void update() override final;

	};
}

#endif // VOODOO_JINX_SCRIPT_HPP