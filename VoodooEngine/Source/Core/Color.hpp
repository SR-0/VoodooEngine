/*
	file: Color.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo
	declared class(es): Color
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_COLOR_HPP
#define VOODOO_COLOR_HPP

#include <cstdint>
#include <ostream>

namespace voodoo
{
	class Color
	{
	public:
	
		Color() 
			: 
			r(255u),
			g(255u),
			b(255u),
			a(255u)
		{}
		
		Color(
			uint8_t r, 
			uint8_t g, 
			uint8_t b, 
			uint8_t a = 255u) 
			: 
			r(r),
			g(g),
			b(b),
			a(a)
		{}
	
	public:
	
		friend bool operator == (const Color& a, const Color& b) 
		{ 
			return 
			(
				a.r == b.r &&
				a.g == b.g &&
				a.b == b.b &&
				a.a == b.a
			);
		}
	
		friend bool operator != (const Color& a, const Color& b) 
		{ 
			return 
			(
				a.r != b.r ||
				a.g != b.g ||
				a.b != b.b ||
				a.a != b.a
			);
		}
	
	public:
	
		uint8_t r = 0u;
		uint8_t g = 0u;
		uint8_t b = 0u;
		uint8_t a = 0u;
	
	public:
	
		static const Color White;
		static const Color Black;
		static const Color Red;
		static const Color Green;
		static const Color Blue;
		static const Color Transparent;
	
	};
}

#endif//VOODOO_COLOR_HPP