#ifndef character_h
#define character_h

#include <string>

class Location;

using namespace std;

// A character is a representation of a player or a monster
class Character
{
public:
	Character(string name, Location *location);
	virtual ~Character();

	string getName();
	void setHealth(int health);
	int getHealth();
	void setLocation(Location *location);
	Location *getLocation();

	// Make the character do some action
	virtual void act() = 0;

private:
	string name;
	int health;
	Location *location;
};

#endif
