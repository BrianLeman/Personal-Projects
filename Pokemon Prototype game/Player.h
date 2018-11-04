#ifndef player_h
#define player_h

#include <sstream>
#include <string>
#include <vector>
#include "Character.h"
#include "Item.h"

using namespace std;

// A player is user controlled
class Player : public Character
{
public:
	Player(string name, Location *location);
	void act();

private:
	vector<Item *> items;

	bool displayHelp();
	bool enterLocation(stringstream &ss);
	bool describeLocation();
	bool takeItem(stringstream &ss);
	bool displayBag();
	bool catchPokemon();
	bool tacklePokemon();
};
#endif
