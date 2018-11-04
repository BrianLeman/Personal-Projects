#include "Character.h"
#include "Location.h"

// Create a character placed at an initial location
Character::Character(string name, Location *location)
{
	this->name = name;
	health = 100;
	this->location = location;
}

// Clean up memory
Character::~Character()
{
	// Nothing to clean
}

// Access to the name property
string Character::getName()
{
	return name;
}

// Update the health of a character
void Character::setHealth(int health)
{
	this->health = health;
}

// Return the health of the character
int Character::getHealth()
{
	return health;
}

// Initialize the location of the character
void Character::setLocation(Location *location)
{
	this->location = location;
}

// Get the location of a character
Location *Character::getLocation()
{
	return location;
}
