#include <iostream>
#include <vector>
#include <cstdlib>
#include "Pokemon.h"
#include "Location.h"

using namespace std;

// Create a pokemon
Pokemon::Pokemon(string name, Location *location) : Character(name, location)
{
	captured = false;
}

// Make the pokemon act
void Pokemon::act()
{
	Location *location = getLocation();

	// If there are players around then attack randomly attack one of the players
	vector<Player *> players = location->getPlayers();

	if (!players.empty())
	{
		Player *player = players[rand() % players.size()];
		cout << getName() << " encountered player " << player->getName() << endl;
		cout << getName() << " should attack player but this feature is not yet implemented." << endl;
	}
	else
	{
		// Otherwise pokemon randomly moves to one of the exits from the current location
		vector<string> exits = location->getExits();
		string exitName = exits[rand() % exits.size()];

		Location *enteringLocation = location->getExit(exitName);
		location->removeCharacter(this);
		enteringLocation->addCharacter(this);
		setLocation(enteringLocation);

		cout << "Pokedex says there's a pokemon in " << enteringLocation->getName() << "!" << endl;
	}
}

// Set the pokemon whether it was captured or not
void Pokemon::setCaptured(bool captured)
{
	this->captured = captured;
}

// Check if the pokemon has been captured
bool Pokemon::isCaptured()
{
	return captured;
}
