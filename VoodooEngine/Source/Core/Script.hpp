/*
	file: Script.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo, std
	declared class(es): Script
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_SCRIPT_HPP
#define VOODOO_SCRIPT_HPP

#include "Core/Common.hpp"

namespace voodoo
{
	class Script
	{
	public:

		Script(const std::string& id);
		virtual ~Script();

	public:

		virtual void update() = 0;

	public:

		std::string	getId() const;
		void		setId(const std::string& id);
		bool		isActive() const;
		void		setActive(bool active);

	private:

		std::string	id		= std::string{};
		bool		active	= bool{};

	};
}

#endif