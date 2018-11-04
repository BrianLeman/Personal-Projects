#ifndef pokemon_h
#define pokemon_h

#include "Character.h"

using namespace std;

// The pokemon is to be captured by a player
class Pokemon : public Character
{
public:

	Pokemon(string name, Location *location);

	void act();
	void setCaptured(bool captured);
	bool isCaptured();

private:
	bool captured;
};

#endif
