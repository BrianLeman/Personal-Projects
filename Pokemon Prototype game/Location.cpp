#include "Location.h"

// Initialize a location
Location::Location(string name, string description)
{
	this->name = name;
	this->description = description;
	pokemon = NULL;
}

// Add a new exit point of this location
void Location::addExit(Location *location)
{
	exits[location->getName()] = location;
}

// Get one of the exits from this location
Location *Location::getExit(string locationName)
{
	if (exits.find(locationName) == exits.end())
		return NULL;

	return exits[locationName];
}

// Get the location's name
string Location::getName()
{
	return name;
}

// Display the location's description
string Location::getDescription()
{
	return description;
}

// Return all possible exit points of this location
vector<string> Location::getExits()
{
	vector<string> exitNames;

	for (map<string, Location *>::iterator it = exits.begin(); it != exits.end(); it++)
		exitNames.push_back(it->first);

	return exitNames;
}

// Return the pokemon in the area
Pokemon *Location::getPokemon()
{
	return pokemon;
}

// Remove the character on this location
void Location::removeCharacter(Character *character)
{
	// Find and remove for the player container
	for (unsigned i = 0; i < players.size(); i++)
	{
		if (players[i] == character)
		{
			players.erase(players.begin() + i);
			return;
		}
	}

	// Find and remove if it is the pokemon
	if (pokemon == character)
		pokemon = NULL;
}

// Add a new character to this location
void Location::addCharacter(Character *character)
{
	if (Player *player = dynamic_cast<Player *>(character))
		players.push_back(player);
	else
		pokemon = dynamic_cast<Pokemon *>(character);
}

// Add a new item
void Location::addItem(Item *item)
{
	items.push_back(item);
}

// Remove the item from the location
void Location::removeItem(Item *item)
{
	for (unsigned i = 0; i < items.size(); i++)
	{
		if (items[i] == item)
		{
			items.erase(items.begin() + i);
			return;
		}
	}
}

// Get the list of items in the location
vector<Item *> Location::getItems()
{
	return items;
}

// Get the players in the location
vector<Player *> Location::getPlayers()
{
	return players;
}