/*
	file: Window.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo, std
	declared class(es): Window
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_WINDOW_HPP
#define VOODOO_WINDOW_HPP

#include "Core/Common.hpp"

namespace voodoo
{
	class Window
	{
	public:

		Window(const Vector2u& size, const std::string& title, bool fullscreen);
		~Window();

	public:

		bool isOpen() const;
		void close();

	private:

		GLFWwindow* glfwWindow = nullptr;

	};
}

#endif//VOODOO_WINDOW_HPP