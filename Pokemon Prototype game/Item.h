#ifndef item_h
#define item_h

#include <string>
#include "Character.h"

using namespace std;

// These are items that can be picked up and used by players
class Item
{
public:
	Item(string name);
	virtual ~Item();
	string getName();

	virtual void act(Character *character) = 0;

private:
	string name;
};

#endif
