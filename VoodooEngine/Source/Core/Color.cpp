/*
	file: Color.cpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo
	declared class(es): N/A
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#include "Core/Color.hpp"

namespace voodoo
{
	const Color Color::White		= Color{	255u,	255u,	255u,	255u	};
	const Color Color::Black		= Color{	0u,		0u,		0u,		255u	};
	const Color Color::Red			= Color{	255u,	0u,		0u,		255u	};
	const Color Color::Green		= Color{	0u,		255u,	0u,		255u	};
	const Color Color::Blue			= Color{	0u,		0u,		255u,	255u	};
	const Color Color::Transparent	= Color{	0u,		0u,		0u,		0u		};
}