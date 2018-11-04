#include <cstdlib>
#include <ctime>
#include "GameEngine.h"

// Start the pokemon game
int main()
{
	srand((unsigned)time(NULL));

	GameEngine engine;
	engine.run();

	return 0;
}