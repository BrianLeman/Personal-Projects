#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Player.h"
#include "Location.h"

using namespace std;

// Create a new player
Player::Player(string name, Location *location) : Character(name, location)
{
}

// Make the user perform commands
void Player::act()
{
	// Get a command from the player
	cout << "Hey " << getName() << ", its you're turn (enter 'help' if you're confused) >>> ";
	string command;
	getline(cin, command);

	// Parse the command
	stringstream ss(command);
	ss >> command;

	bool endTurn = false;

	while (!endTurn)
	{
		if (command == "help")
			endTurn = displayHelp();
		else if (command == "enter")		
			endTurn = enterLocation(ss);
		else if (command == "brief")
			endTurn = describeLocation();
		else if (command == "take")
			endTurn = takeItem(ss);
		else if (command == "bag")
			endTurn = displayBag();
		else if (command == "catch")
			endTurn = catchPokemon();
		else if (command == "tackle")
			endTurn = tacklePokemon();
		else
			cout << "That's an invalid command " << getName() << "!" << endl;

		cout << endl;

		if (!endTurn)
		{
			// Ask another command
			cout << "Okay " << getName() << ", what else do you want to do? >>> ";
			getline(cin, command);
		
			ss.str("");
			ss.clear();
			ss.str(command);
			ss >> command;
		}
	}
}

// Attack a pokemon in the area
bool Player::tacklePokemon()
{
	cout << "Sorry, this feature is not yet implemented." << endl;
	return true;
}

// Catch the pokemon in the current area
bool Player::catchPokemon()
{
	cout << "Sorry, this feature is not yet implemented." << endl;
	return true;
}

// Display the contents of the bag
bool Player::displayBag()
{
	cout << "Sorry, this feature is not yet implemented." << endl;
	return false;
}

// Take an item from the current location
bool Player::takeItem(stringstream &ss)
{
	cout << "Sorry, this feature is not yet implemented." << endl;
	return true;
}

// Display what is in the current location
bool Player::describeLocation()
{
	Location *location = getLocation();
	Pokemon *pokemon = location->getPokemon();

	cout << "You are in " << location->getName() << ", " << location->getDescription() << endl;

	if (pokemon != NULL)
		cout << "A wild " << pokemon->getName() << " has appeared!" << endl;

	vector<Item *> items = location->getItems();

	if (!items.empty())
	{
		cout << "You saw some items around: ";

		for (unsigned i = 0; i < items.size(); i++)
		{
			cout << items[i]->getName();

			if (i + 1 < items.size())
				cout << ", ";
		}

		cout << endl;
	}

	vector<string> exits = location->getExits();

	if (!exits.empty())
	{
		cout << "From here you can to go: ";

		for (unsigned i = 0; i < exits.size(); i++)
		{
			cout << exits[i];

			if (i + 1 < exits.size())
				cout << ", ";
		}

		cout << endl;
	}

	return false;
}

// Display the commands manual
bool Player::displayHelp()
{
	cout << "Commands Manual" << endl;
	cout << "enter [location-name] : Move to the desired location" << endl;
	cout << "brief                 : Give a description of the current area" << endl;
	cout << "take [item-name]      : Pick up an item in the current area" << endl;
	cout << "catch                 : Throws a pokeball to a pokemon in the area" << endl;
	cout << "tackle                : Attack a pokemon" << endl;
	cout << "bag                   : Display the items in bag" << endl;
	return false;
}

// Move to another location
bool Player::enterLocation(stringstream &ss)
{
	// Check where to move
	string locationName;
	
	if (!(ss >> locationName))
	{
		cout << "Sorry, not sure where you want to go." << endl;
		return false;
	}

	Location *enteringLocation = getLocation()->getExit(locationName);

	// Make sure the location exists
	if (enteringLocation == NULL)
	{
		cout << "Unfortunately there's no road going to " << locationName << "." << endl;
		return false;
	}

	// Update the location
	getLocation()->removeCharacter(this);
	enteringLocation->addCharacter(this);
	setLocation(enteringLocation);

	cout << "You are now in " << enteringLocation->getName() << endl;
	return true;
}
