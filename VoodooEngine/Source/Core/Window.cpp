/*
	file: Window.cpp
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

#include "Core/Window.hpp"

namespace voodoo
{
	class Renderable {};

	Window::Window(const Vector2u& size, const std::string& title, bool fullscreen)
	{
		glfwWindow = glfwCreateWindow(size.x, size.y, title.c_str(), nullptr, nullptr);

		// @TODO initial fullscreen
	}

	Window::~Window()
	{
		glfwDestroyWindow(glfwWindow);
	}

	bool Window::isOpen() const
	{
		return !glfwWindowShouldClose(glfwWindow); // todo
	}

	void Window::close()
	{
		glfwSetWindowShouldClose(glfwWindow, true);
	}
}