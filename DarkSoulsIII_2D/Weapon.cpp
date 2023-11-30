#include "Weapon.h"

Weapon::Weapon(string filename, float x, float y, int width, int height, Game* game) :
	Actor(filename, x, y, width, height, game)
{
}

void Weapon::draw(float scrollX, float scrollY)
{
	Actor::draw(0, 0);
}