#include "HealthBar.h"

HealthBar::HealthBar(int health, int height, float x, float y, Game* game)
{
	this->health = health;
	this->x = x;
	this->y = y;
	this->height = height;
	this->game = game;
	width = health;
}

void HealthBar::draw(int x, int y)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = health;
	rect.h = height;

	// Barra de vida
	SDL_SetRenderDrawColor(game->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(game->renderer, &rect);

	for (int i = 0; i < 3; i++)
	{
		SDL_Rect rectBorder;
		rectBorder.x = x - i;
		rectBorder.y = y - i;
		rectBorder.w = width + i * 2;
		rectBorder.h = height + i * 2;

		// Borde de la barra de vida
		SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255); // Color negro para el borde
		SDL_RenderDrawRect(game->renderer, &rectBorder);
	}
}