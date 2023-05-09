#pragma once
#include "includes.h"

class Enemy : public Character
{
public:
	Enemy(int minHealth, int maxHealth, int minShield, int maxShield,
		int minDamage, int maxDamage, int minEvasionChance, int maxEvasionChance)
	{
		this->health_ = random(minHealth, maxHealth);
		this->shield_ = random(minShield, maxShield);
		this->damage_ = random(minDamage, maxDamage);
		this->evasionChance_ = random(minEvasionChance, maxEvasionChance);
	}
};