#ifndef world_h
#define world_h

#include <vector>
#include <cstdlib>
#include "Location.h"
#include "Player.h"
#include "Pokemon.h"
#include "Item.h"
#include "Pokeball.h"

using namespace std;

// World will initialize the linking of locations
class World
{
public:

	World();
	~World();

	void createPlayer(string name);
	vector<Player *> getPlayers();
	Pokemon *getPokemon();

private:
	vector<Location *> locations;
	vector<Player *> players;
	vector<Item *> items;
	Pokemon *pokemon;

	void initializePokeballs();
	void initializePokemon();
	void initializeLocations();
};

#endif
