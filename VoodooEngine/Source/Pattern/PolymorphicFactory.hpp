/*
	file: PolymorphicFactory.hpp
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

	using namespace(s): voodoo
	declared class(es): PolymorphicFactory
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_POLYMORPHIC_FACTORY_HPP
#define VOODOO_POLYMORPHIC_FACTORY_HPP

#include <type_traits>

template <typename Base> class PolymorphicFactory
{
public:

	PolymorphicFactory<Base>() = default;
	~PolymorphicFactory<Base>() = default;

public:

	template <typename Derived> Base* create()
	{
		if (std::is_base_of<Base, Derived>::value)
		{
			Base* object = new Derived();
			setup(object);
			return object;
		}

		return nullptr;
	}

protected:

	virtual void setup(Base* object) {}

};

#endif//POLYMORPH_POLYMORPHIC_FACTORY_HPP