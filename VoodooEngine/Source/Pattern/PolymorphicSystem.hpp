/*
	file: PolymorphicSystem.hpp
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
	declared class(es): PolymorphicSystem
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_POLYMORPHIC_SYSTEM_HPP
#define VOODOO_POLYMORPHIC_SYSTEM_HPP

#include "Pattern/PolymorphicContainer.hpp"

template <typename Base, typename Container = PolymorphicContainer<Base>> class PolymorphicSystem
{
public:

	PolymorphicSystem<Base, Container>() = default;
	~PolymorphicSystem<Base, Container>() = default;

public:

	virtual void update(Container* container) = 0;

public:

	bool isActive() const
	{
		return active;
	}

	void setActive(bool active)
	{
		this->active = active;
	}

private:

	bool active = true;

};

#endif//POLYMORPH_POLYMORPHIC_SYSTEM_HPP