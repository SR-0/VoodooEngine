/*
	file: PolymorphicManager.hpp
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
	declared class(es): PolymorphicManager
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef VOODOO_POLYMORPHIC_MANAGER_HPP
#define VOODOO_POLYMORPHIC_MANAGER_HPP

#include "Pattern/PolymorphicSystem.hpp"

template <typename Base, typename Container = PolymorphicContainer<Base>> class PolymorphicManager
{
public:

	PolymorphicManager<Base, Container>() = default;
	~PolymorphicManager<Base, Container>() = default;

public:
	
	virtual void update(Container* container)
	{
		for (auto system : systems)
		{
			if (system->isActive())
			{
				system->update(container);
			}
		}
	}
	
	template <typename Derived> void push()
	{
		systems.push<Derived>();
	}

	void pop()
	{
		systems.pop();
	}

private:

	PolymorphicContainer<PolymorphicSystem<Base, Container>> systems = PolymorphicContainer<PolymorphicSystem<Base, Container>>{};

};

#endif//POLYMORPH_POLYMORPHIC_MANAGER_HPP