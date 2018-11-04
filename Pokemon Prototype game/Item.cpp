#include "Item.h"

// Create an item
Item::Item(string name)
{
	this->name = name;
}

// Destructor
Item::~Item()
{
}

// Get the name of the item
string Item::getName()
{
	return name;
}