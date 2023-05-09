#pragma once
#include "includes.h"

class Battle
{
public:
	Battle(Player& player, Character& enemy)
	{
		this->player_ = &player;
		this->enemy_ = &enemy;
	}

	void start();

private:
	Player* player_;
	Character* enemy_;

	string actions[4]{ "атаковать", "закрыться щитом", "пнуть", "сбежать" };

	bool getUserAction();
};