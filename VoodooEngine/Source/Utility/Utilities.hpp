/*
	file: Utilities.hpp
	author(s): Scott Rivett
	version: 0.0.1

	- v - DESCRIPTION - v -
	@TODO
	- ^ - DESCRIPTION - ^ -

	using namespace(s): voodoo
	declared class(es): QueueFamilyIndicies, Device
	declared struct(s): N/A
	declared alias(es): N/A

	- v - CHANGE LOG - v -
	- ^ - CHANGE LOG - ^ -

	additional note(s): N/A
*/

#ifndef	VOODOO_UTILITIES_HPP
#define	VOODOO_UTILITIES_HPP

// Indices (locations) of Queue families (if they exist at all)
class QueueFamilyIndicies
{
public:

	bool isValid()
	{
		return graphicsFamily >= 0;
	}

public:

	int graphicsFamily = -1;

};

// temp
class Device
{
public:

	VkPhysicalDevice	physical	= VkPhysicalDevice{};
	VkDevice			logical		= VkDevice{};

};

#endif // VOODOO_UTILITIES_HPP