#include "GameEngine.h"

// Start the game engine, initialize the world
GameEngine::GameEngine()
{
	world = new World();
}

// Free up memory
GameEngine::~GameEngine()
{
	delete world;
}

// Run the game giving each character chance to move
void GameEngine::run()
{
	displayGameIntro();
	initializePlayers();

	// Play the game
	while (true)
	{
		// Make the players make their move
		vector<Player *> players = world->getPlayers();
		Pokemon *pokemon = world->getPokemon();

		int deadPlayers = 0;

		for (unsigned i = 0; i < players.size(); i++)
		{
			if (players[i]->getHealth() > 0)
			{
				players[i]->act();

				// Game is over when pokemon dies or when captured
				if (pokemon->getHealth() < 0 || pokemon->isCaptured())
					break;
			}
			else
			{
				deadPlayers++;
			}
		}

		// If all players are dead then game is over
		if (deadPlayers == (signed)players.size())
		{
			cout << "All players are dead. You all failed the test." << endl;
			break;
		}

		// Make the pokemon move only if alived or not captured
		if (pokemon->getHealth() < 0 || pokemon->isCaptured())
			break;

		pokemon->act();
	}
}

// Initialize the names of each player
void GameEngine::initializePlayers()
{
	cout << "Setting up players..." << endl;
	string name;

	cout << "Player 1, what's your name? ";
	getline(cin, name);
	world->createPlayer(name);

	cout << "Player 2, what's your name? ";
	getline(cin, name);
	world->createPlayer(name);

	cout << endl;
}

// Display the game introduction
void GameEngine::displayGameIntro()
{
	cout << "Welcome to the world of pokemon!" << endl;
	cout << "Today you will be training on how to capture pokemons." << endl;
	cout << "Pokemons are wild, they roam around and they attack anyone around." << endl;
	cout << "To become a pokemaster, your objective is not to kill a pokemon, " << endl;
	cout << "but rather tame them. Before you can tame them, you need to capture " << endl;
	cout << "them using a pokeball. Hint: pokemons are easier to catch if their low." << endl;
	cout << "You will pass this test if and only if you survive capturing a pokemon " << endl;
	cout << "and NOT KILLING IT!" << endl;
	cout << endl;
	cout << "A wild pikachu is around. Go find some pokeballs and capture a pikachu." << endl;
	cout << "Whoever captures pikachu wins this game." << endl;
	cout << endl;
}