#include "Pokeball.h"

// Create a pokeball
Pokeball::Pokeball() : Item("Pokeball")
{
}

// Apply the pokeball but only to pokemons
void Pokeball::act(Character *character)
{
	if (Pokemon *pokemon = dynamic_cast<Pokemon *>(character))
	{
		if (pokemon->getHealth() < 0)
			return;

		// The chances of pokemon getting caused is based on health
		// The weaker the pokemon becomes, the easier it gets captured
		int chance = rand() % 100;

		if (chance > pokemon->getHealth()) {
			pokemon->setCaptured(true);
		}
	}
}