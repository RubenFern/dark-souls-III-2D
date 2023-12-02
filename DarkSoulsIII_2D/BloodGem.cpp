#include "BloodGem.h"
#include "Player.h"
#include "GameLayer.h"

BloodGem::BloodGem(float x, float y, Game* game) :
	Consumable("res/actors/objects/bloodgem.jpg", x, y, 80, 82, game)
{
	text = new Text(to_string(num), WIDTH * 0.04, HEIGHT * 0.85, game);
}

void BloodGem::update()
{
	cout << useTime << endl;

	if (isUsing)
	{
		useTime--;

		if (useTime == 0)
		{
			isUsing = false;
			useTime = TIME;

			Player* player = static_cast<GameLayer*>(game->gameLayer)->player;
			player->setSelectedWeapon(player->weapons[0]);
		}
	}
}

void BloodGem::consume()
{
	isUsing = true;

	Player* player = static_cast<GameLayer*>(game->gameLayer)->player;

	UchigatanaBleeding* ub = new UchigatanaBleeding(WIDTH * 0.13, HEIGHT * 0.90, game);
	ub->setDamage(10);
	ub->stateBleeding = true;
	ub->stateFreezing = false;

	player->setSelectedWeapon(ub);
}