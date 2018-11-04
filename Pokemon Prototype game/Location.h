#ifndef location_h
#define location_h

#include <map>
#include <vector>
#include <string>
#include "Character.h"
#include "Pokemon.h"
#include "Player.h"

using namespace std;

// Location is where characters can move around
class Location
{
public:
	Location(string name, string description);

	void addExit(Location *location);
	Location *getExit(string locationName);
	string getName();
	string getDescription();
	vector<string> getExits();
	Pokemon *getPokemon();
	void removeCharacter(Character *character);
	void addCharacter(Character *character);
	void addItem(Item *item);
	void removeItem(Item *item);
	vector<Item *> getItems();
	vector<Player *> getPlayers();

private:
	map<string, Location *> exits;
	vector<Player *> players;
	vector<Item *> items;
	Pokemon *pokemon;

	string name;
	string description;
};

#endif
