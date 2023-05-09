#pragma once
#include "includes.h"

enum DefenceType
{
	ATTACKING = 1,
	BLOCKING,
	KICKING,
	RUNNING_AWAY
};

class Character
{
public:
	void getAttackDamage(int damage);

	int getHealth();
	int getShield();
	int getDamage();
	int getEvasionChance();

	void addHealth(int health);
	void addShield(int shield);
	void addDamage(int damage);
	void addEvasionChance(int evasionChance);

	string getStats();

	bool isAlive();

protected:
	int health_;
	int shield_;
	int damage_;
	int evasionChance_;

};