/*
	file: PolymorphicContainer.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -

	@TODO (freestyle pattern exploration)

	hint:

		PolymorphicFactory
				|
				v
		PolymorphicContainer
				|
				V
		PolymorphicSystem(s)
				|
				v
		PolymorphicManager

	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo, std
	declared class(es): PolymorphicContainer
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_POLYMORPHIC_CONTAINER_HPP
#define VOODOO_POLYMORPHIC_CONTAINER_HPP

#include "Pattern/PolymorphicFactory.hpp"
#include <vector>

template <typename Base, typename Factory = PolymorphicFactory<Base>> class PolymorphicContainer
{
public:

	PolymorphicContainer<Base, Factory>() = default;
	~PolymorphicContainer<Base, Factory>() { clear(); }

public:

	template <typename Derived> void push()
	{
		objects.push_back(factory.create<Derived>());
	}

	void pop()
	{
		if (objects.back())
		{
			delete objects.back();
			objects.back() = nullptr;
		}

		objects.pop_back();
	}

	Base* back()
	{
		return objects.back();
	}

	Base* get(uint32_t index)
	{
		return objects[index];
	}

	void clear()
	{
		for (auto object : objects)
		{
			if (object)
			{
				delete object;
				object = nullptr;
			}
		}

		objects.clear();
	}

	auto begin() const
	{
		return objects.begin();
	}

	auto end() const
	{
		return objects.end();
	}

private:

	std::vector<Base*>	objects = std::vector<Base*>{};
	Factory				factory = Factory{};

};

#endif//POLYMORPH_POLYMORPHIC_CONTAINER_HPP