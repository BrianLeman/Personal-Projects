#ifndef gameengine_h
#define gameengine_h

#include <iostream>
#include "World.h"

using namespace std;

// Controls the flow of the game
class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	void run();

private:
	World *world;

	void initializePlayers();
	void displayGameIntro();
};

#endif
