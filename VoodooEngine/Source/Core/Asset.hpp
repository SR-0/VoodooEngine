/*
	file: Asset.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo, std
	declared class(es): Asset, SoundBuffer, Sound, Music, Font, Text, Texture, Shape
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_ASSET_HPP
#define VOODOO_ASSET_HPP

#include "Core/Common.hpp"

namespace voodoo
{
	class Asset
	{
	public:

		Asset(const std::string& id) : id(id) {}
		virtual ~Asset() {}

	public:

		virtual void update() = 0;

	public:

		std::string	getId() const;
		void		setId(const std::string& id);

	private:

		std::string id;

	};

	class SoundBuffer : public Asset
	{
	public:

		SoundBuffer(const std::string& id) : Asset(id) {}

	public:

		virtual void update() override final { std::cout << std::string("SoundBuffer with id \"" + this->getId() + "\" called update()\n"); }

	};

	class Sound : public Asset
	{
	public:

		Sound(const std::string& id) : Asset(id) {}

	public:

		virtual void update() override final { std::cout << std::string("Sound with id \"" + this->getId() + "\" called update()\n"); }

	};

	class Music : public Asset
	{
	public:

		Music(const std::string& id) : Asset(id) {}

	public:

		virtual void update() override final { std::cout << std::string("Music with id \"" + this->getId() + "\" called update()\n"); }
		
	};

	class Font : public Asset
	{
	public:

		Font(const std::string& id) : Asset(id) {}

	public:

		virtual void update() override final { std::cout << std::string("Font with id \"" + this->getId() + "\" called update()\n"); }
		
	};

	class Text : public Asset
	{
	public:

		Text(const std::string& id) : Asset(id) {}

	public:

		virtual void update() override final { std::cout << std::string("Text with id \"" + this->getId() + "\" called update()\n"); }
		
	};

	class Texture : public Asset
	{
	public:

		Texture(const std::string& id) : Asset(id) {}

	public:

		virtual void update() override final { std::cout << std::string("Texture with id \"" + this->getId() + "\" called update()\n"); }
		
	};

	class Shape : public Asset
	{
	public:

		Shape(const std::string& id) : Asset(id) {}

	public:

		virtual void update() override final { std::cout << std::string("Shape with id \"" + this->getId() + "\" called update()\n"); }
		
	};

}

#endif