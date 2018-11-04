#ifndef pokeball_h
#define pokeball_h

#include <cstdlib>
#include "Item.h"
#include "Pokemon.h"

class Pokeball : public Item
{
public:
	Pokeball();
	void act(Character *character);
};

#endif
