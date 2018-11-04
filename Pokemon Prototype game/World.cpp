#include "World.h"

// Create the pokemon's world
World::World()
{
	initializeLocations();
	initializePokeballs();
	initializePokemon();
}

// Free objects
World::~World()
{
	for (unsigned i = 0; i < locations.size(); i++)
		delete locations[i];

	for (unsigned i = 0; i < players.size(); i++)
		delete players[i];

	for (unsigned i = 0; i < items.size(); i++)
		delete items[i];

	delete pokemon;
}

// Add a new player with the given name, all players start at PalletTown
void World::createPlayer(string name)
{
	Player *player = new Player(name, locations[0]);
	players.push_back(player);
}

// Return the list of characters
vector<Player *> World::getPlayers()
{
	return players;
}

// Get the pokemon from this world
Pokemon *World::getPokemon()
{
	return pokemon;
}

// Put the pokeballs randomly in any of the locations
void World::initializePokeballs()
{
	// Distribute 10 pokeballs randomly in any city
	for (int i = 0; i < 10; i++)
	{
		Pokeball *pokeball = new Pokeball();
		items.push_back(pokeball);

		Location *location = locations[rand() % locations.size()];
		location->addItem(pokeball);
	}
}

// Create 1 pokemon which will be located at Celadon City
void World::initializePokemon()
{
	pokemon = new Pokemon("Pikachu", locations[9]);
}

// Initialize the locations and link them
void World::initializeLocations()
{
	// Create the locations
	Location *palletTown = new Location("PalletTown", "A  tranquil setting of peace and purity.");
	Location *viridianCity = new Location("ViridianCity", "The eternally green paradise.");
	Location *cinnabarIsland = new Location("CinnabarIsland", "The fiery town of burning desire.");
	Location *pewterCity = new Location("PewterCity", "Between rugged mountains.");
	Location *mountMoon = new Location("MountMoon", "Maountainous nature.");
	Location *ceruleanCity = new Location("CeruleanCity", "A mysterious, blue aura surrounds it.");
	Location *seaCottage = new Location("SeaCottage", "Home of bill.");
	Location *saffronCity = new Location("SaffronCity", "Shining, golden land of commerce.");
	Location *vermilionCity = new Location("VermilionCity", "The port of exquisite sunsets.");
	Location *celadonCity = new Location("CeladonCity", "The city of rainbow dreams.");

	locations.push_back(palletTown);
	locations.push_back(viridianCity);
	locations.push_back(cinnabarIsland);
	locations.push_back(pewterCity);
	locations.push_back(mountMoon);
	locations.push_back(ceruleanCity);
	locations.push_back(seaCottage);
	locations.push_back(saffronCity);
	locations.push_back(vermilionCity);
	locations.push_back(celadonCity);

	// Link the locations
	palletTown->addExit(viridianCity);
	palletTown->addExit(cinnabarIsland);

	cinnabarIsland->addExit(palletTown);

	viridianCity->addExit(pewterCity);
	viridianCity->addExit(palletTown);

	pewterCity->addExit(viridianCity);
	pewterCity->addExit(mountMoon);

	mountMoon->addExit(pewterCity);
	mountMoon->addExit(ceruleanCity);

	ceruleanCity->addExit(seaCottage);
	ceruleanCity->addExit(saffronCity);
	ceruleanCity->addExit(mountMoon);

	saffronCity->addExit(ceruleanCity);
	saffronCity->addExit(celadonCity);
	saffronCity->addExit(vermilionCity);

	vermilionCity->addExit(saffronCity);

	celadonCity->addExit(saffronCity);

	seaCottage->addExit(ceruleanCity);
}